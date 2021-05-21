#include "GameFunc.h"

extern std::string gameOverText;

int main()
{


    Setup();
    while (!Draw())
    {
        Turn();

    }
    std::cout << gameOverText << std::endl;
    delArr();

    return 0;
}
