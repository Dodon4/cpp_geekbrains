
#include "GameFunc.h"
//using namespace std;

extern size_t size;
extern bool GameIsOver;

int main()
{
    Cell** CellsField = new Cell * [size];
    Setup(CellsField);
    while (true)//!GameIsOver)
    {
        Draw(CellsField);
        input(CellsField);
        //system("cls");
    }
    for (size_t i = 0; i < size; i++)
    {
        delete[] CellsField[i];
    }
    return 0;
}
