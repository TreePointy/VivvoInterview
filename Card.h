#pragma once


#include <string>

using namespace std;

const int MAX_DECK_CARDS = 52;

//actual number of cards used: take the shuffled deck, deal the cards out, and keep this many cards for each player
//Set to 52 to use full deck of cards
//for testing purposes
const int CULL_CARD_COUNT = 52;

const string SUITS[4] = { "HEARTS", "CLUBS", "DIAMONDS", "SPADES" };

class Card
{
private:

	int rank;
	string suit;

public:

	Card(int r, string s);
	//Card();

	int GetRank();
	string GetSuit();

	void SetRank(int s);
	void SetSuit(string s);

	Card* GetCard();

};