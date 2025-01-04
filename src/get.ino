float getTheta() {
  checkConnection();

  float theta;
  theta = Enes100.getTheta();

  return theta;
}

float getY() {
  checkConnection();
  
  float y;
  do {
    y = Enes100.getY();
  } while (y < 0);

  return y;
}

float getX() {
  checkConnection();
  
  float x;
  do {
    x = Enes100.getX();
  } while (x < 0);

  return x;
}

void checkConnection() {
  if (!Enes100.isConnected()) {
    delay(500);
    Enes100.begin("Chiu you up and spit you out", DATA, MARKER_ID, WIFI_MODULE_TX, WIFI_MODULE_RX);
  }
}