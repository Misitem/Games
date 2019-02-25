#include "Player.h"


// Player is constructed with a name for i/o purposes
// each new player is given a hand which is a vector of Card*
// a score starting at 0, and the number of aces in their hand, starting at 0 (again helps for handling aces)
Player::Player(std::string name)
{
	this->name = name;
	this->hand = hand;
	this->score = 0;
	this->aces = 0;
}

bool Player::HasBlackJack() {
	if (this->score == 21 & this->hasAce == true) {
		return true;
	}
	return false;
}
//Name Getter
std::string Player::GetName() {
	return this->name;
}

//Adds a card to players hand, taking Card* as argument
// Score is recalculated whenever a card is added to a hand
void Player::AddToHand(Card* card) {
	this->score += card->GetValue();
	this->hand.push_back(card);
}


// Loops through the players hand vector and prints out each cards value
// if the value is 0 it's an ace so print out A
void Player::ShowHand() {
	std::cout << this->name << "'s Hand: \n";
	for (Card* c : hand) {
		if (c->GetValue() == 0) {
			std::cout << "A\t";
		}
		else { std::cout << c->GetValue() << "\t"; };
	}
	std::cout << std::endl;
}


//Boolean for if player busted, aka went over 21
bool Player::Busted() {
	if (this->score > 21) {
		return true;
	}
	return false;
}

// Calculates and gets number of aces in the players hand
int Player::NumOfAces() {
	for (Card* c : this->hand) {
		if (c->GetValue() == 0) {
			aces += 1;
		}
	}
	return aces;
}

// I did not want to make number of aces public so this basically adjusts the players/dealers score for
// Having an ace, the adjustment is based on input. To make it safter you could hash the input in some sort of way
void Player::AdjustForAce(int choice) {
	if (choice == 1) {
		this->score = score + 1;
		return;
	}
	this->score = score + 11;
	aces -= 1;
}

//Getter for score
int Player::GetScore() {
	return this->score;
}

Player::~Player()
{
}
