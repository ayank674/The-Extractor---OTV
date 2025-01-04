void arenaNav() {
  if (getY() < 1.35) {
    turnToTheta(HALF_PI);
    while (getY() < 1.35) {
      moveForward();
    }
  } else if (getY() > 1.8) {
    turnToTheta(-HALF_PI);
    while (getY() > 1.75) {
      moveForward();
    }
  }
  stopMotors();
  turnToTheta(0);
  myServo.write(85);
  while (getX() < 3.8) {
    moveForward();
  }
  stopMotors();
}