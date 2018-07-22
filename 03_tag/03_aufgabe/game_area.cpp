#include "game_area.hpp"
GameArea::GameArea()
    : score(0), steps(0), shots(0), scoredFlag(false)
{
    std::srand(std::time(nullptr)); // seed-gen.

    int min = 15;
    int max = 20;
    this->width = (std::rand() % (max - min)) + min;
    this->height = (std::rand() % (max - min)) + min;
    this->randomizeMovable(); // ball & player getting random position between height and width
    DIRECTION direction_OfGoal = (DIRECTION)(std::rand() % 4); // min 0 max 3
    int lenght_OfGoal = (std::rand() % (8 - 4) + 4);           // min 4 max 8
    int x_OfGoal = 0;
    int y_OfGoal = 0;

    if (direction_OfGoal == TOP || direction_OfGoal == BOTTOM)
    {
        x_OfGoal = (std::rand() % (this->width - lenght_OfGoal));
        if (direction_OfGoal == BOTTOM)
            y_OfGoal = this->height - 1;
    }
    else // if(direction_OfGoal == LEFT || direction_OfGoal == RIGHT)
    {
        y_OfGoal = (std::rand() % (this->height - lenght_OfGoal));
        if (direction_OfGoal == RIGHT)
            x_OfGoal = this->width - 1;
    }

    this->goal = Goal(lenght_OfGoal, direction_OfGoal, Position(x_OfGoal, y_OfGoal));

}

void GameArea::render()
{
    for (int y = 0; y < this->height; y++)
    {
        for (int x = 0; x < this->width; x++)
        {
            Position currentPosition(x, y);
            std::string currentOutput = "-";
            if (currentPosition == this->ball.getPosition())
                currentOutput = "*";
            if (currentPosition == this->player.getPosition())
            {
                if (currentOutput == "*")
                {
                    currentOutput = "!";
                }
                else
                {
                    currentOutput = "+";
                }
            }

            if (this->goal.insideGoal(currentPosition))
                currentOutput = "#";

            std::cout << currentOutput << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void GameArea::execute()
{
    this->steps++;

    if (this->player.getPosition() == this->ball.getPosition()) // shot aviable 
    {
        this->shots++;
        this->ball.move(this->player.getPosition().directionTo(this->goal.getPosition()));
    }
    else
    {
        this->player.move(this->player.getPosition().directionTo(this->ball.getPosition()));
    }
    this->shotScored();
};

void GameArea::randomizeMovable()
{
    this->scoredFlag = false;
    this->player.setPosition(Position(std::rand() % this->width, std::rand() % this->height));
    this->ball.setPosition(Position(std::rand() % this->width, std::rand() % this->height));
};

bool GameArea::shotScored()
{
    if (this->goal.insideGoal(this->ball.getPosition()))
    {
        this->score++;
        this->scoredFlag = true;
        return true;
    }
    return false;
}

// GETTER
bool GameArea::getScoredFlag() const
{
    return this->scoredFlag;
}
int GameArea::getWidth() const
{
    return this->width;
};
int GameArea::getHeight() const
{
    return this->height;
};

int GameArea::getScore() const
{
    return this->score;
};

int GameArea::getSteps() const
{
    return this->steps;
};

int GameArea::getShots() const
{
    return this->shots;
};
Movable &GameArea::getBall()
{
    return this->ball;
}

Movable &GameArea::getPlayer()
{
    return this->player;
}

Goal &GameArea::getGoal()
{
    return this->goal;
}