-- Create ENUM types
CREATE TYPE CustomCategory AS ENUM('Fulltime', 'Parttime');

CREATE TYPE Title AS ENUM(
    'Dr',
    'Prof',
    'Ms',
    'Mev',
    'Miss',
    'Mrs',
    'Mr',
    'Mnr'
);

-- Create domains
CREATE DOMAIN CourseCodeName AS CHAR(6) CHECK (VALUE ~ '^[A-Z]{3}[0-9]{3}$');
CREATE DOMAIN CourseName AS VARCHAR(50) CHECK (VALUE ~ '^[A-Z][a-z]$');
CREATE DOMAIN StudentNumType AS VARCHAR(6) CHECK (VALUE ~ '^[0-9]{6}$');
CREATE DOMAIN StudyYearsType AS INTEGER;

-- Create sequences
CREATE SEQUENCE StudentID START
WITH
    1 INCREMENT BY 1 NO MINVALUE NO MAXVALUE CACHE 1;

CREATE SEQUENCE DegreeKey START
WITH
    1 INCREMENT BY 1 NO MINVALUE NO MAXVALUE CACHE 1;

CREATE SEQUENCE CourseKey START
WITH
    1 INCREMENT BY 1 NO MINVALUE NO MAXVALUE CACHE 1;

-- Create tables
CREATE TABLE IF NOT EXISTS DegreeProgram (
    degKey INT PRIMARY KEY DEFAULT nextval('DegreeKey'),
    degCode VARCHAR(50) UNIQUE,
    degName VARCHAR(50),
    duration INT,
    faculty VARCHAR(50)
);

CREATE TABLE IF NOT EXISTS Course (
    courseKey INT PRIMARY KEY DEFAULT nextval('CourseKey'),
    courseCode CourseCodeName UNIQUE,
    courseName VARCHAR(50),
    department VARCHAR(50),
    credits INT
);

CREATE TABLE IF NOT EXISTS Student (
    stdKey INT PRIMARY KEY DEFAULT nextval('StudentID'),
    stdNum CHAR(6) UNIQUE,
    title Title,
    firstNames VARCHAR(50),
    lastNames VARCHAR(50),
    degreeCode VARCHAR(50) REFERENCES DegreeProgram (degCode),
    DOB DATE,
    YOS INT
);

CREATE TABLE IF NOT EXISTS Undergraduate (
    courseRegistration CourseCodeName[]
) INHERITS (Student);

CREATE TABLE IF NOT EXISTS Supervisor (
    supKey CHAR(6) PRIMARY KEY,
    title Title,
    firstNames VARCHAR(50),
    lastNames VARCHAR(50)
);

CREATE TABLE IF NOT EXISTS Postgraduate (
    supKey CHAR(6) REFERENCES Supervisor (supKey),
    courseRegistration CourseCodeName[],
    category CustomCategory
) INHERITS (Student);

CREATE TABLE if NOT EXISTS DeletedUndergrad (
    stdNum CHAR(6),
    title Title,
    firstNames VARCHAR(50),
    lastNames VARCHAR(50),
    degreeCode VARCHAR(50),
    DOB DATE,
    YOS INT,
    courseRegistration CourseCodeName[],
    DateAndTime TIMESTAMP,
    userID CHAR(6)
);

CREATE TABLE if NOT EXISTS DeletedPostgrad (
    stdNum CHAR(6),
    title Title,
    firstNames VARCHAR(50),
    lastNames VARCHAR(50),
    degreeCode VARCHAR(50),
    DOB DATE,
    YOS INT,
    courseRegistration CourseCodeName[],
    category CustomCategory,
    DateAndTime TIMESTAMP,
    userID CHAR(6)
);


-- Create functions
CREATE FUNCTION personFullName(stdNum CHAR(6))
RETURNS TEXT AS $$
DECLARE
    fullName TEXT;
BEGIN
    SELECT title || ' ' || firstNames || ' ' || lastNames INTO fullName
    FROM Student s
    WHERE s.stdNum = $1;
    
    RETURN fullName;
END;
$$ LANGUAGE plpgsql;

CREATE FUNCTION ageInYears(stdNum CHAR(6))
RETURNS INTEGER AS $$
DECLARE
    years INTEGER;
BEGIN
    SELECT EXTRACT(YEAR FROM AGE(DOB)) INTO years
    FROM Student s
    WHERE s.stdNum = $1;
    
    RETURN years;
END;
$$ LANGUAGE plpgsql;

CREATE FUNCTION isRegisteredFor(stdNum CHAR(6), courseCode CourseCodeName)
RETURNS BOOLEAN AS $$
DECLARE
    isRegistered BOOLEAN;
BEGIN
    SELECT EXISTS (
        SELECT 1
        FROM Undergraduate u
        WHERE u.stdNum = $1 AND courseCode = ANY(u.courseRegistration)
    ) INTO isRegistered;
    
    RETURN isRegistered;
END;
$$ LANGUAGE plpgsql;

CREATE FUNCTION isFinalYearStudent(stdNum CHAR(6))
RETURNS BOOLEAN AS $$
DECLARE
    isFinalYear BOOLEAN;
BEGIN
    SELECT (YOS = duration)
	INTO isFinalYear
    FROM Student s
    JOIN DegreeProgram d ON s.degreeCode = d.degCode
    WHERE s.stdNum = $1;

    RETURN isFinalYear;
END;
$$ LANGUAGE plpgsql;

CREATE FUNCTION isFullTime(stdNum CHAR(6))
RETURNS BOOLEAN AS $$
DECLARE
    isFullTime BOOLEAN;
BEGIN
    SELECT (category = 'Fulltime')
    INTO isFullTime
    FROM Student s
    JOIN Postgraduate pg ON s.stdNum = pg.stdNum
    WHERE s.stdNum = $1;
    
    RETURN isFullTime;
END;
$$ LANGUAGE plpgsql;

CREATE FUNCTION isPartTime(stdNum CHAR(6))
RETURNS BOOLEAN AS $$
DECLARE
    isPartTime BOOLEAN;
BEGIN
    SELECT (category = 'Parttime')
    INTO isPartTime
    FROM Student s
    JOIN Postgraduate pg ON s.stdNum = pg.stdNum
    WHERE s.stdNum = $1;
    
    RETURN isPartTime;
END;
$$ LANGUAGE plpgsql;

-- Prac 4 Functions
CREATE FUNCTION isValidCourseCode(courseCode CourseCodeName)
RETURNS BOOLEAN AS $$
DECLARE
    isExists BOOLEAN;
BEGIN
    SELECT EXISTS (
        SELECT 1
        FROM Course cor
        WHERE cor.courseCode = $1
    ) INTO isExists;
    
    RETURN isExists;
END;
$$ LANGUAGE plpgsql;

CREATE FUNCTION hasValidCourseCodes(CourseCodeName[])
RETURNS BOOLEAN AS $$
DECLARE
    courseCode CourseCodeName;
BEGIN
    FOREACH courseCode IN ARRAY $1
    LOOP
        IF NOT isValidCourseCode(courseCode) THEN
            RETURN FALSE;
        END IF;
    END LOOP;
    RETURN TRUE;
END;
$$ LANGUAGE plpgsql;

CREATE FUNCTION courseCodeFrequency(courseRegistration CourseCodeName[], courseCode CourseCodeName)
RETURNS INTEGER AS $$
DECLARE
    frequency INTEGER;
BEGIN
    SELECT COUNT(*)
    INTO frequency
    FROM unnest(courseRegistration) AS code
    WHERE code = courseCode;
    
    RETURN frequency;
END;
$$ LANGUAGE plpgsql;

CREATE FUNCTION hasDuplicateCourseCodes(courseRegistration CourseCodeName[])
RETURNS BOOLEAN AS $$
DECLARE
    courseCode CourseCodeName;
    duplicateCount INTEGER := 0;
BEGIN
    FOR i IN 1..array_length(courseRegistration, 1) LOOP
        courseCode := courseRegistration[i];
        FOR j IN i+1..array_length(courseRegistration, 1) LOOP
            IF courseCode = courseRegistration[j] THEN
                duplicateCount := duplicateCount + 1;
            END IF;
        END LOOP;
    END LOOP;
    
    IF duplicateCount > 0 THEN
        RETURN TRUE;
    ELSE
        RETURN FALSE;
    END IF;
END;
$$ LANGUAGE plpgsql;

CREATE FUNCTION isValidDegreeCode(degCode VARCHAR(50)) 
RETURNS BOOLEAN AS $$
DECLARE
    isExists BOOLEAN;
BEGIN
    SELECT EXISTS (
        SELECT 1
        FROM DegreeProgram d
        WHERE d.degCode = $1
    ) INTO isExists;
    
    RETURN isExists;
END;
$$ LANGUAGE plpgsql;

-- Trigger procedures
CREATE OR REPLACE FUNCTION check_valid_degree_code()
RETURNS TRIGGER AS $$
BEGIN
    IF NOT isValidDegreeCode(NEW.degreeCode) THEN
        RAISE EXCEPTION 'Invalid degree code';
    END IF;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION check_valid_course_codes()
RETURNS TRIGGER AS $$
BEGIN
    IF NOT hasValidCourseCodes(NEW.courseRegistration) THEN
        RAISE EXCEPTION 'Invalid course codes';

    END IF;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION record_delete_undergrad()
RETURNS TRIGGER AS $$
BEGIN
    INSERT INTO DeletedUndergrad(stdNum, title, firstNames, lastNames, degreeCode, DOB, YOS, courseRegistration, DateAndTime, userID)
    VALUES (OLD.stdNum, OLD.title, OLD.firstNames, OLD.lastNames, OLD.degreeCode, OLD.DOB, OLD.YOS, OLD.courseRegistration, CURRENT_TIMESTAMP, '111111');

    RETURN OLD;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION record_delete_postgrad()
RETURNS TRIGGER AS $$
BEGIN
    INSERT INTO DeletedPostgrad(stdNum, title, firstNames, lastNames, degreeCode, DOB, YOS, courseRegistration, category, DateAndTime, userID)
    VALUES (OLD.stdNum, OLD.title, OLD.firstNames, OLD.lastNames, OLD.degreeCode, OLD.DOB, OLD.YOS, OLD.courseRegistration, OLD.category, CURRENT_TIMESTAMP, '111111');

    RETURN OLD;
END;
$$ LANGUAGE plpgsql;


-- Triggers
-- Triggers
CREATE OR REPLACE TRIGGER check_valid_degree
BEFORE INSERT OR UPDATE ON Student
FOR EACH ROW
EXECUTE FUNCTION check_valid_degree_code();

CREATE OR REPLACE TRIGGER check_valid_degree_undergrad
BEFORE INSERT OR UPDATE ON Undergraduate
FOR EACH ROW
EXECUTE FUNCTION check_valid_degree_code();

CREATE OR REPLACE TRIGGER check_valid_degree_postgrad
BEFORE INSERT OR UPDATE ON Postgraduate
FOR EACH ROW
EXECUTE FUNCTION check_valid_degree_code();

CREATE OR REPLACE TRIGGER check_valid_course_registration
BEFORE INSERT OR UPDATE ON Student
FOR EACH ROW
EXECUTE FUNCTION check_valid_course_codes();

CREATE OR REPLACE TRIGGER check_valid_course_registration_undergrad
BEFORE INSERT OR UPDATE ON Undergraduate
FOR EACH ROW
EXECUTE FUNCTION check_valid_course_codes();

CREATE OR REPLACE TRIGGER check_valid_course_registration_postgrad
BEFORE INSERT OR UPDATE ON Postgraduate
FOR EACH ROW
EXECUTE FUNCTION check_valid_course_codes();

CREATE OR REPLACE TRIGGER audit_delete_undergrad
BEFORE DELETE ON Undergraduate
FOR EACH ROW
EXECUTE FUNCTION record_delete_undergrad();

CREATE OR REPLACE TRIGGER audit_delete_postgrad
BEFORE DELETE ON Postgraduate
FOR EACH ROW
EXECUTE FUNCTION record_delete_postgrad();
