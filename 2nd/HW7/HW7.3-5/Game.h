#pragma once
#include <string>
#include "Deck.h"
#include "House.h"
#include "Player.h"

//!-> add class for project

class Game
{
public:
    Game(const std::vector<std::string>& names, const size_t numOfdecks);

    ~Game();
    void play();

private:
    Deck deck;
    std::vector<Deck> m_deck;
    House m_house;
    std::vector<Player> m_players;
};

