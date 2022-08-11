# WiFiEsp Continued

Original library: https://github.com/bportaluri/WiFiEsp

This version of the library is in maintenance-only mode. The intention is to continue the legacy of the original library, but made to work for modern compilation systems. No new features outside of that which the community or the original author provide are scheduled. Fixes through community pull requests are most appreciated. Please report bugs to issue tracker. Please no feature requests outside of pull requests.

## Introduction

WiFiEsp-Continued library allows an Arduino board with an ESP8266 serial WiFi shield to connect to the internet.
It can serve as either a server accepting incoming connections or a client making outgoing ones.
The WiFiEsp-Continued library is very similar to the Arduino [WiFi](http://www.arduino.cc/en/Reference/WiFi) and [Ethernet](http://www.arduino.cc/en/Reference/Ethernet) libraries, and many of the function calls are the same. 

Supports up to ESP Firmware SDK version v1.7.x (AT command version 0.25 and above). v2+ SDK support may be shaky (under development).

## Features

- APIs compatible with standard Arduino WiFi library.
- Use AT commands of standard ESP firmware.
- Support hardware and software serial ports.
- Configurable tracing level.

## Wiring

The WiFiEsp-Continued library has been designed to work with the [ESP8266 WiFi module](https://www.allaboutcircuits.com/projects/breadboard-and-program-an-esp-01-circuit-with-the-arduino-ide/) (aka ESP-01). It is a cheap version of the Arduino WiFi shield that uses a ESP8266EX module to provide networking capabilities to Arduino boards. It comes in several versions, with the biggest differences being the amount of programmable memory and max data speed supported, with older (blue board, 512KB/4Mbit) versions supporting only 9600 baud while newer (black board, 1MB+/8Mbit+) versions supporting 115200+ baud (recommend to not exceed 115200). Later boards have even more room to support extra features, including OTA firmware updates that do not require a programmer.

## Flashing

Be advised that all newer ESP8266 WiFi modules on market come with firmware that can take advantage of OTA updates. Custom flashing may likely not be needed depending on your device features (read as: flashing the firmware may require some amount of time investment to understand and may leave your module not working properly - so be sure to *read the manual*).

Relevant links:
* [ESP flashing tools](https://www.espressif.com/en/products/socs/esp8266ex/resources) (under Tools section)
* [ESP AT firmware](https://www.espressif.com/en/products/socs/esp8266ex/resources) (under AT section)
* [ESP AT firmware source](https://github.com/espressif/esp-at)
* [ESP AT firmware docs](https://docs.espressif.com/projects/esp-at/en/release-v2.2.0.0_esp8266/index.html)
* [NodeMCU flasher](https://github.com/nodemcu/nodemcu-flasher)
* [ESPEasy](https://github.com/letscontrolit/ESPEasy)
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
