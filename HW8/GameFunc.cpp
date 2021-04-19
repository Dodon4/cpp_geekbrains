
#include "GameFunc.h"
bool GameIsOver = false;
size_t size;
int symbToWin;
OXField PlayerSymb;
OXField ComputerSymb;
OXField SymbTurn = OXField::X;

void CheckSymbol(Cell** pArr, size_t i, size_t j)
{
    if (pArr[i][j].isFlaged)
    {
        if (pArr[i][j].cell == OXField::O)
        {
            std::cout << "O";
        }
        else if (pArr[i][j].cell == OXField::X)
        {
            std::cout << "X";
        }
    }
    else if (i != size - 1)
    {
        std::cout << "_";
    }
    else
    {
        std::cout << " ";
    }
}
void Draw(Cell** pArr)
{

    for (size_t i = 0; i < size; i++)
    {

        for (size_t j = 0; j < size; j++)
        {
            CheckSymbol(pArr, i, j);
            if (j != size - 1)
            {
                std::cout << "|";
            }
        }
        std::cout << std::endl;
    }
}
void input(Cell** pArr)
{
    int x;
    int y;

    do {
        std::cout << "Enter your coordinates within the field:" << std::endl;
        std::cin >> x;
        std::cin >> y;
    } while (x < 0 || x > size || y < 0 || y > size || pArr[x - 1][y - 1].cell != OXField::Empty);

    pArr[x - 1][y - 1].isFlaged = 1;
    pArr[x - 1][y - 1].cell = SymbTurn;

    CheckWin(pArr, x, y);
    NextTurn();

}
void CheckWin(Cell** pArr, int x, int y)
{
    if (CheckLeftDiag(pArr, x, y))//CheckVert(pArr, x, y) || CheckHoris(pArr, x, y))
    {
        std::cout << "Player" << (SymbTurn == OXField::O ? "O " : "X ") << "won" << std::endl;
        GameIsOver = true;
    }
}
void NextTurn()
{
    if (SymbTurn == OXField::X)
    {
        SymbTurn = OXField::O;
    }
    else
    {
        SymbTurn = OXField::X;
    }
}
void Setup(Cell** pArr)
{

    do {
        std::cout << "Enter size of game >= 3:";
        std::cin >> size;
    } while (size < 3);
    std::cout << std::endl;

    do {
        std::cout << "Enter symbols in the row to win:";
        std::cin >> symbToWin;
    } while (symbToWin < 3);

    int symb;
    std::cout << "Choose your symbol: 1 - X, 2 - O";
    std::cin >> symb;

    if (symb == 1)
    {
        PlayerSymb = OXField::X;
        ComputerSymb = OXField::O;
    }
    else
    {
        PlayerSymb = OXField::O;
        ComputerSymb = OXField::X;
    }
    for (size_t i = 0; i < size; i++)
    {
        pArr[i] = new Cell[size];
        for (size_t j = 0; j < size; j++)
        {
            pArr[i][j].isFlaged = 0;
        }
    }
}
bool CheckVert(Cell** pArr, int x, int y)
{
    OXField symb = OXField::X;
    int score = 1;
    int vert = (x - symbToWin) < 0 ? x - 1 : symbToWin - 1;
    int down = (x + symbToWin) > size ? size - x : symbToWin - 1;
    for (int i = x - 1; i >= x - vert; i--)
    {
        if (pArr[i - 1][y - 1].cell == SymbTurn)
        {
            score++;
        }
        else
        {
            break;
        }
    }
    for (int i = x + 1; i <= x + down; i++)
    {
        if (pArr[i - 1][y - 1].cell == SymbTurn)
        {
            score++;
        }
        else
        {
            break;
        }
    }
    return(score >= symbToWin);
}
bool CheckHoris(Cell** pArr, int x, int y)
{
    OXField symb = OXField::X;
    int score = 1;
    int left = (y - symbToWin) < 0 ? y - 1 : symbToWin - 1;
    int right = (y + symbToWin) > size ? size - y : symbToWin - 1;
    for (int j = y - 1; j >= y - left; j--)
    {
        if (pArr[x - 1][j - 1].cell == SymbTurn)
        {
            score++;
        }
        else
        {
            break;
        }
    }
    for (int j = y + 1; j <= y + right; j++)
    {
        if (pArr[x - 1][j - 1].cell == SymbTurn)
        {
            score++;
        }
        else
        {
            break;
        }
    }
    return(score >= symbToWin);
}
bool CheckLeftDiag(Cell** pArr, int x, int y)
{
    OXField symb = OXField::X;
    int score = 1;
    int up = ((y - symbToWin) < 0 || (x - symbToWin) < 0) ?
        (y - symbToWin) < (x - symbToWin) ? y - 1 : x - 1 : symbToWin - 1;
    int down = ((y + symbToWin) > size || (x + symbToWin) > size) ?
        (y - symbToWin) < (x - symbToWin) ? size - y : size - x : symbToWin - 1;
    for (int i = x - 1, j = y - 1; i >= x - up && j >= y - up; i--, j--)
    {
        if (pArr[i - 1][j - 1].cell == SymbTurn)
        {
            score++;
        }
        else
        {
            break;
        }
    }
    for (int i = x + 1, j = y + 1; i <= x + down && j <= y + down; i++, j++)
    {
        if (pArr[i - 1][j - 1].cell == SymbTurn)
        {
            score++;
        }
        else
        {
            break;
        }

    }
    std::cout << up << " " << down << " " << score;
    return(score >= symbToWin);
}