// server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error("socket failed");
    }

    // Binding the socket to the port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        close(server_fd);
        error("bind failed");
    }

    // Listening for connections
    if (listen(server_fd, 3) < 0) {
        close(server_fd);
        error("listen failed");
    }

    printf("Server listening on port %d\n", PORT);

    // Accepting incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        close(server_fd);
        error("accept failed");
    }

    // Reading and echoing back messages
    int valread;
    while ((valread = read(new_socket, buffer, BUFFER_SIZE)) > 0) {
        printf("Received: %s\n", buffer);
        send(new_socket, buffer, valread, 0);
        memset(buffer, 0, BUFFER_SIZE);
    }

    if (valread < 0) {
        close(new_socket);
        close(server_fd);
        error("read failed");
    }

    // Closing the socket
    close(new_socket);
    close(server_fd);

    return 0;
}

