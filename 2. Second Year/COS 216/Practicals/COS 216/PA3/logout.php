<?php

session_start();
$_SESSION['logged_in'] = false;
$_SESSION['User'] = "Scott Bebington";
session_destroy();
header("Location: Index.php");

?>
