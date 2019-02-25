#include "Dealer.h"


// A Dealer is a player
Dealer::Dealer(std::string name) : Player(name)
{
	this->name = name;
}

// This function handles showing the dealers beginning hand, hiding one of two cards
void Dealer::ShowDealerHand() {
	std::cout << "X" << "\t";
	std::cout << this->hand[1]->GetValue();
	std::cout << std::endl;
}

// This reveals the dealer's hand, essentially the same as the Person::ShowHand() method, could be redudant
void Dealer::RevealHand() {
	//this->score = 0;
	std::cout << "\nDealer Hand: \n";
	for (Card* c : this->hand) {
		if (c->GetValue() == 0) {
			std::cout << "A\t";
		}
		else { std::cout << c->GetValue() << "\t"; };
	}
	std::cout << std::endl;
}

Dealer::~Dealer()
{
}
