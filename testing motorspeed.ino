#define ENA 10
#define IN1 9
#define IN2 8
#define IN3 7
#define IN4 6
#define ENB 5

void setup() {
  Serial.begin(115200);
  pinMode(ENA, OUTPUT); pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void loop() {
  // TEST 1 - runs for 2 seconds
  Serial.println("TEST 1 - should go FORWARD");
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  delay(2000);

  // STOP
  analogWrite(ENA, 0); analogWrite(ENB, 0);
  delay(1000);
  analogWrite(ENA, 150); analogWrite(ENB, 150);

  // TEST 2 - runs for 2 seconds
  Serial.println("TEST 2 - should go BACKWARD");
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  delay(2000);

  // STOP
  analogWrite(ENA, 0); analogWrite(ENB, 0);
  delay(3000);
  analogWrite(ENA, 150); analogWrite(ENB, 150);
}
