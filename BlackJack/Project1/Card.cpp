#include "Card.h"


// Each card has a value and a getter for that value
Card::Card(int value)
{
	this->value = value;
}

int Card::GetValue() {
	return this->value;
}

Card::~Card()
{
}
