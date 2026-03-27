#define ENA 10
#define IN1 9
#define IN2 8
#define ENB 5
#define IN3 7
#define IN4 6

int speed = 20;

void setup() {
  Serial.begin(115200);
  pinMode(ENA, OUTPUT); pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);

  // Forward direction
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);

  Serial.println("Increasing speed from 0...");
  Serial.println("Note the value when motors JUST START moving");
}

void loop() {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);

  Serial.print("Speed: ");
  Serial.println(speed);

  speed++;

  if (speed > 255) {
    speed = 0;
    Serial.println("--- Restarting from 0 ---");
    delay(2000);
  }

  delay(100);  // slow increase so you can notice exact moment
}
