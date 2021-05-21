
#include "GameFunc.h"

GameField game;
std::string gameOverText;

void CheckSymbol(const size_t &i, size_t &j)
{
    if (game.pArr[i][j].isFlaged)
    {
        if (game.pArr[i][j].cell == OXField::O)
        {
            std::cout << "O";
        }
        else if (game.pArr[i][j].cell == OXField::X)
        {
            std::cout << "X";
        }
    }
    else if (i != game.size - 1)
    {
        std::cout << "_";
    }
    else
    {
        std::cout << " ";
    }
}
bool Draw()
{
    system("cls");
    for (size_t i = 0; i < game.size; i++)
    {
        for (size_t j = 0; j < game.size; j++)
        {
            CheckSymbol(i, j);
            if (j != game.size - 1)
            {
                std::cout << "|";
            }
        }
        std::cout << std::endl;
    }
    return game.GameIsOver;
}

void input()
{
    int x;
    int y;

    do {
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        std::cout << "Enter your coordinates within the field:" << std::endl;
        std::cout << "x:";
        std::cin >> x;
        std::cout << std::endl << "y:";
        std::cin >> y;
        std::cout << std::endl;

    } while (x < 0 || x > game.size || y < 0 || y > game.size || game.pArr[x - 1][y - 1].cell != OXField::Empty);

    game.pArr[x - 1][y - 1].isFlaged = 1;
    game.pArr[x - 1][y - 1].cell = game.SymbTurn;

    CheckWin(x, y);
}

void Setup()
{
    do {
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        std::cout << "Enter size of game >= 3:";

        std::cin >> game.size;
    } while (game.size < 3);

    std::cout << std::endl;
    do {
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        std::cout << "Enter symbols in the row to win:";
        std::cin >> game.symbToWin;
    } while (game.symbToWin < 3 || game.symbToWin > game.size || std::cin.fail());

    int symb;
    std::cout << "Choose your symbol: X - 1, O - any symbol:";
    std::cin >> symb;

    if (symb == 1)
    {
        game.PlayerSymb = OXField::X;
        game.ComputerSymb = OXField::O;
    }
    else
    {
        game.PlayerSymb = OXField::O;
        game.ComputerSymb = OXField::X;
        std::cin.clear();
        std::cin.ignore(32767, '\n');
    }
    game.pArr = new Cell * [game.size];
    for (size_t i = 0; i < game.size; i++)
    {
        game.pArr[i] = new Cell[game.size];
        for (size_t j = 0; j < game.size; j++)
        {
            game.pArr[i][j].isFlaged = 0;
        }
    }
}
bool CheckVert(const int& x, const int& y)
{
    OXField symb = OXField::X;
    int score = 1;
    int vert = (x - game.symbToWin) < 0 ? x - 1 : game.symbToWin - 1;
    int down = (x + game.symbToWin) > game.size ? game.size - x : game.symbToWin - 1;
    for (int i = x - 1; i >= x - vert; i--)
    {
        if (game.pArr[i - 1][y - 1].cell == game.SymbTurn)
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
        if (game.pArr[i - 1][y - 1].cell == game.SymbTurn)
        {
            score++;
        }
        else
        {
            break;
        }
    }
    return(score >= game.symbToWin);
}
bool CheckHoris(const int& x, const int& y)
{
    OXField symb = OXField::X;
    int score = 1;
    int left = (y - game.symbToWin) < 0 ? y - 1 : game.symbToWin - 1;
    int right = (y + game.symbToWin) > game.size ? game.size - y : game.symbToWin - 1;
    for (int j = y - 1; j >= y - left; j--)
    {
        if (game.pArr[x - 1][j - 1].cell == game.SymbTurn)
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
        if (game.pArr[x - 1][j - 1].cell == game.SymbTurn)
        {
            score++;
        }
        else
        {
            break;
        }
    }
    return(score >= game.symbToWin);
}
bool CheckLeftDiag(const int& x, const int& y)
{
    OXField symb = OXField::X;
    int score = 1;
    int up = ((y - game.symbToWin) < 0 || (x - game.symbToWin) < 0) ?
        y < x ? y - 1 : x - 1 : game.symbToWin - 1;
    int down = ((y + game.symbToWin) > game.size || (x + game.symbToWin) > game.size) ?
        y < x ? game.size - x : game.size - y : game.symbToWin - 1;
    for (int i = x - 1, j = y - 1; i >= x - up && j >= y - up; i--, j--)
    {
        if (game.pArr[i - 1][j - 1].cell == game.SymbTurn)
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
        if (game.pArr[i - 1][j - 1].cell == game.SymbTurn)
        {
            score++;
        }
        else
        {
            break;
        }

    }
    return(score >= game.symbToWin);
}
bool CheckRightDiag(const int& x, const int& y)
{
    OXField symb = OXField::X;
    int score = 1;
    int up;
    int down;
    {
        int rightup = (y + game.symbToWin) > game.size ? game.size - y : game.symbToWin - 1;
        int upup = (x - game.symbToWin) < 0 ? x - 1 : game.symbToWin - 1;
        up = rightup > upup ? upup : rightup;
    }
    {
        int leftdown = (y - game.symbToWin) < 0 ? y - 1 : game.symbToWin - 1;
        int downdown = (x + game.symbToWin) > game.size ? game.size - x : game.symbToWin - 1;
        down = leftdown > downdown ? downdown : leftdown;
    }
    for (int i = x - 1, j = y + 1; i >= x - up && j <= y + up; i--, j++)
    {
        if (game.pArr[i - 1][j - 1].cell == game.SymbTurn)
        {
            score++;
        }
        else
        {
            break;
        }
    }
    for (int i = x + 1, j = y - 1; i <= x + down && j >= y - down; i++, j--)
    {
        if (game.pArr[i - 1][j - 1].cell == game.SymbTurn)
        {
            score++;
        }
        else
        {
            break;
        }
    }
    return(score >= game.symbToWin);
}
void delArr()
{
    for (size_t i = 0; i < game.size; i++)
    {
        delete[] game.pArr[i];
    }
    delete[] game.pArr;
}
void SimpleAI()
{
    int x, y;
    do
    {
        x = getRandomNum(1, game.size);
        y = getRandomNum(1, game.size);
    } while (game.pArr[x - 1][y - 1].isFlaged == 1);
    game.pArr[x - 1][y - 1].isFlaged = 1;
    game.pArr[x - 1][y - 1].cell = game.ComputerSymb;
    CheckWin(x,  y);
}
int32_t getRandomNum(int32_t min, int32_t max)
{
    const static auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937_64 generator(seed);
    std::uniform_int_distribution<int32_t> dis(min, max);
    return dis(generator);
}
void Turn()
{
    if (!noCells())
    {
        if (game.SymbTurn == game.PlayerSymb)
        {
            input();
            game.SymbTurn = game.SymbTurn == OXField::X ? OXField::O : OXField::X;
        }
        else
        {
            SimpleAI();
            game.SymbTurn = game.SymbTurn == OXField::X ? OXField::O : OXField::X;
        }    
    }
    else 
    {
        gameOverText = "Tie";
        game.GameIsOver = true;
    }
}
void CheckWin(const int &x, const int& y)
{
    if (CheckRightDiag(x, y) || CheckLeftDiag(x, y) || CheckVert(x, y) || CheckHoris(x, y))
    {
        if (game.PlayerSymb == game.SymbTurn)
        {
            gameOverText = "You won";
        }
        else
        {
            gameOverText = "You lost";
        }
        game.GameIsOver = true;
    }
}
bool noCells()
{
    for (int i = 0; i < game.size; i++)
    {
        for (int j = 0; j < game.size; j++)
        {
            if (game.pArr[i][j].isFlaged == 0)
            {
                return false;
            }
        }
    }
    return true;
}