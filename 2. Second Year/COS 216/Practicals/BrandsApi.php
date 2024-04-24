<?php
    $host = "localhost";
    $username = "u21546216";
    $password = "ZTG66N4TEDUKVD6LHMUWCUKAPLD7LFXM";
    $database = "u21546216_cars";

    $DBConnection = new mysqli($host, $username, $password, $database);

    // $postData = 
    // '{
    //     "return": "*",
    //     "search":
    //     {
    //         "BrandID": 1
    //     },
    //     "limit": 5
    // }';

    $postData = file_get_contents('php://input');
    $jsonData = json_decode($postData);

    $query = "SELECT * FROM CarBrands WHERE BrandID = '" . $jsonData->search->BrandID . "'";

    $stmt = mysqli_prepare($DBConnection, $query);
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
        // header('Content-Type: application/json');
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
        // header('Content-Type: application/json');
        echo $json;
    }

?>
