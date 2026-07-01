# Network Scanner

> **Project 001 – Systems Programming**
>
> This project is part of my journey into systems programming using C and Linux.
> Rather than following tutorials, my goal is to build progressively more complex tools while learning how operating systems, networking, and computer systems work under the hood.
>
> For this project, the objective was to learn the fundamentals of TCP networking by implementing a simple TCP port scanner from scratch using the POSIX socket API.

---

## Overview

The scanner attempts to establish a TCP connection to each port in a user-defined range. If the connection succeeds, the port is reported as open.

This project was intentionally written without external networking libraries to gain a deeper understanding of sockets and the Linux networking API.

---

## Features

- Scan IPv4 addresses
- Custom start and end port ranges
- Detect open TCP ports
- Simple command-line interface
- Modular project structure using header and source files

---

## Project Structure

```
network-scanner/
├── include/
│   └── scanner.h
├── src/
│   ├── main.c
│   └── scanner.c
├── README.md
└── Makefile
```

---

## Building

```bash
gcc -std=c17 -Wall -Wextra -Wpedantic -Iinclude -o nscanner src/main.c src/scanner.c
```

---

## Usage

Scan localhost:

```bash
./nscanner
```

Scan another host:

```bash
./nscanner 192.168.1.100
```

Scan a specific range:

```bash
./nscanner 127.0.0.1 1 1024
```

---

## What I Learned

During this project I learned:

- Creating TCP sockets with `socket()`
- Connecting to remote hosts with `connect()`
- Using `struct sockaddr_in`
- Converting IPv4 addresses with `inet_pton()`
- Converting ports using `htons()`
- Error handling with `perror()` and `errno`
- Reading Linux man pages
- Passing structures by pointer
- Separating interfaces (`.h`) from implementations (`.c`)
- Basic project organization in C

---

## Challenges

Some of the challenges encountered while building this project included:

- Understanding pointers to structures
- Learning the difference between `.` and `->`
- Passing structures correctly to `connect()`
- Handling terminal output while displaying scan progress
- Parsing command-line arguments
- Organizing the project into multiple source files

---

## Future Improvements

- Hostname support using `getaddrinfo()`
- Configurable connection timeouts
- Parallel scanning using threads
- IPv6 support
- Better progress reporting
- Service detection

---

## License

MIT
