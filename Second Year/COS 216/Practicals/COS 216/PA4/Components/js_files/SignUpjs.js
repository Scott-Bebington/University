function GoToPage() {
    window.location.href = "./login.php";
}

var Name = document.getElementById("Name");
var Surname = document.getElementById("Surname");
var Email = document.getElementById("Email");
var Password = document.getElementById("Password");

const emailRegex = /^[^\s@]+@[^\s@]+.[^\s@]+$/;
const upperCaseLettersRegex = /[A-Z]/;
const lowerCaseLettersRegex = /[a-z]/;
const specialCharacterRegex = /[^\w\s]/;
const numberCharacterRegex = /\d+/;

function ValidateInfo() 
{
    // Check if input fields are valid
    let checks = "Please make sure that.\n";

    if (Email.value == '') {
        checks += "Email: Must be filled in.\n";
    } else if (!emailRegex.test(Email.value)) 
    {
        checks += "Email: Must contain @ symbol.\n";
    }

    if (Password.value == '') 
    {
        checks += "Password: Must be filled in.\n";
    } 
    else 
    {
        if (!upperCaseLettersRegex.test(Password.value)) 
        {
            checks += "Password: Must contain at least 1 Upper case letter.\n";
        }
        if (!lowerCaseLettersRegex.test(Password.value)) 
        {
            checks += "Password: Must contain at least 1 Lower case letter.\n";
        }
        if (!specialCharacterRegex.test(Password.value)) 
        {
            checks += "Password: Must contain at least 1 Special character.\n";
        }
        if (!numberCharacterRegex.test(Password.value)) 
        {
            checks += "Password: Must contain at least 1 Number.\n";
        }
        if (Password.value.length > 8) 
        {
            checks += "Password: Must be less than 8 digits long.\n";
        }
    }

    console.log(checks);
    console.log(checks.length);



    if (checks.length == 23) 
    {
        
        return true;
    }
    else
    {
        alert (checks + '\nClick either to redirect to the Sign up page.');
        return false;
    }
}