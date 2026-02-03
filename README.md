# minitalk

Inter-process communication between a **client** and a **server** using only UNIX signals (`SIGUSR1` / `SIGUSR2`).

This project is part of the 42 curriculum and focuses on understanding:
- processes & PIDs
- signal handling (`signal` / `sigaction`)
- bit-level encoding/decoding (sending characters as bits)
- robustness (no crashes, no leaks, clean error handling)

## Contents

- [Overview](#overview)
- [How it works](#how-it-works)
- [Build](#build)
- [Run](#run)
- [Additional (Bonus) features](#additional-bonus-features)
- [Notes & troubleshooting](#notes--troubleshooting)
- [Allowed functions](#allowed-functions-for-this-project)

## Overview

The program consists of two executables:

- **server**  
  Prints its PID and waits for incoming signals. It reconstructs the received bits into characters and prints the final message.

- **client**  
  Takes the server PID and a string, then sends the message to the server **bit by bit** using signals.

## How it works

Because only signals are allowed, the client encodes each character into 8 bits:

- `SIGUSR1` represents a `0`
- `SIGUSR2` represents a `1`

The server receives signals via a handler, accumulates bits, rebuilds bytes (characters), and outputs them.

## Build

Server and client are built separately. Run make inside each folder: /client and /server
```bash
make
```

## Run
1) From the the '/server' folder, start the server
```bash
./server
```

It will print its PID, e.g.: 12345

2) Send a message from the client

Open another terminal from the '/client' folder and execute the client. It takes two arguments: the server PID and the message
```bash
./client 12345 "Hello from minitalk!"
```

The server should print:

Hello from minitalk!

Very long messages are supported, and the server remains responsive.

## Additional (Bonus) features

- Acknowledgement (handshake): server confirms reception so the client can send reliably
- Unicode support: multi-byte characters

## Notes & troubleshooting

Wrong PID / server not running: the client should detect invalid PIDs and print a clear error.

## Allowed functions for this project:

- write
- ft_printf (code by me)
- signal
- sigemptyset
- sigaddset
- sigaction
- kill
- getpid
- malloc
- free
- pause
- sleep
- usleep
- exit
