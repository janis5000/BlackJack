#pragma once
#include <vector>
#include <chrono>
#include <random>
#include <iostream>
#include <tuple>
#include <numeric>
#include "types.h"

class cardLogic
{
public:
	//Vars 

	int m_deckamount;

	std::vector<CardValue> m_deck;

	std::vector<int> m_randomNumbers;

	std::vector<int> m_cardAmount;

	int m_allAvailableCards;
	//Functions

	cardLogic();

	cardLogic(int deckamount);

	void shuffleCard();

	void cardPrint(CardValue deckNumb);

	std::vector<CardValue> cardDist(int deckamount = 1);

	void setCardAmount(CardValue deckNumb);

	void displayCardAmount();

	float getImportantProb(int score);
};