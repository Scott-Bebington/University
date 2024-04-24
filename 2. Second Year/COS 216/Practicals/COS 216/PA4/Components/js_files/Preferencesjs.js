function IndexPage() {
    window.location.href = "./Index.php";
}


var NumberOfSeats2 = document.getElementById("Two");
var NumberOfSeats4 = document.getElementById("Four");
var TransmissionTypeManual = document.getElementById("Manual");
var TransmissionTypeAuto = document.getElementById("Auto");
var Year = document.getElementById("SortYear");
var Name = document.getElementById("SortName");
var FuelTypePetrol = document.getElementById("Petrol");
var FuelTypeDiesel = document.getElementById("Diesel");
var BodyType = document.getElementById("bodyType");
var ColourSchemeLight = document.getElementById("Light");
var ColourSchemeDark = document.getElementById("Dark");

function GetPreferences() {
    sql = "SELECT * FROM Preferences WHERE UserID = ";

    const xhttp = new XMLHttpRequest();
    xhttp.onload = function () {
        console.log(this.responseText);



        if (xhttp.responseText == "None") {
            console.log("User Has No preferences yet");
        }
        else {
            var decodedData = JSON.parse(this.responseText);
            console.log("Retrieving User preferences");
            console.log("User ID: " + decodedData.UserID);
            console.log("Seats: " + decodedData.Seats);
            console.log("Transmission: " + decodedData.Transmission);
            console.log("Fuel: " + decodedData.Fuel);
            console.log("Body Type: " + decodedData.Body);
            console.log("Sort Name: " + decodedData.SortName);
            console.log("Sort Year: " + decodedData.SortYear);
            console.log("Colour Scheme: " + decodedData.ColourScheme);

            if (decodedData.ColourScheme == "Light") {
                ColourSchemeLight.checked = true;
            }
            else if (decodedData.ColourScheme == "Dark") {
                ColourSchemeDark.checked = true;
                ColourScheme()
            }

            if (decodedData.Seats == 2) {
                NumberOfSeats2.checked = true;
            }
            else if (decodedData.Seats == 4) {
                NumberOfSeats4.checked = true;
            }

            if (decodedData.Transmission == "Manual") {
                TransmissionTypeManual.checked = true;
            }
            else if (decodedData.Transmission == "Automatic") {
                TransmissionTypeAuto.checked = true;
            }

            if (decodedData.Fuel == "Diesel") {
                FuelTypeDiesel.checked = true;
            }
            else if (decodedData.Fuel == "Gasoline") {
                FuelTypePetrol.checked = true;
            }

            if (decodedData.Body != null) {
                console.log("Test 1");
                BodyType.value = decodedData.Body;
            }

            if (decodedData.SortName != null) {
                console.log("Test 2");
                Name.value = decodedData.SortName;
            }

            if (decodedData.SortYear != null) {
                console.log("Test 3");
                Year.value = decodedData.SortYear;
            }

        }
    }
    xhttp.open("POST", "https://wheatley.cs.up.ac.za/u21546216/COS%20216/PA4/validate-preferences.php", true);
    xhttp.send(sql);
}

function SavePreferences() {
    GetUserID();
}

function GetUserID() {
    sql = "SELECT * FROM Preferences WHERE UserID = ";

    const xhttp = new XMLHttpRequest();
    xhttp.open("POST", "https://wheatley.cs.up.ac.za/u21546216/COS%20216/PA4/validate-preferences.php", true);
    xhttp.setRequestHeader('Content-type', 'text/plain');
    xhttp.onreadystatechange = function () {
        if (xhttp.readyState === 4 && xhttp.status === 200) {
            console.log(xhttp.responseText);

            if (xhttp.responseText == "None") {
                console.log("Inserting User Preferences");
                InsertNewPreference();
            }
            else {
                console.log("Updating User preferences");
                DeletePreferences();

            }
        }
    };
    xhttp.send(sql);

}

function DeletePreferences() {
    let sql = 'DELETE FROM Preferences WHERE UserID = ';

    const xhttp = new XMLHttpRequest();
    xhttp.open("POST", "https://wheatley.cs.up.ac.za/u21546216/COS%20216/PA4/validate-preferences.php", true);
    xhttp.setRequestHeader('Content-type', 'text/plain');
    xhttp.onreadystatechange = function () {
        if (xhttp.readyState === 4 && xhttp.status === 200) {
            console.log(xhttp.responseText);
            // Handle the response here
            IndexPage();
        }
    };
    xhttp.send(sql);
    InsertNewPreference();
}

function InsertNewPreference() {
    const values = {
        Seats: NumberOfSeats2.checked ? 2 : NumberOfSeats4.checked ? 4 : null,
        Transmission: TransmissionTypeManual.checked ? 'Manual' : TransmissionTypeAuto.checked ? 'Automatic' : null,
        Fuel: FuelTypeDiesel.checked ? 'Diesel' : FuelTypePetrol.checked ? 'Gasoline' : null,
        Body: BodyType.value !== 'None' ? BodyType.value : null,
        SortName: Name.value !== 'None' ? Name.value : null,
        SortYear: Year.value !== 'None' ? Year.value : null,
        ColourScheme: ColourSchemeLight.checked ? "Light" : ColourSchemeDark.checked ? "Dark" : null,
    };

    const placeholders = Object.keys(values)
        .map((key) => {
            return values[key] === null ? 'null' : `"${values[key]}"`;
        })
        .join(', ');

    const sql = `INSERT INTO Preferences (UserID, Seats, Transmission, Fuel, Body, SortName, SortYear, ColourScheme) VALUES (1, ${placeholders});`;

    // console.log(sql);
    const xhttp = new XMLHttpRequest();
    xhttp.open("POST", "https://wheatley.cs.up.ac.za/u21546216/COS%20216/PA4/validate-preferences.php", true);
    xhttp.setRequestHeader('Content-type', 'text/plain');
    xhttp.onreadystatechange = function () {
        if (xhttp.readyState === 4 && xhttp.status === 200) {
            console.log(xhttp.responseText);
            // Handle the response here
            IndexPage();
        }
    };
    xhttp.send(sql);
}

function ClearFilters() {
    ColourSchemeDark.checked = false;
    ColourSchemeLight.checked = true;
    NumberOfSeats2.checked = false;
    NumberOfSeats4.checked = false;
    TransmissionTypeManual.checked = false;
    TransmissionTypeAuto.checked = false;
    FuelTypeDiesel.checked = false;
    FuelTypePetrol.checked = false;
    BodyType.value = "None";
    Name.value = "None";
    Year.value = "None";
}





function select2() {
    if (NumberOfSeats4.checked) {
        NumberOfSeats4.checked = false;
    }
}

function select4() {
    if (NumberOfSeats2.checked) {
        NumberOfSeats2.checked = false;
    }
}

function selectOneManual() {
    if (TransmissionTypeAuto.checked) {
        TransmissionTypeAuto.checked = false;
    }
}

function selectOneAuto() {
    if (TransmissionTypeManual.checked) {
        TransmissionTypeManual.checked = false;
    }
}

function selectOnePetrol() {
    if (FuelTypeDiesel.checked) {
        FuelTypeDiesel.checked = false;
    }
}

function selectOneDiesel() {
    if (FuelTypePetrol.checked) {
        FuelTypePetrol.checked = false;
    }
}

function selectLight() {
    if (ColourSchemeDark.checked) {
        ColourSchemeDark.checked = false;
    }
}

function selectDark() {
    if (ColourSchemeLight.checked) {
        ColourSchemeLight.checked = false;
    }
}

var Logo = document.getElementById("Logo");
var FiltersContainer = document.getElementById("Filters");
var Nav = document.getElementById("Nav");
var InNav = document.getElementById("InNav");
var NavText = document.getElementsByTagName("a");
var Checkboxes = document.getElementsByClassName("checkmark");
var CheckboxesFilledIn = document.getElementsByClassName("circular-checkbox")
var Legends = document.getElementsByTagName("legend");
var PreferenceText = document.getElementById("PreferenceText");

var DarkMode = document.getElementById("Dark");

function ColourScheme() 
{
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

    PreferenceText.style.borderBottom = "2px solid #ccc";
}
