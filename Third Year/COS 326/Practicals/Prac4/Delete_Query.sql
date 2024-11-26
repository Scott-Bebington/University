-- Drop triggers
DROP TRIGGER IF EXISTS record_delete_postgrad ON Postgraduate;
DROP TRIGGER IF EXISTS record_delete_undergrad ON Undergraduate;
DROP TRIGGER IF EXISTS check_valid_course_codes_postgrad ON Postgraduate;
DROP TRIGGER IF EXISTS check_valid_course_codes_undergrad ON Undergraduate;
DROP TRIGGER IF EXISTS check_valid_course_codes ON Student;
DROP TRIGGER IF EXISTS check_valid_degree_code_postgrad ON Postgraduate;
DROP TRIGGER IF EXISTS check_valid_degree_code_undergrad ON Undergraduate;
DROP TRIGGER IF EXISTS check_valid_degree_code ON Student;

-- Drop functions
DROP FUNCTION IF EXISTS audit_delete_postgrad;
DROP FUNCTION IF EXISTS audit_delete_undergrad;
DROP FUNCTION IF EXISTS check_valid_course_registration;
DROP FUNCTION IF EXISTS check_valid_degree;
DROP FUNCTION IF EXISTS isValidDegreeCode(VARCHAR(50));
DROP FUNCTION IF EXISTS hasDuplicateCourseCodes(CourseCodeName[]);
DROP FUNCTION IF EXISTS courseCodeFrequency(CourseCodeName[], CourseCodeName);
DROP FUNCTION IF EXISTS hasValidCourseCodes(CourseCodeName[]);
DROP FUNCTION IF EXISTS isValidCourseCode(CourseCodeName);
DROP FUNCTION IF EXISTS isPartTime(CHAR(6));
DROP FUNCTION IF EXISTS isFullTime(CHAR(6));
DROP FUNCTION IF EXISTS isFinalYearStudent(CHAR(6));
DROP FUNCTION IF EXISTS isRegisteredFor(CHAR(6), CourseCodeName);
DROP FUNCTION IF EXISTS ageInYears(CHAR(6));
DROP FUNCTION IF EXISTS personFullName(CHAR(6));

-- Drop tables
DROP TABLE IF EXISTS DeletedPostgrad;
DROP TABLE IF EXISTS DeletedUndergrad;
DROP TABLE IF EXISTS Postgraduate;
DROP TABLE IF EXISTS Supervisor;
DROP TABLE IF EXISTS Undergraduate;
DROP TABLE IF EXISTS Student;
DROP TABLE IF EXISTS Course;
DROP TABLE IF EXISTS DegreeProgram;

-- Drop sequences
DROP SEQUENCE IF EXISTS CourseKey;
DROP SEQUENCE IF EXISTS DegreeKey;
DROP SEQUENCE IF EXISTS StudentID;

-- Drop domains
DROP DOMAIN IF EXISTS StudyYearsType;
DROP DOMAIN IF EXISTS StudentNumType;
DROP DOMAIN IF EXISTS CourseName;
DROP DOMAIN IF EXISTS CourseCodeName;

-- Drop types (ENUMs)
DROP TYPE IF EXISTS Title;
DROP TYPE IF EXISTS CustomCategory;
DROP DOMAIN IF EXISTS CourseName;
DROP DOMAIN IF EXISTS CourseCodeName;

-- Drop types (ENUMs)
DROP TYPE IF EXISTS Title;
DROP TYPE IF EXISTS CustomCategory;
