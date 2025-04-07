#include <Arduino.h>

#include "SD.h"

void setup() {

  Serial.begin(115200);

  pinMode(4, OUTPUT);

  SD.begin(4);

  File myMap = SD.open("map.txt", FILE_WRITE);

  if (myMap) {
    myMap.println("(0;0;0),(1;0;0),(2;0;0)");
  }

  myMap.close();
}

void loop() {}
