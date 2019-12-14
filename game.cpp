#include "lib.h"

int Game::getDirection(){
    if(GetAsyncKeyState(VK_KEY_W) & 0x8000) return UP;
    if(GetAsyncKeyState(VK_KEY_A) & 0x8000) return LEFT;
    if(GetAsyncKeyState(VK_KEY_S) & 0x8000) return DOWN;
    if(GetAsyncKeyState(VK_KEY_D) & 0x8000) return RIGHT;
    return 0;
}

Game::Game()
{
    this->field = new Field;
}

void Game::run()
{
    this->field->showField();
    this->field->newApple();
    this->field->showStore();
    this->field->showSnake();
    bool is_game_over = false;
    int i = 0;
    while (i == 0)
    {
        i = this->getDirection();
    }
    while (true)
    {   
        if(this->field->main_snake->getHead()['x'] == this->field->getApple()['x'] &&
            this->field->main_snake->getHead()['y'] == this->field->getApple()['y'])
        {
            is_game_over = this->field->main_snake->move(i, true);
            this->field->newApple();
            this->field->showStore();
        }
        else
        {
            is_game_over = this->field->main_snake->move(i);
        }

        if(this->check() || is_game_over)
        {
            this->gameOver(); 
            break;
        }
        
        this->field->showSnake();
        for(int j = 0; j < 5; j++)
        {
            i = this->getDirection();                
            // Sleep(100 - this->field->main_snake->getSpead());
            Sleep(100);
        }
    }
}

void Game::gameOver()
{
    system("cls");
    std::cout << "GAME OVER :-(\nYour store: " << this->field->main_snake->getSize() - 1 << "\n";
}

bool Game::check()
{
    bool result = false;
    std::map<char, int> head = this->field->main_snake->getHead();
    for(int i = 1; i < this->field->main_snake->getSize() - 1; i++)
    {
        if(head['x'] == this->field->main_snake->getPosition()[i]['x'] &&
            head['y'] == this->field->main_snake->getPosition()[i]['y'])
        {
            result = true;
        }
    }
    return result;
}

Game::~Game()
{
    delete field;
}