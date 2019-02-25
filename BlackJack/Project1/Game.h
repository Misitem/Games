#pragma once
#include "Deck.h"
#include "Dealer.h"
#include "Deck.h"
#include <iostream>
#include <vector>

class Game
{
public:
	Game(Deck* deck, Player* player, Dealer* dealer);
	~Game();
	void DealHands();
	void PlayerTurn();
	void DisplayBoard();
	void DealerTurn();
	void GetWinner();
	//void CreateDeck();
private: 
	int dealerTurnNum;
	Deck* deck;
	Player* player;
	Dealer* dealer;
	//bool isSoft17;
};

