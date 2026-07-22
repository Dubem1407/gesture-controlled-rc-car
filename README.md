# Gesture Controlled RC Car

A wireless RC car controlled by hand gestures using an MPU6500 IMU sensor 
and HC-05 Bluetooth modules. Tilting the remote controller forward, 
backward, left, or right drives the car in the corresponding direction 
in real time.

## Demo
--

## Hardware

### Master Remote (Transmitter)
- Arduino Nano
- MPU6500 IMU (accelerometer + gyroscope)
- HC-05 Bluetooth Module

### Slave Car (Receiver)
- Arduino UNO
- HC-05 Bluetooth Module
- L298N Motor Driver
- 2x DC Motors

## How It Works
The master remote reads tilt angles from the MPU6500 and transmits 
directional commands over Bluetooth via the HC-05 module. The slave car 
receives these commands and drives the motors accordingly through the 
L298N H-bridge motor driver.

## Wiring Diagram
- Master Remote
--
- Slave Car
--


## Folder Structure
gesture-controlled-rc-car/
├── docs/
│   └── wiring_diagram.png
├── master_remote/
│   └── remote.ino         # Gesture reading and BT transmission
├── slave_car/
│   └── car.ino            # BT receiving and motor control
├── .gitignore
└── README.md


## Getting Started

### Prerequisites
- Arduino IDE
- FastIMU library by LiquidCGS
- L298N motor driver library (optional)

### Upload Instructions
1. Open `master_remote/remote.ino` in Arduino IDE
2. Upload to Arduino Nano
3. Open `slave_car/car.ino` in Arduino IDE  
4. Upload to Arduino UNO
5. Power both units and pair the HC-05 modules

## Project Status
- [x] Motor control (L298N)
- [x] IMU integration (MPU6500)
- [ ] Bluetooth communication (HC-05)
- [ ] Gesture to direction mapping
- [ ] Full system integration

## Author
Chidubem Emeka-Nwuba  
[Portfolio](https://chidubemnwuba.vercel.app) | 
[LinkedIn](https://linkedin.com/in/chidubem-emeka-nwuba)