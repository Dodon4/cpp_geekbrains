#include <vector>
#include <iostream>
using namespace std;

class Card
{
    friend ostream& operator<<(ostream& os, const Card& aGenericPlayer);
public:
    enum Suit { clubs, diamonds, heartsand, spades };
    enum rank
    {
        ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
        JACK, QUEEN, KING
    };
    Card(rank cardValue, Suit suit, bool pos) : _cardValue(cardValue), _suit(suit), _pos(pos)
    {}
    void Flip()
    {
        _pos = !_pos;
    }
    size_t GetValue() const
    {
        int value = 0;
        if (_pos)
        {
            value = _cardValue;
            if (value > 10)
            {
                value = 10;
            }
        }
        return value;
    }
private:
    bool _pos;
    Suit _suit;
    rank _cardValue;
};

class Hand
{
public:
    int GetValue() const
    {
        if (m_Cards.empty())
        {
            return 0;
        }

        if (m_Cards[0]->GetValue() == 0)
        {
            return 0;
        }

        int total = 0;
        vector<Card*>::const_iterator iter;
        for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
        {
            total += (*iter)->GetValue();
        }

        bool containsAce = false;
        for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
        {
            if ((*iter)->GetValue() == Card::ACE)
            {
                containsAce = true;
            }
        }

        if (containsAce && total <= 11)
        {
            total += 10;
        }
        return total;
    }
    void Clear()
    {
        vector<Card*>::iterator iter = m_Cards.begin();
        for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
        {
            delete* iter;
            *iter = 0;
        }
        m_Cards.clear();
    }
    void Add(Card* pCard)
    {
        m_Cards.push_back(pCard);
    }
    Hand()
    {
        m_Cards.reserve(7);
    }
    virtual ~Hand()
    {
        Clear();
    }
protected:
    vector<Card*> m_Cards;
};

class GenericPlayer : public Hand
{
    friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);
protected:
    const string _name;

public:
    GenericPlayer(const string& name) : _name(name) {}
    GenericPlayer() {}
    bool isBoosted() const
    {
        if (this->GetValue() > 21)
            return true;
        return false;
    }
    void Bust() const
    {
        std::cout << _name << " has more than 21" << std::endl;
    }
    virtual bool isHitting() const = 0;
};
class Player : public GenericPlayer
{
public:
    virtual bool isHitting() const override 
    {
        if (this->GetValue() >= 20)
            return false;
        cout << _name << ", do you want a hit? (Y/N): ";
        char response;
        cin >> response;
        return (response == 'y' || response == 'Y');
    }
    void Win() const
    {
        cout << _name << "is won" << endl;
    }
    void Lose() const
    {
        cout << _name << "is lost" << endl;
    }
    void Push() const
    {
        cout << _name << "got tie" << endl;
    }
    Player(const string& name) : GenericPlayer(name) {}
};
class House : public GenericPlayer
{
    virtual bool isHitting() const override
    {
        return (this->GetValue() <= 16);
    }
    House() {}
    void FlipFirstCard()
    {
        if (!(m_Cards.empty()))
            m_Cards[0]->Flip();
    }
};
ostream& operator<<(ostream& os, const Card& aCard)
{
    if (aCard._pos == true)
        cout << "XX";
    cout << "Suit:" << aCard._suit << " Rank:" << aCard._cardValue;
}
ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer)
{
    os << aGenericPlayer._name << ":\t";

    vector<Card*>::const_iterator pCard;
    if (!aGenericPlayer.m_Cards.empty())
    {
        for (pCard = aGenericPlayer.m_Cards.begin();
            pCard != aGenericPlayer.m_Cards.end();
            ++pCard)
        {
            os << *(*pCard) << "\t";
        }
        if (aGenericPlayer.GetValue() != 0)
        {
            cout << "(" << aGenericPlayer.GetValue() << ")";
        }
    }
    else
    {
        os << "<empty>";
    }

    return os;
}
