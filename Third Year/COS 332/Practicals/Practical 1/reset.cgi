#!/usr/bin/python3

with open('numbers.txt', 'w') as output_file:
    output_file.write(f'0,1,1,0')

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
