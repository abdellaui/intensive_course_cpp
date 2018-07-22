#include "movable.hpp"

void Movable::move(DIRECTION dir)
{
    if (dir == TOP)
        this->position.setY(this->position.getY() - 1);
    if (dir == RIGHT)
        this->position.setX(this->position.getX() + 1);
    if (dir == BOTTOM)
        this->position.setY(this->position.getY() + 1);
    if (dir == LEFT)
        this->position.setX(this->position.getX() - 1);
}
void Movable::setPosition(Position position)
{
    this->position = position;
}

// GETTER

Position &Movable::getPosition()
{
    return this->position;
}
