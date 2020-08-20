#pragma once

#include <vector>
#include "Card.h"
#include "Deck.h"

class Player
{

private:

	std::vector<Card> *hand;
	std::vector<Card> *discard;

	int playerNumber;

	bool hasCards;
	
public:

	Player(int num);

	std::vector<Card>* GetHand();
	std::vector<Card>* GetDiscard();

	void ShowHand();

	bool HasCards();

	void CheckForEmptyHand();
	void ShuffleDiscardPile();
};