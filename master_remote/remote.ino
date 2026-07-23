#include <SoftwareSerial.h>

// RX = Pin 0, TX = Pin 1
SoftwareSerial BTSerial(0, 1);

int count = 0; // test message to send

void setup() {
  Serial.begin(9600);  
  BTSerial.begin(9600);  
  Serial.println("Setup Complete. Sending data...");
}

void loop() {
  // Send counter over BL module
  BTSerial.println(count);
  Serial.println("Sent integer: ");
  Serial.println(count);
  
  count++;
  delay(1000); // Send once per 2s
}