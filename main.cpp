#include "main.h"

int main()
{
	/*Deck d;

	d.ShowDeck();
	cout << endl << endl;

	d.ShuffleDeck();
	d.ShowDeck();*/

	cout << "Select which game to play: " << endl;
	cout << "War : 2-player (W) ... Exit (Anything else):  ";

	char inputChar;
	cin >> inputChar;

	while (inputChar == 'w' || inputChar == 'W')
	{
		cout << endl;
		Deck deck;
		deck.ShuffleDeck();
		//deck.ShowDeck();

		War war(deck.GetDeck());

		cout << endl << endl
			<< "-------------------------------------------------" << endl << endl;

		war.PlayWar();

		cout << endl << "Input 'W' to play again: ";
		cin >> inputChar;
	}

}



void PrintShuffledDeck(Deck d)
{
	cout << "SHUFFLED DECK: "
		<< endl << "-------------------------------------------------" << endl;

	d.ShowDeck();

	cout << "-------------------------------------------------" << endl
		<< "-------------------------------------------------" << endl << endl;
}