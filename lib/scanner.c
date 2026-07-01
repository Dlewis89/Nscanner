#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#include "scanner.h"

int set_sockaddr(struct sockaddr_in *addr, const char *target_ip) {

    memset(addr, 0, sizeof(*addr));

    (*addr).sin_family = AF_INET;

    if (inet_pton(AF_INET, target_ip, &(*addr).sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    return 0;
}


int start_scan(struct sockaddr_in *addr, const char *target_ip, int starting_port, int ending_port) {
    
    if(set_sockaddr(addr, target_ip) == 1) {
        printf("failed to set sockaddr");
        return 1;
    }

    for(int port = starting_port; port <= ending_port; port++) {

        printf("\rScanning port %d", port);
        fflush(stdout);

        int sockfd = socket(AF_INET, SOCK_STREAM, 0);

        (*addr).sin_port = htons(port);

        if (sockfd == -1) {
            perror("socket");
            return 1;
        }

        int connection = connect(sockfd, (struct sockaddr *)addr, sizeof(*addr));

        if (connection == 0) {
            printf("\r\033[KPort %d is Open\n", port);
        }

        close(sockfd);
    }

    return 0;
}