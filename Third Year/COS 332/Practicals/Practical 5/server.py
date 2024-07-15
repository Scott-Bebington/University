# Authors
#   - Scott Bebington u21546216
#   - Timothy Whitaker

import socket

def compile_request(input_string):
    # create the byte string that will be sent to the server
    

    # if there is a . in the input string, split the string and get the first part
    if "." in input_string:
        input_string = input_string.split(".")[0]
        
    # print(f"Input String: {input_string}")
    
    # get the length of the request
    length = len(input_string) + 74
    byteLength = length.to_bytes(1, byteorder='big')
    requestLength = b'\x30' + byteLength

    # print(f"Byte String: {requestLength}")

    header1 = b'\x02\x01\x02\x63'

    # 69 + the length of the name of the university
    length = len(input_string) + 69
    byteLength = length.to_bytes(1, byteorder='big')
    header2 = byteLength + b'\x04'
    length = len(input_string) + 15
    byteLength = length.to_bytes(1, byteorder='big')
    header2 += byteLength

    # Standard LDAP message header
    header3 = b'\x6f\x75\x3d'
    # print(f"Input String: {input_string}")

    totalBytes = requestLength + header1 + header2 + header3 + input_string.encode('utf-8')

    totalBytes += (
    b'\x2c\x64\x63\x3d\x61\x63\x2c\x64\x63\x3d\x7a\x61\x0a\x01\x02\x0a\x01\x00'
    b'\x02\x01\x00\x02\x01\x00\x01\x01\x00\xa3\x21\x04\x0b\x6f\x62\x6a'
    b'\x65\x63\x74\x43\x6c\x61\x73\x73\x04\x12\x6f\x72\x67\x61\x6e\x69'
    b'\x7a\x61\x74\x69\x6f\x6e\x61\x6c\x55\x6e\x69\x74\x30\x00')

    # print(f"Byte String: {requestLength}{header1}{header2}{header3}{header4}")

    return totalBytes

def format_request(request):
    print()
    string_request = str(request)
    string_request = string_request.replace("b'", '')
    string_request = string_request.replace("'", '')

    stringArray = string_request.split("x04")
    finalArray = []
    
    for index, string in enumerate(stringArray):
        try:
            string = string.replace("\\x", '')

            # store the first 2 characters
            first = string[0:2]

            # convert the characters from hex to decimal
            first = int(string[0:2], 16)

            # remove the first 2 characters from the string
            string = string[2:]

            string = string[0:first]

            if index == 9: 
                finalArray.insert(0,string)
            if index == 1:
                equalSplit = string.split(",")
                tempString = ""
                for index, string in enumerate(equalSplit):
                    tempString += string[3:] + "."
                tempString = tempString[0:len(tempString)-1]
                finalArray.append(tempString)
            if index == 10: 
                finalArray.append(string)
            if index == 11:
                finalArray.append(string)

        except:
            pass

    return finalArray

def checkUniversities(input_string):
    # Establish connection to LDAP server
    ldap_server = '127.0.0.1'
    ldap_port = 389
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect((ldap_server, ldap_port))

    # Send the LDAP bind request
    bind_request = b'\x30\x0c\x02\x01\x01\x60\x07\x02\x01\x03\x04\x00\x80\x00'
    sock.sendall(bind_request)

    # Receive the LDAP bind response
    bind_response = sock.recv(4096)

    if input_string == "up" or input_string == "up.ac.za":
        sock.sendall(compile_request(input_string))
        response = sock.recv(4096)
        # print(response)

        # format the response
        responseArr = format_request(response)

        for string in responseArr:
            print(string)
        print()    
    elif input_string == "wits" or input_string == "wits.ac.za":
        sock.sendall(compile_request(input_string))
        response = sock.recv(4096)
        # print(response)

        # format the response
        responseArr = format_request(response)
        responseArr.append("146.141.13.50")

        for string in responseArr:
            print(string)
        print() 
    elif input_string == "uct" or input_string == "uct.ac.za":
        sock.sendall(compile_request(input_string))
        response = sock.recv(4096)
        # print(response)

        # format the response
        responseArr = format_request(response)
        responseArr.insert(0, "University of Cape Town")

        for string in responseArr:
            print(string)
        print()


    # Close connection
    sock.close()

if __name__ == '__main__':
    input_string = input("What are you looking for?")

    compile_request(input_string)

    if input_string == "ac":
        checkUniversities("up")
        checkUniversities("wits")
        checkUniversities("uct")
    else:
        checkUniversities(input_string)

