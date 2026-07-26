#include <SoftwareSerial.h>

// RX = Pin 2, TX = Pin 3
SoftwareSerial BTSerial(2, 3);

// int count = 0; // test message to send
// Array of instructions to pick from
const char* instructions[] = {
  "FORWARD",
  "REVERSE",
  "LEFT",
  "RIGHT"
};

void setup() {
  Serial.begin(9600);  
  BTSerial.begin(9600);  

  // Seed RNG
  randomSeed(analogRead(0));

  Serial.println("Setup Complete. Sending data...");
}

void loop() {
  // Pick random instruction
  int randomIndex = random(0, 4);
  String instr = instructions[randomIndex];

  // Send instr over BL module
  BTSerial.println(instr);
  Serial.print("Sent Instr: ");
  Serial.println(instr);
  
  //count++;
  delay(3000); // Send once per 3s
}