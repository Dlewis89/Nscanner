#include <stdio.h>
#include <sys/socket.h>
#include <errno.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "scanner.h"

int main(int argc, char** argv) {

    const char* target_ip = "127.0.0.1";
    int starting_port = 1;
    int ending_port = 65535; 

    if ( argc >= 2) {
        target_ip = argv[1];
    }

    if ( argc >= 3) {
        errno = 0;
        starting_port = strtoul(argv[2], NULL, 10);

        if (errno == ERANGE) {
            printf("Invalid argument for STARTING_PORT");
            return 1;
        }
    }

    if ( argc >= 4) {
        errno = 0;
        ending_port = strtoul(argv[3], NULL, 10);

        if (errno == ERANGE) {
            printf("Invalid argument for ENDING_PORT");
            return 1;
        }
    }

    if (argc > 4) {
        printf("Too many number of arguments!");
        return 1;
    }

    if (starting_port < 1 || starting_port > 65535 || ending_port < 1 || ending_port > 65535 || starting_port > ending_port) {
        printf("Invalid port range starting and ending ports should be values between 1 - 65535, and starting port can not be larger than ending port!");
        return 1;
    }

    struct sockaddr_in addr;

    if (start_scan(&addr, target_ip, starting_port, ending_port) == 1) {
        printf("Error running the scan");
        return 1;
    }

    printf("\r\033[KScan completed\n");

    return 0;
}

