<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>COS 216 Practicals</title>
    <link rel="stylesheet" type="text/css" href="./Components/CSS/logincss.css">
</head>

<body>
    <!-- Author: Scott Bebington
    Student Number: u21546216 -->
    <?php include_once('header.php'); ?>
    <div class="FullScreen">
        <div class="Container">
            <div class="LogoContainer">
                <h1>Login</h1>
            </div>
            <form action="./validate-login.php" method="post">
                <div class="LoginDetails">
                    <label for="Email">Email</label>
                    <input class="InputFields" type="email" id="Email" placeholder="Email Address..." name="email">
                    <br>
                    <label for="Email">Password</label>
                    <input class="InputFields" type="password" id="Password" placeholder="Password..." name="password">
                </div>
                <div class="ButtonContainerLeft">
                    <!-- <button class="Button" onclick="testInputs()">Sign Up</button> -->
                    <button class="Button">Login</button>
                </div>
            </form>
            <div class="ButtonContainerRight">
                <button class="Button" onclick="GoToPage()">Sign Up</button>
            </div>
        </div>
    </div>
    <?php include_once('footer.php'); ?>
    <script src="./Components/js_files/Loginjs.js"></script>
</body>

</html>