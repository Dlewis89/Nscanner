#ifndef SCANNER_H
#define SCANNER_H

#include <arpa/inet.h>

typedef enum {
  SCANNER_SUCCESS = 0,
  INVALID_TARGET_IP,
  INVALID_SCANNER_PORT,
  INVALID_SCANNER_SOCK_DESCRIPTOR
} SCANNER_STATUS;

typedef struct {
  struct sockaddr_in addr;
  int starting_port;
  int ending_port;
  SCANNER_STATUS status;
} Scanner;

Scanner *scanner_init(const char *tartget_ip);
int set_scanner_port(Scanner *scanner, int starting_port, int ending_port);
int scanner_scan_port(Scanner *scanner, int port);
void scanner_destroy(Scanner *scanner);

#endif