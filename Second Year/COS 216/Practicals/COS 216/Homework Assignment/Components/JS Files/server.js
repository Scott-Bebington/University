var wS = require('ws');

const server = new wS.Server({ port: 8081 });
var clients = [];
var Users = ["...", "..."];
var ConnectedCount = 0;
var uniqueNumbers = [];
countUsers = 0;

server.on('connection', (ws) => 
{
  console.log('New connection');
  ConnectedCount++;
  console.log('ConnectedCount: ' + ConnectedCount);
  clients.push(ws);

  // Add connection to array for future use
  ws.on('message', (message) => 
  {
    let DecodedData = JSON.parse(message);
    if(DecodedData.type == "Ready")
    {
      // console.log('Received: ' + message);
      
      if(ConnectedCount == 2)
      {
        GetRandomNumbers();
        GoToGame();
      }
    }
    else if(DecodedData.type == "GetRandomNumbers")
    {
      GetRandomNumbers();
    }
    else if(DecodedData.type == "GetPlayers")
    {
      GetPlayers();
    }
    else if(DecodedData.type == "SetPlayers")
    {
      SetPlayers(DecodedData.data);
    }
    else if(DecodedData.type == "SetBrandCompleteOp")
    {
      SetCompleteOp(DecodedData.data, DecodedData.score);
    }
    else if(DecodedData.type == "SetBrandCompleteMe")
    {
      SetCompleteMe(DecodedData.data, DecodedData.score);
    }
    else if(DecodedData.type == "GameOver")
    {
      GameOver();
    }
  });

  // Remove the client from the array
  ws.on('close', () => 
  {
    console.log('Disconnect');
    var i = clients.indexOf(ws);
    if (i > -1) 
    {
      clients.splice(i, 1);
    }
    ConnectedCount--;
    console.log('ConnectedCount: ' + ConnectedCount);
    for (let i = 0; i < clients.length; i++) 
    {
      let sendData = 
      {
        "type": "Disconnected",
        "data": "none"
      }
      var jsonData = JSON.stringify(sendData);
      clients[i].send(jsonData);
    }
    console.log('Disconnected message sent');
  });
});

function GoToGame()
{
  
  for (var i = 0; i < clients.length; i++) 
  {
    let sendData = 
    {
      "type": "GoToGame",
      "data": "none"
    }
    var jsonData = JSON.stringify(sendData);
    clients[i].send(jsonData);
  }
}

generateRandomNumbers();
function generateRandomNumbers()
{
  while (uniqueNumbers.length < 5) 
  {
      let randomBrand = Math.floor(Math.random() * 60) + 1;
      if (!uniqueNumbers.includes(randomBrand)) 
      {
        uniqueNumbers.push(randomBrand);
      }
  }
}

function GetRandomNumbers()
{
  let sendData = 
  {
    "type": "GetRandomNumbers",
    "data": uniqueNumbers
  }
  var jsonData = JSON.stringify(sendData);
  for (var i = 0; i < clients.length; i++) 
  {
    // console.log("Clients [" + i + "] : " + clients[i]);
    clients[i].send(jsonData);
  }
  
}

function SetPlayers(Message)
{
  // console.log("Message: " + Message);
  Users[countUsers] = '' + Message + '';
  countUsers++;
}

function GetPlayers()
{
  for (var i = 0; i < clients.length; i++) 
  {
    let sendData = 
    {
      "type": "GetPlayers",
      "data": Users
    }
    var jsonData = JSON.stringify(sendData);
    clients[i].send(jsonData);
  }
}

function SetCompleteOp(count, score)
{
  let sendData = 
  {
    "type": "SetCompleteOp",
    "data": count,
    "score": score
  }
  var jsonData = JSON.stringify(sendData);
  clients[0].send(jsonData);
}

function SetCompleteMe(count, score)
{
  let sendData = 
  {
    "type": "SetCompleteMe",
    "data": count,
    "score": score
  }
  var jsonData = JSON.stringify(sendData);
  clients[1].send(jsonData);
}

function GameOver()
{
  for (var i = 0; i < clients.length; i++) 
  {
    let sendData = 
    {
      "type": "GameOver",
    }
    var jsonData = JSON.stringify(sendData);
    clients[i].send(jsonData);
  }
}





