
/**********************************
LIBRARIES
**********************************/

#include <vl53l4cd_api.h>
#include <vl53l4cd_class.h>

#include <Servo.h>

#include <Enes100.h>

// #include <Adafruit_LIS2MDL.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>


/**********************************
DEFINITIONS
**********************************/

// Motors
#define IN1 22 //front-right
#define IN2 23
#define IN3 24 //back-right
#define IN4 25
#define ENA 5
#define ENB 4

#define IN5 53 //back-left
#define IN6 52
#define IN7 51 // front-left
#define IN8 50
#define ENA2 2
#define ENB2 3

#define DUTY_PIN 44
// Wifi Module
#define WIFI_MODULE_TX 10
#define WIFI_MODULE_RX 11
#define MARKER_ID 558

// Servo
#define SERVO_PIN A0
Servo myServo;

// TOF
#define XSHUT A1
#define TOF_IN 7
VL53L4CD sensor_vl53l4cd_sat(&Wire, XSHUT);

// Magnetometer
#define MAG_IN   38
#define MAG_GND 40

/**********************************
MAIN
**********************************/

void setup() {
  pinMode(MAG_IN, OUTPUT);
  digitalWrite(MAG_IN, HIGH);
  pinMode(MAG_GND, OUTPUT);
  digitalWrite(MAG_GND, LOW);
  Enes100.begin("Chiu you up and spit you out", DATA, MARKER_ID, WIFI_MODULE_TX, WIFI_MODULE_RX);
  setupMotors();
  setupToF();

  setupServo();
  setupMag();
  if (getX() < 1) {
    missionNav();
    pylon();
  }
  obstacleNav();
  arenaNav();
}


/**********************************
LOOP
**********************************/
void loop() {
}                                       