# WiFiEsp Continued

Original library: https://github.com/bportaluri/WiFiEsp

This version of the library is in maintenance-only mode. The intention is to continue the legacy of the original library, but made to work for modern compilation systems. No new features outside of that which the community or the original author provide are scheduled. Fixes through community pull requests are most appreciated. Please report bugs to issue tracker. Please no feature requests outside of pull requests that do not change any existing interfaces.

For new projects it is recommended to instead use: https://github.com/jandrassy/WiFiEspAT

## Introduction

WiFiEsp-Continued library allows an Arduino board with an ESP8266 serial WiFi shield to connect to the internet.
It can serve as either a server accepting incoming connections or a client making outgoing ones.
The WiFiEsp-Continued library is very similar to the Arduino [WiFi](http://www.arduino.cc/en/Reference/WiFi) and [Ethernet](http://www.arduino.cc/en/Reference/Ethernet) libraries, and many of the function calls are the same. 

Supports *up to* ESP Firmware SDK v1.5.4 (AT command version v1.1.1.0). SDK v2+ and later revisions have not been tested.

## Features

- APIs compatible with standard Arduino WiFi library.
- Use AT commands of standard ESP firmware.
- Support CUR mode commands.
- Support hardware and software serial ports.
- Configurable tracing level.
- Added community fixes.

## Wiring

The WiFiEsp-Continued library has been designed to work with the [ESP8266 WiFi module](https://www.allaboutcircuits.com/projects/breadboard-and-program-an-esp-01-circuit-with-the-arduino-ide/) (aka ESP-01). It is a cheap version of the Arduino WiFi shield that uses a ESP8266EX module to provide networking capabilities to Arduino boards. It comes in several versions, with the biggest differences being the amount of programmable memory, with older (blue board, 512KB/4Mbit) versions supporting up to SDK v1.4 and newer (black board, 1MB+/8Mbit+) versions supporting beyond SDK v2+.

## Flashing

In order to flash, you will need to know the Flash ROM size of your module (i.e. 4Mbit, 8Mbit, 16Mbit, etc.), and inside of the flashing tool select the correct set of bin files with the appropriate offsets for that specific Flash ROM size. These bin files and offsets are found in the readme file in the bin/AT subfolder of the downloaded SDK firmware files (with subfolders based on optional OS partitioning for OTA: noboot -> 4+Mbit (no OTA), 512+512 -> 8Mbit (OTA), 1024+1024 -> 16Mbit (OTA), etc.).

Relevant links:
* [ESP flashing tools](https://www.espressif.com/en/products/socs/esp8266ex/resources) (under Tools section)
* [ESP AT firmware](https://www.espressif.com/en/products/socs/esp8266ex/resources) (under AT section)
* [SDK v1.4.0 AT firmware](https://github.com/NachtRaveVL/WiFiEsp-Continued/raw/master/extra/esp_iot_sdk_v1.4.0_15_09_18.zip) direct link (last SDK version to support blue boards)
* [SDK v1.5.4 AT firmware](https://github.com/NachtRaveVL/WiFiEsp-Continued/raw/master/extra/esp8266_nonos_sdk_v1.5.4_16_05_20.zip) direct link (last SDK version this library *officially* supports)
* [ESP AT firmware source](https://github.com/espressif/esp-at)
* [ESP AT firmware docs](https://docs.espressif.com/projects/esp-at/en/release-v2.2.0.0_esp8266/index.html)
* [flashing guide](https://www.allaboutcircuits.com/projects/flashing-the-ESP-01-firmware-to-SDK-v2.0.0-is-easier-now)
* [another flashing guide](https://www.electronicshub.org/update-flash-esp8266-firmware/)
* [alternate pre-compiled AT binaries](https://github.com/CytronTechnologies/esp-at-binaries)
* [more alternate pre-compiled AT binaries](https://github.com/loboris/ESP8266_AT_LoBo)

## Examples

- [ConnectWPA](https://github.com/NachtRaveVL/WiFiEsp-Continued/blob/master/examples/ConnectWPA/ConnectWPA.ino) - Demonstrates how to connect to a network that is encrypted with WPA2 Personal
- [WebClient](https://github.com/NachtRaveVL/WiFiEsp-Continued/blob/master/examples/WebClient/WebClient.ino) - Connect to a remote webserver 
- [WebClientRepeating](https://github.com/NachtRaveVL/WiFiEsp-Continued/blob/master/examples/WebClientRepeating/WebClientRepeating.ino) - Make repeated HTTP calls to a webserver 
- [WebServer](https://github.com/NachtRaveVL/WiFiEsp-Continued/blob/master/examples/WebServer/WebServer.ino) - Serve a webpage from the WiFi shield 
- [WebServerAP](https://github.com/NachtRaveVL/WiFiEsp-Continued/blob/master/examples/WebServerAP/WebServerAP.ino) - Serve a webpage from the WiFi shield starting a local Access Point
- [WebServerLed](https://github.com/NachtRaveVL/WiFiEsp-Continued/blob/master/examples/WebServerLed/WebServerLed.ino) - Turn on and off a led from a webpage
- [UdpNTPClient](https://github.com/NachtRaveVL/WiFiEsp-Continued/blob/master/examples/UdpNTPClient/UdpNTPClient.ino) - Query a Network Time Protocol (NTP) server using UDP
- [FirmwareVersion](https://github.com/NachtRaveVL/WiFiEsp-Continued/blob/master/examples/FirmwareVersion/FirmwareVersion.ino) - Check SDK and AT firmware version of the ESP8266 module

## Supported APIs

Most of the standard Arduino WiFi library methods are available. Refer to the [WiFi library page](http://www.arduino.cc/en/Reference/WiFi) for more details.

### WiFiEsp class

- begin() - Not all authentication types
- disconnect() - YES
- config()
- setDNS() - YES
- hostByname() - YES
- SSID() - YES
- BSSID() - YES
- RSSI() - YES
- encryptionType() - NO (no AT command available)
- scanNetworks() - YES
- getSocket()
- macAddress() - YES


### WiFiEspServer class

The WiFiEspServer class creates servers which can send data to and receive data from connected clients (programs running on other computers or devices).

- WiFiEspServer() - YES
- begin() - YES
- available() - YES
- write() - YES
- print() - YES
- println() - YES


### Client class

The WiFiEspClient class creates clients that can connect to servers and send and receive data.

- WiFiEspClient() - YES
- connected() - YES
- connect() - YES
- write() - YES
- print() - YES
- println() - YES
- available() - YES
- read() - YES
- flush() - YES
- stop() - YES


### WiFiEspUDP class

The UDP class enables UDP message to be sent and received.

- WiFiUDP - YES
- begin() - YES
- available() - YES
- beginPacket() - YES
- endPacket() - YES
- write() - YES
- parsePacket() - YES
- peek()
- read() - YES
- flush()
- stop()
- remoteIP() - YES
- remotePort() - YES
