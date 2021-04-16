#pragma once
#include <iostream>
#include <conio.h>

class GameObject
{
protected:
    int dirX;
    int dirY;
    double _velocity;
    double _x;
    double _y;
    enum eDir{LEFT, RIGHT, UP, DOWN};
    eDir dir;
public:
    double getX() 
    {
        return _x;
    }
    double getY()
    {
        return _y;
    }
    double getV()
    {
        return _velocity;
    }
    explicit GameObject(double x, double y, double velocity) : _x(x), _y(y), _velocity(velocity){}
};

class Bot : public GameObject
{
    explicit Bot(double x, double y, double velocity) : GameObject(x, y, velocity) {}
};

class Player : public GameObject
{
public:
    explicit Player(double x, double y, double velocity) : GameObject(x, y, velocity) {}

    void input();

};

void Player::input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            _x -= _velocity;
            break;
        case 'w':
            _y += _velocity;
            break;
        case 'd':
            _x += _velocity;
            break;
        case 's':
            _y -= _velocity;
            break;
        }
    }
}
class GameField
{
private:
    size_t _width;
    size_t _height;
    int x;
    int y;
    Player &_p;
public:
    GameField(Player& p, size_t width = 20, size_t height = 20) : _p(p), _width(width), _height(height) {}
    void GetTickCount();
    void MoveObjects();
    void DrawFrame();

};
void GameField::DrawFrame()
{
    for (size_t i = this->_height; i > 0; i--)
    {
        for (size_t j = 1; j <= this->_width; j++)
        {
            if (_p.getX() >= j && _p.getX() < j + 1 && _p.getY() >= i && _p.getY() < i + 1)
                std::cout << "0 ";
            else
            {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }

}
void GameField::MoveObjects()
{
    _p.input();
}
void GameField::GetTickCount()
{
    system("cls");
    this->MoveObjects();
    this->DrawFrame();
    
}