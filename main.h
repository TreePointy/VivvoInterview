#pragma once

#include <iostream>
#include <string>
#include <vector>
//#include <algorithm>
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>

#include "Card.h"
#include "Deck.h"
#include "War.h"

using namespace std;

/*

1 deck of cards
2 player
The cards are shuffled
All the card are dealt to player 1 and to. This makes up their hand.
Each player turns over a card
Whoever has the higher card takes both cards and puts them in the discard.
If the cards match (give the cards to whoever you want)
When a player runs out of cards in their hand, their discard is shuffled and becomes their hand.
Play until 1 player has all the cards.


*/

void PrintShuffledDeck(Deck deck);

 