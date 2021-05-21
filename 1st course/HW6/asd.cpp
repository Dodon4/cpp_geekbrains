#pragma once
#include <iostream>
#include <conio.h>
#include <sysinfoapi.h>
class GameObject
{
protected:
    int dirX;
    int dirY;
    double _velocity;
    double _x;
    double _y;
    enum eDir{LEFT, RIGHT, UP, DOWN};
    eDir _dir;
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
    void move(double t);
    void input();

};

void Player::input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            _dir = LEFT;
            break;
        case 'w':
            _dir = UP;
            break;
        case 'd':
            _dir = RIGHT;
            break;
        case 's':
            _dir = DOWN;
            break;
        }
    }
}
void Player::move(double t)
{
    switch (_dir)
    {
    case LEFT:
        _x -= t * _velocity;
        break;
    case UP:
        _y+= t * _velocity;
        break;
    case RIGHT:
        _x+= t * _velocity;
        break;
    case DOWN:
        _y-= t * _velocity;
        break;
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
    //void GetTickCount();
    void MoveObjects(double t);
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
void GameField::MoveObjects(double t)
{
    _p.move(t);
}
//void GameField::GetTickCount()
//{
//    system("cls");
//    this->MoveObjects();
//    this->DrawFrame();
//    
//}