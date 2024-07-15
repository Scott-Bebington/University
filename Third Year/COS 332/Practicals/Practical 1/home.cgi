#!/usr/bin/python3

num1 = 0
num2 = 1
num3 = 1
num4 = 0

# Open the text file in write mode
with open('numbers.txt', 'r') as input_file:
    # Read the contents of the file
    file_contents = input_file.read()
    num1 = int(file_contents.split(",")[0])
    num2 = int(file_contents.split(",")[1])
    num3 = int(file_contents.split(",")[2])
    num4 = int(file_contents.split(",")[3])

def styling():
    print("""
    <style>
    .background {
        background-color: #000000;
        height: 100vh;
        width: 100vw;
        display: grid;
        place-items: center;
    }

    .Custom_Button {
        width: 10vw;
        height: 5vh;
        border: 2px solid #ffffff;
        border-radius: 5px;
        background-color: #000000;
        color: #ffffff;
        transition: 0.5s ease-in;
        text-decoration: none;
        text-align: center;
    }

    .Custom_Button:hover {
        background-color: #ffffff;
        color: #000000;
    }

    .Custom_Button_Reset {
        width: 50vw;
        border: 2px solid #ffffff;
        border-radius: 5px;
        background-color: #000000;
        color: #ffffff;
        transition: 0.5s ease-in;
        text-decoration: none;
        text-align: center;
        font-size: 2vh;
        margin-top: 2vh;
    }

    .Custom_Button_Reset:hover {
        background-color: #ff0000;
        color: #ffffff;
        border: 2px solid transparent;
    }

    .Custom_Row {
        display: flex;
        justify-content: space-between;
        align-items: center;
        width: 50vw;
        /* background-color: white; */
    }

    .Numbers {
        color: #ffffff;
        font-size: 2.5vw;
    }
    </style>
    """)

print(f"Content-type: text/html\n\n")
print(f"<!DOCTYPE html>")
print(f'<html lang="en">')
print(f"<head>")
print(f'    <meta charset="UTF-8">')
print(f'    <meta name="viewport" content="width=device-width, initial-scale=1.0">')
print(f"    <title>Document</title>")
print(f'    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet"')
print(f'        integrity="sha384-9ndCyUaIbzAi2FUVXJi0CjmCapSmO7SnpJef0486qhLnuZ2cdeRhO02iuK6FUUVM" crossorigin="anonymous">')
print(f"</head>")
print(f"<body>")
print(f'    <div class="background">')
print(f'        <div>')
print(f'            <h1 class="text-center text-light">Fibonacci sequence generator</h1>')
print(f'            <h4 class="text-center text-light">showing values: {num4 + 1} - {num4 + 3}</h4>')
print(f'            <br><br><div class="Custom_Row">')
print(f'                <a class="Custom_Button Prev" href="prev.cgi">Previous</a>')
print(f'                <div class="Numbers">{num1} - {num2} - {num3}</div>')
print(f'                <a class="Custom_Button Prev" href="next.cgi">Next</a>')
print(f"            </div>")
print(f'            <button class="Custom_Button_Reset" onclick="window.location.href=\'reset.cgi\'">Reset</button>')
print(f"        </div>")
print(f"    </div>")
print(f"</body>")
styling()
print(f"</html>")


