<?php
    session_start();
    $currentPage = basename($_SERVER['PHP_SELF']);
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <nav class="Nav" id="Nav">
        <nav class="inNav" id="InNav">
            <div>
                <a href="../../index.html">
                    <img alt="Logo" style="height: 100%" src="./Components/Logos/Other_Logo.png" id="Logo">
                </a>
            </div>
            <ul>
                <li><a <?php if($currentPage === "Index.php") { echo 'class="active"'; } else { echo 'class="inactive"'; } ?> href="./Index.php">Cars</a></li>
            </ul>
            <ul>
                <li><a <?php if($currentPage === "FindCar.php") { echo 'class="active"'; } else { echo 'class="inactive"'; } ?> href="./FindCar.php">Find Car</a></li>
            </ul>
            <ul>
                <li><a <?php if($currentPage === "Brands.php") { echo 'class="active"'; } else { echo 'class="inactive"'; } ?> href="./Brands.php">Brands</a></li>
            </ul>
            <ul>
                <li><a <?php if($currentPage === "Compare.php") { echo 'class="active"'; } else { echo 'class="inactive"'; } ?> href="./Compare.php">Compare</a></li>
            </ul>
            <?php if (isset($_SESSION['logged_in']) && $_SESSION['logged_in'] == true) : ?>
                <ul style="display: flex">
                    <li><a style="text-decoration: none; color: black;" href="./logout.php" onclick="return LogoutWarning()"><?php echo $_SESSION['User'] . '(logout)'; ?>&nbsp</a></li>
                    <script>
                        function LogoutWarning() 
                        {
                            return confirm("Are you sure you want to log out?");
                        }
                    </script>
                    <li>
                        <a href="./Preferences.php">
                            <img 
                            src="./Components/Sort_Images/Settings Icon.png" 
                            alt="Settings Icon"
                            style="height: 1.3em"
                            >
                        </a>
                    </li>

                </ul>
                
            <?php else : ?>
                <ul>
                    <li><a <?php if($currentPage === "login.php") { echo 'class="active"'; } else { echo 'class="inactive"'; } ?> href="./login.php">Login</a></li>
                </ul>
                <ul>
                    <li><a <?php if($currentPage === "signup.php") { echo 'class="active"'; } else { echo 'class="inactive"'; } ?> href="./signup.php">Sign Up</a></li>
                </ul>
            <?php endif; ?>
        </nav>
    </nav>
</body>
</html>
