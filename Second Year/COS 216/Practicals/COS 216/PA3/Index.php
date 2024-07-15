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

<body onload="populateCars()">
    <!-- Author: Scott Bebington
    Student Number: u21546216 -->
    <?php include_once('header.php'); ?>
    <div class="fullscreen">
        <div class="filters">
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
                                <input type="checkbox" id="Manual" name="agree" value="Manual"
                                    onclick="selectOneManual()">
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
                                <input type="checkbox" id="Auto" name="agree" value="Automatic"
                                    onclick="selectOneAuto()">
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
                                <input type="checkbox" id="Petrol" name="agree" value="Petrol"
                                    onclick="selectOnePetrol()">
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
                                <input type="checkbox" id="Diesel" name="agree" value="Diesel"
                                    onclick="selectOneDiesel()">
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
                <button class="Button" onclick="applyfilters()">
                    Apply Filters
                </button>
                <button class="Button" onclick="clearfilters()">
                    Clear FIlters
                </button>
            </div>
        </div>
        <div class="noFlex">
            <div class="sort">
                <div class="sortspace">
                    <div class="searchcontainer">
                        <div>
                            <input class="searchbar" type="text" id="search" placeholder="Search for a car...">
                        </div>
                        <div class="searchbutton" onclick="search()"></div>

                    </div>
                    <div class="sortContainer">
                        <button class="sortbutton" onclick="sortarrayname()">
                            Name
                            <img alt="Sort Image" class="SortImage" src="./Components/Sort_Images/SortImage.jpg">
                        </button>
                        <button class="sortbutton" onclick="sortarrayyear()">
                            Year
                            <img alt="Sort Image" class="SortImage" src="./Components/Sort_Images/SortImage.jpg">
                        </button>
                    </div>

                </div>
            </div>

            <div class="Cars" id="cardContainer">
                <img alt="Loading Gif" src="./Components/Backgrounds/loading.gif">
            </div>
            <div id="NotFound"></div>
        </div>
    </div>
    <?php include_once('footer.php'); ?>
    <script src="Components/js_files/Indexjs.js"></script>
</body>

</html>