#ifndef __POSITION__
#define __POSITION__

enum DIRECTION
{
  TOP,
  RIGHT,
  BOTTOM,
  LEFT,
  NO_DIRECTION
};

class Position
{
public:
  Position();
  Position(const int x, const int y);

  bool operator==(const Position &);
  DIRECTION directionTo(const Position &);

  void setX(const int x);
  void setY(const int y);

  int getX() const;
  int getY() const;

private:
  int x;
  int y;
};

#endif