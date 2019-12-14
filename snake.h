#ifndef SNAKE_H
#define SNAKE_H

#include "lib.h"

class Snake
{
    private:
        int size;
        std::map<char, int>* positiion;
        int spead;

    public:
    
        Snake();
        int getSize() const;
        std::map<char, int>* getPosition() const;
        void resize();
        std::map<char, int> getTail() const;
        std::map<char, int> getHead() const;
        void shiftPosiition();
        bool move(int choise, bool check = false);
        int getSpead();
        ~Snake();
};

#endif //SNAKE_H