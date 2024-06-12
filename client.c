// client.c
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
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("socket creation error");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Converting IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        close(sock);
        error("invalid address / address not supported");
    }

    // Connecting to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        close(sock);
        error("connection failed");
    }

    // Sending a message to the server
    const char *hello = "Hello from client";
    send(sock, hello, strlen(hello), 0);
    printf("Message sent: %s\n", hello);

    // Receiving the echoed message from the server
    int valread = read(sock, buffer, BUFFER_SIZE);
    if (valread < 0) {
        close(sock);
        error("read failed");
    }
    printf("Echoed message: %s\n", buffer);

    // Closing the socket
    close(sock);

    return 0;
}

