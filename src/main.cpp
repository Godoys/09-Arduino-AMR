#include <Arduino.h>
#include "map.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  Point p1(0, 0, 0);
  Point p2(15, 15, 0);

  Map m1(p1, p2);
  //m1.genBoarders();
  m1.genObstacle(Point (0, 2, 1), Point (1, 5, 1));
  m1.printMap();
}

void loop() {
  // put your main code here, to run repeate
}
