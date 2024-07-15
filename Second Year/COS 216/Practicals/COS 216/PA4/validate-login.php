<?php
session_start();
require_once('config.php');

if ($DBConnection->connect_error) 
{
    die("Connection failed: " . $DBConnection->connect_error);
}

$email = $_POST['email'];
$password = $_POST['password'];

$sqlCheck = "SELECT * FROM Users WHERE Email = ?";
$stmt = mysqli_prepare($DBConnection, $sqlCheck);
mysqli_stmt_bind_param($stmt, "s", $email);
mysqli_stmt_execute($stmt);
$result = mysqli_stmt_get_result($stmt);

if (mysqli_num_rows($result) > 0) 
{
    $row = mysqli_fetch_assoc($result);


    $hash = $row['Password'];
    
    $salt_hashed = $row['Salt'];
    $passwordAfterSalt = $salt_hashed . $password;

    if (password_verify($passwordAfterSalt, $hash)) 
    {
        $_SESSION['logged_in'] = true;
        $_SESSION['User'] = $row['Name'] . " " . $row['Surname'];
        $_SESSION['UserID'] = $row['ID'];
        $_SESSION['APIKEY'] = $row['API_key'];
        // echo $_SESSION['APIKEY'];
        header("Location: Index.php");
        exit();
    } 
    else 
    {
        echo "<script>alert('Invalid Password. Please try again.')</script>";
        header("Refresh:0; url=login.php");
        exit();
    }
} 
else 
{
    echo "<script>alert('Invalid Email Address. Please try again.')</script>";
    header("Refresh:0; url=login.php");
    exit();
}


?>
