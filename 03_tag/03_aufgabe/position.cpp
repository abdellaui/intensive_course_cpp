#include "position.hpp"
// Default-init x = 0, y = 0;
Position::Position()
    : x(0), y(0){
                // TODO:: sortable maybe
            };

Position::Position(const int x, const int y)
    : x(x), y(y)
{
    // TODO: sortable maybe
}

bool Position::operator==(const Position &that)
{
    return (this->getX() == that.getX() && this->getY() == that.getY());
}

DIRECTION Position::directionTo(const Position &that)
{
        if (this->x > that.getX())
            return LEFT;
        else if (this->x < that.getX()) // this_RIGHT_TO_that
            return RIGHT;
        else if (this->y > that.getY()) // this_UNDER_that
            return TOP;
        else if(this->y < that.getY()) // this_OVER_that
            return BOTTOM;
        
        return NO_DIRECTION;
}

// Getter - Setter
void Position::setX(const int x)
{
    this->x = x;
}
void Position::setY(const int y)
{
    this->y = y;
}

int Position::getX() const
{
    return this->x;
}
int Position::getY() const
{
    return this->y;
}
