#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include "../include/scanner.h"

int main(int argc, char **argv) {

  const char *target_ip = "127.0.0.1";
  int starting_port = 1;
  int ending_port = 65535;

  if (argc >= 2) {
    target_ip = argv[1];
  }

  if (argc >= 3) {
    errno = 0;
    starting_port = strtoul(argv[2], NULL, 10);

    if (errno == ERANGE) {
      printf("Invalid argument for STARTING_PORT");
      return 1;
    }
  }

  if (argc >= 4) {
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

  Scanner *scanner = scanner_init(target_ip);

  if (set_scanner_port(scanner, starting_port, ending_port) > 0) {
    printf("Invalid port set");
  }

  for (int port = scanner->starting_port; port <= scanner->ending_port;
       port++) {

    if (scanner_scan_port(scanner, port) > 0) {
      continue;
    }

    printf("Port %d is Open!\n", port);
  }

  scanner_destroy(scanner);

  printf("\r\033[KScan completed\n");

  return 0;
}