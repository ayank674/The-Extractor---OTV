void setupMotors() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);
  pinMode(ENA2, OUTPUT);
  pinMode(ENB2, OUTPUT);

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  analogWrite(ENA2, 200);
  analogWrite(ENB2, 200);
}