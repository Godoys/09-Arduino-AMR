
//------------------------------------------
// Point Class Definition
//------------------------------------------

class Point {

  // A Point is a reference to the (X, Y, OCP) values stored in a Map file.

  struct pointStruct {
    int x;
    int y;
    int ocp;
  };

  pointStruct p;

public:
  Point(int x, int y, int ocp);

  int getX();

  void setX(int n);

  int getY();

  void setY(int n);

  int getOcp();

  void setOcp(int n);
};
