# CANopen ZMQ Simulation + AM64x Deployment

A portable CANopen communication stack built on [CANopenNode](https://github.com/CANopenNode/CANopenNode), supporting both PC-based simulation via ZeroMQ and embedded deployment on AM64x targets.

## Architecture

The stack is organized into three decoupled layers:

Application Layer (canopen_app)
↓
CANopen Stack (CANopenNode)
↓
Transport Layer (ZMQ or MCAN driver)

Swapping the transport layer is the only change needed to move between simulation and hardware. All application and protocol logic remains identical across master, slave, and embedded targets.

## Prerequisites

| Dependency                                                | Purpose                | Install                                       |
|-----------------------------------------------------------|------------------------|-----------------------------------------------|
| [CANopenNode](https://github.com/CANopenNode/CANopenNode) | CANopen protocol stack | Cloned into project root (see Setup)          |
| ZeroMQ (`libzmq`)                                         | Simulation transport   | `sudo apt install libzmq3-dev`                |
| GCC / Make                                                | Build toolchain        | `sudo apt install build-essential`            |
| C/C++ Extension (optional)                                | VS Code IntelliSense   | `code --install-extension ms-vscode.cpptools` |

## Setup

**1. Clone this repository**

```bash
git clone <this-repo-url> canopen-zmq
cd canopen-zmq
```

**2. Clone CANopenNode into the project root**

```bash
git clone https://github.com/CANopenNode/CANopenNode canopennode
```

**3. Install ZeroMQ development headers**

```bash
sudo apt install libzmq3-dev
```

**4. Build and run**

```bash
make clean && make
./master
```

## Contributing

CANopenNode source is used **without modification**. Platform-specific code lives exclusively in `transport/`. When contributing:

- Keep application logic in `canopen_app/` transport-agnostic.
- New transport backends should implement the same driver interface as the ZMQ transport.
- Open an issue before starting large changes.

## Roadmap

- [ ] Slave node implementation
- [ ] AM64x MCAN driver integration  
- [ ] Timing abstraction layer
