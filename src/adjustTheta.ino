#include "arduino_secrets.h"

float adjustTheta(float theta) {
  if (theta > PI) {
    return theta - 2 * PI;
  } else if (theta < 0) {
    return theta + 2 * PI;
  } else {
    return theta;
  }
}