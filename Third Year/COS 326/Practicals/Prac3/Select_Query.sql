-- Stdent Personal Details (1)
SELECT 
	stdKey AS student_id, 
	stdNum AS studentnumber, 
	personFullName(stdNum) AS personfullnames, 
	ageInYears(stdNum) AS ageinyears
FROM Student;

-- Undergrad Students (2)
SELECT 
	s.stdKey AS student_id, 
	s.stdNum AS studentnumber, 
	personFullName(s.stdNum) AS personfullnames,
	degreeCode AS studentdegreecode,
	YOS AS studentyearofstudy,
	courseRegistration AS courseregistration
FROM Student s
JOIN Undergraduate u ON s.stdNum = u.stdNum;

-- Postgrad Students (3)
SELECT 
	s.stdKey AS student_id, 
	s.stdNum AS studentnumber, 
	personFullName(s.stdNum) AS personfullnames,
	degreeCode AS studentdegreecode,
	YOS AS studentyearofstudy,
	pg.category AS postgraduatecategory,
	sv.title || ' ' || sv.firstNames || ' ' || sv.lastNames AS supervisor
FROM Student s
JOIN Postgraduate pg ON s.stdNum = pg.stdNum
JOIN Supervisor sv ON pg.supKey = sv.supKey;

-- Undergrad Students In Final Year (4)
SELECT 
	s.stdKey AS student_id, 
	s.stdNum AS studentnumber, 
	personFullName(s.stdNum) AS personfullnames,
	degreeCode AS studentdegreecode,
	YOS AS studentyearofstudy,
	courseRegistration AS courseregistration
FROM Student s
JOIN Undergraduate u ON s.stdNum = u.stdNum
WHERE isFinalYearStudent(s.stdNum);

-- Undergrad Students Registered For BIO201 (4)
SELECT 
	s.stdKey AS student_id, 
	s.stdNum AS studentnumber, 
	personFullName(s.stdNum) AS personfullnames,
	degreeCode AS studentdegreecode,
	YOS AS studentyearofstudy,
	courseRegistration AS courseregistration
FROM Student s
JOIN Undergraduate u ON s.stdNum = u.stdNum
WHERE isRegisteredFor(s.stdNum, 'BIO201');

-- Postgrad Students Full Time (6)
SELECT 
	s.stdKey AS student_id, 
	s.stdNum AS studentnumber, 
	personFullName(s.stdNum) AS personfullnames,
	degreeCode AS studentdegreecode,
	YOS AS studentyearofstudy,
	pg.category AS postgraduatecategory,
	sv.title || ' ' || sv.firstNames || ' ' || sv.lastNames AS supervisor
FROM Student s
JOIN Postgraduate pg ON s.stdNum = pg.stdNum
JOIN Supervisor sv ON pg.supKey = sv.supKey
WHERE isFullTime(s.stdNum);

-- Postgrad Students Part Time (7)
SELECT 
	s.stdKey AS student_id, 
	s.stdNum AS studentnumber, 
	personFullName(s.stdNum) AS personfullnames,
	degreeCode AS studentdegreecode,
	YOS AS studentyearofstudy,
	pg.category AS postgraduatecategory,
	sv.title || ' ' || sv.firstNames || ' ' || sv.lastNames AS supervisor
FROM Student s
JOIN Postgraduate pg ON s.stdNum = pg.stdNum
JOIN Supervisor sv ON pg.supKey = sv.supKey
WHERE isPartTime(s.stdNum);





