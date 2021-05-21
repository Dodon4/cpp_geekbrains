#include <iostream>
#include <string>
using namespace std;

class Cards
{
private:
    enum Card {six, seven, eight, nine, ten, J, Q, K, A};
    int *NumOfCards;
    const size_t _size = 36;
    const size_t _cards = 9;
    const int _valueOfCards[9] = {6, 7, 8, 9, 10, 2, 3, 4, 11};
public:
    Cards()
    {
        NumOfCards = new int [_cards];
        for(int i = 0; i < _cards; i++)
        {
            NumOfCards[i] = 4;
        }
    }
    ~Cards()
    {
        delete[] NumOfCards;
    }
};
class Player
{
protected:
    size_t _score = 0;
    size_t _gotCards = 0;
    const size_t _minCards = 2;
    const size_t _maxScore = 21;
public:
    void getCard();
    void Stop();
};
class Diller : public Player
{
    const size_t _minScore = 17;
};
class Man : public Player
{
    
};