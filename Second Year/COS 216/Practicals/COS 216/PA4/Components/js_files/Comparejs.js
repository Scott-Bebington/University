const Cars = [
    { // 1
        Make: "bugatti",
        Model: "chiron",
    },
    { // 2
        Make: "audi",
        Model: "r8",
    },
    { // 3
        Make: "audi",
        Model: "rs 6",
    },
    { // 4
        Make: "ford",
        Model: "gt40",
    },
    { // 6
        Make: "bmw",
        Model: "m8",
    },
    { // 7
        Make: "lamborghini",
        Model: "aventador",
    },
    { // 9
        Make: "porsche",
        Model: "911",
    },
    { // 10
        Make: "porsche",
        Model: "cayenne",
    },
    { // 11
        Make: "aston martin",
        Model: "dbs",
    },
    { // 12
        Make: "aston martin",
        Model: "vantage",
    },
    { // 13
        Make: "lamborghini",
        Model: "urus",
    },
    { // 14
        Make: "lamborghini",
        Model: "huracan",
    },
    { // 15
        Make: "mercedes-benz",
        Model: "amg gt",
    },
    { // 16
        Make: "rolls-royce",
        Model: "wraith",
    },
    { // 17
        Make: "rolls-royce",
        Model: "cullinan",
    },
    { // 18
        Make: "audi",
        Model: "rs 7",
    },
    { // 19
        Make: "volvo",
        Model: "xc90",
    },
    { // 20
        Make: "bentley",
        Model: "continental gt",
    },
    {
        Make: "audi",
        Model: "sq7",
    }
];
const arr = [];

function ApiRequest(Brand, Type, colour, carcard) {
    const Cars = { "make": Brand, "model": Type }
    const xhttp = new XMLHttpRequest();
    xhttp.onload = function () {
        let random = JSON.parse(this.responseText)
        console.log(random);

        let card1 = generateCarCard(random.data[0].make, random.data[0].model, colour);
        carcard(card1);
    }
    xhttp.open("POST", "https://wheatley.cs.up.ac.za/u21546216/api.php", true);
    let x = {
        "studentnum": "u21546216",
        "type": "GetAllCars",
        "limit": 1,
        "apikey": "a9198b68355f78830054c31a39916b7f",
        "search": Cars,
        "fuzzy": true,
        "return": "*"
    };
    xhttp.send(JSON.stringify(x));
    console.log(JSON.stringify(x));
}

function ApiRequestInfo(Brand1, Type1, colour, callback) {
    const Cars = { "make": Brand1, "model": Type1 }
    const xhttp = new XMLHttpRequest();
    xhttp.onload = function () {
        let random = JSON.parse(this.responseText)
        console.log(random);

        const carArray1 =
            [
                random.data[0].make,
                random.data[0].model,
                random.data[0].id_trim,
                random.data[0].generation,
                random.data[0].year_from,
                random.data[0].year_to,
                random.data[0].series,
                random.data[0].trim,
                random.data[0].body_type,
                random.data[0].number_of_seats,
                random.data[0].length_mm,
                random.data[0].width_mm,
                random.data[0].height_mm,
                random.data[0].number_of_cylinders,
                random.data[0].engine_type,
                random.data[0].drive_wheels,
                random.data[0].transmission,
                random.data[0].max_speed_km_per_h,
                random.data[0].image,
            ];

        let card = generateInfoCard(carArray1, colour);
        callback(card);
    }
    xhttp.open("POST", "https://wheatley.cs.up.ac.za/u21546216/api.php", true);
    let x = {
        "studentnum": "u21546216",
        "type": "GetAllCars",
        "limit": 1,
        "apikey": "a9198b68355f78830054c31a39916b7f",
        "search": Cars,
        "return": "*"
    };
    xhttp.send(JSON.stringify(x));
}

function generateCarCard(carMake, carModel, colour) {
    const card = document.createElement("div");
    card.classList.add("Cars");
    // if(colour == "Dark")
    // {
    //     card.style.color = "#ccc";
    // }
    card.innerHTML = `
    ${carMake} ${carModel}
`;
    return card;
}

function generatePhotoCard(make, model) {
    let model2 = model.replace(" ", "%20");
    let make2 = make.replace(" ", "%20");
    const card = document.createElement("div");
    card.classList.add("Cars");
    card.innerHTML = `
    <div class="image" style="background-image: url(https://wheatley.cs.up.ac.za/api/images/models/${make2}_${model2}.jpg);">
    </div>
`;
    return card;
}

function generateInfoCard(apiRequestInfo1, colour) {
    const card = document.createElement("table");
    card.classList.add("Cars");

    card.innerHTML = `
    <table>
        <tr>
            <th>${apiRequestInfo1[0]} ${apiRequestInfo1[1]}</th>
        </tr>
        <tr>
            <td class="outline">${apiRequestInfo1[2]}</td>
        </tr>
        <tr>
            <td class="outline">${apiRequestInfo1[3]}</td>
        </tr>
        <tr>
            <td class="outline">${apiRequestInfo1[4]}</td>
        </tr>
        <tr>
            <td class="outline">${apiRequestInfo1[5]}</td>
        </tr>
        <tr>
            <td class="outline">${apiRequestInfo1[6]}</td>
        </tr>
        <tr>
            <td class="outline">${apiRequestInfo1[7]}</td>
        </tr>
        <tr>
            <td class="outline">${apiRequestInfo1[8]}</td>
        </tr>
        <tr>
            <td class="outline">${apiRequestInfo1[9]}</td>
        </tr>
        <tr>
            <td class="outline">${apiRequestInfo1[10]} mm</td>
        </tr>
        <tr>
            <td class="outline">${apiRequestInfo1[11]} mm</td>
        </tr>
        <tr>
            <td class="outline">${apiRequestInfo1[12]} mm</td>
        </tr>
        <tr>
            <td class="outline">${apiRequestInfo1[13]}</td>
        </tr>
        <tr>
            <td class="outline">${apiRequestInfo1[14]}</td>
        </tr>
        <tr>
            <td class="outline">${apiRequestInfo1[15]}</td>
        </tr>
        <tr>
            <td class="outline">${apiRequestInfo1[16]}</td>
        </tr>
        <tr>
            <td class="outline">${apiRequestInfo1[17]} km/h</td>
        </tr>
    </table>
    `;
    return card;
}


// Both Divs
const car1 = document.getElementById("car1");
const car2 = document.getElementById("car2");

const option1 = document.getElementById("option1");
const option2 = document.getElementById("option2");

const photo1 = document.getElementById("photo1");
const photo2 = document.getElementById("photo2");

const Car1Info = document.getElementById("Car1Info");
const Car2Info = document.getElementById("Car2Info");

function populateCars(colour) {
    photo1.innerHTML = '';
    photo2.innerHTML = '';
    removeCars();
    if (option1.value != 'None') {
        ApiRequest(Cars[option1.value].Make, Cars[option1.value].Model, colour, function (card1) {
            car1.appendChild(card1);
        });

        const photocard1 = generatePhotoCard(Cars[option1.value].Make, Cars[option1.value].Model);
        photo1.appendChild(photocard1);

        ApiRequestInfo(Cars[option1.value].Make, Cars[option1.value].Model, colour, function (carInfo) {
            if (colour === "Dark") {
                const tds = carInfo.querySelectorAll('td');
                for (let i = 0; i < tds.length; i++) {
                    tds[i].style.outline = '1px solid #ccc';
                }
            }
            Car1Info.appendChild(carInfo);
        });

    }
    if (option2.value != 'None') {
        ApiRequest(Cars[option2.value].Make, Cars[option2.value].Model, colour, function (card2) 
        {
            car2.appendChild(card2);
        });

        const photocard2 = generatePhotoCard(Cars[option2.value].Make, Cars[option2.value].Model);
        photo2.appendChild(photocard2);

        ApiRequestInfo(Cars[option2.value].Make, Cars[option2.value].Model, colour, function (carInfo) 
        {
            if (colour === "Dark") 
            {
                const tds = carInfo.querySelectorAll('td');
                for (let i = 0; i < tds.length; i++) {
                    tds[i].style.outline = '1px solid #ccc';
                }
            }
            Car2Info.appendChild(carInfo);
        });
    }

}

function removeCars() {
    car1.innerHTML = '';
    car2.innerHTML = '';
    photo1.innerHTML = '';
    photo2.innerHTML = '';
    Car1Info.innerHTML = '';
    Car2Info.innerHTML = '';
}

function GetPreferences() {
    sql = "SELECT * FROM Preferences WHERE UserID = ";

    const xhttp = new XMLHttpRequest();
    xhttp.onload = function () {
        console.log(this.responseText);



        if (xhttp.responseText == "None") {
            console.log("User Has No preferences yet");
            populateCars("Light");
        }
        else {
            var decodedData = JSON.parse(this.responseText);
            console.log("Retrieving User preferences Index Page");
            console.log("Colour Scheme: " + decodedData.ColourScheme);


            if (decodedData.ColourScheme == "Dark") {
                console.log("Set Colour Scheme to dark mode");
                SetColourScheme();
                populateCars("Dark");
            }
            else {
                populateCars("Light");
            }

        }
    }
    xhttp.open("POST", "https://wheatley.cs.up.ac.za/u21546216/COS%20216/PA4/validate-preferences.php", true);
    xhttp.send(sql);

}

var Logo = document.getElementById("Logo");
var FiltersContainer = document.getElementById("Filters");
var Nav = document.getElementById("Nav");
var InNav = document.getElementById("InNav");
var NavText = document.getElementsByTagName("a");
var carcontainer = document.getElementById("CarContainer");
var info = document.getElementsByClassName("heading");
var InfoTable = document.getElementById("InfoTable");
var TableOutline = document.getElementsByClassName("outline");


function SetColourScheme() {
    Logo.src = "./Components/Logos/Inverted Logo.jpg";

    Nav.style.backgroundColor = '#34343c';
    Nav.style.outline = "1px solid #ccc";

    InNav.style.backgroundColor = '#34343c';
    InNav.style.color = '#ccc';

    for (let index = 0; index < NavText.length; index++) {
        NavText[index].style.color = '#ccc';
    }

    carcontainer.style.backgroundColor = '#34343c';
    carcontainer.style.outline = '1px solid #ccc';

    for (let index = 0; index < info.length; index++) {
        info[index].style.color = "#ccc";
    }

    InfoTable.style.color = "#ccc";

    for (let index = 0; index < TableOutline.length; index++) {
        TableOutline[index].style.outline = "1px solid #ccc";
    }
}