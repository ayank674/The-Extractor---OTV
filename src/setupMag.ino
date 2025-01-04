void setupMag() {
  
  pinMode(MAG_IN, OUTPUT);
  digitalWrite(MAG_IN, HIGH);
  pinMode(MAG_GND, OUTPUT);
  digitalWrite(MAG_GND, LOW);
  
  /* Initialise the sensor */
  if (!lis2mdl.begin()) {  // I2C mode
  //   /* There was a problem detecting the LIS2MDL ... check your connections */
    Enes100.println("Ooops, no LIS2MDL detected ... Check your wiring!");
     while (1) delay(10);
  }

  lis2mdl.enableAutoRange(true);
}