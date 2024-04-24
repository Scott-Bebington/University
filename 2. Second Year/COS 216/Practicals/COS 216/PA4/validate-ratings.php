<?php

session_start();
require_once ('./config.php');

$postData = file_get_contents('php://input');

$UpdateCheck = substr($postData, 0, 6);
if($_SESSION['APIKEY'] != '')
{
    if($UpdateCheck == "USERID")
    {
        if (isset($_SESSION['UserID']) && $_SESSION['UserID'] != null)
        {
            echo $_SESSION['UserID'];
        }
        else
        {
            echo "None";
        }
    }
    else if($UpdateCheck == "SELECT")
    {
        $SQLQuery = $postData;

        // echo $SQLQuery;

        $stmt = mysqli_prepare($DBConnection, $SQLQuery);
        mysqli_stmt_bind_param($stmt, "s", $table_name);
        mysqli_stmt_execute($stmt);
        $result = mysqli_stmt_get_result($stmt);

        if (mysqli_num_rows($result) > 0) 
        {
            while ($row = mysqli_fetch_assoc($result)) 
            {
                echo "Results Found, Updating Rating";
            }
        }
        else
        {
            echo "No Results, Inserting Rating";
        }
    }
    else 
    {
        $SQLQuery = $postData;
        $stmt = mysqli_prepare($DBConnection, $SQLQuery);
        mysqli_stmt_bind_param($stmt, "s", $table_name);
        mysqli_stmt_execute($stmt);

        if($UpdateCheck == "INSERT")
        {
            echo "Inserted Rating";
        }
        else
        {
            echo "Updated Rating";
        }
        
    }
}
else
{
    echo "None";
}



?>
