#include "map.h"

/*
 * ====================
 *  Points Definitions
 * ====================
*/

Point::Point(int x, int y, int ocp)
  : p{x, y, ocp} {};

Point::Point() = default;

int Point::getX(){
  return this->p.x;
}

int Point::getY(){
  return this->p.y;
}

int Point::getOcp(){
  return this->p.ocp;
}

/*
 * =================
 *  Map Definitions
 * =================
*/

Map::Map(Point start, Point end){
  rows = end.getY();
  clms = end.getX();

  map = new Point*[rows];

  for (int r = 0; r < rows; r++){

    map[r] = new Point[clms];

    for (int c = 0; c < clms; c++){

      map[r][c] = Point(r, c, 0);

    }
  }
}


void Map::printMap(){
  
  for (int r = 0; r < rows; r++){

    for (int c = 0; c < clms; c++){

      Serial.print("(");
      Serial.print((map[r][c]).getX());
      Serial.print(", ");
      Serial.print((map[r][c]).getY());
      Serial.print(", ");
      Serial.print((map[r][c]).getOcp());
      Serial.print(") ");
    }

    Serial.println();
  }
}

void Map::generateBoarders(){

  for (int r =0; r < rows; r++){

    for (int c = 0; c < clms; c++){
      Point p = map[r][c];
      int x =   p.getX();
      int y =   p.getY();
      int ocp = p.getOcp();

      if (x == 0 || x == (rows - 1) || y == 0 || y == (clms - 1)){
        map[r][c] = Point(r, c, 1);
      }

    }
  }
}

