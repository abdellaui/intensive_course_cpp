#ifndef __MOVABLE__
#define __MOVABLE__

#include "position.hpp"

class Movable
{
public:
  void move(DIRECTION direction);
  void setPosition(Position position);
  Position &getPosition();

private:
  Position position;
};

#endif