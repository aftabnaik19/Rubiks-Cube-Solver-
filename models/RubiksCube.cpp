#include "RubiksCube.h"
#include <string>

void RubiksCube::printCube() const
{
  std::cout << "Rubiks Cube State\n\n";

  // printing the top face
  for (int row = 0; row <= 2; row++)
  {
    for (int spaces = 0; spaces < 7; spaces++)
    {
      std::cout << ' ';
    }
    for (int col = 0; col <= 2; col++)
    {
      std::cout << getColorLetter(getColor(RubiksCube::FACE::UP, row, col))
                << ' ';
    }
    std::cout << '\n';
  }
  for (int row = 0; row <= 2; row++)
  {

    // printing the Left, front, right and back faces
    for (int col = 0; col <= 2; col++)
    {
      std::cout << getColorLetter(getColor(RubiksCube::FACE::LEFT, row, col))
                << ' ';
    }
    std::cout << ' ';
    for (int col = 0; col <= 2; col++)
    {
      std::cout << getColorLetter(getColor(RubiksCube::FACE::FRONT, row, col))
                << ' ';
    }
    std::cout << ' ';

    for (int col = 0; col <= 2; col++)
    {
      std::cout << getColorLetter(getColor(RubiksCube::FACE::RIGHT, row, col))
                << ' ';
    }
    std::cout << ' ';

    for (int col = 0; col <= 2; col++)
    {
      std::cout << getColorLetter(getColor(RubiksCube::FACE::BACK, row, col))
                << ' ';
    }
    std::cout << '\n';
  }
  for (int row = 0; row <= 2; row++)
  {

    // printing the bottom face
    for (int spaces = 0; spaces < 7; spaces++)
    {
      std::cout << ' ';
    }
    for (int col = 0; col <= 2; col++)
    {
      std::cout << getColorLetter(getColor(RubiksCube::FACE::DOWN, row, col))
                << ' ';
    }
    std::cout << std::endl;
  }
}

char RubiksCube::getColorLetter(COLOR color)
{
  switch (color)
  {
  case COLOR::BLUE:
    return 'B';
  case COLOR::WHITE:
    return 'W';
  case COLOR::RED:
    return 'R';
  case COLOR::GREEN:
    return 'G';
  case COLOR::YELLOW:
    return 'Y';
  case COLOR::ORANGE:
    return 'O';
  }
}

std::string RubiksCube::getMoveNotation(MOVE ind)
{
  switch (ind)
  {
  case MOVE::L:
    return "L";
  case MOVE::LPRIME:
    return "L'";
  case MOVE::L2:
    return "L2";
  case MOVE::R:
    return "R";
  case MOVE::RPRIME:
    return "R'";
  case MOVE::R2:
    return "R2";
  case MOVE::U:
    return "U";
  case MOVE::UPRIME:
    return "U'";
  case MOVE::U2:
    return "U2";
  case MOVE::D:
    return "D";
  case MOVE::DPRIME:
    return "D'";
  case MOVE::D2:
    return "D2";
  case MOVE::F:
    return "F";
  case MOVE::FPRIME:
    return "F'";
  case MOVE::F2:
    return "F2";
  case MOVE::B:
    return "B";
  case MOVE::BPRIME:
    return "B'";
  case MOVE::B2:
    return "B2";
  }
}
