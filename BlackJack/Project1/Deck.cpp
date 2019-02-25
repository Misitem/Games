#include "Deck.h"


// Constructor a Deck is given a Card* list that is then filled
// to mimic a normal 52 card deck
Deck::Deck()
{
	this->cards = cards;
	this->FillDeck();
}

//Draw return the card from the tail end of the Card* vector, then removes it from the vector
Card* Deck::Draw() {
	Card* temp = this->cards.back();
	this->cards.pop_back();

	return temp;

}

//Shuffle is a built in function that shuffles a given vector based on a given seed
//The seed is random in this case to prevent the same shuffle every time
void Deck::ShuffleDeck() {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
	//std::random_shuffle(this->cards.begin(), this->cards.end(), myrandom);
}

// Fills the deck by having an outer loop that loops 4 times because there are 4 of each card,
// and an inner loop that loops 13 times for each 'suit' totaling 52 cards created with the correct
// values. Aces are 0 and anything past iteration 9 is a 10
void Deck::FillDeck() {
	int i;
	int j;
	//std::vector<Card*> newDeck;

	for (i = 0; i < 4; i++)
	{
		j = 1;
		for (j; j < 14; j++)
		{
			int value;
			if (j > 10)
			{
				value = 10;
			}
			else if (j == 1) {
				value = 0;
			}
			else { value = j; }
			Card* c = new Card(value);
			this->cards.push_back(c);
		}
		
	}
}

// For Debugging purposes/to test is FillDeck() and ShuffleDeck() worked
void Deck::PrintDeck() {
	for (Card* card : this->cards) {
		std::cout << card->GetValue() << std::endl;
	}
}

//Deconsutrctor
Deck::~Deck()
{
}
