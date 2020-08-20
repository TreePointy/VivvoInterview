#pragma once

#include <vector>

#include "Card.h"
#include "Deck.h"
#include "Player.h"

class War
{

private:

	std::vector<Card>* warDeck;

	std::vector<Player> *players;

public:

	War(std::vector<Card>* deck);

	void PlayWar();
};