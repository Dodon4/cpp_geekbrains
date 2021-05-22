
#include <iostream>
using namespace std;

class Card
{
private:
	enum Suit { clubs, diamonds, heartsand, spades};
	enum CardValue {six, seven, eight, nine, ten, king, queen, prince, ace};
	bool pos = false;
	const int _valueOfCards[9] = { 6, 7, 8, 9, 10, 4, 3, 2, 1 };
	CardValue _cv;
	size_t _value;
public:
	Card(int card)
	{
		_cv = static_cast<CardValue>(card);
		_value = _valueOfCards[card % 9];
	}
	void Flip()
	{
		pos = !pos;
	}
	size_t GetValue() const
	{
		return _value;
	}
};

int main()
{
	Card card(5);
	cout << card.GetValue();
	return 0;
}

