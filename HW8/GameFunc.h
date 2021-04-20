#pragma once
#include <iostream>
#include <chrono>
#include <random>
#include <string>
enum class OXField { O, X, Empty };
struct Cell
{
    OXField cell = OXField::Empty;
    unsigned int isFlaged : 1;
};
struct GameField
{
    size_t size;
    OXField PlayerSymb;
    OXField ComputerSymb;
    OXField SymbTurn = OXField::X;
    int symbToWin;
    bool GameIsOver = false;
    Cell** pArr;
};

int32_t getRandomNum(int32_t min, int32_t max);

bool CheckHoris(const int& x, const int& y);
bool CheckVert(const int& x, const int& y);
bool CheckLeftDiag(const int& x, const int& y);
bool CheckRightDiag(const int& x, const int& y);
bool noCells();
bool Draw();

void SimpleAI();
void delArr();
void input();
void Setup();
void CheckWin(const int& x, const int& y);
void Turn();
void CheckSymbol(const size_t& i, size_t& j);


