#include "RubiksCube.h"
#include "../utils/Random.h"

void RubiksCube::printState() const {
  std::cout << "Rubiks Cube State\n\n";

  // printing the top face
  for (int row = 0; row <= 2; row++) {
    for (int spaces = 0; spaces < 7; spaces++) {
      std::cout << ' ';
    }
    for (int col = 0; col <= 2; col++) {
      std::cout << getColorLetter(getColor(RubiksCube::FACE::UP, row, col))
                << ' ';
    }
    std::cout << '\n';
  }

  // printing the Left, front, right and back faces
  for (int row = 0; row <= 2; row++) {
    for (int col = 0; col <= 2; col++) {
      std::cout << getColorLetter(getColor(RubiksCube::FACE::LEFT, row, col))
                << ' ';
    }
    std::cout << ' ';
    for (int col = 0; col <= 2; col++) {
      std::cout << getColorLetter(getColor(RubiksCube::FACE::FRONT, row, col))
                << ' ';
    }
    std::cout << ' ';

    for (int col = 0; col <= 2; col++) {
      std::cout << getColorLetter(getColor(RubiksCube::FACE::RIGHT, row, col))
                << ' ';
    }
    std::cout << ' ';

    for (int col = 0; col <= 2; col++) {
      std::cout << getColorLetter(getColor(RubiksCube::FACE::BACK, row, col))
                << ' ';
    }
    std::cout << '\n';
  }

  // printing the bottom face
  for (int row = 0; row <= 2; row++) {
    for (int spaces = 0; spaces < 7; spaces++) {
      std::cout << ' ';
    }
    for (int col = 0; col <= 2; col++) {
      std::cout << getColorLetter(getColor(RubiksCube::FACE::DOWN, row, col))
                << ' ';
    }
    std::cout << std::endl;
  }
}

char RubiksCube::getColorLetter(COLOR color) {
  switch (color) {
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
  __builtin_unreachable();
}

std::string RubiksCube::getMoveNotation(MOVE ind) {
  switch (ind) {
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
  __builtin_unreachable();
}

RubiksCube& RubiksCube::performMove(MOVE move) {
  switch(move) {
      case MOVE::L : 
       return this->l();

      case MOVE::L2 :
       return this->l2();

      case MOVE::LPRIME :
       return this->lPrime();

      case MOVE::R :
       return this->r();

      case MOVE::R2 :
       return this->r2();

      case MOVE::RPRIME :
       return this->rPrime();

      case MOVE::U :
       return this->u();

      case MOVE::U2 :
       return this->u2();

      case MOVE::UPRIME :
       return this->uPrime();

      case MOVE::B :
       return this->b();

      case MOVE::B2 :
       return this->b2();

      case MOVE::BPRIME :
       return this->bPrime();

      case MOVE::F :
       return this->f();

      case MOVE::F2 :
       return this->f2();

      case MOVE::FPRIME :
       return this->fPrime();

      case MOVE::D : 
       return this->d();

      case MOVE::D2 :
       return this->d2();

      case MOVE::DPRIME :
       return this->dPrime();
  }
  __builtin_unreachable();
}

RubiksCube &RubiksCube::invertMove(MOVE move) {
  switch (move) {
  case MOVE::L:
    return this->lPrime();
  case MOVE::LPRIME:
    return this->l();
  case MOVE::L2:
    return this->l2();
  case MOVE::R:
    return this->rPrime();
  case MOVE::RPRIME:
    return this->r();
  case MOVE::R2:
    return this->r2();
  case MOVE::U:
    return this->uPrime();
  case MOVE::UPRIME:
    return this->u();
  case MOVE::U2:
    return this->u2();
  case MOVE::D:
    return this->dPrime();
  case MOVE::DPRIME:
    return this->d();
  case MOVE::D2:
    return this->d2();
  case MOVE::F:
    return this->fPrime();
  case MOVE::FPRIME:
    return this->f();
  case MOVE::F2:
    return this->f2();
  case MOVE::B:
    return this->bPrime();
  case MOVE::BPRIME:
    return this->b();
  case MOVE::B2:
    return this->b2();
  }
  __builtin_unreachable();
}

std::vector<RubiksCube::MOVE> RubiksCube::randomShuffle(unsigned int shuffleMovesCount) {
  std::vector<MOVE> randomMovesPerformed;
  for (int turn = 0; turn < shuffleMovesCount; turn++) {
    unsigned int randomMove = Random::get(1u, 18u);
    randomMovesPerformed.push_back(static_cast<MOVE>(randomMove));
    this->performMove(randomMovesPerformed.back());
  }
  return randomMovesPerformed;
}


