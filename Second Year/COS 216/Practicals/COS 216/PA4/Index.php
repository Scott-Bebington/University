<?php ?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>COS 216 Practicals</title>
    <link rel="stylesheet" type="text/css" href="./Components/CSS/Indexcss.css">
</head>

<!-- <body> -->

<body onload="GetPreferences()">
    <!-- Author: Scott Bebington
    Student Number: u21546216 -->
    <?php include_once('header.php'); ?>
    <div class="fullscreen">
        <div class="filters" id="Filters">
            <div class="FilterSize">
                <b>Number of seats</b>
                <table>
                    <tr>
                        <td class="filterSpacing">
                            Two (2)
                        </td>
                        <td>
                            <form>
                                <label class="circular-checkbox">
                                    <input type="checkbox" id="Two" onclick="select2()">
                                    <span class="checkmark"></span>
                                </label>
                            </form>
                        </td>
                    </tr>
                    <tr>
                        <td class="filterSpacing">
                            Four (4)
                        </td>
                        <td>
                            <form>
                                <label class="circular-checkbox">
                                    <input type="checkbox" id="Four" onclick="select4()">
                                    <span class="checkmark"></span>
                                </label>
                            </form>
                        </td>
                    </tr>
                </table>
            </div>

            <div class="FilterSize">
                <b>Transmission Type</b>
                <table>
                    <tr>
                        <td class="filterSpacing">
                            Manual
                        </td>
                        <td>
                            <label class="circular-checkbox">
                                <input type="checkbox" id="Manual" name="agree" value="Manual" onclick="selectOneManual()">
                                <span class="checkmark"></span>
                            </label>
                        </td>
                    </tr>
                    <tr>
                        <td class="filterSpacing">
                            Automatic
                        </td>
                        <td>
                            <label class="circular-checkbox">
                                <input type="checkbox" id="Auto" name="agree" value="Automatic" onclick="selectOneAuto()">
                                <span class="checkmark"></span>
                            </label>
                        </td>
                    </tr>
                </table>
            </div>

            <div class="FilterSize">
                <b>Fuel Type</b>
                <table>
                    <tr>
                        <td class="filterSpacing">
                            Petrol
                        </td>
                        <td>
                            <label class="circular-checkbox">
                                <input type="checkbox" id="Petrol" name="agree" value="Petrol" onclick="selectOnePetrol()">
                                <span class="checkmark"></span>
                            </label>
                        </td>
                    </tr>
                    <tr>
                        <td class="filterSpacing">
                            Diesel
                        </td>
                        <td>
                            <label class="circular-checkbox">
                                <input type="checkbox" id="Diesel" name="agree" value="Diesel" onclick="selectOneDiesel()">
                                <span class="checkmark"></span>
                            </label>
                        </td>
                    </tr>
                </table>
            </div>
            <div class="FilterSize">
                <b>Body Type</b>
                <br>
                <form style="height: 100%">
                    <select class="dropdown" id="bodyType" name="bodyType">
                        <option value="None">---</option>
                        <option value="Coupe">Coupe</option>
                        <option value="Roadster">Roadster</option>
                        <option value="Wagon">Wagon</option>
                        <option value="Cabriolet">Cabriolet</option>
                        <option value="Crossover">Crossover</option>
                        <option value="Liftback">Liftback</option>
                    </select>
                </form>
            </div>
            <div>
                <button id="ApplyButton" class="Button" onclick="populateCars()">
                    Apply Filters
                </button>
                <button class="Button" onclick="clearfilters()">
                    Clear Filters
                </button>
            </div>
        </div>
        <div class="noFlex">
            <div class="sort" id="sort">
                <div class="sortspace">
                    <div class="searchcontainer">
                        <div>
                            <input class="searchbar" type="text" id="search" placeholder="Search for a car...">
                        </div>
                        <div class="searchbutton" onclick="populateCars()"></div>

                    </div>
                    <div class="sortContainer">
                        <fieldset style="height: 50%; width: 30%">
                            <legend>Name:</legend>
                            <select class="dropdownSort" id="SortName" name="SortName">
                                <option value="None">---</option>
                                <option value="Ascending">A-Z</option>
                                <option value="Descending">Z-A</option>
                            </select>
                        </fieldset>
                        <fieldset style="height: 50%; width: 30%">
                            <legend>Year:</legend>
                            <select class="dropdownSort" id="SortYear" name="SortYear">
                                <option value="None">---</option>
                                <option value="Ascending">New-Old</option>
                                <option value="Descending">Old-New</option>
                            </select>
                        </fieldset>
                    </div>

                </div>
            </div>

            <div class="Cars" id="cardContainer">
                <img alt="Loading Gif" src="./Components/Backgrounds/loading.gif">
            </div>
            <div id=" NotFound"></div>
        </div>
    </div>
    <script src="Components/js_files/Indexjs.js"></script>
</body>

</html>