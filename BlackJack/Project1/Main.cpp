#include "Game.h"
// Mike Misite
// Side note: I felt denoting each face card did not seem neccessary as BlackJack is purely based off the numbers
// and it is well known that there are 4 of each card in every deck. So each face card is just a 10, its value;

int main(){
	while (1) {
		//Objects, a game requires a player, a dealer, and a deck
		Player* player1 = new Player("Player One");
		Deck* deck1 = new Deck();
		Dealer* dealer1 = new Dealer("Dealer");

		Game* game1 = new Game(deck1, player1, dealer1);

		// Testing Game which contains all methods for a game of blackjack
		game1->DealHands();
		game1->DisplayBoard();
		game1->PlayerTurn();
		game1->DealerTurn();
		game1->GetWinner();
		std::cout << std::endl;
		std::cout << "Enter anything to play again: ";
		int i;
		std::cin >> i;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		game1->~Game();
	}



}