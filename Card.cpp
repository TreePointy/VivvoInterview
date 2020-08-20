#include "Card.h"

Card::Card(int r, string s) : rank(r), suit(s) {}

int Card::GetRank() { return rank; }
string Card::GetSuit() { return suit; }

void Card::SetRank(int r) { rank = r; }
void Card::SetSuit(string s) { suit = s; }

Card* Card::GetCard() { return this; }