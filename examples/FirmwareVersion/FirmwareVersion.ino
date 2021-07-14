/*
 WiFiEsp example: SDK and AT version

 This sketch checks the SDK and AT version of the ESP8266 module
*/

#include "WiFiEsp.h"


void setup()
{
  // initialize serial for debugging
  Serial.begin(115200);
  // initialize serial for ESP module
  Serial1.begin(115200);
  // initialize ESP module
  WiFi.init(&Serial1);

  // check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue
    while (true);
  }
  else {
    Serial.print(F("WiFi SDK: v")); Serial.println (WiFi.firmwareVersion() );      
    Serial.print(F("WiFi AT: v")); Serial.println (WiFi.ATfirmwareVersion() );              
  }

}

void loop()
{

}
