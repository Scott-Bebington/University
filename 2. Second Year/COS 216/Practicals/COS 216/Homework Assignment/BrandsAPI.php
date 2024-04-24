<?php

session_start();
require_once ('./config.php');

$postData = file_get_contents('php://input');
$jsonData = json_decode($postData);

$DBQuery = "SELECT * FROM CarBrands WHERE BrandID = ";

// // echo "Query is as follows: <br><br>";

if ($jsonData->type == "GetBrands")
{
    $DBQuery .= $jsonData->BrandID;
    $stmt = mysqli_prepare($DBConnection, $DBQuery);
    mysqli_stmt_execute($stmt);
    $result = mysqli_stmt_get_result($stmt);

    if (mysqli_num_rows($result) > 0) 
    {
        $timestamp = round(microtime(true) * 1000);
        $cars = array();
        while ($row = mysqli_fetch_assoc($result)) 
        {
            $cars[] = $row;
        }
        $response = array(
            "status" => "success",
            "timestamp" => $timestamp,
            "data" => $cars
        );
        $json = json_encode($response);
        header('Content-Type: application/json');
        echo $json;
    } 
    else 
    {
        $timestamp = round(microtime(true) * 1000);
        $response = array(
            "status" => "error",
            "timestamp" => $timestamp,
            "message" => "Bad request"
        );
        $json = json_encode($response);
        header('Content-Type: application/json');
        echo $json;
    }
}
else 
{
    $timestamp = round(microtime(true) * 1000);
    $response = array(
        "status" => "error",
        "timestamp" => $timestamp,
        "message" => "Post parameters are missing"
    );
    $json = json_encode($response);
    header('Content-Type: application/json');
    echo $json;
}


?>