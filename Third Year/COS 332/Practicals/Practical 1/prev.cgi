#!/usr/bin/python3

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

print(f"Content-type: text/html\n\n")
print(f'<html')
print(f"<head>")
print(f'    <meta charset="UTF-8">')
print(f'    <meta name="viewport" content="width=device-width, initial-scale=1.0">')
print(f"    <title>COS 332 Prac 1</title>")
print(f"</head>")
print(f'<body  onload="window.location.href=\'home.cgi\'">')
print(f"</body>")
print(f"</html>")
