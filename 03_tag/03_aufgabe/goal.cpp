#include "goal.hpp"
Goal::Goal()
    : length(0), borderPosition(TOP)
{
    // TODO:
}
Goal::Goal(int lenght, DIRECTION borderPosition, Position position)
    : length(lenght), borderPosition(borderPosition), position(position)
{
    // TODO:
}

bool Goal::insideGoal(Position & obj)
{
    Position currentGoalPosition = this->position;
    for (int x = 0; x < this->length; x++)
    {
        if (currentGoalPosition == obj)
            return true;

        if (this->borderPosition == TOP || this->borderPosition == BOTTOM)
        {
            currentGoalPosition.setX(currentGoalPosition.getX() + 1);
        }
        else // if(this->borderPosition == LEFT || this->borderPosition == RIGHT)
        {
            currentGoalPosition.setY(currentGoalPosition.getY() + 1);
        }
    }
    return false;
}

// Getter

int Goal::getLength() const
{
    return this->length;
}

DIRECTION Goal::getBorderPosition() const
{
    return this->borderPosition;
}

Position &Goal::getPosition()
{
    return this->position;
}
