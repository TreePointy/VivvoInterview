#include "Deck.h"


Deck::Deck()
{
	deck = new std::vector<Card>();
	deck->reserve(MAX_DECK_CARDS);

	for (int i = 1; i <= 13; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			deck->emplace_back(Card(i, SUITS[j]));
		}
	}

}


void Deck::ShuffleDeck()
{
	srand(time(NULL));
	std::random_shuffle(deck->begin(), deck->end());
}

void Deck::ShowDeck()
{
	std::string showCard("");
	auto it = deck->begin();
	while (it != deck->end())
	{
		showCard.append((to_string(it->GetRank())));
		showCard.append(" of ");
		showCard.append((it->GetSuit()));
		showCard.append("\n");
		it = std::next(it);
	}
	std::cout << showCard;

}

std::vector<Card>* Deck::GetDeck() { return deck; }