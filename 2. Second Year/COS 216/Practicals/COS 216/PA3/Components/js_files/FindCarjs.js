const Cars = [
    { // 1
        Make: "bugatti",
        Model: "chiron",
        Price: "R 54 727 650",
    },
    { // 2
        Make: "audi",
        Model: "r8",
        Price: "R 2 654 950",
    },
    { // 3
        Make: "audi",
        Model: "rs 6",
        Price: "R 1 354 000",
    },
    { // 4
        Make: "ford",
        Model: "gt40",
        Price: "R 9 119 000",
    },
    { // 5
        Make: "ferrari",
        Model: "812 superfast",
        Price: "R 6 699 900",
    },
    { // 6
        Make: "BMW",
        Model: "m8",
        Price: "R 2 599 000",
    },
    { // 7
        Make: "lamborghini",
        Model: "aventador",
        Price: "R 9 486 374",
    },
    { // 8
        Make: "alfa romeo",
        Model: "gtv",
        Price: "R 2 345 120",
    },
    { // 9
        Make: "porsche",
        Model: "911",
        Price: "R 6 240 000",
    },
    { // 10
        Make: "porsche",
        Model: "cayenne",
        Price: "R 6 240 000",
    },


    { // 11
        Make: "aston martin",
        Model: "dbs",
        Price: "R 54 727 650",
    },
    { // 12
        Make: "aston martin",
        Model: "vantage",
        Price: "R 2 654 950",
    },
    { // 13
        Make: "lamborghini",
        Model: "urus",
        Price: "R 1 354 000",
    },
    { // 14
        Make: "lamborghini",
        Model: "huracan",
        Price: "R 9 119 000",
    },
    { // 15
        Make: "mercedes-benz",
        Model: "amg gt",
        Price: "R 6 699 900",
    },
    { // 16
        Make: "rolls-royce",
        Model: "wraith",
        Price: "R 2 599 000",
    },
    { // 17
        Make: "rolls-royce",
        Model: "cullinan",
        Price: "R 9 486 374",
    },
    { // 18
        Make: "audi",
        Model: "rs 7",
        Price: "R 2 345 120",
    },
    { // 19
        Make: "volvo",
        Model: "xc90",
        Price: "R 6 240 000",
    },
    { // 20
        Make: "bentley",
        Model: "continental gt",
        Price: "R 6 240 000",
    },
    {
        Make: "audi",
        Model: "sq7",
        Price: "R 1 345 232"
    }
];

function ApiRequest(make, model, callback) {
    const Cars = { "make": make, "model": model }
    const xhttp = new XMLHttpRequest();
    xhttp.onload = function () {
        let random = JSON.parse(this.responseText)
        console.log(random);

        const card = generateCarCard(
            random.data[0].make, random.data[0].model,
            random.data[0].year_to);
        callback(card);

    }
    xhttp.open("POST", "https://wheatley.cs.up.ac.za/api/", true);
    let x = {
        "studentnum": "u21546216",
        "type": "GetAllCars",
        "limit": 1,
        "apikey": "a9198b68355f78830054c31a39916b7f",
        "search": Cars,
        "fuzzy": true,
        "return":
        [
            "make", "model", "year_to", "engine_type"
        ]
    };
    xhttp.send(JSON.stringify(x));
}

function generateCarCard(make, model, year) {
    let model2 = model.replace(' ', "%20");
    let make2 = make.replace(' ', "%20");
    const card = document.createElement("div");
    card.classList.add("Cars");
    // card.style.backgroundImage = `url(${Car.Image})`;
    card.innerHTML = `

    <div class="Cars" style="background-image: URL(https://wheatley.cs.up.ac.za/api/images/models/${make2.toLocaleLowerCase()}_${model2.toLocaleLowerCase()}.jpg)">
        <div style="margin-left: 2vw;">
            <h1 style="padding-top: 1%;">
                ${year} ${make} ${model}
            </h1>
            
        </div>
    </div>
`;
    return card;
}

// function generateCarCard(make, model, year) {
//     const model2 = model.replace(' ', '%20');
//     const make2 = make.replace(' ', '%20');
//     const card = document.createElement('div');
//     card.classList.add('Cars');
//     card.style.backgroundImage = `url(https://wheatley.cs.up.ac.za/api/images/models/${make2.toLowerCase()}_${model2.toLowerCase()}.jpg)`;
//     const cardContent = document.createElement('div');
//     cardContent.style.marginLeft = '2vw';
//     const cardTitle = document.createElement('h1');
//     cardTitle.style.paddingTop = '1%';
//     cardTitle.textContent = `${year} ${make} ${model}`;
//     const loadingGif = document.createElement('img');
//     loadingGif.src = './Backgrounds/loading.gif';
//     cardContent.appendChild(cardTitle);
//     cardContent.appendChild(loadingGif);
//     card.appendChild(cardContent);
//     return card;
//   }
  



function generateNoneFound() {
    const card = document.createElement("div");
    card.classList.add("Cars");
    // card.style.backgroundImage = `url(${Car.Image})`;
    card.innerHTML = `

    <div class="Cars">
        <div style="margin-left: 2vw;">
            <h1 style="padding-top: 1%;">
                We're Sorry
            </h1>
            <h3 style="padding-top: 1%;">
                There are currently no results found for the filters you entered, please change them and try again
            </h3>
        </div>
    </div>
`;
    return card;
}

const cardContainer = document.getElementById("cardContainer");

// Loop through the Cars array and append a Car card HTML element for each one to the cardContainer
function populateCars() 
{
    cardContainer.innerHTML = '';
    for (let i = 0; i < Cars.length; i++) {
        ApiRequest(Cars[i].Make, Cars[i].Model, function (card1) {
            cardContainer.appendChild(card1);
        });
    }
}

var seats2 = document.getElementById("Two");
var seats4 = document.getElementById("Four");
var manual = document.getElementById("Manual");
var auto = document.getElementById("Auto");
var petrol = document.getElementById("Petrol");
var diesel = document.getElementById("Diesel");
var AWD = document.getElementById("Rear");
var RWD = document.getElementById("All");

var body = document.getElementById("bodytype");
var cylinders = document.getElementById("cylinders");

var applybutton = document.getElementById("applybutton");
applybutton.disabled = true;

function applycheck() {
    if ((seats2.checked || seats4.checked) &&
        (manual.checked || auto.checked) &&
        (petrol.checked || diesel.checked) &&
        (AWD.checked || RWD.checked)) {
        applybutton.disabled = false;
    }
    else {
        applybutton.disabled = true;
    }
}

function clearfilters() {
    removeCars();
    populateCars();
    seats2.checked = false;
    seats4.checked = false;
    manual.checked = false;
    auto.checked = false;
    petrol.checked = false;
    diesel.checked = false;
    AWD.checked = false;
    RWD.checked = false;
    cylinders.value = "None";
    body.value = "None";
}

function removeCars() {
    cardContainer.innerHTML = '';
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

function selectOneRear() {
    if (RWD.checked) {
        RWD.checked = false;
    }
}

function selectOneAll() {
    if (AWD.checked) {
        AWD.checked = false;
    }
}

function populateCarsFilters() 
{
    for (let i = 0; i < Cars.length; i++) {
        let BodyType = body.value;
        let Cylinders = cylinders.value;
        let numberofseats = 0;
        let transmissiontype = "";
        let fueltype = "";
        let DriveTrain = "";
        if (seats2.checked) {
            numberofseats = 2;
        }
        if (seats4.checked) {
            numberofseats = 4
        }
        if (petrol.checked) {
            fueltype = "Gasoline";
        }
        if (diesel.checked) {
            fueltype = "Diesel";
        }
        if (manual.checked) {
            transmissiontype = "Manual";
        }
        if (auto.checked) {
            transmissiontype = "Automatic";
        }
        if (AWD.checked) {

            DriveTrain = "Rear wheel drive";
        }
        if (RWD.checked) {
            DriveTrain = "All wheel drive (AWD)";
        }
        ApiRequestSeats(Cars[i].Make, Cars[i].Model, numberofseats, transmissiontype, fueltype, DriveTrain, BodyType, Cylinders, function (card) {
            cardContainer.appendChild(card);
        });
    }
}
function ApiRequestSeats(make, model, seatNo, TransType, FuelType, DriveTrain, BodyType, CylinderNo, callback) {
    const Cars = { "make": make, "model": model }
    const xhttp = new XMLHttpRequest();
    xhttp.onload = function () {
        let random = JSON.parse(this.responseText);
        console.log(random);

        const card = generateCarCard(
            random.data[0].make, random.data[0].model,
            random.data[0].year_to);

        if (FuelType === random.data[0].engine_type &&
            seatNo === random.data[0].number_of_seats &&
            DriveTrain === random.data[0].drive_wheels &&
            TransType === random.data[0].transmission
            ) 
        {
            
            if(CylinderNo !== "None" && CylinderNo == random.data[0].number_of_cylinders)
            {
                if(BodyType !== "None" && BodyType === random.data[0].body_type)
                {
                    
                    callback(card);
                }
                else if(BodyType === "None")
                {
                    
                    callback(card);
                }
            }
            else if(CylinderNo === "None")
            {
                if(BodyType !== "None" && BodyType === random.data[0].body_type)
                {
                    
                    callback(card);
                }
                else if(BodyType === "None")
                {
                    
                    callback(card);
                }
            }
        }
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
function applyfilters() {
    removeCars();
    populateCarsFilters();
    
  }