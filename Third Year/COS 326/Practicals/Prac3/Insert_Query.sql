-- Insert data into the tables
INSERT INTO degreeProgram (degCode, degName, duration, faculty)
VALUES 
    ('BSC', 'Bachelor of Science', 3, 'Engineering and Built Environment'),
    ('BIT', 'Bachelor of IT', 4, 'Engineering and Built Environment'),
    ('PHD', 'Doctor of Philosophy', 5, 'Engineering and Built Environment');

INSERT INTO course (courseCode, courseName, department, credits)
VALUES 
    ('COS301', 'Software Engineering', 'Computer Science', 40),
    ('COS326', 'Database Systems', 'Computer Science', 20),
    ('MTH301', 'Discrete Mathematics', 'Mathematics', 15),
    ('PHL301', 'Logical Reasoning', 'Philosophy', 15);

INSERT INTO Supervisor(supKey, title, firstNames, lastNames)
VALUES 
	('111111', 'Mr' , 'You', 'Dont Know'),
	('222222', 'Mrs', 'You', 'Do Know');

INSERT INTO Student (stdNum, title, firstNames, lastNames, degreeCode, DOB, YOS)
VALUES
    ('150010', 'Mnr', 'Alice', 'Green', 'BIT', '1997-03-15', 3),
    ('150020', 'Ms', 'Natalie', 'Adams', 'BIT', '1998-08-22', 4),
    ('140130', 'Mr', 'Michael', 'Clark', 'BSC', '1996-11-05', 1),
    ('140140', 'Ms', 'Olivia', 'Taylor', 'BSC', '1997-07-30', 2),
    ('160001', 'Mr', 'John', 'Smith', 'PHD', '1995-02-10', 1),
    ('160002', 'Ms', 'Emily', 'Johnson', 'PHD', '1994-09-18', 2);
    

INSERT INTO Undergraduate (stdNum, courseRegistration)
VALUES
    ('150010', ARRAY['BIO201', 'CHE202', 'PHY203']),
    ('150020', ARRAY['BIO201', 'CHE202', 'MAT204']),
    ('140130', ARRAY['PHY201', 'CHE202', 'BIO203']),
    ('140140', ARRAY['MAT204', 'PHY201', 'BIO203', 'CHE202']);

INSERT INTO Postgraduate (stdNum, supKey, courseRegistration, category)
VALUES
    ('160001', '111111', ARRAY['COS700', 'COS702'], 'Fulltime'),
    ('160002', '222222', ARRAY['COS702', 'COS703'], 'Parttime');
