#include "lib.h"

void Field::setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}


Field::Field()
{
    this->size = SIZE_FIELD;
    this->main_snake = new Snake;
}

void Field::showField() const
{
    system("cls");
    for(int i = 0; i < this->size; i++)
    {
        for(int j = 0; j < this->size; j++)
        {
            std::cout << ' ';
        }
        std::cout << '#';
        std::cout << std::endl;
    }
    for(int j = 0; j < this->size + 1; j++)
    {
        std::cout << '#';
    }
}

void Field::showStore()
{
    this->setCursorPosition(this->getSize() + 5, 3);
    std::cout << "length snake: " << this->main_snake->getSize() - 1;
}

void Field::newApple()
{
    bool flag = false;
    while(!flag)
    {
        this->apple['x'] = rand() % this->size;
        this->apple['y'] = rand() % this->size;
        flag = true;
        for(int i = 0; i < this->main_snake->getSize(); i++)
        {
            if(this->main_snake->getPosition()[i]['x'] == this->apple['x'] && this->main_snake->getPosition()[i]['y'] == this->apple['y'])
            {
                flag = false;
            }
        }
    }
    this->setCursorPosition(this->apple['x'], this->apple['y']);  
    std::cout << '$';
}

std::map<char, int> Field::getApple()
{
    return this->apple;
}

int Field::getSize()
{
    return this->size;
}

void Field::showSnake()
{
    std::map<char, int>* position =  this->main_snake->getPosition();
    int size_snake = this->main_snake->getSize();
    for(int i = 0; i < size_snake - 1; i++)
    {
        this->setCursorPosition(position[i]['x'], position[i]['y']);
        std::cout << '@';
    }
    this->setCursorPosition(position[size_snake - 1]['x'], position[size_snake - 1]['y']);
    std::cout << ' ';
    this->setCursorPosition(SIZE_FIELD, SIZE_FIELD);    
}

Field::~Field()
{
    delete this->main_snake;
}