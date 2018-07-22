#ifndef __GAME_AREA__
#define __GAME_AREA__

#include <iostream>
#include <random>
#include "position.hpp"
#include "movable.hpp"
#include "goal.hpp"

class GameArea
{
public:
  GameArea();
  void render();
  void execute();
  void randomizeMovable();

  int getWidth() const;
  int getHeight() const;
  int getScore() const;
  int getSteps() const;
  int getShots() const;
  bool getScoredFlag() const;
  Movable &getBall();
  Movable &getPlayer();
  Goal &getGoal();

private:
  int width;
  int height;
  int score;
  int steps;
  int shots;
  bool scoredFlag;
  Movable ball;
  Movable player;
  Goal goal;

  bool shotScored();
};

#endif