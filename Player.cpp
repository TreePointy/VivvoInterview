#include "Player.h"

Player::Player(int num)
{
	playerNumber = num;
	hand = new std::vector<Card>();
	discard = new std::vector<Card>();
	hasCards = true;
}

std::vector<Card>* Player::GetHand() { return hand; }
std::vector<Card>* Player::GetDiscard() { return discard; }


void Player::ShowHand()
{
	std::string showCard("");
	showCard.append("PLAYER ");
	showCard.append(to_string(playerNumber));
	showCard.append(" HAND:\n");
	showCard.append("-------------------------------------------------\n");
	auto it = hand->begin();
	while (it != hand->end())
	{
		showCard.append((to_string(it->GetRank())));
		showCard.append(" of ");
		showCard.append((it->GetSuit()));
		showCard.append("\n");
		it = std::next(it);
	}
	std::cout << showCard << std::endl;

}

bool Player::HasCards() { return hasCards; }


void Player::CheckForEmptyHand()
{
	//testing
	//cout << "CheckForEmptyHand() " << playerNumber <<":       " << hand->size() << "          " << discard->size() << endl;

	//check for empty hand and replace with discard if available
	if (hand->size() == 0 && discard->size() == 0)
	{
		hasCards = false;
	}

	else if (hand->size() == 0 && discard->size() > 0)
	{
		ShuffleDiscardPile();

		auto it = discard->begin();
		while (it != discard->end())
		{
			hand->emplace_back(*(it->GetCard()));
			it = std::next(it);
		}

		discard->clear();
		
		ShowHand();
	}

}

void Player::ShuffleDiscardPile()
{
	srand(time(NULL));
	std::random_shuffle(discard->begin(), discard->end());
}