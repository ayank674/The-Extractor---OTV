void missionNav() {
  if (getY() < 1) {
    turnToTheta(HALF_PI);
  } else {
    turnToTheta(-HALF_PI);
  }

  while (getDistance() > 28) {
    moveForward();
  }
  stopMotors();
}