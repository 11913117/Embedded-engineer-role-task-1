# Embedded-engineer-role-task-1

# TCP/IP Socket Programming in C

## Description

This project consists of a client-server application using TCP/IP sockets in C. The server listens for incoming connections and echoes back any messages received from the client. The client connects to the server, sends a message, and displays the echoed message from the server.

## Files

- `server.c`: Source code for the server program.
- `client.c`: Source code for the client program.

## Instructions for Compiling and Running the Programs

### Step 1: Compile the Server and Client Programs

Open a terminal and run the following commands to compile the server and client programs:

gcc -o server server.c
gcc -o client client.c

### Step 2: Run the Server Program
In the terminal, run the server program:

./server

You should see output indicating that the server is listening on port 8080:

Server listening on port 8080

### Step 3: Run the Client Program
Open a new terminal window and run the client program:

./client

You should see output indicating that the client has sent a message and received an echoed message from the server:

Message sent: Hello from client
Echoed message: Hello from client

## Brief Documentation

### Server Program (server.c)

1. Includes and Defines: Standard libraries and defines for port and buffer size.
2. Error Handling: Function error prints the error message and exits.
3. Socket Creation: Creates a TCP socket.
4. Binding: Binds the socket to a local port.
5. Listening: Listens for incoming connections.
6. Accepting Connections: Accepts an incoming connection from a client.
7. Echoing Messages: Reads messages from the client and echoes them back.
8. Closing Socket: Closes the socket when done.

### Client Program (client.c)

1. Includes and Defines: Standard libraries and defines for port and buffer size.
2. Error Handling: Function error prints the error message and exits.
3. Socket Creation: Creates a TCP socket.
4. Connecting to Server: Connects to the server at the specified IP and port.
5. Sending Messages: Sends a message to the server.
6. Receiving Messages: Receives the echoed message from the server.
7. Closing Socket: Closes the socket when done.

## Troubleshooting

### Connection Issues

If the client program gives a "connection failed: connection refused" error, try the following steps:

1. Ensure the server is running: Make sure the server program is running before starting the client.

2. Check the server's output: The server should print "Server listening on port 8080". If you don't see this message, the server might not be starting correctly.

3. Verify the server is listening on the correct port: Use the netstat or ss command to verify that the server is listening on port 8080:

sudo netstat -tuln | grep 8080
# or
sudo ss -tuln | grep 8080

4. Firewall settings: Ensure that no firewall is blocking the connection to port 8080:

sudo ufw allow 8080/tcp

5. Correct IP address: Make sure the client is using the correct IP address to connect to the server. If the server and client are on the same machine, 127.0.0.1 is correct. Otherwise, use the server machine's IP address.

### Elevated Privileges

If you still encounter issues, try running the client and server with elevated privileges (e.g., using sudo) to rule out any permission issues.
