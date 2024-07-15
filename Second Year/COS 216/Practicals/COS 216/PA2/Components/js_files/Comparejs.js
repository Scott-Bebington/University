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
    { // 5
        Make: "ferrari",
        Model: "812 superfast",
    },
    { // 6
        Make: "bmw",
        Model: "m8",
    },
    { // 7
        Make: "lamborghini",
        Model: "aventador",
    },
    { // 8
        Make: "alfa romeo",
        Model: "gtv",
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

function sendData() {
    populateCars();
}

function ApiRequest(Brand, Type, carcard) {
    const Cars = { "make": Brand, "model": Type }
    const xhttp = new XMLHttpRequest();
    xhttp.onload = function () {
        let random = JSON.parse(this.responseText)
        console.log(random);

        let card1 = generateCarCard(random.data[0].make, random.data[0].model);
        carcard(card1);
    }
    xhttp.open("POST", "https://wheatley.cs.up.ac.za/api/", true);
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
}

function ApiRequestInfo(Brand1, Type1, callback) {
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
            ];

        let card = generateInfoCard(carArray1);
        callback(card);
    }
    xhttp.open("POST", "https://wheatley.cs.up.ac.za/api/", true);
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

function generateCarCard(carMake, carModel) {
    const card = document.createElement("div");
    card.classList.add("Cars");
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

var choice1;
function generateInfoCard(apiRequestInfo1) {
    const card = document.createElement("table");
    card.classList.add("Cars");
    card.innerHTML = `
    <table>
        <tr>
            <th>${apiRequestInfo1[0]} ${apiRequestInfo1[1]}</th>
        </tr>
        <tr>
            <td>${apiRequestInfo1[2]}</td>
        </tr>
        <tr>
            <td>${apiRequestInfo1[3]}</td>

        </tr>
        <tr>
            <td>${apiRequestInfo1[4]}</td>
        </tr>
        <tr>
            <td>${apiRequestInfo1[5]}</td>
        </tr>
        <tr>
            <td>${apiRequestInfo1[6]}</td>
        </tr>
        <tr>
            <td>${apiRequestInfo1[7]}</td>
        </tr>
        <tr>
            <td>${apiRequestInfo1[8]}</td>
        </tr>
        <tr>
            <td>${apiRequestInfo1[9]}</td>
        </tr>
        <tr>
            <td>${apiRequestInfo1[10]} mm</td>
        </tr>
        <tr>
            <td>${apiRequestInfo1[11]} mm</td>
        </tr>
        <tr>
            <td>${apiRequestInfo1[12]} mm</td>
        </tr>
        <tr>
            <td>${apiRequestInfo1[13]}</td>
        </tr>
        <tr>
            <td>${apiRequestInfo1[14]}</td>
        </tr>
        <tr>
            <td>${apiRequestInfo1[15]}</td>
        </tr>
        <tr>
            <td>${apiRequestInfo1[16]}</td>
        </tr>
        <tr>
            <td>${apiRequestInfo1[17]} km/h</td>
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

function populateCars() 
{
    photo1.innerHTML = '';
    photo2.innerHTML = '';
    removeCars();
    if (option1.value != 'None') {
        ApiRequest(Cars[option1.value].Make, Cars[option1.value].Model, function (card1,) {
            car1.appendChild(card1);
        });
        const photocard1 = generatePhotoCard(Cars[option1.value].Make, Cars[option1.value].Model);
        photo1.appendChild(photocard1);
        ApiRequestInfo(Cars[option1.value].Make, Cars[option1.value].Model, function (carInfo) {
            Car1Info.appendChild(carInfo);
        });
    }
    if (option2.value != 'None') {
        ApiRequest(Cars[option2.value].Make, Cars[option2.value].Model, function (card2) {
            car2.appendChild(card2);
        });
        const photocard2 = generatePhotoCard(Cars[option2.value].Make, Cars[option2.value].Model);
        photo2.appendChild(photocard2);
        ApiRequestInfo(Cars[option2.value].Make, Cars[option2.value].Model, function (carInfo) {
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