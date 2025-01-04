void pylon() {

  myServo.write(0);
  for (int pos = 0; pos <= 90; pos += 1) { 
    myServo.write(pos);           
    delay(200);                       
  }

  moveBackward();
  delay(150);
  stopMotors();

  for (int pos = 90; pos <= 150; pos += 1) { 
    myServo.write(pos);           
    delay(200);                       
  }

  sensors_event_t event;
  lis2mdl.getEvent(&event);

  if (abs(event.magnetic.z) > 250 || abs(event.magnetic.y) > 250 || abs(event.magnetic.x) > 250) {
    Enes100.mission(MAGNETISM, MAGNETIC);
  } else {
    Enes100.mission(MAGNETISM, NOT_MAGNETIC);
  }

  int onTime = pulseIn(DUTY_PIN, HIGH);
  int offTime = pulseIn(DUTY_PIN, LOW);
  int totalTime = onTime + offTime;
  int duty = ((float) onTime/ totalTime)*100;
  Enes100.mission(CYCLE, duty);

  myServo.write(0);
  moveBackward();
  delay(1000);
  stopMotors();
  myServo.write(40);
  turnToTheta(0);
}