# WiFiEsp Continued

Original library: https://github.com/bportaluri/WiFiEsp

This version of the library is in maintenance-only mode. The intention is to continue the legacy of the original library, but made to work for modern compilation systems. No new features outside of that which the community or the original author provide are scheduled. Fixes through community pull requests are most appreciated. Please report bugs to issue tracker. Please no feature requests outside of pull requests.

## Introduction

With an ESP8266 board, WiFiEsp-Continued library allows an Arduino board to connect to the internet.
It can serve as either a server accepting incoming connections or a client making outgoing ones.
The WiFiEsp-Continued library is very similar to the Arduino [WiFi](http://www.arduino.cc/en/Reference/WiFi) and [Ethernet](http://www.arduino.cc/en/Reference/Ethernet) libraries, and many of the function calls are the same. 

Supports ESP SDK version 1.1.1 and above (AT version 0.25 and above).


## Features

- APIs compatible with standard Arduino WiFi library.
- Use AT commands of standard ESP firmware (no need to flash a custom firmware).
- Support hardware and software serial ports.
- Configurable tracing level.

## Wiring

The WiFiEsp-Continued library has been designed to work with the [ESP WiFi shield](http://www.instructables.com/id/Cheap-Arduino-WiFi-Shield-With-ESP8266/).

It is a cheap version of the Arduino WiFi shield that uses an ESP8266 module to provide networking capabilities to Arduino boards.


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


## Contributing

Only pull requests will be accepted.
