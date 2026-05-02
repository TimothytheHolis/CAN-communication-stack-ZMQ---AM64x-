# CANopen ZMQ Simulation + AM64x Deployment

This project implements a CANopen communication stack using the CANopenNode library, with support for both:

* PC-based simulation using ZeroMQ
* Embedded deployment on AM64x microcontrollers

## Overview

The system is structured into three layers:

Application Layer (canopen_app)
↓
CANopen Stack (CANopenNode)
↓
Transport Layer (ZMQ or MCAN driver)

This design allows the same CANopen logic to be reused across simulation and hardware, with only the transport layer changing.

## Dependencies

* CANopenNode
  https://github.com/CANopenNode/CANopenNode

* ZeroMQ (for simulation)
  sudo apt install zmq

## Setup

1. Clone CANopenNode into project root:
   git clone https://github.com/CANopenNode/CANopenNode canopennode

2. Install zmq
   sudo apt install zmq

3. Build:

   make clean
   make
   ./master

## Notes

* CANopenNode source is used without modification
* Platform-specific drivers are isolated
* Same application logic is reused across:

  * Master node
  * Slave node
  * Embedded target

## Future Work

* Add slave node implementation
* Integrate AM64x MCAN driver
* Add timing abstraction layer
