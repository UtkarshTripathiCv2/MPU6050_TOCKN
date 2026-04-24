#include <Wire.h>
#include <MPU6050_tockn.h>

MPU6050 mpu6050(Wire);

void setup() {
  Serial.begin(115200);
  Wire.begin();

  mpu6050.begin();

  Serial.println("Calibrating... Keep sensor still");
  delay(2000);
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  mpu6050.update();

  Serial.print("Accel X: ");
  Serial.print(mpu6050.getAccX());
  Serial.print(" | Y: ");
  Serial.print(mpu6050.getAccY());
  Serial.print(" | Z: ");
  Serial.println(mpu6050.getAccZ());

  Serial.print("Gyro X: ");
  Serial.print(mpu6050.getGyroX());
  Serial.print(" | Y: ");
  Serial.print(mpu6050.getGyroY());
  Serial.print(" | Z: ");
  Serial.println(mpu6050.getGyroZ());

  Serial.println("----------------------");

  delay(500);
}
