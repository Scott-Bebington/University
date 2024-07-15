const Brands = [
    "aston martin",
    "audi",
    "bentley",
    "bmw",
    "bugatti",
    "cadillac",
    "ferrari",
    "jaguar",
    "lamborghini",
    "land rover",
    "lexus",
    "maserati",
    "maybach",
    "mclaren",
    "mercedes-benz",
    "porsche",
    "rolls-royce",
    "tesla",
    "volvo",
    "alfa romeo"
];

// function generateBrandCard(make, colour) 
// {
//     let space = make.replace(" ", '-');
//     let URL = "https://wheatley.cs.up.ac.za/api/images/brands/"
//     URL = URL + space + ".png";
//     // console.log(URL);
//     const card = document.createElement("div");
//     card.classList.add("car");
//     card.innerHTML = `

//         <div class="heading">
//           ${make.toUpperCase()}
//         </div>
//         <div class="logo"
//           style="background-image: URL(${URL});"
//         >
//         </div>

//     `;
//     return card;
// }

function generateBrandCard(make, colour) {
    let space = make.replace(" ", '-');
    let URL = "https://wheatley.cs.up.ac.za/api/images/brands/";
    URL = URL + space + ".png";

    const card = document.createElement("div");
    card.classList.add("car");
    if (colour == "Dark") {
        card.style.backgroundColor = "#34343c"; // Set the background color
        card.style.outline = '1px solid #ccc';
    }


    card.innerHTML = `
      <div class="heading">
        ${make.toUpperCase()}
      </div>
      <div class="logo"
        style="background-image: url(${URL});"
      >
      </div>
    `;

    return card;
}


const cardContainer1 = document.getElementById("carRow1");
const cardContainer2 = document.getElementById("carRow2");
const cardContainer3 = document.getElementById("carRow3");
const cardContainer4 = document.getElementById("carRow4");
const cardContainer5 = document.getElementById("carRow5");

function populateBrands(colour) {
    cardContainer1.innerHTML = '';
    cardContainer2.innerHTML = '';
    cardContainer5.innerHTML = '';
    cardContainer3.innerHTML = '';
    cardContainer4.innerHTML = '';
    for (let i = 0; i < 4; i++) {
        const card1 = generateBrandCard(Brands[i], colour);
        if (colour == "Dark") 
        {
            card1.querySelector('.heading').style.color = '#ccc';
            card1.querySelector('.heading').style.borderBottom = ' solid #ccc';
        }
        cardContainer1.appendChild(card1);
    }
    for (let i = 4; i < 8; i++) {
        const card2 = generateBrandCard(Brands[i], colour);
        if (colour == "Dark") 
        {
            card2.querySelector('.heading').style.color = '#ccc';
            card2.querySelector('.heading').style.borderBottom = ' solid #ccc';
        }
        cardContainer2.appendChild(card2);
    }
    for (let i = 8; i < 12; i++) {
        const card3 = generateBrandCard(Brands[i], colour);
        if (colour == "Dark") 
        {
            card3.querySelector('.heading').style.color = '#ccc';
            card3.querySelector('.heading').style.borderBottom = ' solid #ccc';
        }
        cardContainer3.appendChild(card3);
    }
    for (let i = 12; i < 16; i++) {
        const card4 = generateBrandCard(Brands[i], colour);
        if (colour == "Dark") 
        {
            card4.querySelector('.heading').style.color = '#ccc';
            card4.querySelector('.heading').style.borderBottom = ' solid #ccc';
        }
        cardContainer4.appendChild(card4);
    }
    for (let i = 16; i < 20; i++) {
        const card5 = generateBrandCard(Brands[i], colour);
        if (colour == "Dark") 
        {
            card5.querySelector('.heading').style.color = '#ccc';
            card5.querySelector('.heading').style.borderBottom = ' solid #ccc';
        }
        cardContainer5.appendChild(card5);
    }
}

function GetPreferences() {
    sql = "SELECT * FROM Preferences WHERE UserID = ";

    const xhttp = new XMLHttpRequest();
    xhttp.onload = function () {
        console.log(this.responseText);



        if (xhttp.responseText == "None") {
            console.log("User Has No preferences yet");
            populateBrands("Light");
        }
        else {
            var decodedData = JSON.parse(this.responseText);
            console.log("Retrieving User preferences Index Page");
            console.log("Colour Scheme: " + decodedData.ColourScheme);

            if (decodedData.ColourScheme == "Dark") {
                console.log("Set Colour Scheme to dark mode");
                SetColourScheme();
                populateBrands("Dark");
            }
            else {
                populateBrands("Light");
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
var BrandsContainer = document.getElementsByClassName("carcontainer");


function SetColourScheme() {
    Logo.src = "./Components/Logos/Inverted Logo.jpg";

    Nav.style.backgroundColor = '#34343c';
    Nav.style.outline = "1px solid #ccc";

    InNav.style.backgroundColor = '#34343c';
    InNav.style.color = '#ccc';

    for (let index = 0; index < NavText.length; index++) {
        NavText[index].style.color = '#ccc';
    }

    // for (let index = 0; index < BrandsContainer.length; index++) {
    //     console.log("Setting Dark Mode");
    //     BrandsContainer[index].style.backgroundColor = '#34343c';
    // }
}
