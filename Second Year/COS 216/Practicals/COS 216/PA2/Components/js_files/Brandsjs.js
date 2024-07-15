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

function generateBrandCard(make) {
    let space = make.replace(" ", '-');
    const card = document.createElement("div");
    card.classList.add("car");
    card.innerHTML = `

        <div class="heading">
          ${make.toUpperCase()}
        </div>
        <div class="logo"
          style="background-image: URL(https://wheatley.cs.up.ac.za/api/images/brands/${space}.png);"
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

function populateBrands() 
{
    cardContainer1.innerHTML = '';
    cardContainer2.innerHTML = '';
    cardContainer5.innerHTML = '';
    cardContainer3.innerHTML = '';
    cardContainer4.innerHTML = '';
    for (let i = 0; i < 4; i++) {
        const card1 = generateBrandCard(Brands[i]);
        cardContainer1.appendChild(card1);
    }
    for (let i = 4; i < 8; i++) {
        const card2 = generateBrandCard(Brands[i]);
        cardContainer2.appendChild(card2);
    }
    for (let i = 8; i < 12; i++) {
        const card3 = generateBrandCard(Brands[i]);
        cardContainer3.appendChild(card3);
    }
    for (let i = 12; i < 16; i++) {
        const card4 = generateBrandCard(Brands[i]);
        cardContainer4.appendChild(card4);
    }
    for (let i = 16; i < 20; i++) {
        const card5 = generateBrandCard(Brands[i]);
        cardContainer5.appendChild(card5);
    }
}

populateBrands();
