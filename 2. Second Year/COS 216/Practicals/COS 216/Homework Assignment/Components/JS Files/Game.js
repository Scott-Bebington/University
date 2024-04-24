var timerElement = document.getElementById("BrandImage");

var ImageArray = ["1", "2", "3", "4", "5"];
var BrandArray = ["1", "2", "3", "4", "5"];

var ScreenShowing = document.getElementById("Screen");
var Test = document.getElementById("Test");
var BrandInput = document.getElementById("BrandInput");
var GameOver = document.getElementById("Timer");
var Timer = document.getElementById("app");
var SubmitButton = document.getElementById("Submit");
var StartText = document.getElementById("StartText");

var uniqueNumbers = [];
var Users = [];
var socket;
const queryString = window.location.search;
const urlParams = new URLSearchParams(queryString);
const username = urlParams.get("username");
const portNumber = urlParams.get("portNumber");

const usernameSpan = document.getElementById("username");
const OpusernameSpan = document.getElementById("Opusername");


function Countdown()
{
  BrandInput.hidden = true;
  Timer.hidden = true;
  SubmitButton.hidden = true;
  
  setTimeout(function () 
  {
    Test.hidden = true;
    // ScreenShowing.hidden = false;
    BrandInput.hidden = false;
    Timer.hidden = false;
    SubmitButton.hidden = false;
    StartText.innerHTML = "Good Luck!";
    LoadBrands();
  }, 4500);
}


function LoadBrands() 
{
  let apiRequestsCompleted = 0;
  for (let i = 0; i < 5; i++) 
  {
    let x = 
    {
      "type": "GetBrands",
      "BrandID": uniqueNumbers[i]
    };
    ApiRequest(x, i, function() 
    {
      apiRequestsCompleted++;
      if (apiRequestsCompleted === uniqueNumbers.length) 
      {
        // console.log("Brands Populated")
        for (let index = 0; index < 5; index++) 
        {
          // console.log(ImageArray[index]);
          // console.log(BrandArray[index]);
        }
        console.log("Beginning Game");
        console.log("User 1: " + Users[0]);
        console.log("User 2: " + Users[1]);
        BrandGame();
        startTimer();
      }
    });
    
  }
  setTimeout(function () 
  {
    console.log("Game Over");
    GameOver.innerHTML = "Game Over!";
    clearInterval(timerInterval);
    return;
  }, 45000);
}

function ApiRequest(Request, index, callback) 
{
  const xhttp = new XMLHttpRequest();
  xhttp.onload = function() 
  {
    let JSONResponse = JSON.parse(this.responseText);
    ImageArray[index] = JSONResponse.data[0].BrandImage;
    BrandArray[index] = JSONResponse.data[0].BrandName;
    callback();
  };

  xhttp.open("POST", "https://wheatley.cs.up.ac.za/u21546216/COS%20216/Homework%20Assignment/BrandsAPI.php", true);
  xhttp.send(JSON.stringify(Request));
}

function BrandGame()
{
  console.log("");
  console.log(BrandArray[count].toLocaleUpperCase());
  TimeTakenArray[TimeTakenCount] = Date.now();
  console.log("Timestamp start of guess: " + TimeTakenArray[TimeTakenCount]);
  
  timerElement.style.backgroundImage = "url('" + ImageArray[count] + "')";
  timerElement.style.backgroundSize = "contain";
  timerElement.style.backgroundRepeat = "no-repeat";
  timerElement.style.backgroundPosition = "center";
}





document.addEventListener("keydown", function(event) 
{
  if (event.key === "Enter") 
  {
    CheckBrand();
  }
});





var TimeTakenArray = [0, 0, 0, 0, 0, 0];
var TimeTakenCount = 0;
var count = 0;
var SideBar = document.getElementsByClassName("MyBrand");
var MyScore = document.getElementById("MyScore");
var RunningScore = 0;
var OpSideBar = document.getElementsByClassName("OpBrand");
var OpScore = document.getElementById("OpScore");
var OpRunningScore = 0;


function CheckBrand()
{
  let brandinput = BrandInput.value.replace(" ", "");
  let brandoutput = BrandArray[count].replace("-", "");
  if(brandinput.toLowerCase() == brandoutput.toLowerCase())
  {
    TimeTakenCount++;
    TimeTakenArray[TimeTakenCount] = Date.now();
    console.log("Timetaken to guess: " + (TimeTakenArray[TimeTakenCount] - TimeTakenArray[TimeTakenCount - 1]) + "ms");
    let score = Math.floor(90 - ((TimeTakenArray[TimeTakenCount] - TimeTakenArray[TimeTakenCount - 1]) / 100));
    console.log("Score for " + BrandArray[count] + ": " + score + " points");
    
    count++;
    BrandInput.value = "";
    

    console.log("Timestamp end of guess: " + TimeTakenArray[TimeTakenCount]);






    if(Users[0] == username)
    {
      if(score > 0)
      {
        RunningScore += score;
        MyScore.innerHTML = "Score: " + RunningScore;
      }
      console.log("My Correct");
      SideBar[count - 1].innerHTML = "Brand " + (count) + ": Complete";
      let sendData = 
      {
        "type": "SetBrandCompleteMe",
        "data": count,
        "score": RunningScore
      }
      var jsonData = JSON.stringify(sendData);
      socket.send(jsonData);
    }
    else
    {
      if(score > 0)
      {
        RunningScore += score;
        OpScore.innerHTML = "Score: " + RunningScore;
      }
      console.log("Opponent Correct");
      OpSideBar[count - 1].innerHTML = "Brand " + (count) + ": Complete";
      let sendData = 
      {
        "type": "SetBrandCompleteOp",
        "data": count,
        "score": RunningScore
      }
      var jsonData = JSON.stringify(sendData);
      socket.send(jsonData);
      
    }
    if(count != 5)
    {
      BrandGame();
    }
    else
    {
      console.log("Game Over");
      clearInterval(timerInterval);
      let sendData = 
      {
        "type": "GameOver",
        "data": "none"
      }
      var jsonData = JSON.stringify(sendData);
      socket.send(jsonData);
      
      return;
    }
  }
  else
  {
    BrandInput.value = "Incorrect!";
  }
}

BrandInput.addEventListener("click", function(event) 
{
  BrandInput.value = "";
});







const FULL_DASH_ARRAY = 283;
const WARNING_THRESHOLD = 15;
const ALERT_THRESHOLD = 5;

const COLOR_CODES = {
  info: {
    color: "green"
  },
  warning: {
    color: "orange",
    threshold: WARNING_THRESHOLD
  },
  alert: {
    color: "red",
    threshold: ALERT_THRESHOLD
  }
};

const TIME_LIMIT = 45;
let timePassed = 0;
let timeLeft = TIME_LIMIT;
let timerInterval = null;
let remainingPathColor = COLOR_CODES.info.color;

document.getElementById("app").innerHTML = `
<div class="base-timer">
  <svg class="base-timer__svg" viewBox="0 0 100 100" xmlns="http://www.w3.org/2000/svg">
    <g class="base-timer__circle">
      <circle class="base-timer__path-elapsed" cx="50" cy="50" r="45"></circle>
      <path
        id="base-timer-path-remaining"
        stroke-dasharray="283"
        class="base-timer__path-remaining ${remainingPathColor}"
        d="
          M 50, 50
          m -45, 0
          a 45,45 0 1,0 90,0
          a 45,45 0 1,0 -90,0
        "
      ></path>
    </g>
  </svg>
  <span id="base-timer-label" class="base-timer__label">${formatTime(
    timeLeft
  )}</span>
</div>
`;


function onTimesUp() {
  clearInterval(timerInterval);
}

function startTimer() 
{
  clearInterval(timerInterval);
  
  // Reset variables
  timerInterval = null;
  timePassed = 0;
  timeLeft = TIME_LIMIT;
  remainingPathColor = COLOR_CODES.info.color;

  timerInterval = setInterval(() => {
    timePassed = timePassed += 1;
    timeLeft = TIME_LIMIT - timePassed;
    document.getElementById("base-timer-label").innerHTML = formatTime(
      timeLeft
    );
    setCircleDasharray();
    setRemainingPathColor(timeLeft);

    if (timeLeft === 0) {
      onTimesUp();
    }
  }, 1000);
}

function formatTime(time) {
  const minutes = Math.floor(time / 60);
  let seconds = time % 60;

  if (seconds < 10) {
    seconds = `0${seconds}`;
  }

  return `${minutes}:${seconds}`;
}

function setRemainingPathColor(timeLeft) {
  const { alert, warning, info } = COLOR_CODES;
  if (timeLeft <= alert.threshold) {
    document
      .getElementById("base-timer-path-remaining")
      .classList.remove(warning.color);
    document
      .getElementById("base-timer-path-remaining")
      .classList.add(alert.color);
  } else if (timeLeft <= warning.threshold) {
    document
      .getElementById("base-timer-path-remaining")
      .classList.remove(info.color);
    document
      .getElementById("base-timer-path-remaining")
      .classList.add(warning.color);
  }
}

function calculateTimeFraction() {
  const rawTimeFraction = timeLeft / TIME_LIMIT;
  return rawTimeFraction - (1 / TIME_LIMIT) * (1 - rawTimeFraction);
}

function setCircleDasharray() {
  const circleDasharray = `${(
    calculateTimeFraction() * FULL_DASH_ARRAY
  ).toFixed(0)} 283`;
  document
    .getElementById("base-timer-path-remaining")
    .setAttribute("stroke-dasharray", circleDasharray);
}

