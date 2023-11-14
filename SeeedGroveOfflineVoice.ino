#include "GroveOfflineSensor.h"
#include <SoftwareSerial.h>
#define RX_VC02 3
#define TX_VC02 2

SoftwareSerial groveSerial(RX_VC02, TX_VC02); // RX, TX

void setup() {
  Serial.begin(9600);
  while (!Serial); // wait for serial port to connect. Needed for native USB port only , This port is for displaying data Grove Sensor sends

  Serial.println("USB Serial Port connection Established!");

  groveSerial.begin(115200); // Make sure to set the baud rate to match your communication
}

void loop() {
  // Your main code here
  
   uint8_t *voiceData = detectVoiceFromGroveSensor(&groveSerial);

  if(voiceData != NULL){
    String response = getCommandInString(voiceData);
    Serial.println(response);
  }
  
  delay(100);
}
