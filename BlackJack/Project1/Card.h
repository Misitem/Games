#pragma once
class Card
{
public:
	Card(int value);
	~Card();
	int GetValue();
private:
	int value;
	bool isAce;
};

