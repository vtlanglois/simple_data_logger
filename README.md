# Simple Arduino Data Logger

A simple data logger project made to demonstrate data collection using Arduino, Python, and Jupyter Notebooks. Made for educators and developers.

**NOTE: this is a work-in-progress. Code and documentation can change before a final release.**

# Description

## Data Logging (Arduino)

The Arduino device uses a temperature sensor and a phototransistor to collect surrounding temperature and light data. 

In `data_logger.ino`, before collecting data the Arduino calibrates the phototransistor. Once calibrated, the Arduino will collect data at a set frequency. Then, the devices outputs the most recently collected data across a serial connection in a `.csv` format. 

## Data Collection (Python)

The Python script `data_collection.py` takes that output and stores it in a list. Once a endpoint is reached, the Python script writes the list to a new `.csv` file.

## Data Intrepretation (Jupyter Notebook)

# Instructions

## Setup

To build this Arduino project, you'll need the following materials:
- 1 Arduino UNO
- 1 breadboard
- 1 Temperature Sensor
- 1 Phototransistor
- 1 kOhm resistor
- Jumper wires
