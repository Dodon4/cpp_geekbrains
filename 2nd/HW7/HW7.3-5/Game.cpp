#include "Game.h" //!-> include h
#include <algorithm>
using namespace std;


// Конструктор этого класса принимает ссылку на вектор строк, представляющих
// имена игроков - людей. Конструктор создает объект класса Player для каждого имени
Game::Game(const vector<string>& names, const size_t numOfdecks)
{
    // создает вектор игроков из вектора с именами
    vector<string>::const_iterator pName;
    for (pName = names.begin(); pName != names.end(); ++pName)
    {
        m_players.push_back(Player(*pName));
    }

    for (size_t i = 0; i < numOfdecks; i++)
    {
        Deck *deck = new Deck();
        m_deck.push_back(*deck);
        delete deck;
    }
    for (Deck deck: m_deck)
    {
        deck.populate();
        deck.shuffle();
    }
}


Game::~Game()
{}

void Game::play()
{
    const int startCardCount = 2;
    // раздает каждому по две стартовые карты
    vector<Player>::iterator pPlayer;
    for (int i = 0; i < startCardCount; ++i)
    {
        for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
        {
            srand(static_cast<unsigned int>(time(0)));
            std::random_shuffle(m_deck.begin(), m_deck.end());
            m_deck[0].deal(*pPlayer);
        }
        m_deck[0].deal(m_house);
    }

    // прячет первую карту дилера
    m_house.flipFirstCard();

    // открывает руки всех игроков
    for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
    {
        cout << *pPlayer << endl;
    }
    cout << m_house << endl;

    // раздает игрокам дополнительные карты
    for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
    {
        srand(static_cast<unsigned int>(time(0)));
        std::random_shuffle(m_deck.begin(), m_deck.end());
        m_deck[0].additionalCards(*pPlayer);
    }

    // показывает первую карту дилера
    m_house.flipFirstCard();
    cout << endl << m_house;

    // раздает дилеру дополнительные карты
    srand(static_cast<unsigned int>(time(0)));
    std::random_shuffle(m_deck.begin(), m_deck.end());
    m_deck[0].additionalCards(m_house);

    if (m_house.isBusted())
    {
        // все, кто остался в игре, побеждают
        for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
        {
            if (!(pPlayer->isBusted()))
            {
                pPlayer->win();
            }
        }
    }
    else
    {
        // сравнивает суммы очков всех оставшихся игроков с суммой очков дилера
        for (pPlayer = m_players.begin(); pPlayer != m_players.end();
            ++pPlayer)
        {
            if (!(pPlayer->isBusted()))
            {
                if (pPlayer->getTotal() > m_house.getTotal())
                {
                    pPlayer->win();
                }
                else if (pPlayer->getTotal() < m_house.getTotal())
                {
                    pPlayer->lose();
                }
                else
                {
                    pPlayer->push();
                }
            }
        }

    }

    // очищает руки всех игроков
    for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
    {
        pPlayer->clear();
    }
    m_house.clear();
}
