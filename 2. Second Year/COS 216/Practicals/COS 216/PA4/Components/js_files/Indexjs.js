function ApiRequest(Request, num) {
    const xhttp = new XMLHttpRequest();
    xhttp.onload = function () {
        let random = JSON.parse(this.responseText)
        console.log(random);

        // if(random.loggedin == "User Not Logged In")
        // {
        //     alert("Please note that you wont be able to filter cars unless you are logged in!");
        // }

        if (random.status == "error") {
            const card = generateNoneFound()

            cardContainer.appendChild(card);
        }
        else {
            let count = 0;
            for (let index = 0; index < num; index++) {
                if (random.data[index] && typeof random.data[index].make !== 'undefined') {
                    const card = generateCarCard
                        (
                            random.data[index].make, random.data[index].model,
                            random.data[index].year_to, random.data[index].body_type,
                            random.data[index].engine_type, random.data[index].transmission,
                            random.data[index].number_of_seats, random.data[index].image, count
                        );

                    cardContainer.appendChild(card);

                    count += 2;
                }
            }
        }
    }
    xhttp.open("POST", "https://wheatley.cs.up.ac.za/u21546216/api.php", true);
    xhttp.send(JSON.stringify(Request));
    // console.log(JSON.stringify(Request));
}

function generateCarCard(make, model, year, bodytype, fuel, transmission, seats, image, index) {

    image = image.replace(' ', "%20");
    let card = document.createElement("div");
    card.classList.add("Cars");


    GetPreferences2(function (colour, loggedin) {
        console.log(loggedin);
        if (loggedin == "Testing") {
            card.innerHTML = `
            <div class="CarOutline" id="CarOutline">
                <div class="Photo" style="background-image: URL(${image});"></div>
                <div class="Info">
                    <h1>
                        ${year} ${make} ${model}
                    </h1>
                    <h1>

                    </h1>
                    <h3>
                        ${bodytype} | ${transmission} | ${fuel} | Seats (${seats})
                    </h3>

                    <div class="rating">
                        <fieldset>
                            <legend>Rating:</legend>
                            <label class="circular-checkbox">
                                1:
                                <input type="checkbox" id="${index}" name="Stars" value="${model}" onclick="Ratings('${make}', '${model}', 0)">
                                <span class="checkmark2"></span>
                            </label>
                            <label class="circular-checkbox">
                                &nbsp;&nbsp;&nbsp;2: 
                                <input type="checkbox" id="${index + 1}" name="Stars" value="${model}" onclick="Ratings('${make}', '${model}', 1)">
                                <span class="checkmark2"></span>
                            </label>
                            <label class="circular-checkbox">
                                &nbsp;&nbsp;&nbsp;3:
                                <input type="checkbox" id="${index + 2}" name="Stars" value="${model}" onclick="Ratings('${make}', '${model}', 2)">
                                <span class="checkmark2"></span>
                            </label>
                            <label class="circular-checkbox">
                                &nbsp;&nbsp;&nbsp;4:
                                <input type="checkbox" id="${index + 3}" name="Stars" value="${model}" onclick="Ratings('${make}', '${model}', 3)">
                                <span class="checkmark2"></span>
                            </label>
                            <label class="circular-checkbox">
                                &nbsp;&nbsp;&nbsp;5:
                                <input type="checkbox" id="${index + 4}" name="Stars" value="${model}" onclick="Ratings('${make}', '${model}', 4)">
                                <span class="checkmark2"></span>
                            </label>
                        </fieldset>
                    </div>
                </div>
            </div>
                
        `;

        }
        else {
            card.innerHTML = `
            <div class="CarOutline" id="CarOutline">
                <div class="Photo" style="background-image: URL(${image});"></div>
                <div class="Info">
                    <h1>
                        ${year} ${make} ${model}
                    </h1>
                    <h1>

                    </h1>
                    <h3>
                        ${bodytype} | ${transmission} | ${fuel} | Seats (${seats})
                    </h3>
                </div>
            </div>
                
        `;
        }
        // console.log(colour);
        if (colour === "Dark") {

            const carOutline = card.querySelector('.CarOutline');
            carOutline.style.backgroundColor = '#34343c';
            carOutline.style.color = "#ccc";
            carOutline.style.outline = "1px solid #ccc";
        }
    });

    card.innerHTML += ``
    return card;
}


function generateNoneFound() {
    const card = document.createElement("div");
    card.classList.add("Cars");
    // card.style.backgroundImage = `url(${Car.Image})`;
    card.innerHTML = `

    <div class="CarOutline">
    <div class="Info">
        <h1>
        We're Sorry
        </h1>
        <h3>
        There are currently no results found for the filters you entered, please change them and try again
        </h3>
    </div>
    </div>
`;
    GetPreferences2(function (colour, none) {
        // console.log(colour);
        if (colour === "Dark") {

            const carOutline = card.querySelector('.CarOutline');
            carOutline.style.backgroundColor = '#34343c';
            carOutline.style.color = "#ccc";
            carOutline.style.outline = "1px solid #ccc";
        }
    });
    return card;
}

var seats2 = document.getElementById("Two");
var seats4 = document.getElementById("Four");
var manual = document.getElementById("Manual");
var auto = document.getElementById("Auto");
var petrol = document.getElementById("Petrol");
var diesel = document.getElementById("Diesel");
var body = document.getElementById("bodyType");
var searchbar = document.getElementById("search");
var SortName = document.getElementById("SortName");
var SortYear = document.getElementById("SortYear");


function populateCars() {
    removeCars();
    let num = 10;
    let x = {
        "type": "GetAllCars",
        "limit": num,
        // "apikey": "a9198b68355f78830054c31a39916b7f",
        "fuzzy": true,
        "return": ["make", "model", "year_to", "body_type", "engine_type", "transmission", "number_of_seats"]
    };

    let search = {};

    if (searchbar.value != '') {
        search.make = searchbar.value;
    }
    if (seats2.checked) {
        // console.log("2 Seats Checked");
        search.number_of_seats = 2;
    }
    if (seats4.checked) {
        // console.log("4 Seats Checked");
        search.number_of_seats = 4;
    }
    if (auto.checked) {
        search.transmission = "automatic";
    }
    if (manual.checked) {
        search.transmission = "manual";
    }
    if (diesel.checked) {
        search.engine_type = "diesel";
    }
    if (petrol.checked) {
        search.engine_type = "gasoline";
    }
    if (body.value !== "None") {
        search.body_type = body.value;
    }
    if (SortYear.value !== "None") {
        let sorting = "year_to ";
        if (SortYear.value == "Ascending") {
            sorting += "DESC";
        }
        else {
            sorting += "ASC";
        }

        if (SortName !== "None") {
            sorting += ", model ";
            if (SortName.value == "Ascending") {
                sorting += "ASC";
            }
            else {
                sorting += "DESC";
            }
        }
        x.sort = sorting;
    }
    if (SortName.value !== "None") {
        let sorting = "";
        if (SortName.value == "Ascending") {
            sorting += "make ASC, model ASC";
        }
        else {
            sorting += "make DESC, model DESC";
        }
        x.sort = sorting;
    }


    if (Object.keys(search).length !== 0) {
        x.search = search;
    }
    ApiRequest(x, num);
}

function GetPreferences() {
    // alert("Please note that you wont be able to filter cars unless you are logged in!");

    sql = "SELECT * FROM Preferences WHERE UserID = ";

    const xhttp = new XMLHttpRequest();
    xhttp.onload = function () {
        // console.log(this.responseText);



        if (xhttp.responseText == "None") {
            // console.log("User Has No preferences yet");
            populateCars();
        }
        else {
            var decodedData = JSON.parse(this.responseText);
            if (decodedData.SortName) {
                SortName.value = decodedData.SortName;
            }

            if (decodedData.SortYear) {
                SortYear.value = decodedData.SortYear;
            }

            switch (decodedData.Seats) {
                case "2":
                    seats2.checked = true;
                    break;
                case "4":
                    seats4.checked = true;
                    break;
            }

            switch (decodedData.Transmission) {
                case "Manual":
                    manual.checked = true;
                    break;
                case "Automatic":
                    auto.checked = true;
                    break;
            }

            switch (decodedData.Fuel) {
                case "Diesel":
                    diesel.checked = true;
                    break;
                case "Gasoline":
                    petrol.checked = true;
                    break;
            }

            if (decodedData.Body) {
                body.value = decodedData.Body;
            }

            if (decodedData.SortName) {
                SortName.value = decodedData.SortName;
            }

            if (decodedData.SortYear) {
                SortYear.value = decodedData.SortYear;
            }

            // console.log("Populating Cars With Given Preferences");


            if (decodedData.ColourScheme == "Dark") {
                // console.log("Set Colour Scheme to dark mode");
                SetColourScheme();
                populateCars();
            }
            else {
                populateCars();
            }

            // RetrieveRatings();
        }
    }
    xhttp.open("POST", "https://wheatley.cs.up.ac.za/u21546216/COS%20216/PA4/validate-preferences.php", true);
    xhttp.send(sql);

}

function GetPreferences2(callback) {
    sql = "SELECT * FROM Preferences WHERE UserID = ";

    const xhttp = new XMLHttpRequest();
    xhttp.onload = function () {
        // console.log(this.responseText);

        if (xhttp.responseText == "None") {
            console.log("User Has No preferences yet");
            callback("Light", "None");
        } else {
            var decodedData = JSON.parse(this.responseText);
            callback(decodedData.ColourScheme, "Testing");
        }
    }
    xhttp.open("POST", "https://wheatley.cs.up.ac.za/u21546216/COS%20216/PA4/validate-preferences.php", true);
    xhttp.send(sql);
}



function removeCars() {
    cardContainer.innerHTML = '';
}

function clearfilters() {
    removeCars();
    seats2.checked = false;
    seats4.checked = false;
    manual.checked = false;
    auto.checked = false;
    petrol.checked = false;
    diesel.checked = false;
    body.value = "None";
    SortName.value = "None";
    SortYear.value = "None";
    searchbar.value = '';
    populateCars();
}

function select2() {
    if (seats4.checked) {
        seats4.checked = false;
    }
}

function select4() {
    if (seats2.checked) {
        seats2.checked = false;
    }
}

function selectOneManual() {
    if (auto.checked) {
        auto.checked = false;
    }
}

function selectOneAuto() {
    if (manual.checked) {
        manual.checked = false;
    }
}

function selectOnePetrol() {
    if (diesel.checked) {
        diesel.checked = false;
    }
}

function selectOneDiesel() {
    if (petrol.checked) {
        petrol.checked = false;
    }
}

var Logo = document.getElementById("Logo");
var FiltersContainer = document.getElementById("Filters");
var Nav = document.getElementById("Nav");
var InNav = document.getElementById("InNav");
var NavText = document.getElementsByTagName("a");
var Checkboxes = document.getElementsByClassName("checkmark");
var SortBar = document.getElementById("sort");
var Legends = document.getElementsByTagName("legend");
var Searchbar = document.getElementById("search");


function SetColourScheme() {
    Logo.src = "./Components/Logos/Inverted Logo.jpg";

    Nav.style.backgroundColor = '#34343c';
    Nav.style.outline = "1px solid #ccc";

    InNav.style.backgroundColor = '#34343c';
    InNav.style.color = '#ccc';

    for (let index = 0; index < NavText.length; index++) {
        NavText[index].style.color = '#ccc';
    }

    FiltersContainer.style.backgroundColor = '#34343c';
    FiltersContainer.style.outline = "1px solid #ccc";
    FiltersContainer.style.color = '#ccc';
    for (let index = 0; index < Checkboxes.length; index++) {
        Checkboxes[index].style.border = '2px solid purple';
    }

    SortBar.style.backgroundColor = "#34343c";
    SortBar.style.outline = "1px solid #ccc";

    for (let index = 0; index < Legends.length; index++) {
        Legends[index].style.color = '#ccc';
    }

    searchbar.style.borderColor = "#ccc";
}


var Stars = document.getElementsByName("Stars");

function Ratings(make, model, checkindex) 
{
    console.clear();
    // let Car = make + " " + model;
    // console.log("Checking Ratings for: " + Car);
    for (let index = 0; index < Stars.length; index++) {
        if (Stars[index].value == model) {
            let rangeStart = index;
            let rangeEnd = index + 4;
            checkindex = checkindex + index;
            // console.log("Range Start: " + rangeStart);
            // console.log("Range End: " + rangeEnd);
            for (let index2 = rangeStart; index2 <= rangeEnd; index2++) {
                if (index2 <= checkindex) {
                    Stars[index2].checked = true;
                }
                else {
                    Stars[index2].checked = false;
                }

            }


            checkindex = checkindex - index + 1;
            GetCarID(make, model, checkindex);
            break;
        }

    }
}

function GetCarID(make, model, rating) {
    console.log(make + " " + model)
    console.log(rating + " Stars");


    sql = {
        "type": "GetAllCars",
        "apikey": "a9198b68355f78830054c31a39916b7f",
        "fuzzy": true,
        "return": "*",
        "search": {
            "make": make,
            "model": model
        }
    };

    const xhttp = new XMLHttpRequest();
    xhttp.onload = function () {
        let ReturnData = JSON.parse(this.responseText);

        CarID = ReturnData.data[0].id_trim
        console.log("Car ID: " + CarID);

        GetUserID(CarID, make, model, rating);
    }
    xhttp.open("POST", "https://wheatley.cs.up.ac.za/u21546216/api.php", true);
    xhttp.send(JSON.stringify(sql));
    // console.log(JSON.stringify(Request));
}

function GetUserID(CarID, make, model, rating) {
    sql = "USERID";

    const xhttp = new XMLHttpRequest();
    xhttp.onload = function () {
        let UserID = xhttp.responseText
        if (UserID == "None") {
            console.log("User Not Logged In");
        }
        else {
            console.log("User ID: " + UserID);
            GetRating(CarID, make, model, UserID, rating);
        }
    }
    xhttp.open("POST", "https://wheatley.cs.up.ac.za/u21546216/COS%20216/PA4/validate-ratings.php", true);
    xhttp.send(sql);
}

function GetRating(CarID, make, model, UserID, rating) {
    sql = "SELECT * FROM Ratings WHERE UserID = " + UserID + " AND "
        + "Make = '" + make + "' AND Model = '" + model + "';"

    const xhttp = new XMLHttpRequest();
    xhttp.onload = function () {
        let Result = xhttp.responseText
        if (Result == "Results Found, Updating Rating") {
            console.log("Updating...");
            let Query = "UPDATE Ratings "
                + "SET Rating = " + rating + " "
                + "WHERE "
                + "CarID = " + CarID + " AND "
                + "Make = '" + make + "' AND "
                + "Model = '" + model + "' AND "
                + "UserID = " + UserID + ";"
            // console.log(Query);
            SetRating(Query);
        }
        else {
            console.log("Inserting...");
            let Query = "INSERT INTO `Ratings`(`CarID`, `Make`, `Model`, `UserID`, `Rating`) "
                + "VALUES ("
                + CarID + ", '"
                + make + "', '"
                + model + "', "
                + UserID + ", "
                + rating
                + ");"
            // console.log(Query);
            SetRating(Query);
        }
    }
    xhttp.open("POST", "https://wheatley.cs.up.ac.za/u21546216/COS%20216/PA4/validate-ratings.php", true);
    xhttp.send(sql);
}

function SetRating(SQLQuery) {
    const xhttp = new XMLHttpRequest();
    xhttp.onload = function () {
        let Result = xhttp.responseText
        console.log(Result);
    }
    xhttp.open("POST", "https://wheatley.cs.up.ac.za/u21546216/COS%20216/PA4/validate-ratings.php", true);
    xhttp.send(SQLQuery);
}





