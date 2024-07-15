const requirementsDiv = document.getElementById("Requirements"); // Get the div element by its ID
const requirementsList = requirementsDiv.getElementsByTagName("li"); // Get all the li elements inside the div
const usernameInput = document.querySelector(".UsernameInput"); // Get the username input element
const submitbutton = document.getElementById("Submit");
const generatebutton = document.getElementById("Generate");

generatebutton.classList.add("ButtonAccept");
submitbutton.classList.add("ButtonReject");

usernameInput.addEventListener("input", function () 
{
    checkRequirements();
});

function checkRequirements() {
    const username = usernameInput.value;

    let allRequirementsMet = true;

    for (let i = 0; i < requirementsList.length; i++) {
        const liText = requirementsList[i].innerHTML;
        const isValid = checkCriteria(liText, username);

        if (isValid) {
            requirementsList[i].classList.remove("Incorrect");
            requirementsList[i].classList.add("Correct");
        }
        else {
            requirementsList[i].classList.remove("Correct");
            requirementsList[i].classList.add("Incorrect");
            allRequirementsMet = false;
        }
    }

    if (allRequirementsMet) {
        submitbutton.classList.remove("ButtonReject");
        submitbutton.classList.add("ButtonAccept");
    }
    else {
        submitbutton.classList.remove("ButtonAccept");
        submitbutton.classList.add("ButtonReject");
    }
}

function checkCriteria(criteria, value) {
    switch (criteria) {
        case "Must be between 5 and 20 characters":
            return value.length >= 5 && value.length <= 20;
        case "Must contain at least 1 upper-case letter":
            return /[A-Z]/.test(value);
        case "Must contain at least 1 lower-case letter":
            return /[a-z]/.test(value);
        case "Must contain at least 1 number":
            return /[0-9]/.test(value);
        default:
            return false;
    }
}

// Add the Incorrect class to each li element by default
for (let i = 0; i < requirementsList.length; i++) {
    requirementsList[i].classList.add("Incorrect");
}

function generateRandomUsername() {
    const uppercaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const lowercaseChars = "abcdefghijklmnopqrstuvwxyz";
    const numberChars = "0123456789";
    const chars = [];
    let username = "";
  
    // Add required characters to the character pool
    const uppercaseIndex = Math.floor(Math.random() * 10);
    const lowercaseIndex = Math.floor(Math.random() * 10);
    const numberIndex = Math.floor(Math.random() * 10);
    
    for (let i = 0; i < 10; i++) {
      if (i === uppercaseIndex) {
        chars.push(uppercaseChars);
      } else if (i === lowercaseIndex) {
        chars.push(lowercaseChars);
      } else if (i === numberIndex) {
        chars.push(numberChars);
      } else {
        chars.push(uppercaseChars + lowercaseChars + numberChars);
      }
    }
  
    // Generate a random username of the specified length from the character pool
    for (let i = 0; i < 10; i++) {
      const randomIndex = Math.floor(Math.random() * chars[i].length);
      username += chars[i][randomIndex];
    }
  
    usernameInput.value = username;
}

generatebutton.addEventListener("click", () => {
    generateRandomUsername();
    checkRequirements();
});

submitbutton.addEventListener("click", function () {
    const username = usernameInput.value;
    let isValid = true;

    for (let i = 0; i < requirementsList.length; i++) {
        const liText = requirementsList[i].innerHTML;
        isValid = isValid && checkCriteria(liText, username);

        if (isValid) {
            requirementsList[i].classList.remove("Incorrect");
            requirementsList[i].classList.add("Correct");
        }
        else {
            requirementsList[i].classList.remove("Correct");
            requirementsList[i].classList.add("Incorrect");
        }
    }

    if (isValid) 
    {
        const url = "./ReadyUp.html?username=" + encodeURIComponent(username);
        window.location.href = url;
    }
});


// submitbutton.addEventListener("click", submitForm);
