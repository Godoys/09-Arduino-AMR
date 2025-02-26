#include <Arduino.h>
#include "map.h"
#include "microsd.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  MicroSD mSD(10);
  myFile file(mSD, mSD.open("map.csv", "O_RDWR"));
  Map m1(file);
}

void loop() {
  // put your main code here, to run repeate
}
