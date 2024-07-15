// Ronan van de Vyver

// This socket server is for use only with the tutorial on Sockets.
// It accepts a connection on port 8081, and if sent a number
// it will broadcast that number to all connected clients.
// The number is an angle in degrees, from 0 to 360.

var wS = require('ws');

var angle = 0;
const server = new wS.Server({ port: 8081 });
var clients = [];
var Test = [];
var count = 0;

server.on('connection', (ws) => 
{
  console.log('New connection');
  ws.send(angle.toString());
  clients.push(ws);

  if (count == 0) 
  {
    Test.push("Scott");
    count++;
  }
  else 
  {
    Test.push("Kyla");
  }

  // Add connection to array for future use
  ws.on('message', (message) => 
  {
    if (!isNaN(message)) 
    {
      console.log('Received: ' + message);
      // If it is a number, update angle and send to clients
      console.log(Test[clients.indexOf(ws)] + " " + message);
      setAngle(message, ws);
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
  });
});

// For all connected clients, send the angle after updating it
function setAngle(nAngle, sourceClient) 
{
  console.log('Angle: ' + nAngle + ', Source: ' + Test[clients.indexOf(sourceClient)]);
  angle = nAngle % 360;
  for (var i = 0; i < clients.length; i++) 
  {
    clients[i].send(angle.toString());
    console.log('Sent to: ' + Test[i]);
  }
}
