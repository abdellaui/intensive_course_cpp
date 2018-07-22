#include <iostream>
#include <unistd.h>
#include "game_area.hpp"

int main()
{
    GameArea game;
    const int maxScore = 2;
    std::cout << "Breite :" << game.getWidth() << ", ";
    std::cout << "Laenge :" << game.getHeight() << ", ";
    std::cout << "Torbreite :" << game.getGoal().getLength() << std::endl;

    game.render();

    while (game.getScore() < maxScore)
    {
        while (!game.getScoredFlag())
        {
            std::cout << std::endl;
            usleep(200000);
            game.execute();
            game.render();
        }
        std::cout << "Tor!!! Schritte: " << game.getSteps() << ", Anzahl Schuesse: "<< game.getShots() <<",Aktueller Score: " << game.getScore() << std::endl;
        sleep(2);
        if (game.getScore() < maxScore)
        {
            game.randomizeMovable();
            game.render();
        }
    }
    std::cout << "Du hast gewonnen!" << std::endl;

    return 0;
}