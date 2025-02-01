#include "models/3DArrayModel.cpp"
using namespace std;

int main()
{
  RubiksCube3dArray cube1, cube2, cube3, cube4, cube5, cube6;
  cube1.d2();
  cube1.printState();
  cube1.b2();
  cube1.printState();
  cube1.l2();
  cube1.printState();
  cube1.d();
  cube1.printState();
  cube1.r();
  cube1.printState();
  cube1.bPrime();
  cube1.printState();

  return 0;
}
