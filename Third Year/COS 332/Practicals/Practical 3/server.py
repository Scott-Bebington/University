import logging
import socket

from urllib.parse import urlparse

from home import resetPage, nextPage, prevPage, display_Page
import datetime

logging.basicConfig(filename='server.log', level=logging.INFO)
def serve():
    # Create a socket
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    
    # Bind the socket to localhost and port 55555
    server_socket.bind(('localhost', 55555))
    
    # Listen for incoming connections
    server_socket.listen(1)
    
    print("Server is listening on port 55555...")
    
    while True:
        # Accept a connection
        client_socket, client_address = server_socket.accept()
        # print(f"Request from {client_address} has been made.")

        request = client_socket.recv(1024).decode()
        parsed_request = urlparse(request)
        path = parsed_request.path

        if '/next' in path:
            print("Client requested the next digit in the sequence")
            nextPage()
            logging.info(f'{datetime.datetime.now()}: Getting the next value in the sequence')
        elif '/prev' in path:
            print("Client requested the previous digit in the sequence")
            prevPage()
            logging.info(f'{datetime.datetime.now()}: Getting the previous value in the sequence')
        elif '/reset' in path:
            print("Client requested to reset the sequence")
            resetPage()
            logging.info(f'{datetime.datetime.now()}: Resetting the sequence')
        
        # Handle the request
        display_Page(client_socket)
        client_socket.close()

if __name__ == "__main__":
    serve()

