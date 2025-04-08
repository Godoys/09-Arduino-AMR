#include "Map.h"

Point::Point(int x, int y, int ocp) : p{x, y, ocp} {}

int Point::getX() { return p.x; }

int Point::getY() { return p.y; }

int Point::getOcp() { return p.ocp; }

void Point::setOcp(int ocp) { p.ocp = ocp; }
