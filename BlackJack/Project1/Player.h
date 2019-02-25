#pragma once
#include "Card.h"
#include <vector>
#include <iostream>
#include <string>
class Player
{
public:
	Player(std::string name);
	~Player();
	void ShowHand();
	int GetScore();
	void AddToHand(Card* card);
	bool Busted();
	int NumOfAces();
	void AdjustForAce(int choice);
	std::string GetName();
	bool HasBlackJack();
protected:
	bool hasAce;
	std::vector<Card*> hand;
	int score;
	std::string name;
	int aces;

};

