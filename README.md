# <img src="https://user-images.githubusercontent.com/63792403/133922028-fefc8abb-fde9-460b-826f-09a458502d17.png" alt="Icon" height="24"> &nbsp; ArduinoOcpp

[![Build Status]( https://github.com/matth-x/ArduinoOcpp/workflows/PlatformIO%20CI/badge.svg)](https://github.com/matth-x/ArduinoOcpp/actions)
[![Unit tests]( https://github.com/matth-x/ArduinoOcpp/workflows/Unit%20tests/badge.svg)](https://github.com/matth-x/ArduinoOcpp/actions)
[![codecov](https://codecov.io/github/matth-x/ArduinoOcpp/branch/develop/graph/badge.svg?token=UN6LO96HM7)](https://codecov.io/github/matth-x/ArduinoOcpp)

OCPP-J 1.6 client for embedded microcontrollers. Portable C/C++. Compatible with Espressif, NXP, Texas Instruments and STM.

Reference usage: [OpenEVSE](https://github.com/OpenEVSE/ESP32_WiFi_V4.x/blob/master/src/ocpp.cpp)

PlatformIO package: [ArduinoOcpp](https://platformio.org/lib/show/11975/ArduinoOcpp)

Website: [www.arduino-ocpp.com](https://www.arduino-ocpp.com)

Fully integrated into the Arduino platform and the ESP32 / ESP8266. Runs on ESP-IDF, FreeRTOS and generic embedded C/C++ platforms.

## Make your EVSE ready for OCPP :car::electric_plug::battery:

This library allows EVSEs to communicate with an OCPP Backend and to participate in commercial charging networks. You can integrate it into an existing firmware development, or start a new EVSE project from scratch with it.

:heavy_check_mark: Works with [SteVe](https://github.com/RWTH-i5-IDSG/steve) and [15+ commercial Central Systems](https://www.arduino-ocpp.com/#h.314525e8447cc93c_81)

:heavy_check_mark: Tested in many charging stations

:heavy_check_mark: Eligible for public chargers (Eichrecht-compliant)

Technical introduction: [ArduinoOcpp Docs](https://matth-x.github.io/ArduinoOcpp/intro-tech)

Try it (no hardware required): [ArduinoOcppSimulator](https://github.com/matth-x/ArduinoOcppSimulator)

### Features

- handles the OCPP communication with the charging network
- implements the standard OCPP charging process
- provides an API for the integration of the hardware modules of the EVSE
- works with any TLS implementation and WebSocket library. E.g.
   - Arduino networking stack: [Links2004/arduinoWebSockets](https://github.com/Links2004/arduinoWebSockets), or
   - generic embedded systems: [Mongoose Networking Library](https://github.com/cesanta/mongoose)

The necessary hardware and internet integration is usually far below 1000 LOCs.

## Developers guide

Please take `examples/ESP/main.cpp` as the starting point for the first project. It is a minimal example which shows how to establish an OCPP connection and how to start and stop charging sessions. The API documentation can be found in [`ArduinoOcpp.h`](https://github.com/matth-x/ArduinoOcpp/blob/master/src/ArduinoOcpp.h).

### Dependencies

Mandatory:

- [bblanchon/ArduinoJSON](https://github.com/bblanchon/ArduinoJson)

If compiled with the Arduino integration:

- [Links2004/arduinoWebSockets](https://github.com/Links2004/arduinoWebSockets) (version `2.3.6`)

In case you use PlatformIO, you can copy all dependencies from `platformio.ini` into your own configuration file. Alternatively, you can install the full library with dependencies by adding `matth-x/ArduinoOcpp` in the PIO library manager.

## OCPP 2.0.1 and ISO 15118

The OCPP 2.0.1 upgrade is being worked on. Further details will be announced soon.

ISO 15118 is a must-have for future chargers. It will hugely improve the security and user-friendliness of EV charging. ArduinoOcpp facilitates the integration of ISO 15118 by handling its OCPP-side communication. This is being validated now in a proprietary firmware development.

However, no public ISO 15118 integration exists at the moment. If your company considers working on an open source ISO 15118 stack, it would be great to discuss a potential collaboration on an open source OCPP 2.0.1 + ISO 15118 solution.

## Supported Feature Profiles

| Feature profile | supported | in progress |
| -------------- | :---------: | :-----------: |
| **Core** | :heavy_check_mark: |
| **Smart charging** | :heavy_check_mark: |
| **Remote trigger** | :heavy_check_mark: |
| **Firmware management** | :heavy_check_mark: |
| **Local auth list management** | :heavy_check_mark: |
| **Reservation** | :heavy_check_mark: |

Fully OCPP 1.6 compliant :heavy_check_mark:

## Further help

I hope this guide can help you to successfully integrate an OCPP controller into your EVSE. If something needs clarification or if you have a question, please send me a message.

:envelope: : matthias A⊤ arduino-ocpp DО⊤ com

If you want professional assistance for your EVSE project, you can contact me as well. I'm looking forward to hearing about your ideas!
