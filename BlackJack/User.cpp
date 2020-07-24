#include "Player.h"

bool User::insensitiveChComparison(std::string s1, std::string s2)
{
	unsigned size = s1.size();
	if (size != s2.size())
		return false;

	for (unsigned x = 0; x < size; x++)
	{
		if (tolower(s1[x]) != tolower(s2[x]))
		{
			return false;
		}
	}
	return true;
}

User::User() {}

User::User(int startmoney)
{
	m_money = startmoney;
}

User::User(std::string name, int startmoney)
{
	m_name = name;
	m_money = startmoney;
}

User::User(std::string name)
{
	std::cout << "Choose your name" << '\n';
	m_name = name;
}

bool User::HitStand(cardLogic cardLogic)
{
	for (unsigned int tries = 0; tries < 2; tries++) //2 tries to write what the player wants to do
	{
		std::string choice;
		m_score = getScore();
		Player::getScore();
		std::cout << "You want to stand (s), hit (h) or get current cards (g)? ";
		std::cin >> choice;
		if (insensitiveChComparison("s", choice) || insensitiveChComparison("stand", choice))
		{
			return false;
		}
		else if (insensitiveChComparison("h", choice) || insensitiveChComparison("hit", choice))
		{
			return true;
		}
		else if (insensitiveChComparison("g", choice) || insensitiveChComparison("G", choice))
		{
			cardLogic.displayCardAmount();
			std::cout << "The probability to get cards for 21 - " << m_score << " = " << 21 - m_score << "is: " << cardLogic.getImportantProb(m_score) << '\n';
			tries -= 1;
			continue;
		}
		else
		{
			std::cout << "This option is not available" << '\n';
		}
	}
	return false; //if the player doesn't enter anything correct after 2 tries he is going to stand
}

int User::getScore()
{
	return m_score;
}

bool User::playAgain()
{
	for (int x = 0; x < 3; x++)
	{
		std::string choice;
		std::cout << '\n';
		std::cout << "Do you want to play again ? y/n ";
		std::cin >> choice;
		if (insensitiveChComparison("y", choice) || insensitiveChComparison("yes", choice))
		{
			return true;
		}
		else if (insensitiveChComparison("n", choice) || insensitiveChComparison("no", choice))
		{
			return false;
		}
		else
		{
			std::cout << "invalid" << '\n';
		}
	}
	return true;
}

void User::setMoney()
{
	for (int x = 0; x < 2; x++)
	{
		std::cout << "How much money do you want to bet ? ";
		std::cin >> m_setMoney;
		std::cout << '\n';
		if (m_setMoney > m_money)
		{
			std::cout << "Not enough money !\n";
			continue;
		}
		//m_money - setMoney;
		return;
	}
	std::cout << "You didn't set any money.\n\n";
	m_setMoney = 0;
}

void User::recieveMoney(bool win)
{
	if (win == 1)
	{
		std::cout << '\n';
		std::cout << "You won " << m_setMoney << '\n';
		m_money += m_setMoney;
	}
	else
	{
		std::cout << '\n';
		std::cout << "You lost " << m_setMoney << '\n';
		m_money -= m_setMoney;
	}
}

int User::getMoneyValue()
{
	std::cout << "Your current money is: " << m_money << '\n';
	return m_money;
}