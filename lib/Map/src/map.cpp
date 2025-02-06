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

      Point p = map[r][c];
      int ocp = p.getOcp();

      if (ocp == 1){
        Serial.print("■ ");
      } else {
        Serial.print("○ ");
      }

    }

    Serial.println();
  }
}

void Map::genBoarders(){

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

void Map::genObstacle(Point start, Point end){

  int x1 = start.getX();
  int y1 = start.getY();

  int x2 = end.getX();
  int y2 = end.getY();

  int s = (y2 - y1)/(x2 - x1);
  int b = (-1 * s * x1) + y1;

  for (int r = 0; r < rows; r++){

    int y = s * r + b;

    map[r][y] = Point(r, y, 1);

  }
}










