# Minitalk - 42 Barcelona

## Description
`Minitalk` is a communication program that uses UNIX signals to facilitate data exchange between a client and a server. The primary objective is to send a string from the client to the server using only the UNIX signals `SIGUSR1` and `SIGUSR2`.

## Features
- **Server Behavior**:
  - Must be started first and display its PID upon launch.
  - Should receive and print the string sent by the client.
  - Capable of receiving strings from multiple clients consecutively without restarting.
  - Communication is exclusively through UNIX signals.
  
- **Client Behavior**:
  - Takes two parameters: The server PID and the string to send.
  - Sends the provided string to the server using UNIX signals.

## General Instructions
- Executable files should be named `client` and `server`.
- Handle errors thoroughly to prevent unexpected program termination.
- No memory leaks allowed.

## Bonus Features
- Server acknowledges every received message by sending a signal back to the client.
- Support for Unicode characters.

