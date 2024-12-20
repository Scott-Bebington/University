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

<body onload="sendData()">
    <!-- Author: Scott Bebington
    Student Number: u21546216 -->
    <?php include_once('header.php'); ?>
    <div class=" fullscreen">
        <div class="cars">
            <br>
            <table id="cars">
                <tr>
                    <th style="padding-right: 2vw;">
                        <div class="heading">
                            <form>
                                Car 1
                                <select class="dropdown" id="option1" name="option1" onchange="populateCars()">
                                    <option value="None">Select a car</option>
                                    <option value="0">Bugatti Chiron</option>
                                    <option value="1">Audi R8</option>
                                    <option value="2">Audi RS 6</option>
                                    <option value="3">Ford GT40</option>
                                    <option value="4">Ferrari 812 Superfast</option>
                                    <option value="5">BMW M8</option>
                                    <option value="6">Lamborghini Aventador</option>
                                    <option value="7">Alfa Romeo GTV</option>
                                    <option value="8">Porsche 911</option>
                                    <option value="9">Porsche Cayenne</option>
                                    <option value="10">Aston Martin DBS</option>
                                    <option value="11">Aston Martin Vantage</option>
                                    <option value="12">Lamborghini Urus</option>
                                    <option value="13">Lamborghini Huracan</option>
                                    <option value="14">Mercedes-Benz AMG GT</option>
                                    <option value="15">Rolls-Royce Wraith</option>
                                    <option value="16">Rolls-Royce Cullinan</option>
                                    <option value="17">Audi RS 7</option>
                                    <option value="18">Volvo XC90</option>
                                    <option value="19">Bentley Continental GT</option>
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
                                <select class="dropdown" id="option2" name="option2" onchange="populateCars()">
                                    <option value="None">Select a car</option>
                                    <option value="0">Bugatti Chiron</option>
                                    <option value="1">Audi R8</option>
                                    <option value="2">Audi RS 6</option>
                                    <option value="3">Ford GT40</option>
                                    <option value="4">Ferrari 812 Superfast</option>
                                    <option value="5">BMW M8</option>
                                    <option value="6">Lamborghini Aventador</option>
                                    <option value="7">Alfa Romeo GTV</option>
                                    <option value="8">Porsche 911</option>
                                    <option value="9">Porsche Cayenne</option>
                                    <option value="10">Aston Martin DBS</option>
                                    <option value="11">Aston Martin Vantage</option>
                                    <option value="12">Lamborghini Urus</option>
                                    <option value="13">Lamborghini Huracan</option>
                                    <option value="14">Mercedes-Benz AMG GT</option>
                                    <option value="15">Rolls-Royce Wraith</option>
                                    <option value="16">Rolls-Royce Cullinan</option>
                                    <option value="17">Audi RS 7</option>
                                    <option value="18">Volvo XC90</option>
                                    <option value="19">Bentley Continental GT</option>
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
            <table>
                <tr>
                    <td style="outline: none;">
                        <table>
                            <tr>
                                <th>Specifications</th>
                            </tr>
                            <tr>
                                <td>ID Trim</td>
                            </tr>
                            <tr>
                                <td>Generation</td>

                            </tr>
                            <tr>
                                <td>Year from</td>
                            </tr>
                            <tr>
                                <td>Year to</td>
                            </tr>
                            <tr>
                                <td>Series</td>
                            </tr>
                            <tr>
                                <td>Trim</td>
                            </tr>
                            <tr>
                                <td>Body Type</td>
                            </tr>
                            <tr>
                                <td>Number Of Seats</td>
                            </tr>
                            <tr>
                                <td>Length</td>
                            </tr>
                            <tr>
                                <td>Width</td>
                            </tr>
                            <tr>
                                <td>Height</td>
                            </tr>
                            <tr>
                                <td>Cylinders</td>
                            </tr>
                            <tr>
                                <td>Engine Type</td>
                            </tr>
                            <tr>
                                <td>Drivetrain</td>
                            </tr>
                            <tr>
                                <td>Transmission</td>
                            </tr>
                            <tr>
                                <td>Top Speed</td>
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