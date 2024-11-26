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
    stdNum CHAR(6) REFERENCES Student (stdNum),
    courseRegistration CourseCodeName[]
);

CREATE TABLE IF NOT EXISTS Supervisor (
    supKey CHAR(6) PRIMARY KEY,
    title Title,
    firstNames VARCHAR(50),
    lastNames VARCHAR(50)
);

CREATE TABLE IF NOT EXISTS Postgraduate (
    stdNum CHAR(6) REFERENCES Student (stdNum),
    supKey CHAR(6) REFERENCES Supervisor (supKey),
    courseRegistration CourseCodeName[],
    category CustomCategory
);

-- Create functions
CREATE FUNCTION personFullName(stdNum CHAR(6))
RETURNS TEXT AS $$
    SELECT title || ' ' || firstNames || ' ' || lastNames
    FROM Student
    WHERE stdNum = $1;
$$ LANGUAGE SQL;

CREATE FUNCTION ageInYears(stdNum CHAR(6))
RETURNS INTEGER AS $$
    SELECT EXTRACT(YEAR FROM AGE(DOB))
    FROM Student
    WHERE stdNum = $1;
$$ LANGUAGE SQL;

CREATE FUNCTION isRegisteredFor(stdNum CHAR(6), courseCode CourseCodeName)
RETURNS BOOLEAN AS $$
    SELECT EXISTS (
        SELECT 1
        FROM Undergraduate
        WHERE stdNum = $1 AND courseCode = ANY(courseRegistration)
    );
$$ LANGUAGE SQL;

CREATE FUNCTION isFinalYearStudent(stdNum CHAR(6))
RETURNS BOOLEAN AS $$
    SELECT (YOS = duration)
    FROM Student s
    JOIN DegreeProgram d ON s.degreeCode = d.degCode
    WHERE s.stdNum = $1;
$$ LANGUAGE SQL;

CREATE FUNCTION isFullTime(stdNum CHAR(6))
RETURNS BOOLEAN AS $$
    SELECT (category = 'Fulltime')
    FROM Student s
    JOIN Postgraduate pg ON s.stdNum = pg.stdNum
    WHERE s.stdNum = $1;
$$ LANGUAGE SQL;

CREATE FUNCTION isPartTime(stdNum CHAR(6))
RETURNS BOOLEAN AS $$
    SELECT (category = 'Parttime')
    FROM Student s
    JOIN Postgraduate pg ON s.stdNum = pg.stdNum
    WHERE s.stdNum = $1;
$$ LANGUAGE SQL;
