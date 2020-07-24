#pragma once
#include <string>
#include <iostream>
#include "types.h"
#include "cardLogic.h"

class Player
{
protected:
	std::string m_name;

public:

	int m_score = 0;

	int m_money;

	int getScore();

	void setScore(int score);

	int cardToNumb(CardValue deckNumb);
};

class User : public Player
{
private:

	bool insensitiveChComparison(std::string s1, std::string s2);

	int m_setMoney;

public:

	User();

	User(std::string name);

	User(int startmoney);

	User(std::string name, int startmoney);


	bool HitStand(cardLogic cardLogic);

	int getScore();

	bool playAgain();

	void setMoney();

	void recieveMoney(bool win);

	int getMoneyValue();
};

class Dealer : public Player
{
public:

	bool HitStand(User user);
};