# StatVolt - IoT Energy Monitoring System

StatVolt is an IoT-based energy monitoring system designed to help manage and limit energy consumption in response to energy crisis situations. The system connects hardware sensors with a web interface to display real-time power usage data and provide consumption control capabilities.

## Hardware Components

- ESP32 Microcontroller
- ACS712 Current Sensor (20A)
- ZMPT101B AC Voltage Sensor (0-250V)

## Features

- Real-time current monitoring
- Real-time voltage monitoring
- WiFi connectivity via ESP32 Access Point
- Web API endpoints for data access
- Configurable sampling and measurement settings

## Software Dependencies

- Arduino IDE
- Libraries:
  - WiFi.h
  - ESPAsyncWebServer.h
  - Wire.h
  - Robojax_AllegroACS_Current_Sensor.h
  - Filters.h

## API Endpoints

- `/current` - Get real-time current readings
- `/voltage` - Get real-time voltage readings

## Configuration

Default WiFi Access Point settings:

- SSID: `ESP36-Access-Point`
- Password: `123456789`
- IP Address: Automatically assigned (check serial monitor)

## Getting Started

1. Install required libraries in Arduino IDE
2. Connect the hardware components
3. Upload the code to ESP32
4. Connect to the ESP32's WiFi access point
5. Access sensor data through the API endpoints

## License

This project is licensed under the Apache License 2.0 - see the LICENSE file for details.
