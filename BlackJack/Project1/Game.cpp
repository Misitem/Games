#include "Game.h"
#include <string>

// Where everything comes together

//A game needs a deck, player, and dealer to play
Game::Game(Deck* deck, Player* player, Dealer* dealer)
{
	this->deck = deck;
	this->player = player;
	this->dealer = dealer;
	this->dealerTurnNum = 0;
	//this->isSoft17 = false;
}

// First the deck is shuffled, then each player is dealt 2 cards accordingly
void Game::DealHands() {
	this->deck->ShuffleDeck();
	this->player->AddToHand(this->deck->Draw());
	this->dealer->AddToHand(this->deck->Draw());
	this->player->AddToHand(this->deck->Draw());
	this->dealer->AddToHand(this->deck->Draw());
}

//Function for displaying the state of the board, it really only shows the dealers hand
// This is because this idea did not fully work if I want to redisplay just the players hand, which I do often. 
// Kind of useless
void Game::DisplayBoard() {
	std::cout << "Dealer Hand: " << "\t" << std::endl;
	dealer->ShowDealerHand();
	
	
	//std::cout << "Your Hand: " << "\t" << std::endl;
	//player->ShowHand();

}

// Player turn is complex, this method might do wayy to much
// First blackjack is checked for, the player itself actually determines this. Then aces are handled ( Inner Loop )
// the player is asked for its number of aces in hand, then this is compared to how many aces have been
// handled already, this helps if the player is given 2 aces at once, and accounts for any aces drawn in the future
// after that the normal player turn is carried out ( Outer Loop ), where they are asked if they want to hit or stay, as
// long as they havent busted. Invalid input is handled, when the player decides to stand, the function returns.
void Game::PlayerTurn() {
	int handledAces = 0;
	
	if (this->player->HasBlackJack()) {
		std::cout << "Blackjack for the Player! \n";
		return;
	}

	while (this->player->Busted() == false) {
		std::string strChoice;
		int choice;
		int currentAces = this->player->NumOfAces();

		while(handledAces < currentAces) {
			this->player->ShowHand();
			
			std::cout << "You have an ace: \n(1) take 1 for a total of: " << this->player->GetScore() + 1 << "\n(2) take 11 for a total of: " << (this->player->GetScore() + 11) << std::endl;
			std::cin >> choice;

			if (choice == 1 || choice == 2) { 
				this->player->AdjustForAce(choice);
				handledAces += 1;
				std::cin.clear();
			}
			else {
				std::cout << "\n\nINVALID CHOICE!!!\n\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			
			}
			
		}
		

		// If the player busts, break loop and jump to 'You Busted'
		if (player->GetScore() > 21) { break; }

		// If nothing above breaks the loop or ends the players turn
		// Continue to ask if they would like to hit or stand
		// Hitting will update the hand and the loop will continue until something stops it
		// Standing will return, ending the players turn
		this->player->ShowHand();
		std::cout << "Your total is: " << player->GetScore() << std::endl;
		std::cout << "Hit (1) or Stand (2) ? ";
		std::cin >> choice;
		if (choice == 1) {
			Card* drawnCard = this->deck->Draw();
			std::cout << "\n" << this->player->GetName() << " Drew a " << drawnCard->GetValue() << "\n" << std::endl;
			this->player->AddToHand(drawnCard);
			
		
		}
		else if (choice == 2) {
			return;
		}
		else { 
			std::cout << "\n\nINVALID CHOICE!!!\n\n";
			std::cin.clear(); 
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	this->player->ShowHand();
	std::cout << this->player->GetName() << "'s Score: " << this->player->GetScore() << std::endl;
	std::cout << "\nYou Busted, sorry you lose\n";
}


// Logic for dealers turn
void Game::DealerTurn() {
	dealerTurnNum += 1;
	if (this->player->HasBlackJack()) {
		std::cout << "Blackjack for the Dealer! \n";
		dealer->RevealHand();
		return;
	}
	// Dealer only goes if player has not busted, the rules I found said if its 1 on 1 and the player busts, even
	// if the dealer busts, the player still loses.
	if ((!this->player->Busted())) {
		
		// Dealer plays by rules if under 17 they will hit, if they have a soft 17 they will also hit
		// Reveal hand is just showing the dealers hand before and after drawing
		while ((this->dealer->GetScore() < 17) || ((dealerTurnNum == 0 & dealer->NumOfAces() > 0) & (dealer->GetScore() + 11 == 17))) {
			dealer->RevealHand();
			Card* drawnCard = this->deck->Draw();
			std::cout << "\n" << this->dealer->GetName() << " Drew a " << drawnCard->GetValue() << "\n";
			dealer->AddToHand(drawnCard);
			//dealer->RevealHand();

		}
	}
	dealer->RevealHand();
	return;
}

//Determines winner, first displays player and dealer score, then determines winner based on a couple if statements
void Game::GetWinner() {
	std::cout << "\nPlayer Score: " << player->GetScore() << std::endl;
	std::cout << "\nDealer Score: " << dealer->GetScore() << "\n" << std::endl;

	if (player->GetScore() == dealer->GetScore()) {
		std::cout << "Tie Game";
		return;
	}
	else if (player->Busted()) {
		std::cout << "Dealer Wins";
		return;
	}
	else if (dealer->Busted()) {
		std::cout << "Dealer Busted! " << "You Win!";
		return;
	}
	else if (player->GetScore() > dealer->GetScore()) {
		std::cout << " You Win!";
		return;
	}
	else { std::cout << " Dealer Wins"; return; }
}

Game::~Game()
{
}
