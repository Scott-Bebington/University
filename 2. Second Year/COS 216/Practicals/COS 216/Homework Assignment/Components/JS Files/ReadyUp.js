
var PortCheckButton = document.getElementById("PortCheckButton");
var PortInput = document.getElementById("PortInput");
var portNumber = 0;

function CheckPort() 
{
    var input = PortInput.value; // Get the trimmed value from the input field

    // Check if the input consists of only digits and is 4 or 5 characters long
    if (/^\d{4,5}$/.test(input) && input >= 1024 && input <= 49151) 
    {
        portNumber = parseInt(input); // Convert the input to an integer
        console.log("Valid port number:", portNumber);
        PortCheckButton.style.outline = "solid green";
    } 
    else 
    {
        alert("Invalid port number!\nPlease enter a port number between 1024 and 49151.");
        console.log("Invalid port number!");
    }
}