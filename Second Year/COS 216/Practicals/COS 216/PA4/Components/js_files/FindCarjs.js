function ApiRequest(Request, num, colour) 
{
    const xhttp = new XMLHttpRequest();
    xhttp.onload = function () {
        let random = JSON.parse(this.responseText)
        console.log(random);

        if(random.status == "error")
        {
            const card = generateNoneFound()
                
            cardContainer.appendChild(card);
        }
        else
        {
            for (let index = 0; index < num; index++) 
            {
                if(random.data[index] && typeof random.data[index].make !== 'undefined') 
                {
                    const card = generateCarCard
                    (
                        random.data[index].make, random.data[index].model,
                        random.data[index].year_to, random.data[index].image
                    );
                    
                    if(colour == "Dark")
                    {
                        card.querySelector('.CarOutline').style.backgroundColor = '#34343c';
                        card.querySelector('.CarOutline').style.color = '#ccc';
                        card.querySelector('.CarOutline').style.outline = '1px solid #ccc';
                    }
                    
                    cardContainer.appendChild(card);
                }
            }
        }
    }
    xhttp.open("POST", "https://wheatley.cs.up.ac.za/u21546216/api.php", true);
    xhttp.send(JSON.stringify(Request));
    console.log(JSON.stringify(Request))
}

function generateCarCard(make, model, year, image) 
{
    image = image.replace(' ', "%20");
    let model2 = model.replace(' ', "%20");
    let make2 = make.replace(' ', "%20");
    const card = document.createElement("div");
    card.classList.add("Cars");
    // card.style.backgroundImage = `url(${Car.Image})`;
    card.innerHTML = `

    <div class="Cars" style="background-image: URL(${image})">
        <div style="margin-left: 2vw;">
            <h1 style="padding-top: 1%;">
                ${year} ${make} ${model}
            </h1>
            
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

function applycheck() 
{
    if ((seats2.checked || seats4.checked) &&
        (manual.checked || auto.checked) &&
        (petrol.checked || diesel.checked) &&
        (AWD.checked || RWD.checked)) {
        applybutton.disabled = false;
    }
    else 
    {
        applybutton.disabled = true;
    }
}

function clearfilters() 
{
    removeCars();
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
    populateCars();
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

function populateCars() 
{
    removeCars();
    let num = 20;
    let x = {
        "type": "GetAllCars",
        "limit": num,
        "apikey": "a9198b68355f78830054c31a39916b7f",
        "fuzzy": true,
        "return": ["make", "model", "year_to"]
    };

    let search = {};
    if (seats2.checked) 
    {
        console.log("2 Seats Checked");
        search.number_of_seats = 2;
    }
    if (seats4.checked) 
    {
        console.log("4 Seats Checked");
        search.number_of_seats = 4;
    }
    if (auto.checked) 
    {
        search.transmission = "automatic";
    }
    if (manual.checked) 
    {
        search.transmission = "manual";
    }
    if (diesel.checked) 
    {
        search.engine_type = "diesel";
    }
    if (petrol.checked) 
    {
        search.engine_type = "gasoline";
    }
    if(body.value != "None")
    {
        search.body_type = body.value;
    }
    if(cylinders.value != "None")
    {
        search.number_of_cylinders = cylinders.value;
    }
    if(Object.keys(search).length !== 0)
    {
        x.search = search;
    }
    console.log("Testing");
    ApiRequest(x, num);
}

function GetPreferences() 
{
    sql = "SELECT * FROM Preferences WHERE UserID = ";

    const xhttp = new XMLHttpRequest();
    xhttp.onload = function () {
        console.log(this.responseText);



        if (xhttp.responseText == "None") 
        {
            console.log("User Has No preferences yet");
            populateCars();
        }
        else {
            var decodedData = JSON.parse(this.responseText);
            console.log("Retrieving User preferences Index Page");
            console.log("Colour Scheme: " + decodedData.ColourScheme);

            if(decodedData.ColourScheme == "Dark")
            {
                console.log("Set Colour Scheme to dark mode");
                SetColourScheme();
                populateCars();
            }  
            else
            {
                populateCars();
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
var Checkboxes = document.getElementsByClassName("checkmark");
var Headings1 = document.getElementById("Heading1");
var Headings2 = document.getElementById("Heading2");


function SetColourScheme()
{
    Logo.src = "./Components/Logos/Inverted Logo.jpg";

    Nav.style.backgroundColor = '#34343c';
    Nav.style.outline = "1px solid #ccc";

    InNav.style.backgroundColor = '#34343c';
    InNav.style.color = '#ccc';

    for (let index = 0; index < NavText.length; index++) 
    {
        NavText[index].style.color = '#ccc';
    }

    FiltersContainer.style.backgroundColor = '#34343c';
    FiltersContainer.style.outline = "1px solid #ccc";
    FiltersContainer.style.color = '#ccc';
    for (let index = 0; index < Checkboxes.length; index++) 
    {
        Checkboxes[index].style.border = '2px solid purple';
    }

    Headings1.style.borderBottom = "solid #ccc";
    Headings2.style.borderBottom = "solid #ccc";
    Headings2.style.borderTop = "solid #ccc";
}