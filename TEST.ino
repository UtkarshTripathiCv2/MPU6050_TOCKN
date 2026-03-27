#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

void setup() {
  Serial.begin(115200);
  Wire.begin();
  
  Serial.println("Starting MPU6500 (ID 0x70) Calibration...");
  mpu6050.begin();
  
  // Keep the sensor perfectly still during this part!
  mpu6050.calcGyroOffsets(true);
  
  Serial.println("Done! Ready for data.");
}

void loop() {
  mpu6050.update();

  static uint32_t prev_ms = millis();
  if (millis() - prev_ms > 100) {
    Serial.print("AngleX: "); Serial.print(mpu6050.getAngleX());
    Serial.print("  AngleY: "); Serial.print(mpu6050.getAngleY());
    Serial.print("  AngleZ: "); Serial.println(mpu6050.getAngleZ());
    prev_ms = millis();
  }
}


or or or 
#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

void setup() {
  Serial.begin(115200);
  Wire.begin();
  Wire.setClock(100000);  // 🔥 stability

  Serial.println("MPU START");

  mpu6050.begin();   // should NOT hang now

  Serial.println("Calibrating... Keep still");
  delay(2000);

  mpu6050.calcGyroOffsets(true);

  Serial.println("READY");
}

void loop() {
  mpu6050.update();

  Serial.print("X: ");
  Serial.print(mpu6050.getAngleX());
  Serial.print("  Y: ");
  Serial.print(mpu6050.getAngleY());
  Serial.print("  Z: ");
  Serial.println(mpu6050.getAngleZ());

  delay(100);
}
