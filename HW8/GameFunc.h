#pragma once
#include <iostream>

enum class OXField { O, X, Empty };
struct Cell
{
    OXField cell = OXField::Empty;
    unsigned int isFlaged : 1;
};




bool CheckHoris(Cell** pArr, int x, int y);
bool CheckVert(Cell** pArr, int x, int y);
bool CheckLeftDiag(Cell** pArr, int x, int y);

void CheckSymbol(Cell** pArr, size_t i, size_t j);
void Draw(Cell** pArr);
void input(Cell** pArr);
void Setup(Cell** pArr);
void CheckWin(Cell** pArr, int x, int y);
void NextTurn();


