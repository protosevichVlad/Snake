#ifndef FIELD_H
#define FIELD_H

#include "lib.h"

class Field
{
    private:
        int size;
        std::map<char, int> apple;

        void setCursorPosition(int x, int y);
    
    public:
        Snake* main_snake;

        Field();
        void showField() const;
        void showStore();
        void newApple();
        std::map<char, int> getApple();
        int getSize();
        void showSnake();
        ~Field();


};

#endif // FIELD_H