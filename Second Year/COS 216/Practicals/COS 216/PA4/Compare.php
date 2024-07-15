<?php ?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>COS 216 Practicals</title>
    <link rel="stylesheet" type="text/css" href="./Components/CSS/Comparecss.css">
</head>

<body onload="GetPreferences()">
    <!-- Author: Scott Bebington
    Student Number: u21546216 -->
    <?php include_once('header.php'); ?>
    <div class=" fullscreen">
        <div class="cars" id="CarContainer">
            <br>
            <table id="cars">
                <tr>
                    <th style="padding-right: 2vw;">
                        <div class="heading">
                            <form>
                                Car 1
                                <select class="dropdown" id="option1" name="option1" onchange="GetPreferences()">
                                <option value="None">Select a car</option>
                                    <option value="0">Bugatti Chiron</option>
                                    <option value="1">Audi R8</option>
                                    <option value="2">Audi RS 6</option>
                                    <option value="3">Ford GT40</option>
                                    <option value="4">BMW M8</option>
                                    <option value="5">Lamborghini Aventador</option>
                                    <option value="6">Porsche 911</option>
                                    <option value="7">Porsche Cayenne</option>
                                    <option value="8">Aston Martin DBS</option>
                                    <option value="9">Aston Martin Vantage</option>
                                    <option value="10">Lamborghini Urus</option>
                                    <option value="11">Lamborghini Huracan</option>
                                    <option value="12">Mercedes-Benz AMG GT</option>
                                    <option value="13">Rolls-Royce Wraith</option>
                                    <option value="14">Rolls-Royce Cullinan</option>
                                    <option value="15">Audi RS 7</option>
                                    <option value="16">Volvo XC90</option>
                                    <option value="17">Bentley Continental GT</option>
                                </select>
                            </form>

                        </div>
                        <p class="heading" id="car1">

                        </p>
                        <div class="heading" id="photo1">
                            <img alt="Loading Gif" src="./Components/Backgrounds/loading.gif">
                        </div>
                    </th>
                    <th style="padding-left: 2vw;">
                        <div class="heading">
                            <form>
                                Car 2
                                <select class="dropdown" id="option2" name="option2" onchange="GetPreferences()">
                                    <option value="None">Select a car</option>
                                    <option value="0">Bugatti Chiron</option>
                                    <option value="1">Audi R8</option>
                                    <option value="2">Audi RS 6</option>
                                    <option value="3">Ford GT40</option>
                                    <option value="4">BMW M8</option>
                                    <option value="5">Lamborghini Aventador</option>
                                    <option value="6">Porsche 911</option>
                                    <option value="7">Porsche Cayenne</option>
                                    <option value="8">Aston Martin DBS</option>
                                    <option value="9">Aston Martin Vantage</option>
                                    <option value="10">Lamborghini Urus</option>
                                    <option value="11">Lamborghini Huracan</option>
                                    <option value="12">Mercedes-Benz AMG GT</option>
                                    <option value="13">Rolls-Royce Wraith</option>
                                    <option value="14">Rolls-Royce Cullinan</option>
                                    <option value="15">Audi RS 7</option>
                                    <option value="16">Volvo XC90</option>
                                    <option value="17">Bentley Continental GT</option>
                                </select>
                            </form>

                        </div>
                        <p class="heading" id="car2">

                        </p>
                        <div class="heading" id="photo2">
                            <img alt="Loading Gif" src="./Components/Backgrounds/loading.gif">
                        </div>
                    </th>
                </tr>
            </table>
            <br>
            <br>
            <table id="InfoTable">
                <tr>
                    <td style="outline: none;">
                        <table id="SpecsTable">
                            <tr>
                                <th>Specifications</th>
                            </tr>
                            <tr>
                                <td class="outline">ID Trim</td>
                            </tr>
                            <tr>
                                <td class="outline">Generation</td>
                            </tr>
                            <tr>
                                <td class="outline">Year from</td>
                            </tr>
                            <tr>
                                <td class="outline">Year to</td>
                            </tr>
                            <tr>
                                <td class="outline">Series</td>
                            </tr>
                            <tr>
                                <td class="outline">Trim</td>
                            </tr>
                            <tr>
                                <td class="outline">Body Type</td>
                            </tr>
                            <tr>
                                <td class="outline">Number Of Seats</td>
                            </tr>
                            <tr>
                                <td class="outline">Length</td>
                            </tr>
                            <tr>
                                <td class="outline">Width</td>
                            </tr>
                            <tr>
                                <td class="outline">Height</td>
                            </tr>
                            <tr>
                                <td class="outline">Cylinders</td>
                            </tr>
                            <tr>
                                <td class="outline">Engine Type</td>
                            </tr>
                            <tr>
                                <td class="outline">Drivetrain</td>
                            </tr>
                            <tr>
                                <td class="outline">Transmission</td>
                            </tr>
                            <tr>
                                <td class="outline">Top Speed</td>
                            </tr>
                        </table>
                    </td>
                    <td id="Car1Info" style="outline: none;">

                    </td>
                    <td id="Car2Info" style="outline: none;">

                    </td>
                </tr>
            </table>
            <br>
        </div>
    </div>
    <?php include_once('footer.php'); ?>
    <script src="Components/js_files/Comparejs.js">
    </script>
</body>



</html>