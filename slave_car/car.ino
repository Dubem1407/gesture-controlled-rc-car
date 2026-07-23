#include <SoftwareSerial.h>

// RX = Pin 0, TX = Pin 1
SoftwareSerial BTSerial(0, 1);

void setup() {
  Serial.begin(9600);  
  BTSerial.begin(9600);    
  Serial.println("Setup Complete. Waiting for data...");
}

void loop() {
  // Check for data in BL module
  if (BTSerial.available() > 0) {
    // Print received data
    int receivedValue = BTSerial.parseInt();
    Serial.println("Received integer: ");
    Serial.println(receivedValue);
  }
}