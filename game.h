#ifndef GAME_H
#define GAME_H

#include "lib.h"

class Game
{
    private:
        Field* field;

        int getDirection();

    public:
        Game();
        void run();
        void gameOver();
        bool check();
        ~Game();
};

#endif //GAME_H