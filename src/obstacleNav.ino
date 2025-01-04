void obstacleNav() {
  turnToTheta(0);
  Enes100.println("Entering while loop....");
  while (getX() < 3) {
  Enes100.println("Entered while loop....");
    if (getDistance() < 300) {
      stopMotors();
      nextZone();
    } else {
      moveForward();
    }
  }
  stopMotors();
}

void nextZone() {
  if (getY() < 0.75) {
    turnToTheta(HALF_PI);
    while (getY() < 0.8) {
      moveForward();
    }
  } else if (getY() < 1.25) {
    turnToTheta(HALF_PI);
    while (getY() < 1.3) {
      moveForward();
    }
  } else {
    turnToTheta(-HALF_PI);
    while (getY() > 0.75) {
      moveForward();
    }

  }
  stopMotors();
  turnToTheta(0);
}