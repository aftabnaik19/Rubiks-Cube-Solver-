#include "RubiksCube.h"

class RubiksCube3dArray : public RubiksCube
{
private:
public:
  char cube[6][3][3]{};
  RubiksCube3dArray()
  {
    for (int face = 0; face < 6; face++)
    {
      for (int row = 0; row < 3; row++)
      {
        for (int col = 0; col < 3; col++)
        {
          cube[face][row][col] = getColorLetter(COLOR(face));
        }
      }
    }
  }

  COLOR getColor(FACE face, int row, int col) const override
  {
    char color = cube[int(face)][row][col];
    switch (color)
    {
    case 'B':
      return COLOR::BLUE;
    case 'R':
      return COLOR::RED;
    case 'G':
      return COLOR::GREEN;
    case 'O':
      return COLOR::ORANGE;
    case 'Y':
      return COLOR::YELLOW;
    default:
      return COLOR::WHITE;
    }
  }

  bool isSolved() const override
  {
    // add logic
    return true;
  }
};
