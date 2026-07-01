#ifndef SCANNER_H
#define SCANNER_H

#include <arpa/inet.h>

int set_sockaddr(struct sockaddr_in *addr, const char *target_ip);
int start_scan(struct sockaddr_in *addr, const char *target_ip, int starting_port, int ending_port);

#endif