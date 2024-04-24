<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>COS 216 Practicals</title>
    <link rel="stylesheet" type="text/css" href="./Components/CSS/Registercss.css">
</head>

<body>
    <!-- Author: Scott Bebington
    Student Number: u21546216 -->
    <?php include_once('header.php'); ?>
    <div class="FullScreen">
        <div class="Container">
            <div class="LogoContainer">
                <h1>Sign Up</h1>
            </div>
            <form action="validate-signup.php" method="post" onsubmit="return ValidateInfo();">
                <div class="LoginDetails">
                    <label for="Email">Name</label>
                    <input class="InputFields" type="text" id="Name" placeholder="Name..." name="name">
                    <!-- <br> -->
                    <label for="Email">Surname</label>
                    <input class="InputFields" type="text" id="Surname" placeholder="Surname..." name="surname">
                    <!-- <br> -->
                    <label for="Email">Email</label>
                    <input class="InputFields" type="email" id="Email" placeholder="Email Address..." name="email">
                    <!-- <br> -->
                    <label for="Email">Password</label>
                    <input class="InputFields" type="password" id="Password" placeholder="Password..." name="password">
                </div>
                <div class="ButtonContainerLeft">
                    <button class="Button" type="submit">Sign Up</button>
                </div>
            </form>
            <div class="ButtonContainerRight">
                <button class="Button" onclick="GoToPage()">Login</button>
            </div>
        </div>
    </div>
    <?php include_once('footer.php'); ?>
    <script src="./Components/js_files/SignUpjs.js"></script>
</body>

</html>