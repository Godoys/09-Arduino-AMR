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

/*
 * =================
 *  Map Definitions
 * =================
*/

Map::Map(Point start, Point end){
  int rows = end.getY();
  int clms = end.getX();

  map = new Point*[rows];

  for (int r = 0; r < rows; r++){

    map[r] = new Point[clms];

    for (int c = 0; c < clms; c++){

      map[r][c] = Point(r, c, 0);

    }
  }
}
