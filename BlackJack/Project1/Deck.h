#pragma once
#include <list>
#include "Card.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>    
#include <chrono> 
class Deck
{
public:
	Deck();
	~Deck();
	void FillDeck();
	void ShuffleDeck();
	void PrintDeck();
	Card* Draw();
private:
	std::vector<Card*> cards;
	int myrandom;
};

