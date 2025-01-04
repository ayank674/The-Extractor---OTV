void turnToTheta(float theta) {
  float diff;
  float turnDiff = adjustTheta(theta) - adjustTheta(getTheta());
  
  do {
    if (turnDiff > PI || (turnDiff > -PI && turnDiff < 0)) {
      turnRight();
    } else {
      turnLeft();
    }
    delay(70);
    
    stopMotors();
    delay(500);

    float curr = getTheta();
    diff = curr - theta;

    turnDiff = adjustTheta(theta) - adjustTheta(curr);
    
  } while(diff > 0.05 || diff < -0.05);

  stopMotors();

}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  analogWrite(ENA2, 200);
  analogWrite(ENB2, 200);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  analogWrite(ENA2, 200);
  analogWrite(ENB2, 200);
}