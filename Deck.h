#pragma once

#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>

#include "Card.h"

class Deck
{
	
private:

	std::vector<Card>* deck;

public:

	Deck();

	void ShuffleDeck();
	void ShowDeck();

	std::vector<Card>* GetDeck();
};