# Network Scanner

A simple TCP port scanner written in C for Linux.

This project was built as part of my journey into systems programming. The goal was to learn how TCP sockets work by implementing a basic port scanner from scratch using the POSIX socket API.

## Features

- Scan a single IPv4 address
- Configure start and end port ranges
- Display open TCP ports
- Simple command-line interface
- Built using POSIX sockets

## Requirements

- Linux
- GCC with C17 support

## Building

```bash
gcc -std=c17 -Wall -Wextra -Wpedantic -Iinclude -o nscanner src/main.c src/scanner.c
```

## Usage

Scan localhost using the default port range:

```bash
./nscanner
```

Scan a specific host:

```bash
./nscanner 192.168.1.1
```

Scan a custom port range:

```bash
./nscanner 127.0.0.1 1 1024
```

## What I Learned

- Creating TCP sockets with `socket()`
- Connecting to remote hosts with `connect()`
- Using `sockaddr_in`
- Converting IP addresses with `inet_pton()`
- Converting ports to network byte order with `htons()`
- Reading Linux man pages
- Working with pointers and structures
- Organizing a small C project using header and source files

## Future Improvements

- Add hostname support using `getaddrinfo()`
- Add configurable connection timeouts
- Scan multiple ports concurrently
- Support IPv6
- Improve terminal output and progress display

## License

MIT
