# ESP32-Arduino SPI Communication

A simple embedded systems project demonstrating SPI communication between an ESP32 and an Arduino Uno.

The ESP32 is configured as the SPI Master, while the Arduino Uno operates as the SPI Slave. The project demonstrates data exchange between the two microcontrollers using the SPI protocol.

## Project Overview

In this project, the ESP32 reads the state of a push button and sends the corresponding data to the Arduino Uno through SPI.

The Arduino Uno receives the data as the SPI Slave and processes the received information. LEDs are used to demonstrate the result of the communication.

This project provides practical experience with SPI communication between two different microcontroller platforms.

## Features

- ESP32 as SPI Master
- Arduino Uno as SPI Slave
- Hardware SPI communication
- Push button input
- LED output
- Data transmission between two microcontrollers
- Master/Slave communication architecture

## Hardware

- ESP32 Development Board
- Arduino Uno
- Push Buttons
- LEDs
- Resistors
- Breadboard
- Jumper Wires

## SPI Communication

The ESP32 acts as the SPI Master and initiates the communication.

The Arduino Uno acts as the SPI Slave and responds to the Master's SPI transactions.

### SPI Signals

| SPI Signal | ESP32 Master | Arduino Uno Slave |
|------------|--------------|-------------------|
| MOSI | Master Out | Slave In |
| MISO | Master In | Slave Out |
| SCK | SPI Clock | SPI Clock |
| SS/CS | Slave Select | Slave Select |
| GND | Ground | Ground |

## How It Works

1. The ESP32 reads the push button state.
2. The button state is converted into a data value.
3. The ESP32 starts an SPI transaction.
4. The ESP32 sends the data to the Arduino Uno.
5. The Arduino Uno receives the data as the SPI Slave.
6. The received data is processed by the Arduino Uno.
7. The LED state is controlled according to the received data.
8. The Arduino Uno can also return data to the ESP32 through the SPI MISO line.

## ESP32 SPI Master

The ESP32 uses the VSPI peripheral for SPI communication.

The SPI interface is initialized using:

```cpp
SPIClass *spi = new SPIClass(VSPI);
