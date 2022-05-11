using namespace pros;

#include <cmath>
#include <stdio>
#include "api.h"
//Define the wheel encoders
Rotation leftTracking(2);
Rotation rightTracking(1);
Rotation centerTracking(3);
//The position of the wheels this iteration of the loop
double currentLeft;
double currentRight;
double currentCenter;
//Distance traveled by the wheels
double deltaLeft;
double deltaRight;
double deltaCenter;
//Totale distance traveled by the wheels
double totalLeft = 0;
double totalRight = 0;
double totalCenter = 0;
//Wheel diameters and distances of the tracking wheels from the tracking center
int wheel_radius = 2;
double wheel_cir = wheel_radius * 2 * M_PI;
//Distance from tracking center to right tracking wheel
double sL = 7.250;
//Distance from tracking center to right tracking wheel
double sR = 7.250;
//Distance from tracking center to center tracking wheel
double sS - 7.250;
double theta = M_PI;
double deltaTheta;
//Coords before rotation
double localXCoord;
double localYCoord;
//Coords aligned with the field
double xCoord;
double yCoord;

void resetEncoders() {
  leftTracking.reset_position();
  rightTracking.reset_position();
  centerTracking.reset_position();
}

void odon() {
  //infinite loop, so it can be run as a task
  while true {
  resetEncoders();
  //Get encoder position in centidegrees
  currentLeft = leftTracking.get_position();
  currentRight = rightTracking.get_position();
  currentCenter = centerTracking.get_position();
  //convert position to distance traveled
  deltaLeft = wheel_cir / 36000 * currentLeft;
  deltaRight = wheel_cir / 36000 * currentRight;
  deltaCenter = wheel_cir / 36000 * currentCenter;
  //Update the total distance
  totalLeft = totalLeft + deltaLeft;
  totalRight = totalRight + deltaRight;
  totalCenter = totalCenter + deltaCenter;
  std::cout << "Left Traveled:" << totalLeft << std::endl;
  std::cout << "Right Traveled:" << totalRight << std::endl;
  std::cout << "Center Traveled:" << totalCenter << std::endl;

  theta = M_PI;
  thetaNew = (totalLeft - totalRight)/(sL+sR);
  deltaTheta = theta - thetaNew;

  //Local coords
  localXCoord = 2 * sin(deltaTheta\2) * deltaS/deltatheta + sS;
  localYCoord = 2 * sin(deltatheta\2) * deltaR/deltatheta + sR;

  //Global coords
  xCoord = localXCoord * cos(deltaTheta) + localYCoord * cos(deltaTheta);
  yCoord = localXCoord * sin(deltaTheta) + localYCoord * sin(deltaTheta);
  std::cout << "xCoord" << xCoord << std::endl;
  std::cout << "yCoord" << yCoord << std::endl;
  delay(10);
  }
}
