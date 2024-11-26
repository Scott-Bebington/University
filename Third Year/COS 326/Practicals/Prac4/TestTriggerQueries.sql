-- INSERT Undergraduate a record with an invalid degree code
INSERT INTO Undergraduate (stdNum, title, firstNames, lastNames, degreeCode, DOB, YOS, courseRegistration)
VALUES ('215462', 'Mr', 'Scott', 'Bebington', 'ABC', '2001-12-25', 3, ARRAY['COS301', 'CHE202', 'PHY203'])

-- INSERT Undergraduate a record with a courseRegistration array which has an invalid course code
INSERT INTO Undergraduate (stdNum, title, firstNames, lastNames, degreeCode, DOB, YOS, courseRegistration)
VALUES ('215462', 'Mr', 'Scott', 'Bebington', 'BSC', '2001-12-25', 3, ARRAY['COS333'])

-- INSERT Postgraduate a record with an invalid degree code
INSERT INTO Postgraduate (stdNum, title, firstNames, lastNames, degreeCode, DOB, YOS, courseRegistration)
VALUES ('215462', 'Mr', 'Scott', 'Bebington', 'ABC', '2001-12-25', 3,ARRAY['COS301', 'CHE202', 'PHY203'])

-- UPDATE Undergraduate to change the degree code of an existing record to an invalid degree code
UPDATE Undergraduate
SET degreeCode = 'ABC'
WHERE stdNum = '140140';

-- UPDATE Undergraduate to change the CourseRegistration array of an existing record to another array which has an invalid course code
UPDATE Undergraduate
SET courseRegistration = ARRAY['ABC123']
WHERE stdNum = '140140';

-- UPDATE Postgraduate to change the degree code of an existing record to an invalid degree code
UPDATE Postgraduate
SET degreeCode = 'ABC'
WHERE stdNum = '160001';


-- DELETE Undergraduate
DELETE FROM Undergraduate
WHERE stdNum = '140140';

SELECT *
FROM Undergraduate;

SELECT *
FROM DeletedUndergrad;


-- DELETE Postgraduate
DELETE FROM Postgraduate
WHERE stdNum = '160001';

SELECT *
FROM Postgraduate;

SELECT *
FROM DeletedPostgrad;
