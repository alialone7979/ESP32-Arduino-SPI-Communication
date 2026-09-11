# ESP32-Arduino SPI Communication

A simple SPI communication project demonstrating data exchange between an ESP32 and an Arduino Uno.

## Project Overview

This project demonstrates SPI (Serial Peripheral Interface) communication between two different microcontroller platforms.

The ESP32 is configured as the **SPI Master**, while the Arduino Uno operates as the **SPI Slave**.

The Master sends data to the Slave based on the state of a push button. The received data is then used to control an LED, demonstrating basic SPI data exchange between the two microcontrollers.

## System Architecture

ESP32 (SPI Master)
       │
       │ SPI
       │
       ▼
Arduino Uno (SPI Slave)
Hardware
ESP32 Development Board
Arduino Uno
Push Buttons
LEDs
Resistors
Breadboard
Jumper Wires
SPI Communication

The ESP32 acts as the Master and initiates SPI communication.

The Arduino Uno acts as the Slave and responds to the Master's SPI transactions.

The main SPI signals are:

SPI Signal	ESP32 Master	Arduino Uno Slave
MOSI	Master Out	Slave In
MISO	Master In	Slave Out
SCK	SPI Clock	SPI Clock
SS/CS	Slave Select	Slave Select
GND	GND	GND
How It Works
The ESP32 reads the state of a push button.
The ESP32 converts the button state into a data value.
The ESP32 starts an SPI transaction.
The ESP32 sends the data to the Arduino Uno using SPI.
The Arduino Uno receives the data as the SPI Slave.
The received data is processed by the Arduino.
The LED state is controlled according to the received data.
The Arduino can also return data to the ESP32 through the SPI MISO line.
ESP32 SPI Master

The ESP32 uses the VSPI peripheral for SPI communication.

Example:

SPIClass *spi = new SPIClass(VSPI);

SPI communication is performed using:

spi->beginTransaction(SPISettings());

and data is exchanged using:

spi->transfer(data);
Arduino Uno SPI Slave

The Arduino Uno is configured as the SPI Slave and receives data from the ESP32 through the SPI interface.

The Slave processes the received data and can return information to the Master during the same SPI transaction.

Circuit Diagram
Fritzing Diagram

Hardware Setup

Demo

A demonstration video of the SPI communication between the ESP32 and Arduino Uno is included in this repository.

SPI-communication.mp4

Project Structure
ESP32-Arduino-SPI-Communication/
│
├── SPI_Master.ino
├── SPI_Slave.ino
├── SPI-communication-Fritzing.png
├── SPI-communication.jpg
├── SPI-communication.mp4
└── README.md
Technologies
ESP32
Arduino Uno
SPI
Hardware SPI
Embedded C/C++
Digital I/O
Push Buttons
LEDs
Key Concepts

This project provides practical experience with:

SPI Master/Slave architecture
Communication between different microcontroller platforms
Hardware SPI peripherals
MOSI, MISO, SCK, and SS signals
SPI data transfer
Digital input and output
Interfacing multiple microcontrollers
Author

Ali Ahmadi

GitHub: @alialone7979
