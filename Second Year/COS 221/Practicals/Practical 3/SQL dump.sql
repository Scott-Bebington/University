-- --------------------------------------------------------
-- Host:                         127.0.0.1
-- Server version:               11.1.0-MariaDB - mariadb.org binary distribution
-- Server OS:                    Win64
-- HeidiSQL Version:             12.3.0.6589
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

-- Dumping structure for table banking_system.account
CREATE TABLE IF NOT EXISTS `account` (
  `Client_Unique_Number` int(11) NOT NULL,
  `Account_Type` varchar(50) NOT NULL,
  PRIMARY KEY (`Client_Unique_Number`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table banking_system.account: ~7 rows (approximately)
INSERT INTO `account` (`Client_Unique_Number`, `Account_Type`) VALUES
	(12345, 'Cheque'),
	(23456, 'Savings'),
	(34567, 'Savings'),
	(45678, 'Cheque'),
	(54321, 'Savings'),
	(67890, 'Savings'),
	(98765, 'Cheque');

-- Dumping structure for table banking_system.atm
CREATE TABLE IF NOT EXISTS `atm` (
  `Available_Cash` bigint(20) DEFAULT NULL,
  `Date_And_Time_Of_Last_Filling` datetime DEFAULT NULL,
  `Branch_Code` int(11) DEFAULT NULL,
  `Filled_By` int(11) DEFAULT NULL,
  `Serial_Number` varchar(255) NOT NULL DEFAULT 'Cant Happen',
  PRIMARY KEY (`Serial_Number`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table banking_system.atm: ~7 rows (approximately)
INSERT INTO `atm` (`Available_Cash`, `Date_And_Time_Of_Last_Filling`, `Branch_Code`, `Filled_By`, `Serial_Number`) VALUES
	(40000, '2023-03-21 16:10:00', 6, 678901234, 'ABC121936789'),
	(35000, '2023-03-18 09:00:00', 7, 789012345, 'ABC123443889'),
	(50000, '2023-04-03 08:35:00', 2, 123456789, 'ABC123456789'),
	(55000, '2023-03-24 13:30:00', 5, 567890123, 'ABC123458249'),
	(30000, '2023-03-30 15:45:00', 3, 345678901, 'ABC123493489'),
	(20000, '2023-04-01 12:00:00', 2, 234567890, 'ABC125756789'),
	(45000, '2023-03-27 10:20:00', 4, 456789012, 'ABC126543789');

-- Dumping structure for table banking_system.branch
CREATE TABLE IF NOT EXISTS `branch` (
  `Unique_Branch_Code` int(11) NOT NULL,
  `Address` varchar(255) DEFAULT NULL,
  `Contact_Details` varchar(255) DEFAULT NULL,
  `Open_Times` int(11) DEFAULT NULL,
  `Close_Times` int(11) DEFAULT NULL,
  `Open_Days` varchar(255) DEFAULT NULL,
  `Close_Days` varchar(255) DEFAULT NULL,
  `Branch_Name` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`Unique_Branch_Code`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table banking_system.branch: ~7 rows (approximately)
INSERT INTO `branch` (`Unique_Branch_Code`, `Address`, `Contact_Details`, `Open_Times`, `Close_Times`, `Open_Days`, `Close_Days`, `Branch_Name`) VALUES
	(1, '1234 Maple St', 'branch1@FNB.com', 9, 5, 'Every day except public holidays', 'Christmas and new years', 'Randburg'),
	(2, '456 Elm Ave', 'branch2@FNB.com', 9, 5, 'Every day except public holidays', 'Christmas and new years', 'Hatfield'),
	(3, '789 Pine Rd', 'branch3@FNB.com', 9, 5, 'Every day except public holidays', 'Christmas and new years', 'Groenkloof'),
	(4, '234 Oak St', 'branch4@FNB.com', 9, 5, 'Every day except public holidays', 'Christmas and new years', 'Fourways'),
	(5, '567 Birch Ln', 'branch5@FNB.com', 9, 5, 'Every day except public holidays', 'Christmas and new years', 'Centurion'),
	(6, '890 Maplewood Dr', 'branch6@FNB.com', 9, 5, 'Every day except public holidays', 'Christmas and new years', 'Midrand'),
	(7, '123 Pinecrest Rd', 'branch7@FNB.com', 9, 5, 'Every day except public holidays', 'Christmas and new years', 'Suninghill');

-- Dumping structure for table banking_system.cit
CREATE TABLE IF NOT EXISTS `cit` (
  `Contarct_Start_Date` date DEFAULT NULL,
  `Contract_End_Date` date DEFAULT NULL,
  `Contract_number` int(11) NOT NULL DEFAULT 0,
  `Contact_Information` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`Contract_number`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table banking_system.cit: ~7 rows (approximately)
INSERT INTO `cit` (`Contarct_Start_Date`, `Contract_End_Date`, `Contract_number`, `Contact_Information`) VALUES
	('2022-01-01', '2022-12-31', 1234, 'johndoe@email.com'),
	('2021-05-01', '2022-04-30', 2345, 'janesmith@email.com'),
	('2023-06-01', '2024-05-31', 3456, 'alexjohnson@email.com'),
	('2021-08-01', '2022-07-31', 4567, 'samanthalee@email.com'),
	('2022-09-01', '2023-08-31', 5678, 'chrisbrown@email.com'),
	('2022-02-01', '2023-01-31', 6789, 'davidwilson@email.com'),
	('2023-03-01', '2024-02-29', 7890, 'sarahkim@email.com');

-- Dumping structure for table banking_system.clients
CREATE TABLE IF NOT EXISTS `clients` (
  `ID_Number` bigint(20) NOT NULL DEFAULT 0,
  `DOB` date DEFAULT NULL,
  `Full_Name` varchar(255) DEFAULT NULL,
  `Address` varchar(255) DEFAULT NULL,
  `Unique_Number` int(11) DEFAULT NULL,
  `Age` int(11) DEFAULT NULL,
  `Sex` varchar(255) DEFAULT NULL,
  `Net_Worth` int(11) DEFAULT NULL,
  `Contact_Details` varchar(255) DEFAULT NULL,
  `Validate_ID` binary(50) DEFAULT NULL,
  `Transactions_per_year` int(11) DEFAULT NULL,
  PRIMARY KEY (`ID_Number`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table banking_system.clients: ~8 rows (approximately)
INSERT INTO `clients` (`ID_Number`, `DOB`, `Full_Name`, `Address`, `Unique_Number`, `Age`, `Sex`, `Net_Worth`, `Contact_Details`, `Validate_ID`, `Transactions_per_year`) VALUES
	(202020000124, '2002-02-02', 'William Lee', '789 Oak Ave', 98765, 19, 'Male', 8000, 'william.lee@yahoo.com', _binary 0x3000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 0),
	(312010000123, '2003-12-01', 'Emily Johnson', '456 Elm St', 54321, 18, 'Female', 5000, 'emily.johnson@gmail.com', _binary 0x3000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 9),
	(412040000126, '2004-12-04', 'Jacob Patel', '567 Pine Blvd', 67890, 17, 'Male', 2000, 'jacob.patel@gmail.com', _binary 0x3000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 42),
	(503030000125, '2005-03-03', 'Sophie Brown', '123 Maple Rd', 12345, 16, 'Female', 1000, 'sophie.brown@hotmail.com', _binary 0x3100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 10),
	(707050000127, '2007-07-05', 'Emma Kim', '789 Cedar Dr', 23456, 14, 'Female', 1500, 'emma.kim@hotmail.com', _binary 0x3100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 10),
	(808070000129, '2008-08-07', 'Ava Hernandez', '234 Birch Ave', 45678, 13, 'Female', 700, 'ava.hernandez@gmail.com', _binary 0x3000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 76),
	(906060000128, '2009-06-06', 'Michael Nguyen', '901 Oak St', 34567, 12, 'Male', 500, 'michael.nguyen@yahoo.com', _binary 0x3100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 35);

-- Dumping structure for table banking_system.fnb
CREATE TABLE IF NOT EXISTS `fnb` (
  `Client_Number` int(11) NOT NULL DEFAULT 0,
  `Branch_Codes` int(11) DEFAULT NULL,
  PRIMARY KEY (`Client_Number`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table banking_system.fnb: ~7 rows (approximately)
INSERT INTO `fnb` (`Client_Number`, `Branch_Codes`) VALUES
	(12345, 2),
	(23456, 3),
	(34567, 5),
	(45678, 2),
	(54321, 4),
	(67890, 7),
	(98765, 2);

-- Dumping structure for table banking_system.parents
CREATE TABLE IF NOT EXISTS `parents` (
  `Childs_Unique_Number` int(11) NOT NULL DEFAULT 0,
  `Parent_Name` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`Childs_Unique_Number`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table banking_system.parents: ~7 rows (approximately)
INSERT INTO `parents` (`Childs_Unique_Number`, `Parent_Name`) VALUES
	(12345, 'Karen Brown'),
	(23456, 'Jin Kim'),
	(34567, 'Linh Nguyen'),
	(45678, 'Sofia Hernandez'),
	(54321, 'Mary Johnson'),
	(67890, 'Raj Patel'),
	(98765, 'David Lee');

/*!40103 SET TIME_ZONE=IFNULL(@OLD_TIME_ZONE, 'system') */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
