# ServerClientChat

A minimal two-way chat application written in C++ using POSIX TCP sockets.
It consists of a server and a client that exchange messages over a local
TCP connection on port `8080`.

## Project Structure

```
Project2/
├── server.cpp   # TCP server: listens on port 8080, accepts one client
└── client.cpp   # TCP client: connects to 127.0.0.1:8080
```

## How It Works

1. The **server** creates a socket, binds to port `8080` on all interfaces,
   and waits for a single client connection.
2. The **client** connects to the server at `127.0.0.1:8080`.
3. The two then exchange messages turn by turn:
   - The client sends a message first.
   - The server reads it, prints it, then sends a reply.
   - This repeats until either side sends `Bye`.
4. When `Bye` is sent, both sides close their sockets and the chat ends.

## Building

Requires a C++ compiler with POSIX socket headers (Linux/macOS).

```bash
g++ -o Project2/server Project2/server.cpp
g++ -o Project2/client Project2/client.cpp
```

## Running

Start the server first, then the client in a separate terminal:

```bash
# Terminal 1
./Project2/server

# Terminal 2
./Project2/client
```

Type messages and press Enter to send. Type `Bye` to end the chat.

## Notes / Limitations

- The server only accepts a **single** client connection (no loop around
  `accept`).
- Buffers are fixed at 100 bytes with no bounds checking on `read`/`send`.
- No error handling on socket calls (`socket`, `bind`, `listen`, `connect`,
  etc.) — intended as a simple learning exercise, not production code.
