# minitalk

Inter-process communication between a **client** and a **server** using only UNIX signals (`SIGUSR1` / `SIGUSR2`).

This project is part of the 42 curriculum and focuses on understanding:

- Processes & PIDs
- Signal handling (`signal` / `sigaction`)
- Bit-level encoding/decoding (sending characters as bits)
- Robustness (no crashes, no leaks, clean error handling)

---

## Table of Contents

- [Overview](#overview)
- [How it works](#how-it-works)
- [Build](#build)
- [Run](#run)
- [Additional (Bonus) features](#additional-bonus-features)
- [Notes & troubleshooting](#notes--troubleshooting)
- [Allowed functions](#allowed-functions)

---

## Overview

The program consists of two executables:

### Server

- Prints its PID
- Waits for incoming signals
- Reconstructs received bits into characters
- Outputs the final message

### Client

- Takes the server PID and a message string
- Encodes and sends the message **bit by bit** using signals

---

## How it works

Because only signals are allowed, the client encodes each character into 8 bits:

- `SIGUSR1` represents `0`
- `SIGUSR2` represents `1`

The server:

1. Receives signals via a signal handler
2. Accumulates bits
3. Rebuilds bytes (characters)
4. Prints the decoded output

An optional acknowledgement mechanism improves reliability.

---

## Build

Server and client are built separately.

Run `make` inside each folder:

```bash
cd server && make
cd ../client && make
```

---

## Run

### 1. Start the server

From the `server/` folder:

```bash
./server
```

It will print its PID, for example:

```text
12345
```

### 2. Send a message

! Open a second terminal window.

From the `client/` folder:

```bash
./client 12345 "Hello from minitalk!"
```

The server should display:

```text
Hello from minitalk!
```

Very long messages are supported, and the server remains responsive.

---

## Additional (Bonus) features

- Acknowledgement / handshake mechanism
- Reliable transmission
- Unicode / multi-byte character support

---

## Notes & troubleshooting

- **Wrong PID / server not running**  
  The client detects invalid PIDs and prints a clear error message.

- **Signal loss**  
  The acknowledgement mechanism reduces transmission errors.

---

## Allowed functions

- `write`
- `ft_printf` (custom implementation)
- `signal`
- `sigemptyset`
- `sigaddset`
- `sigaction`
- `kill`
- `getpid`
- `malloc`
- `free`
- `pause`
- `sleep`
- `usleep`
- `exit`
