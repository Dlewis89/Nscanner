#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#include "scanner.h"

Scanner *scanner_init(const char *target_ip) {
    Scanner *scanner = malloc(sizeof(*scanner));
    if (scanner == NULL) {
        return NULL;
    }

    struct sockaddr_in addr;

    memset(&addr, 0, sizeof(addr));

    addr.sin_family = AF_INET;

    if (inet_pton(AF_INET, target_ip, &addr.sin_addr) <= 0) {
        scanner->status = INVALID_TARGET_IP;
    }

    scanner->addr = addr;

    return scanner;
}

int set_scanner_port(Scanner *scanner, int starting_port, int ending_port) {
    if (starting_port < 1 || starting_port > 65535 || ending_port < 1 || ending_port > 65535 || starting_port > ending_port) {
        scanner->status = INVALID_SCANNER_PORT;
    }
 
    scanner->starting_port = starting_port;
    scanner->ending_port = ending_port;
 
    return 0;
}

// Todo Need to refactor this function. just need to know connect to socket successfully or not and remove all printf and add custom error handling.
int scanner_scan_port(Scanner *scanner, int port) {

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    scanner->addr.sin_port = htons(port);

    if (sockfd == -1) {
        scanner->status = INVALID_SCANNER_SOCK_DESCRIPTOR;
    }

    int connection = connect(sockfd, (struct sockaddr *)&scanner->addr, sizeof(scanner->addr));
    close(sockfd);

    if (connection != 0) { 
        return 1;
    }

    return 0;
}

void scanner_destroy(Scanner *scanner) {
    if (scanner != NULL) {
        free(scanner);
    }
}
    