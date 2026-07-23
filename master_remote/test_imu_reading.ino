#include <Wire.h>
#include <FastIMU.h>

MPU6500 IMU;

calData calib = { 0 };
AccelData accelData;
GyroData gyroData;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  delay(1000);

  // Check for init error
  int err = IMU.init(calib, 0x68);
  if (err != 0) {
    Serial.print("IMU init failed. Error code: ");
    Serial.println(err);
    while (1);
  }
  Serial.println("MPU6500 ready.");
}

void loop() {
  IMU.update();
  IMU.getAccel(&accelData);
  IMU.getGyro(&gyroData);   

  // Read and Print IMU readings 
  Serial.print("Accel X: "); Serial.print(accelData.accelX);
  Serial.print("  Y: ");     Serial.print(accelData.accelY);
  Serial.print("  Z: ");     Serial.println(accelData.accelZ);

  Serial.print("Gyro  X: "); Serial.print(gyroData.gyroX);
  Serial.print("  Y: ");     Serial.print(gyroData.gyroY);
  Serial.print("  Z:");     Serial.println(gyroData.gyroZ);

  Serial.println("---");
  delay(500);

  // TODO: 
  // Caliberate/test tilting angles to see what is considered up, down, right or left
  // Caliberate further to determine the margin of tolerance for the different directions
  // Make state machine to link angle readings to directional instructions. 
  // Translate state machine to switch case block
}
