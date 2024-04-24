<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>COS 216 Practicals</title>
    <link rel="stylesheet" type="text/css" href="./Components/CSS/Preferences.css">
</head>

<!-- <body> -->

<body onload="GetPreferences()">
    <!-- Author: Scott Bebington
    Student Number: u21546216 -->
    <?php include_once('header.php'); ?>
    <div class="fullscreen">
        <div class="filters" id="Filters">
            <h1 id="PreferenceText">
                Preferences
            </h1>
            <div>
                <fieldset>
                    <legend>Colour Scheme:</legend>
                    <table>
                        <tr>
                            <td class="filterSpacing">
                                Light Mode
                            </td>
                            <td>
                                <form>
                                    <label class="circular-checkbox">
                                        <input type="checkbox" id="Light" onclick="selectLight()">
                                        <span class="checkmark"></span>
                                    </label>
                                </form>
                            </td>
                            <td style="width: 15%;">

                            </td>
                            <td class="filterSpacing">
                                Dark Mode
                            </td>
                            <td>
                                <form>
                                    <label class="circular-checkbox">
                                        <input type="checkbox" id="Dark" onclick="selectDark()">
                                        <span class="checkmark" ></span>
                                    </label>
                                </form>
                            </td>
                        </tr>
                    </table>
                </fieldset>
            </div>
            <table class="Table">
                <tr>
                    <td>
                        <fieldset class="FilterSize">
                            <legend>Number Of Seats:</legend>
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
                        </fieldset>
                    </td>
                    <td>
                        <fieldset class="FilterSize">
                            <legend>Transmission Type:</legend>
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
                        </fieldset>
                    </td>
                    <td>
                        <fieldset class="FilterSize">
                            <legend>Year:</legend>
                            <select class="dropdownSort" id="SortYear" name="SortYear">
                                <option value="None">---</option>
                                <option value="Ascending">New-Old</option>
                                <option value="Descending">Old-New</option>
                            </select>
                        </fieldset>
                    </td>
                </tr>
                <tr>
                    <td>
                        <fieldset class="FilterSize">
                            <legend>Fuel Type:</legend>
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
                        </fieldset>
                    </td>
                    <td>
                        <fieldset class="FilterSize">
                            <legend>Body Type:</legend>
                            <select class="dropdown" id="bodyType" name="bodyType">
                                <option value="None">---</option>
                                <option value="Coupe">Coupe</option>
                                <option value="Roadster">Roadster</option>
                                <option value="Wagon">Wagon</option>
                                <option value="Cabriolet">Cabriolet</option>
                                <option value="Crossover">Crossover</option>
                                <option value="Liftback">Liftback</option>
                            </select>
                        </fieldset>
                    </td>
                    <td>
                        <fieldset class="FilterSize">
                            <legend>Name:</legend>
                            <select class="dropdownSort" id="SortName" name="SortName">
                                <option value="None">---</option>
                                <option value="Ascending">A-Z</option>
                                <option value="Descending">Z-A</option>
                            </select>
                        </fieldset>
                    </td>
                </tr>
            </table>
            <div>
                <button class="Button" onclick="SavePreferences()">
                    Save
                </button>
                <button class="Button" onclick="ClearFilters()">
                    Clear Filters
                </button>
                <button class="Button" onclick="IndexPage()">
                    Back
                </button>
            </div>
        </div>
    </div>
    <script src="./Components/js_files/Preferencesjs.js"></script>
</body>

</html>