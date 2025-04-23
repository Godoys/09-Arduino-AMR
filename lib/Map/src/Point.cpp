#include "../include/Map.h"

Point::Point(int x, int y, int ocp) : p{x, y, ocp} {};

int Point::getX() { return p.x; }

void Point::setX(int n) { p.x = n; }

int Point::getY() { return p.y; }

void Point::setY(int n) { p.y = n; }

int Point::getOcp() { return p.ocp; }

void Point::setOcp(int n) { p.ocp = n; }
