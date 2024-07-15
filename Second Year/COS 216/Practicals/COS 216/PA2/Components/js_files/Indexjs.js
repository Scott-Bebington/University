
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

function ApiRequest(make, model, price, callback) 
{
    const Cars = { "make": make, "model": model }
    const xhttp = new XMLHttpRequest();
    xhttp.onload = function () {
        let random = JSON.parse(this.responseText)
        console.log(random);

        const card = generateCarCard(
            random.data[0].make, random.data[0].model,
            random.data[0].year_to, random.data[0].body_type,
            random.data[0].engine_type, random.data[0].transmission,
            random.data[0].number_of_seats, price);
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
                "make", "model", "year_to", "body_type", "engine_type", "transmission", "number_of_seats",
            ]
    };
    xhttp.send(JSON.stringify(x));
}

// Create a function to generate a Car card HTML element for each Car object
function generateCarCard(make, model, year, bodytype, fuel, transmission, seats, price) {
    let model2 = model.replace(' ', "%20");
    let make2 = make.replace(' ', "%20");
    const card = document.createElement("div");
    card.classList.add("Cars");
    // card.style.backgroundImage = `url(${Car.Image})`;
    card.innerHTML = `

    <div class="CarOutline"><div class="Photo" style="background-image: URL(https://wheatley.cs.up.ac.za/api/images/models/${make2.toLocaleLowerCase()}_${model2.toLocaleLowerCase()}.jpg);"></div>
    <div class="Info">
        <h1>
            ${year} ${make} ${model}
        </h1>
        <h1>
            ${price}
        </h1>
        <h3>
            ${bodytype} | ${transmission} | ${fuel} | Seats (${seats})
        </h3>
    </div>
    </div>
`;
    return card;
}

function generateNoneFound() {
    const card = document.createElement("div");
    card.classList.add("Cars");
    // card.style.backgroundImage = `url(${Car.Image})`;
    card.innerHTML = `

    <div class="CarOutline"><div class="Photo"></div>
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
    return card;
}

const cardContainer = document.getElementById("cardContainer");

// Loop through the Cars array and append a Car card HTML element for each one to the cardContainer
function populateCars() 
{
    cardContainer.innerHTML = '';
    for (let i = 0; i < Cars.length; i++) {
        ApiRequest(Cars[i].Make, Cars[i].Model, Cars[i].Price, function (card1) {
            cardContainer.appendChild(card1);
        });
    }
}

function removeCars() 
{
    cardContainer.innerHTML = '';
}

var seats2 = document.getElementById("Two");
var seats4 = document.getElementById("Four");
var manual = document.getElementById("Manual");
var auto = document.getElementById("Auto");
var petrol = document.getElementById("Petrol");
var diesel = document.getElementById("Diesel");
var body = document.getElementById("bodyType");
var searchbar = document.getElementById("search");


function applyfilters() 
{
    removeCars();
    populateCarsFilters();
}

function populateCarsFilters() 
    {
        for (let i = 0; i < Cars.length; i++) 
        {
            let BodyType = body.value;
            let numberofseats = 0;
            let transmissiontype = "";
            let fueltype = "";
            if(seats2.checked)
            {
                numberofseats = 2;
            }
            if(seats4.checked)
            {
                numberofseats = 4
            }
            if(petrol.chekced)
            {
                fueltype = "Gasoline";
            }
            if(diesel.checked)
            {
                fueltype = "Diesel";
            }
            if(manual.checked)
            {
                transmissiontype = "Manual";
            }
            if(auto.checked)
            {
                transmissiontype = "Automatic";
            }
            ApiRequestSeats(Cars[i].Price, Cars[i].Make, Cars[i].Model, numberofseats, transmissiontype, fueltype, BodyType, function (card) {
                cardContainer.appendChild(card);
            });
        }
    }
function ApiRequestSeats(price, make, model, seatNo, TransType, FuelType, BodyType, callback) 
{
    const Cars = { "make": make, "model": model }
    const xhttp = new XMLHttpRequest();
    xhttp.onload = function () {
        let random = JSON.parse(this.responseText);
        console.log(random);

        const card = generateCarCard(
            random.data[0].make, random.data[0].model,
            random.data[0].year_to, random.data[0].body_type,
            random.data[0].engine_type, random.data[0].transmission,
            random.data[0].number_of_seats, price);
        
        // if(BodyType === random.data[0].body_type)
        // {
        //     callback(card);
        // }
        if (seatNo !== 0 && random.data[0].number_of_seats === seatNo)
        {
            if(TransType !== "" && TransType === random.data[0].transmission)
            {
                if(FuelType !== "" && FuelType === random.data[0].engine_type)
                {
                    if(BodyType !== "None" && BodyType === random.data[0].body_type)
                    {
                        // 
                        callback(card);
                    }
                    else if(BodyType === "None")
                    {
                        // 
                        callback(card);
                    }
                }
                else if(FuelType === "")
                {
                    if(BodyType !== "None" && BodyType === random.data[0].body_type)
                    {
                        // 
                        callback(card);
                    }
                    else if(BodyType === "None")
                    {
                        // 
                        callback(card);
                    }
                }
            }
            else if(TransType === "")
            {
                if(FuelType !== "" && FuelType === random.data[0].engine_type)
                {
                    if(BodyType !== "None" && BodyType === random.data[0].body_type)
                    {
                        // 
                        callback(card);
                    }
                    else if(BodyType === "None")
                    {
                        // 
                        callback(card);
                    }
                }
                else if(FuelType === "")
                {
                    if(BodyType !== "None" && BodyType === random.data[0].body_type)
                    {
                        // 
                        callback(card);
                    }
                    else if(BodyType === "None")
                    {
                        // 
                        callback(card);
                    }
                }
            }
        }
        else if(seatNo === 0)
        {
            if(TransType !== "" && TransType === random.data[0].transmission)
            {
                if(FuelType !== "" && FuelType === random.data[0].engine_type)
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
                else if(FuelType === "")
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
            else if(TransType === "")
            {
                if(FuelType !== "" && FuelType === random.data[0].engine_type)
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
                else if(FuelType === "")
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
                "make", "model", "year_to", "body_type", "engine_type", "transmission", "number_of_seats",
            ]
    };
    xhttp.send(JSON.stringify(x));
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
    body.value = "None";
}

function select2()
{
    if(seats4.checked)
    {
        seats4.checked = false;
    }
}

function select4()
{
    if(seats2.checked)
    {
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

// var searchbar = document.getElementById("search");
function search()
{
    removeCars();
    for (let i = 0; i < Cars.length; i++) 
    {
        ApiRequestSearch(Cars[i].Make, Cars[i].Model, Cars[i].Price, searchbar.value, function (card1) 
        {
            cardContainer.appendChild(card1);
        });
    }
}

function ApiRequestSearch(make, model, price, searchtext, callback) 
{
    const Cars = { "make": make, "model": model }
    const xhttp = new XMLHttpRequest();
    xhttp.onload = function () {
        let random = JSON.parse(this.responseText);
        console.log(random);

        const card = generateCarCard(
            random.data[0].make, random.data[0].model,
            random.data[0].year_to, random.data[0].body_type,
            random.data[0].engine_type, random.data[0].transmission,
            random.data[0].number_of_seats, price);
        
        if(searchtext.toLocaleLowerCase() === random.data[0].make.toLocaleLowerCase() || searchtext === random.data[0].model.toLocaleLowerCase())
            {
                callback(card);
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
        "return":
            [
                "make", "model", "year_to", "body_type", "engine_type", "transmission", "number_of_seats",
            ]
    };
    xhttp.send(JSON.stringify(x));
}