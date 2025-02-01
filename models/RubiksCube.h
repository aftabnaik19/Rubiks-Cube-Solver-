#ifndef RUBIKS_CUBE_SOLVER_GENERIC_CUBE
#define RUBIKS_CUBE_SOLVER_GENERIC_CUBE

#include <bits/stdc++.h>

class RubiksCube
{
public:
  enum class COLOR
  {
    WHITE,
    YELLOW,
    RED,
    GREEN,
    ORANGE,
    BLUE
  };
  enum class MOVE
  {
    L,
    L2,
    LPRIME,
    R,
    R2,
    RPRIME,
    U,
    U2,
    UPRIME,
    B,
    B2,
    BPRIME,
    F,
    F2,
    FPRIME,
    D,
    D2,
    DPRIME
  };
  enum class FACE
  {
    UP,
    DOWN,
    FRONT,
    LEFT,
    BACK,
    RIGHT
  };

  // helper function to get colour of each cubie
  virtual COLOR getColor(FACE face, int row, int col) const = 0;

  // to get color letter for each color
  static char getColorLetter(COLOR color);

  // to print the state of the cube
  //        U U U
  //        U U U
  //        U U U
  // L L L  F F F  R R R  B B B
  // L L L  F F F  R R R  B B B
  // L L L  F F F  R R R  B B B
  //        D D D
  //        D D D
  //        D D D
  void printCube() const;

  virtual bool isSolved() const = 0;

  static std::string getMoveNotation(MOVE move);
};

#endif
