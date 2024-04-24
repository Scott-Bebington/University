<?php

session_start();
require_once ('./COS 216/PA3/config.php');

    // $postData = 
    // '{
    //     "type":"GetAllCars",
    //     "apikey":"a9198b68355f78830054c31a39916b7f",
    //     "return":["id_trim", "make", "model", "max_speed_km_per_h"],
    //     "search":
    //     {
    //         "make":"audi"
    //     },
    //     "fuzzy":false,
    //     "sort": "max_speed_km_per_h",
    //     "order": "ASC",
    //     "limit": 5
    // }';

$postData = file_get_contents('php://input');
$jsonData = json_decode($postData);

$DBQuery = "SELECT ";

// echo "Query is as follows: <br><br>";

if ($jsonData->type == "GetAllCars" && $jsonData->return != '')
{
    if (implode(", ", $jsonData->return) == '')
    {
        $DBQuery .= '*';
    }
    else
    {
        foreach ($jsonData->return as $SearchType)
        {
            $DBQuery .= $SearchType . ", ";
        }
        $DBQuery = substr($DBQuery, 0, strlen($DBQuery)-2);
    }
    $DBQuery .= " FROM cars ";

    if ($jsonData->search)
    {
        $Count = 0;
        $FuzzySearch = true;
        if ($jsonData->fuzzy !== null)
        {
            $FuzzySearch = $jsonData->fuzzy;
        }
        $DBQuery .= "WHERE ";
        $table_name = "cars";

        $stmt = mysqli_prepare($DBConnection, "SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_SCHEMA = 'u21546216' AND TABLE_NAME = ?");
        mysqli_stmt_bind_param($stmt, "s", $table_name);
        mysqli_stmt_execute($stmt);
        $result = mysqli_stmt_get_result($stmt);


        while ($row = mysqli_fetch_assoc($result)) 
        {
            
            $column_name = $row['COLUMN_NAME'];
            if (isset($jsonData->search->$column_name))
            {
                if ($count > 0)
                {
                    $DBQuery .= " AND ";
                }
                if ($FuzzySearch)
                {
                    $DBQuery .= $column_name . " LIKE '%" . $jsonData->search->$column_name . "%'";
                }
                else
                {
                    $DBQuery .= $column_name . ' = "' . $jsonData->search->$column_name . '"';
                }
                
                $count = $count + 1;
            }
        }
    } 
    if($jsonData->sort)
    {
        $DBQuery .= " ORDER BY " . $jsonData->sort;
        if($jsonData->order)
        {
            $DBQuery .= " " . $jsonData->order;
        }
    }
    if ($jsonData->limit)
    {
        $DBQuery .= " LIMIT " . $jsonData->limit;
    }
    // echo $DBQuery;

    $stmt = mysqli_prepare($DBConnection, $DBQuery);
    mysqli_stmt_execute($stmt);
    $result = mysqli_stmt_get_result($stmt);

    if (mysqli_num_rows($result) > 0) 
    {
        $timestamp = round(microtime(true) * 1000);
        $cars = array();
        while ($row = mysqli_fetch_assoc($result)) 
        {
            $brand = str_replace(' ', '%20', $row['make']);
            $Model = str_replace(' ', '%20', $row['model']);
            $url = "https://wheatley.cs.up.ac.za/api/getimage?brand=" . $brand . "&model=" . $Model;

            $ch = curl_init();
            curl_setopt($ch, CURLOPT_URL, $url);
            curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
            $output = curl_exec($ch);

            $row['image'] = $output;
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
else if($jsonData->type == "GetBrand")
{
    $BrandID = $jsonData->BrandID;
    
    $timestamp = round(microtime(true) * 1000);
    $response = array(
        "status" => "Success",
        "timestamp" => $timestamp,
        "data" => "Get Brands Works"
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
        "message" => "Post parameters are missing"
    );
    $json = json_encode($response);
    header('Content-Type: application/json');
    echo $json;
}


?>