<?php ?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>COS 216 Practicals</title>
    <link rel="stylesheet" type="text/css" href="./Components/CSS/FindCarcss.css">

</head>

<body onload="GetPreferences()">
    <!-- Author: Scott Bebington
    Student Number: u21546216 -->
    <?php include_once('header.php'); ?>
    <div class="fullscreen">
        <div class="filters" id="Filters">
            <div class="heading" id="Heading1">
                <h1>
                    Search By...
                </h1>
            </div>
            <div class="nonoptional">
                <div class="splittop">
                    <div class="FilterSize">
                        <b>Number of seats</b>
                        <table>
                            <tr class="rows">
                                <td class="filterSpacing">
                                    Two (2)
                                </td>
                                <td>
                                    <form>
                                        <label class="circular-checkbox">
                                            <input type="checkbox" id="Two" onclick="select2()" onchange="applycheck()">
                                            <span class="checkmark"></span>
                                        </label>
                                    </form>
                                </td>
                            </tr>
                            <tr class="rows">
                                <td class="filterSpacing">
                                    Four (4)
                                </td>
                                <td>
                                    <form>
                                        <label class="circular-checkbox">
                                            <input type="checkbox" id="Four" onclick="select4()"
                                                onchange="applycheck()">
                                            <span class="checkmark"></span>
                                        </label>
                                    </form>
                                </td>
                            </tr>
                        </table>
                    </div>
                    <div class="FilterSize">
                        <b>
                            Fuel Type
                        </b>
                        <table>
                            <tr class="rows">
                                <td class="filterSpacing">
                                    Petrol
                                </td>
                                <td>
                                    <label class="circular-checkbox">
                                        <input type="checkbox" id="Petrol" name="agree" value="Petrol"
                                            onclick="selectOnePetrol()" onchange="applycheck()">
                                        <span class="checkmark"></span>
                                    </label>
                                </td>
                            </tr>
                            <tr class="rows">
                                <td class="filterSpacing">
                                    Diesel
                                </td>
                                <td>
                                    <label class="circular-checkbox">
                                        <input type="checkbox" id="Diesel" name="agree" value="Diesel"
                                            onclick="selectOneDiesel()" onchange="applycheck()">
                                        <span class="checkmark"></span>
                                    </label>
                                </td>
                            </tr>

                        </table>
                    </div>
                </div>
                <div class="splittop">
                    <div class="FilterSize">
                        <b>
                            Transmission Type
                        </b>
                        <table>
                            <tr class="rows">
                                <td class="filterSpacing">
                                    Manual
                                </td>
                                <td>
                                    <label class="circular-checkbox">
                                        <input type="checkbox" id="Manual" name="agree" value="Manual"
                                            onclick="selectOneManual()" onchange="applycheck()">
                                        <span class="checkmark"></span>
                                    </label>
                                </td>
                            </tr>
                            <tr class="rows">
                                <td class="filterSpacing">
                                    Automatic
                                </td>
                                <td>
                                    <label class="circular-checkbox">
                                        <input type="checkbox" id="Auto" name="agree" value="Automatic"
                                            onclick="selectOneAuto()" onchange="applycheck()">
                                        <span class="checkmark"></span>
                                    </label>
                                </td>
                            </tr>
                        </table>
                    </div>
                    <div class="FilterSize">
                        <b>
                            Drivetrain
                        </b>
                        <table>
                            <tr class="rows">
                                <td class="filterSpacing">
                                    Rear Wheel
                                </td>
                                <td>
                                    <label class="circular-checkbox">
                                        <input type="checkbox" id="Rear" onclick="selectOneRear()"
                                            onchange="applycheck()">
                                        <span class="checkmark"></span>
                                    </label>
                                </td>
                            </tr>
                            <tr class="rows">
                                <td class="filterSpacing">
                                    All Wheel
                                </td>
                                <td>
                                    <label class="circular-checkbox">
                                        <input type="checkbox" id="All" onclick="selectOneAll()"
                                            onchange="applycheck()">
                                        <span class="checkmark"></span>
                                    </label>
                                </td>
                            </tr>
                        </table>
                    </div>
                </div>

            </div>
            <div class="heading" style="border-top: solid black;" id="Heading2">
                <h1>
                    Optional
                </h1>
            </div>
            <div class="optional">
                <div class="splitbottom">
                    <div class="FilterSizebottom">
                        <b>
                            Cylinders
                        </b>
                        <select class="dropdown" id="cylinders" name="colors">
                            <option value="None">---</option>
                            <option value="3">3 Cylinders</option>
                            <option value="4">4 Cylinders</option>
                            <option value="5">5 Cylinders</option>
                            <option value="6">6 Cylinders</option>
                            <option value="8">8 Cylinders</option>
                            <option value="10">10 Cylinders</option>
                            <option value="12">12 Cylinders</option>
                            <option value="16">16 Cylinders</option>
                        </select>
                    </div>
                </div>
                <div class="splitbottom">

                    <div class="FilterSizebottom">
                        <b>
                            Body Type
                        </b>
                        <select class="dropdown" id="bodytype" name="body type">
                            <option value="None">---</option>
                            <option value="Coupe">Coupe</option>
                            <option value="Roadster">Roadster</option>
                            <option value="Wagon">Wagon</option>
                            <option value="Cabriolet">Cabriolet</option>
                            <option value="Crossover">Crossover</option>
                            <option value="Liftback">Liftback</option>
                        </select>
                    </div>
                </div>
            </div>
            <div class="heading">
                <button class="Button" id="applybutton" onclick="populateCars()">
                    Apply Filters
                </button>
                <button class="Button" onclick="clearfilters()">
                    Clear FIlters
                </button>
            </div>
        </div>
        <div class="noFlex" id="cardContainer">
            <img alt="Loading Gif" src="./Components/Backgrounds/loading.gif">
        </div>

    </div>
    <?php include_once('footer.php'); ?>
    <script src="Components/js_files/FindCarjs.js"></script>
</body>



</html>