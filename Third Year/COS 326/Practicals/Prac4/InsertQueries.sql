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
    ('PHL301', 'Logical Reasoning', 'Philosophy', 15),
    ('BIO201', 'Biology', 'Science', 15),
    ('CHE202', 'Chemistry', 'Science', 15),
    ('PHY201', 'Physics', 'Science', 15),
    ('BIO203', 'Genetics', 'Science', 15),
    ('PHY203', 'Thermodynamics', 'Science', 15),
    ('MAT204', 'Mathematics', 'Mathematics', 15),
    ('COS700', 'Research Methodology', 'Computer Science', 40),
    ('COS702', 'Advanced Software Engineering', 'Computer Science', 40),
    ('COS703', 'Advanced Database Systems', 'Computer Science', 40);

INSERT INTO Supervisor(supKey, title, firstNames, lastNames)
VALUES 
    ('111111', 'Mr' , 'You', 'Dont Know'),
    ('222222', 'Mrs', 'You', 'Do Know');

-- Insert into Undergraduate for specific undergraduate details
INSERT INTO Undergraduate (stdNum, title, firstNames, lastNames, degreeCode, DOB, YOS, courseRegistration)
VALUES
    ('150010', 'Mnr', 'Alice', 'Green', 'BIT', '1997-03-15', 3,ARRAY['BIO201', 'CHE202', 'PHY203']),
    ('150020', 'Ms', 'Natalie', 'Adams', 'BIT', '1998-08-22', 4,ARRAY['BIO201', 'CHE202', 'MAT204']),
    ('140130', 'Mr', 'Michael', 'Clark', 'BSC', '1996-11-05', 1,ARRAY['PHY201', 'CHE202', 'BIO203']),
    ('140140', 'Ms', 'Olivia', 'Taylor', 'BSC', '1997-07-30', 2,ARRAY['MAT204', 'PHY201', 'BIO203', 'CHE202']);

-- Insert into Postgraduate for specific postgraduate details
INSERT INTO Postgraduate (stdNum, title, firstNames, lastNames, degreeCode, DOB, YOS, supKey, courseRegistration, category)
VALUES
    ('160001', 'Mr', 'John', 'Smith', 'PHD', '1995-02-10', 1,'111111', ARRAY['COS700', 'COS702'], 'Fulltime'),
    ('160002', 'Ms', 'Emily', 'Johnson', 'PHD', '1994-09-18', 2,'222222', ARRAY['COS702', 'COS703'], 'Parttime');

