#ifndef __GOAL__
#define __GOAL__

#include "position.hpp"

class Goal
{
public:
  Goal();
  Goal(int lenght, DIRECTION direction, Position position);
  bool insideGoal(Position &);

  int getLength() const;
  DIRECTION getBorderPosition() const;
  Position &getPosition();

private:
  int length;
  DIRECTION borderPosition;
  Position position;
};
#endif