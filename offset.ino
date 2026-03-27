#include <Wire.h>
#include <MPU6050_tockn.h>

MPU6050 mpu6050(Wire);

void setup() {
  Serial.begin(115200);
  Wire.begin();

  mpu6050.begin();

  Serial.println("Keep still...");
  delay(3000);

  mpu6050.calcGyroOffsets(true);

  Serial.print("GyroX offset: ");
  Serial.println(mpu6050.getGyroXoffset());
  Serial.print("GyroY offset: ");
  Serial.println(mpu6050.getGyroYoffset());
  Serial.print("GyroZ offset: ");
  Serial.println(mpu6050.getGyroZoffset());
}

void loop() {}
