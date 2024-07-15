#pragma once 
#include <string>
using namespace std;

// category:

// 1: ingredients
// 2: meat 
// 3: fish
// 4: pizza
// 5: fry
// 6: burger
// 7: pastry
// 8: pasta
// 9: salads
// 10: drinks
    
    const int ingredPrepMin = 5;
    const int ingredPrepMax = 15;
    const int ingredCost = 10;
    const int meatPrepMin = 10;
    const int meatPrepMax = 20;
    const int meatCost = 20;
    const int fishMin = 60;
    const int fishMax = 100;
    const int fishCost = 100;
    const int pizzaMin = 150;
    const int pizzaMax = 200;
    const int pizzaCost = 90;
    const int fryMin = 20;
    const int fryMax = 120;
    const int fryCost = 50;
    const int burgerMin = 100;
    const int burgerMax = 130;
    const int burgerCost = 110;
    const int pastryMin = 200;
    const int pastryMax = 250;
    const int pastryCost = 75;
    const int pataMin = 100;
    const int pastaMax = 150;
    const int pastaCost = 85;
    const int saladMin = 20;
    const int saladMax = 30;
    const int saladCost = 40;
    const int drinksMin = 10;
    const int drinksMax = 50;
    const int drinkCost = 20;

const string cheeseBurgerIng[6] = {"Buns","BeefPatty","Cheddar","Onion","Lettuce","Tomato"};
const string steak[2] = {"Beef","Herbs"};
const string lamb[3] ={"Lamb","Herbs","Lemon"};
const string pork[2] = {"Pork","Herbs"};
const string chickenCrumbed[2] ={"Chicken","Crumbs"};
const string chicken[2] ={"Chicken","Crumbs"};
const string friedHake[6] ={"Hake","Crumbs","Herbs","Garlic","Butter","Lemon"};
const string grilledHake[5] ={"Hake","Herbs","Garlic","Butter","Lemon"};
const string salmon[5] = {"Salmon","Herbs","Garlic","Butter","Lemon"};
const string sole[5] = {"Sole","Herbs","Garlic","Butter","Lemon"};
const string prawn[5] = {"Pawn","Herbs","Garlic","Butter","Lemon"};
const string grilledCalamari[5] = {"Calamari","Herbs","Garlic","Butter","Lemon"};
const string rawTuna[1] = {"Tuna"};
const string lobster[5] = {"Lobster","Herbs","Garlic","Butter","Lemon"};
const string mussel[5] = {"Mussels","Herbs","Garlic","Butter","Lemon"};
const string oyster[3] = {"Oyster","Herbs","Lemon"};
const string margheritaPizzaIng[2] = {"PizzaBase", "TomatoSauce"};
const string pepperoniPizzaIng[2] = {"PizzaBase", "Pepperoni"};
const string vegetarianPizzaIng[6] = {"PizzaBase", "Mozzarella", "TomatoSauce", "Peppers", "Mushroom", "Olives"};
const string hawaiianPizzaIng[4] = {"PizzaBase", "Mozzarella", "TomatoSauce", "Ham"};
const string bbqChickenPizzaIng[4] = {"PizzaBase", "Mozzarella", "BBQSauce", "Chicken"};
const string mushroomPizzaIng[4] = {"PizzaBase", "TomatoSauce", "Mushroom", "Mozzarella"};
const string veggieSupremePizzaIng[7] = {"PizzaBase", "TomatoSauce", "Mushroom", "Peppers", "Olives", "Onion", "Mozzarella"};
const string meatLoversPizzaIng[5] = {"PizzaBase", "TomatoSauce", "Pepperoni", "Bacon", "Sausages"};
const string supremePizzaIng[7] = {"PizzaBase", "TomatoSauce", "Pepperoni", "Olives", "Peppers", "Mushroom", "Sausages"};
const string whitePizzaIng[3] = {"PizzaBase", "Garlic", "Mozzarella"};
const string buffaloChickenPizzaIng[4] = {"PizzaBase", "TomatoSauce", "Chicken", "Cheddar"};
const string bbqPulledPorkPizzaIng[4] = {"PizzaBase", "BBQSauce", "Pulled Pork", "Onion"};
const string mediterraneanPizzaIng[6] = {"PizzaBase", "TomatoSauce", "Feta", "Olives", "Peppers", "Onion"};
const string frenchFriesIng[2] = {"Potato", "Salt"};
const string onionRingsIng[2] = {"Onion", "Batter"};
const string sweetPotatoFriesIng[2] = {"Squash", "Salt"};
const string zucchiniFriesIng[2] = {"Zucchini", "Batter"};
const string curlyFriesIng[2] = {"Potato", "Salt"};
const string garlicParmesanFriesIng[3] = {"Potato", "Garlic", "Parmesan"};
const string loadedChiliCheeseFriesIng[4] = {"Potato", "Jalapeno", "Cheddar", "Onions"};
const string applePieIng[3] = {"PastryDough", "Apples", "Sugar"};
const string chocolateCroissantIng[3] = {"PastryDough", "Chocolate", "Butter"};
const string danishPastryIng[3] = {"PastryDough", "Cream", "Apples"};
const string eclairIng[4] = {"PastryDough", "Cream", "Chocolate", "Vanilla"};
const string cinnamonRollIng[3] = {"PastryDough", "Cinnamon", "Sugar"};
const string bbqBaconBurgerIng[6] = {"Buns", "BeefPatty", "Bacon", "BBQ Sauce", "Onion", "Lettuce"};
const string mushroomSwissBurgerIng[5] = {"Buns", "BeefPatty", "Mushrooms", "Cheddar", "Onion"};
const string spicyJalapenoBurgerIng[5] = {"Buns", "BeefPatty", "Jalapeno", "Pepper", "Lettuce"};
const string veggieBurgerIng[6] = {"Buns", "BeefPatty", "Cheddar", "Onion", "Lettuce", "Tomato"};
const string doublePattyBurgerIng[7] = {"Buns", "BeefPatty", "BeefPatty", "Cheese", "Onion", "Lettuce", "Tomato"};
const string baconAvocadoBurgerIng[6] = {"Buns", "BeefPatty", "Bacon", "Avocado", "Onion", "Lettuce"};
const string teriyakiPineappleBurgerIng[5] = {"Buns", "BeefPatty", "Seasoning", "Pineapple", "Lettuce"};
const string buffaloChickenBurgerIng[4] = {"Buns", "ChickenPatty", "TomatoSauce", "Parmesan"};
const string blueCheeseBurgerIng[5] = {"Buns", "BeefPatty", "Bacon", "Parmesan", "Lettuce"};
const string spaghettiAglioEOlioIng[2] = {"Spaghetti", "Garlic"};
const string penneArrabbiataIng[3] = {"LasagnaStrips", "Sauce", "Parmesan"};
const string linguineClamsIng[3] = {"LasagnaStrips", "Oyster", "Garlic"};
const string fettuccinePestoIng[2] = {"Spaghetti", "Sauce"};
const string cavatelliBroccoliIng[2] = {"Spaghetti", "Broccoli"};
const string rigatoniTomatoSauceIng[2] = {"Ravioli", "TomatoSauce"};
const string spaghettiPuttanescaIng[5] = {"Spaghetti", "TomatoSauce", "Olives", "Garlic", "Garlic"};
const string penneVodkaIng[4] = {"Ravioli", "Vodka", "Cream", "Parmesan"};
const string linguineAglioEOlioIng[2] = {"Ravioli", "Garlic"};
const string fettuccineAlfredoIng[4] = {"Spaghetti", "Cream", "Parmesan", "Butter"};
const string caesarSaladIng[4] = {"Lettuce", "Crumbs", "Parmesan", "OliveOil"};
const string gardenSaladIng[3] = {"Beans", "Tomato", "Cucumber"};
const string greekSaladIng[5] = {"Lettuce", "Tomato", "Cucumber", "Olives", "Feta"};
const string capreseSaladIng[3] = {"Tomato", "Mozzarella", "Herbs"};
const string cobbSaladIng[6] = {"Beans", "Chicken", "Bacon", "Egg", "Avocado", "Blue Cheese"};
const string spinachStrawberrySaladIng[4] = {"Lettuce", "Strawberry", "Herbs", "Peas"};
const string waldorfSaladIng[5] = {"Beans", "Apples", "Garlic", "Herbs", "Sauce"};
const string asianNoodleSaladIng[5] = {"Noodles", "Cabbage", "Carrots", "Noodles", "Sauce"};
const string mediterraneanSaladIng[5] = {"Beans", "Tomato", "Cucumber", "Onion", "Feta"};
const string antipastoSaladIng[6] = {"Beans", "Salami", "Olives", "Anchovies", "Mozzarella", "Sauce"};
const string cocaColaIng[1] = {"Coke"};
const string pepsiIng[1] = {"Coke"};
const string spriteIng[1] = {"Sprite"};
const string mountainDewIng[1] = {"Fanta"};
const string rootBeerIng[1] = {"Beer"};
const string icedTeaIng[1] = {"RooiBos"};
const string lemonadeIng[3] = {"Lemon","Water","Sugar"};
const string orangeJuiceIng[1] = {"Fanta"};
const string cranberryJuiceIng[1] = {"Sauce"};
const string grapeJuiceIng[1] = {"Wine"};
const string appleJuiceIng[1] = {"Brandy"};
const string limeSodaIng[1] = {"Sprite"};
const string cherrySodaIng[1] = {"Sprite"};
const string fruitPunchIng[1] = {"Wine"};
const string lemonLimeSodaIng[1] = {"Sprite"};
const string mangoSmoothieIng[2] = {"Sauce", "Cream"};
const string strawberryBananaSmoothieIng[2] = {"Strawberries", "Banana"};
const string pinaColadaIng[3] = {"Pineapple", "Milk", "Whiskey"};
const string mojitoIng[3] = {"Lime", "Mint", "Whiskey"};
const string espressoIng[1] = {"CoffeeBeans"};

struct Food{

    string name ;
    int category;
    int min;
    int max;
    int cost;
    const string* ingredients;
    int size;

};

const Food foodBank[206]={

            {"Fillet",2,meatPrepMin,meatPrepMax,meatCost,steak,2}
            ,{"Rump",2,meatPrepMin,meatPrepMax,meatCost,steak,2}
            ,{"LambChops",2,meatPrepMin,meatPrepMax,meatCost,lamb,3}
            ,{"PorkChops",2,meatPrepMin,meatPrepMax,meatCost,pork,2}
            ,{"Schnitzel",2,meatPrepMin,meatPrepMax,meatCost,chickenCrumbed,2}
            ,{"FriedHake",3,fishMin,fishMax,fishCost,friedHake,6}
            ,{"KingPrawn",3,fishMin,fishMax,fishCost,prawn,5}
            ,{"GrilledCalamari",3,fishMin,fishMax,fishCost,grilledCalamari,5}
            ,{"ThreeOysters",3,fishMin,fishMax,fishCost,oyster,3}
            ,{"Margherita Pizza", 4, pizzaMin, pizzaMax, pizzaCost, margheritaPizzaIng, 2}
            ,{"Pepperoni Pizza", 4, pizzaMin, pizzaMax, pizzaCost, pepperoniPizzaIng, 2}
            ,{"Vegetarian Pizza", 4, pizzaMin, pizzaMax, pizzaCost, vegetarianPizzaIng, 6}
            ,{"Hawaiian Pizza", 4, pizzaMin, pizzaMax, pizzaCost, hawaiianPizzaIng, 4}
            ,{"BBQ Chicken Pizza", 4, pizzaMin, pizzaMax, pizzaCost, bbqChickenPizzaIng, 4}
            ,{"Mushroom Pizza", 4, pizzaMin, pizzaMax, pizzaCost, mushroomPizzaIng, 4}
            ,{"Buffalo Chicken Burger", 6, burgerMin, burgerMax, burgerCost, buffaloChickenBurgerIng, 4}
            ,{"Double Patty Burger", 6, burgerMin, burgerMax, burgerCost, doublePattyBurgerIng, 7}
            ,{"Bacon Avocado Burger", 6, burgerMin, burgerMax, burgerCost, baconAvocadoBurgerIng, 6}
            ,{"French Fries", 5, fryMin, fryMax, fryCost, frenchFriesIng, 2}
            ,{"Onion Rings", 5, fryMin, fryMax, fryCost, onionRingsIng, 2}
            ,{"Sweet Potato Fries", 5, fryMin, fryMax, fryCost, sweetPotatoFriesIng, 2}
            ,{"Caesar Salad", 9, saladMin, saladMax, saladCost, caesarSaladIng, 4}
            ,{"Greek Salad", 9, saladMin, saladMax, saladCost, greekSaladIng, 5}
            ,{"Caprese Salad", 9, saladMin, saladMax, saladCost, capreseSaladIng, 3}


            ,{"Apple Pie", 7, pastryMin, pastryMax, pastryCost, applePieIng, 3}
            ,{"Chocolate Croissant", 7, pastryMin, pastryMax, pastryCost, chocolateCroissantIng, 3}
            ,{"Danish Pastry", 7, pastryMin, pastryMax, pastryCost, danishPastryIng, 3}
            ,{"Eclair", 7, pastryMin, pastryMax, pastryCost, eclairIng, 4}
            ,{"Cinnamon Roll", 7, pastryMin, pastryMax, pastryCost, cinnamonRollIng, 3}
            
            

            ,{"Coca-Cola", 10, drinksMin, drinksMax, drinkCost, cocaColaIng, 1}
            ,{"Sprite", 10, drinksMin, drinksMax, drinkCost, spriteIng, 1}
            ,{"Iced Tea", 10, drinksMin, drinksMax, drinkCost, icedTeaIng, 1}
            ,{"Lemonade", 10, drinksMin, drinksMax, drinkCost, lemonadeIng, 3}
            ,{"Orange Juice", 10, drinksMin, drinksMax, drinkCost, orangeJuiceIng, 1}
            ,{"Cranberry Juice", 10, drinksMin, drinksMax, drinkCost, cranberryJuiceIng, 1}
            ,{"Grape Juice", 10, drinksMin, drinksMax, drinkCost, grapeJuiceIng, 1}
            ,{"Apple Juice", 10, drinksMin, drinksMax, drinkCost, appleJuiceIng, 1}
            ,{"Mango Smoothie", 10, drinksMin, drinksMax, drinkCost, mangoSmoothieIng, 2}
            ,{"Strawberry Banana Smoothie", 10, drinksMin, drinksMax, drinkCost, strawberryBananaSmoothieIng, 2}
            ,{"Espresso", 10, drinksMin, drinksMax, drinkCost, espressoIng, 1}
            
        };
        
