<?php

require_once ('config.php');

if ($DBConnection->connect_error) 
{
    die("Connection failed: " . $DBConnection->connect_error);
    exit();
}

$name = $_POST['name'];
$surname = $_POST['surname'];
$email = $_POST['email'];
$password = $_POST['password'];

$salt_length = 15;
$salt_chars = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
$salt = '';
for ($i = 0; $i < $salt_length; $i++) 
{
    $salt .= $salt_chars[random_int(0, 61)];
}

// $salt_hashed = password_hash($salt, PASSWORD_BCRYPT);
$salt_hashed = $salt;

$passwordAfterSalt = $salt . $password;
$Itterations = ['cost' => 12];
$hash = password_hash($passwordAfterSalt, PASSWORD_ARGON2ID, $Itterations);
// $hash = $passwordAfterSalt;

$EmailRexEx = "/^[^\s@]+@[^\s@]+\.[^\s@]+$/";
$UpperCaseLetters = "/[A-Z]/";
$LowerCaseLetters = "/[a-z]/";
$SpecialCharacter = "/[^\w\s]/";
$NumberCharacter = "/\d+/";

$sqlCheck = "SELECT * FROM Users WHERE Email = ?;";
$stmt = $DBConnection->prepare($sqlCheck);
$stmt->bind_param("s", $email);
$stmt->execute();
$result = $stmt->get_result();

if (mysqli_num_rows($result) > 0) 
{
    $row = mysqli_fetch_assoc($result);
    echo '<script>
        if (confirm("Email Address: ' . $email . ' already exists.\nClick Ok to go to the Login page.\nClick Cancel to return to the Sign Up page.")) 
        {
            window.location.href = "login.php";
        }
        else
        {
            window.location.href = "signup.php";
        }
        </script>';
        exit();
}
else 
{
    $sqlCheck = "SELECT `ID` FROM Users ORDER BY `ID` DESC LIMIT 1";
    $stmt = mysqli_prepare($DBConnection, $sqlCheck);
    mysqli_stmt_execute($stmt);
    $result = mysqli_stmt_get_result($stmt);
    $row = mysqli_fetch_assoc($result);

    $Checks = "Please make sure that.";

    if ($email == '') 
    {
        $Checks .= "Email: Must be filled in.";
    }
    else if (!strpos($Checks, "Email: Must be filled in.")) 
    {
        if (!preg_match($EmailRexEx, $email)) {
            $Checks .= "Email: Must contain @ symbol.";
        }
    }

    if ($password == '') 
    {
        $Checks .= "Password: Must be filled in.";
    }
    else if (!strpos($Checks, "Password: Must be filled in.")) 
    {
        if (!preg_match($UpperCaseLetters, $password)) {
            $Checks .= "Password: Must contain at least 1 Upper case letter.";
        }
        if (!preg_match($LowerCaseLetters, $password)) {
            $Checks .= "Password: Must contain at least 1 Lower case letter.";
        }
        if (!preg_match($SpecialCharacter, $password)) {
            $Checks .= "Password: Must contain at least 1 Special character.";
        }
        if (!preg_match($NumberCharacter, $password)) {
            $Checks .= "Password: Must contain at least 1 Number.";
        }
        if (strlen($password) > 8)
        {
            $Checks .= "Password: Must be less than 8 digits long.";
        }
    }
    if (strlen($Checks) == 22) 
{
    $ID = $row["ID"] + 1;

    $key_length = 15;
    $key_chars = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
    $apikey = '';
    for ($i = 0; $i < $key_length; $i++) 
    {
        $apikey .= $key_chars[random_int(0, 61)];
    }

    $stmt = mysqli_prepare($DBConnection, "INSERT INTO Users (ID, Name, Surname, Email, Password, Salt, API_key) VALUES (?, ?, ?, ?, ?, ?, ?)");
    mysqli_stmt_bind_param($stmt, "issssss", $ID, $name, $surname, $email, $hash, $salt_hashed, $apikey);
    mysqli_stmt_execute($stmt);

    echo '<script>
    if (confirm("User: ' . $name . ' ' . $surname . ' Successfully created.\nApi key for user: ' . $apikey . '\nClick OK to redirect to the Home page. \nClick Cancel to go back to the Sign up page.")) {
        window.location.href = "Index.php";
    }
    else
    {
        window.location.href = "signup.php";
    }
    </script>';
}

        
}

?>
