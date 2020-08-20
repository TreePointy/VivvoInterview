#include "War.h"

War::War(std::vector<Card> *deck)
{
	players = new std::vector<Player>();
	warDeck = deck;
	
	for (int i = 1; i <= 2; i++)
	{
		players->emplace_back(Player(i));
	}

	auto it = warDeck->begin();

	while (it != warDeck->end())
	{
		int i = 0;
		auto playerIt = players->begin();

		while (playerIt != players->end())
		{

			if (i == 0)
			{
				if (playerIt->GetHand()->size() < CULL_CARD_COUNT)
				{
					playerIt->GetHand()->emplace_back(*(it->GetCard()));
					i++;
				}
			}
			else
			{
				if (playerIt->GetHand()->size() < CULL_CARD_COUNT)
				{
					playerIt->GetHand()->emplace_back(*(it->GetCard()));
				}
			}

			playerIt = std::next(playerIt);
			it = std::next(it);
		}
	}

	auto playerIt = players->begin();

	while (playerIt != players->end())
	{
		playerIt->ShowHand();
		playerIt = std::next(playerIt);
	}
}


void War::PlayWar()
{
	
	while (players->at(0).HasCards() && players->at(1).HasCards())
	{
		//testing
		//cout << "PlayWar()" << endl;

		int player1Value = players->at(0).GetHand()->at(0).GetRank();
		int player2Value = players->at(1).GetHand()->at(0).GetRank();

		//compare card from each player
		//highest number wins - adds both cards to that player's discard pile and removes from both hands
			//tie goes to the player whose next card is highest (if they have one), otherwise it is given to player 1
			// I did this because it would HEAVILY lean in the favour of whichever player had priority (i.e. player1Value >= player2Value)

		if (player1Value == player2Value)
		{
			if (players->at(0).GetHand()->size() > 1 && players->at(1).GetHand()->size() > 1)
			{
				int nextCardPlayer1 = players->at(0).GetHand()->at(1).GetRank();
				int nextCardPlayer2 = players->at(1).GetHand()->at(1).GetRank();

				if (nextCardPlayer1 > nextCardPlayer2)
				{
					players->at(0).GetDiscard()->emplace_back(players->at(0).GetHand()->at(0));
					players->at(0).GetDiscard()->emplace_back(players->at(1).GetHand()->at(0));
				}
				else if (nextCardPlayer1 < nextCardPlayer2)
				{
					players->at(1).GetDiscard()->emplace_back(players->at(0).GetHand()->at(0));
					players->at(1).GetDiscard()->emplace_back(players->at(1).GetHand()->at(0));
				}
				else
				{
					players->at(0).GetDiscard()->emplace_back(players->at(0).GetHand()->at(0));
					players->at(0).GetDiscard()->emplace_back(players->at(1).GetHand()->at(0));
				}
			}
		}
		else if (player1Value > player2Value)
		{
			//add to discard player 1
			players->at(0).GetDiscard()->emplace_back(players->at(0).GetHand()->at(0));
			players->at(0).GetDiscard()->emplace_back(players->at(1).GetHand()->at(0));
		}
		else
		{
			//add to discard player 2
			players->at(1).GetDiscard()->emplace_back(players->at(0).GetHand()->at(0));
			players->at(1).GetDiscard()->emplace_back(players->at(1).GetHand()->at(0));
		}

		//delete from hand since they are now discarded
		players->at(0).GetHand()->erase(players->at(0).GetHand()->begin());
		players->at(1).GetHand()->erase(players->at(1).GetHand()->begin());

		//check for empty hand/discard -> update hand with discard if necessary
		players->at(0).CheckForEmptyHand();
		players->at(1).CheckForEmptyHand();

		//check for win conditions
		if (players->at(0).HasCards() && !players->at(1).HasCards())
		{
			cout << endl << "Player 1 WINS!" << endl;
		}

		if (players->at(1).HasCards() && !players->at(0).HasCards())
		{
			cout << endl << "Player 2 WINS!" << endl;
		}
	}

}