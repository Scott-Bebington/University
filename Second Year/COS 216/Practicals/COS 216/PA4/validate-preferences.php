<?php

session_start();
require_once ('./config.php');

$postData = file_get_contents('php://input');

$UpdateCheck = substr($postData, 0, 6);
if($_SESSION['APIKEY'] != "")
{
    if($UpdateCheck == "SELECT")
    {
        $SQLQuery = $postData . $_SESSION['UserID'] . ";";
        $stmt = mysqli_prepare($DBConnection, $SQLQuery);
        mysqli_stmt_bind_param($stmt, "s", $table_name);
        mysqli_stmt_execute($stmt);
        $result = mysqli_stmt_get_result($stmt);

        if (mysqli_num_rows($result) > 0)
        {
            while ($row = mysqli_fetch_assoc($result)) 
            {
                $response = array(
                    'UserID' => $row['UserID'],
                    'Seats' => $row['Seats'],
                    'Transmission' => $row['Transmission'],
                    'Fuel' => $row['Fuel'],
                    'Body' => $row['Body'],
                    'SortName' => $row['SortName'],
                    'SortYear' => $row['SortYear'],
                    'ColourScheme' => $row['ColourScheme']
                );
                
                $jsonResponse = json_encode($response);
                
                echo $jsonResponse;
                
            }
        }
        else
        {
            echo "None";
        }
    }
    else if($UpdateCheck == "DELETE")
    {
        $SQLQuery = $postData . $_SESSION['UserID'] . ";";
        $stmt = mysqli_prepare($DBConnection, $SQLQuery);
        mysqli_stmt_bind_param($stmt, "s", $table_name);
        mysqli_stmt_execute($stmt);
        echo $SQLQuery;
    }
    else if($UpdateCheck == "INSERT")
    {
        $SQLQuery = $postData;
        $stmt = mysqli_prepare($DBConnection, $SQLQuery);
        mysqli_stmt_bind_param($stmt, "s", $table_name);
        mysqli_stmt_execute($stmt);
        echo $SQLQuery;
    }
}
else
{
    echo "None";
}



?>
