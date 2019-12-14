#include "lib.h"

Snake::Snake()
{
    this->size = 2;
    this->positiion = new std::map<char, int>[size];
    positiion[0]['x'] = SIZE_FIELD / 2;
    positiion[0]['y'] = SIZE_FIELD / 2;
    positiion[1]['x'] = SIZE_FIELD / 2 + 1;
    positiion[1]['y'] = SIZE_FIELD / 2;
    this->spead = 1;
}

int Snake::getSize() const
{
    return this->size;
}

std::map<char, int>* Snake::getPosition() const
{
    return this->positiion;
}

void Snake::resize()
{
    std::map<char, int>* newPosition;
    newPosition = new std::map<char, int>[size + 1];
    for(int i = 0; i < this->size; i++)
    {
        newPosition[i]['x'] = this->positiion[i]['x'];
        newPosition[i]['y'] = this->positiion[i]['y'];
    }
    newPosition[size]['x'] = 0;
    newPosition[size]['y'] = 0;
    this->size++;
    delete this->positiion;
    positiion = new std::map<char, int>[size];
    for(int i = 0; i < this->size; i++)
    {
        this->positiion[i]['x'] = newPosition[i]['x'];
        this->positiion[i]['y'] = newPosition[i]['y']; 
    }
    delete newPosition;
}

std::map<char, int> Snake::getTail() const
{
    return positiion[size - 1];
}

std::map<char, int> Snake::getHead() const
{
    return positiion[0];
}

void Snake::shiftPosiition()
{
    for(int i = size - 2; i >= 0; i--)
    {
        this->positiion[i + 1] = this->positiion[i];
    }
}

bool Snake::move(int choise, bool check /*=false*/)
{
    bool gameOver = false;
    std::map<char, int> tail = this->getTail();
    std::map<char, int> head = this->getHead();
    static int temp = 0;
    if(choise)
    {
        if(choise == temp)
        {
            if(this->spead < 64)
            {
                this->spead *= 2;
            }
        }
        if(abs(choise - temp) == 1 && temp != 0)
        {
            choise = temp;
            if(this->spead > 1)
            {
                this->spead /= 2;
            }
            
        }
        temp = choise;
    }
    else
    {
        choise = temp;
    }
    switch (choise)
    {
    case UP:
        if (head['y'] > 0)
        {
            this->shiftPosiition();
            this->positiion[0]['x'] = head['x'];
            this->positiion[0]['y'] = head['y'] - 1;
        }
        else
        {
            gameOver = true;
        }
        break;
    
    case DOWN:
        if (head['y'] < SIZE_FIELD - 1)
        {
            this->shiftPosiition();
            this->positiion[0]['x'] = head['x'];
            this->positiion[0]['y'] = head['y'] + 1;
        }
        else
        {
            gameOver = true;
        }
        break;
    
    case LEFT:
        if (head['x'] > 0)
        {
            this->shiftPosiition();
            this->positiion[0]['x'] = head['x'] - 1;
            this->positiion[0]['y'] = head['y'];
        }
        else
        {
            gameOver = true;
        }
        break;

    case RIGHT:
        if (head['x'] < SIZE_FIELD - 1)
        {
            this->shiftPosiition();
            this->positiion[0]['x'] = head['x'] + 1;
            this->positiion[0]['y'] = head['y'];
        }
        else
        {
            gameOver = true;
        }
        break;
    }
    if(check)
    {
        this->resize();
    }
    return gameOver;
}

int Snake::getSpead()
{
    return this->spead;
}

Snake::~Snake()
{
    delete this->positiion;
}