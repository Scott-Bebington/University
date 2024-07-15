def resetPage():
    with open('numbers.txt', 'w') as output_file:
        output_file.write(f'0,1,1,0')

def nextPage():
    # Open the text file in read mode
    with open('numbers.txt', 'r') as input_file:
        # Read the contents of the file
        file_contents = input_file.read()

        num1 = int(file_contents.split(",")[0])
        num2 = int(file_contents.split(",")[1])
        num3 = int(file_contents.split(",")[2])
        num4 = int(file_contents.split(",")[3])

        num1 = num2
        num2 = num3
        num3 = num1 + num2
        num4 += 1


        with open('numbers.txt', 'w') as output_file:
            output_file.write(f'{num1},{num2},{num3},{num4}')

def prevPage():
    # Open the text file in read mode
    with open('numbers.txt', 'r') as input_file:
        # Read the contents of the file
        file_contents = input_file.read()

        num1 = int(file_contents.split(",")[0])
        num2 = int(file_contents.split(",")[1])
        num3 = int(file_contents.split(",")[2])
        num4 = int(file_contents.split(",")[3])

        if num1 != 0:


            temp = num2 - num1

            num3 = num2
            num2 = num1
            num1 = temp

            num4 -= 1

            with open('numbers.txt', 'w') as output_file:
                output_file.write(f'{num1},{num2},{num3},{num4}')

def display_Page(client_socket):
    num1 = 0
    num2 = 1
    num3 = 1
    num4 = 0

    try:
        with open('numbers.txt', 'r') as input_file:
            file_contents = input_file.read()
            num1, num2, num3, num4 = map(int, file_contents.split(","))
    except FileNotFoundError:
        print("File not found")
    except Exception as e:
        print("An error occurred:", str(e))

    # Construct the HTTP response
    response = b"HTTP/1.1 200 OK\r\n"
    response += b"Content-Type: text/html; charset=utf-8\r\n"
    response += b"\r\n"
    response += b"<html>"
    response += b"<head>"
    response += b"    <meta charset=\"UTF-8\">"
    response += b"    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"
    response += b"    <title>Document</title>"
    response += b"    <link href=\"https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css\" rel=\"stylesheet\" integrity=\"sha384-9ndCyUaIbzAi2FUVXJi0CjmCapSmO7SnpJef0486qhLnuZ2cdeRhO02iuK6FUUVM\" crossorigin=\"anonymous\">"
    response += b"</head>"
    response += b"<body>"
    response += b"    <div class=\"background\">"
    response += b"        <h4>"
    response += b"            <h1 class=\"text-center text-light\">Fibonacci sequence generator</h1>"
    response += b"            <h4 class=\"text-center text-light\">showing values: "
    response += str(num4 + 1).encode()
    response += b" - "
    response += str(num4 + 3).encode()
    response += b"            </h4>"
    response += b"            <div class=\"Custom_Row\">"
    response += b"                <a class=\"Custom_Button Prev\" href=\"prev\">Previous</a>"
    response += b"                <div class=\"Numbers\">"
    response += str(num1).encode()
    response += b" - "
    response += str(num2).encode()
    response += b" - "
    response += str(num3).encode()
    response += b"                </div>"
    response += b"                <a class=\"Custom_Button Prev\" href=\"next\">Next</a>"
    response += b"            </div>"
    response += b"            <button class=\"Custom_Button_Reset\" onclick=\"window.location.href='reset'\">Reset</button>"
    response += b"        </div>"
    response += b"    </div>"
    response += b"</body>"
    response += b"""
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
    """
    response += b"</html>"

    # Send the response to the client
    client_socket.sendall(response)