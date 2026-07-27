#include <Wire.h>
#include <FastIMU.h>
#include <SoftwareSerial.h>

// RX = Pin 2, TX = Pin 3
SoftwareSerial BTSerial(2, 3);
// Instruction to send over BL module
String instr;

MPU6500 IMU;

calData calib = { 0 };
AccelData accelData;
GyroData gyroData;

// Angles
float accAngleX, accAngleY;
float roll = 0, pitch = 0;

// Gyro Offsets 
float gyroX_offset = 1.85;
float gyroY_offset = 1.37;
float gyroZ_offset = 0.03;

// Time Vars
unsigned long previousTime = 0;
float elapsedTime = 0;
unsigned long prevPrintTime = 0;
const unsigned long PRINT_INTERVAL = 1000; // print every 1s

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600); 
  Wire.begin();
  delay(1000);

  int err = IMU.init(calib, 0x68);
  if (err != 0) {
    Serial.print("IMU init failed. Error code: ");
    Serial.println(err);
    while (1);
  }

  Serial.println("Setup Complete. Sending data...");
  previousTime = millis();
}

void loop() {
  // calculate delta time
  unsigned long currentTime = millis();
  elapsedTime = (currentTime - previousTime) / 1000.0; // convert to seconds
  previousTime = currentTime;

  // get sensor data
  IMU.update();
  IMU.getAccel(&accelData);
  IMU.getGyro(&gyroData);

  float AccX = accelData.accelX;
  float AccY = accelData.accelY;
  float AccZ = accelData.accelZ;

  // apply calibrations 
  float GyroX = gyroData.gyroX - gyroX_offset;
  float GyroY = gyroData.gyroY - gyroY_offset;
  float GyroZ = gyroData.gyroZ - gyroZ_offset;

  // calculate tilt angles and apply filters
  accAngleX = (atan(AccX / sqrt(pow(AccY, 2) + pow(AccZ, 2))) * 180.0 / PI);
  accAngleY = (atan(-1 * AccY / sqrt(pow(AccX, 2) + pow(AccZ, 2))) * 180.0 / PI);

  roll  = 0.96 * (roll + GyroY * elapsedTime) + 0.04 * accAngleX; // For left/right tilt
  pitch = 0.96 * (pitch + (-GyroX) * elapsedTime) + 0.04 * accAngleY; // For up/down tilt

  // Print results
  if (currentTime - prevPrintTime >= PRINT_INTERVAL) {
    prevPrintTime = currentTime; // Reset timer

    // print pitch and roll results
    Serial.print("Pitch: ");
    Serial.print(pitch);
    Serial.print("  |  Roll: ");
    Serial.print(roll);
    Serial.print("  --> State: ");

    // apply thresholds and print corresponding state 
    if (pitch > 20.0) {
      instr = "REVERSE";
    } else if (pitch < -20.0) {
      instr = "FORWARD";
    } else if (roll > 20.0) {
      instr = "RIGHT";
    } else if (roll < -20.0) {
      instr = "LEFT";
    } else {
      instr = "BRAKE";
    }
    
    // Send instr over BL module
    BTSerial.println(instr);
    Serial.print("Sent Instr: ");
    Serial.println(instr);
  }

  delay(20); // 50Hz

}