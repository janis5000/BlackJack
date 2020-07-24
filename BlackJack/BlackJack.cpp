#include <iostream>
#include <string>
#include <vector>
#include <array>

#include <random>
#include <chrono>
#include <algorithm>
#include "Player.h"
#include "cardLogic.h"

class Game
{
private:
	Dealer m_dealer;
	User m_user;
	int m_deckamount = 1;
	cardLogic cardFunctions;
	int m_botAmount = 0;
	int m_userAmount = 1;
	int m_playeramount = m_botAmount + m_userAmount + 1; //+1 for dealer

	bool m_dealerPlaying;
	bool m_userPlaying;
	bool m_userBust;
	bool m_dealerBust;

	int m_cardUserCount;

	std::array<CardValue, 2> m_beginDealerCards;

	void currentStatus(CardValue card)
	{
		if (m_userPlaying == false)
			return;
		/*std::cout << "Do you want to take the card: ";
		cardPrint(card, m_user.m_score);
		std::cout << "?" <<'\n';
		m_user.Player::getScore();*/
		m_userPlaying = m_user.HitStand(cardFunctions);

	}

	void preGame()
	{
		int current_dealer = m_cardUserCount + 2;
		int current_bots = m_cardUserCount + 2 * m_botAmount;
		std::vector<CardValue> beginUserCards(2 * m_userAmount);
		//Begin of the round

		//Dealer loop
		for (m_cardUserCount; m_cardUserCount < current_dealer; m_cardUserCount++)
		{
			CardValue dealerCardtemp = cardFunctions.m_deck[m_cardUserCount];
			m_dealer.m_score += m_dealer.cardToNumb(dealerCardtemp);
			m_beginDealerCards[current_dealer - m_cardUserCount - 1] = dealerCardtemp;
		}

		cardFunctions.setCardAmount(m_beginDealerCards[1]);
		//User loop
		int current_user = m_cardUserCount + 2 * m_userAmount;
		for (m_cardUserCount; m_cardUserCount < current_user; m_cardUserCount++)
		{
			CardValue userCardtemp = cardFunctions.m_deck[m_cardUserCount];
			m_user.m_score += m_user.cardToNumb(userCardtemp);
			beginUserCards[current_user - m_cardUserCount - 1] = userCardtemp;
			cardFunctions.setCardAmount(userCardtemp);
		}

		//Print current cards etc.
		std::cout << "At the beginning you got the cards: ";
		current_user = m_cardUserCount + 2 * m_userAmount;
		for (int x = 0; x < current_user - m_cardUserCount; x++)
		{
			cardFunctions.cardPrint(beginUserCards[x]);
			if (x == 0)
				std::cout << ", ";
		}
		std::cout << '\n';
		std::cout << "The dealer has a ";
		cardFunctions.cardPrint(m_beginDealerCards[1]);
		std::cout << " and another hidden card. " << '\n';
	}

	void dealerPlaying()
	{
		std::cout << "The hidden dealer card is ";
		cardFunctions.cardPrint(m_beginDealerCards[0]);
		std::cout << " his start card was ";
		cardFunctions.cardPrint(m_beginDealerCards[1]);
		std::cout << '\n';
		cardFunctions.setCardAmount(m_beginDealerCards[0]);
		if (m_userBust == true)
		{
			std::cout << "You lost ! Dealer: " << m_dealer.m_score << " vs. Your score (over 21): " << m_user.m_score;
			return;
		}
		for (m_cardUserCount; m_cardUserCount < m_deckamount * 52; m_cardUserCount++)
		{
			CardValue card = cardFunctions.m_deck[m_cardUserCount];
			if (m_dealer.m_score > 21)
			{
				std::cout << "You won ! Dealer (over 21): " << m_dealer.m_score << " vs. Your score: " << m_user.m_score;
				m_dealerBust = 1;
				return;
			}
			if (m_dealer.HitStand(m_user) == true)
			{
				std::cout << "Dealer got a ";
				cardFunctions.cardPrint(card);
				cardFunctions.setCardAmount(card);
				std::cout << '\n';
				m_dealer.m_score += m_dealer.cardToNumb(card);
			}
			else
			{
				m_dealerPlaying = false;
				return;
			}
		}
	}

	void userPlaying()
	{
		preGame();
		//Card distribution loop
		for (m_cardUserCount; m_cardUserCount < m_deckamount * 52; m_cardUserCount++)
		{
			CardValue card = cardFunctions.m_deck[m_cardUserCount];
			//Checking if score is still below 21
			if (m_user.m_score > 21)
			{
				m_userBust = true;
				return;
			}

			//Giving the current status of the player and what card he can accept
			currentStatus(card);
			if (m_userPlaying == true)
			{
				std::cout << "You got a ";
				cardFunctions.cardPrint(card);
				std::cout << '\n';
				cardFunctions.setCardAmount(card);
				m_user.m_score += m_user.cardToNumb(card);
			}
			else
			{
				m_userPlaying = false;
				break;
			}
		}
		return;
	}

	void resetGame()
	{
		m_dealerPlaying = true;
		m_userPlaying = true;
		m_userBust = false;
		m_dealerBust = false;
		m_dealer.setScore(0);
		m_user.setScore(0);
	}
public:

	Game() : m_dealerPlaying{ true }, m_userPlaying{ true }, m_userBust{ false }, m_dealerBust{ false },
		m_cardUserCount{ 0 }, m_user(100)
	{
		cardFunctions.m_deckamount = m_deckamount;
		cardFunctions.m_deck = cardFunctions.cardDist(m_deckamount);
	}

	Game(int deckamount) : cardFunctions(deckamount), m_dealerPlaying{ true },
		m_userPlaying{ true }, m_userBust{ false }, m_dealerBust{ false }, m_cardUserCount{ 0 },
		m_deckamount{ deckamount }, m_user(100)
	{
		cardFunctions.m_deckamount = m_deckamount;
		cardFunctions.m_deck = cardFunctions.cardDist(m_deckamount);
	}

	Game(int deckamount, int startmoney) : cardFunctions(deckamount), m_dealerPlaying{ true },
		m_userPlaying{ true }, m_userBust{ false }, m_dealerBust{ false }, m_cardUserCount{ 0 }, m_user(startmoney),
		m_deckamount{ deckamount }
	{
		cardFunctions.m_deckamount = m_deckamount;
		cardFunctions.m_deck = cardFunctions.cardDist(m_deckamount);
	}

	void playGame()
	{
		bool restart = 0;
		while (true)
		{
			if (m_cardUserCount > m_deckamount * 52 - 11)//m_deckamount * 52 - 15 * m_playeramount) //15 max amount you could need per round: 6 twos and 9 aces (multiple decks)
			{
				std::cout << "Not enough cards ! Reshuffling";
				cardFunctions.m_deck = cardFunctions.cardDist(m_deckamount);
				m_cardUserCount = 0;
			}
			std::cout << "Starting another round... \n";
			m_user.setMoney();
			userPlaying();
			dealerPlaying();
			//cardFunctions.displayCardAmount();

			if (m_dealer.m_score > m_user.m_score && m_userBust == false && m_dealerBust == false)
			{
				m_user.recieveMoney(0);
				std::cout << "You lost ! Dealer: " << m_dealer.m_score << " vs. Your score: " << m_user.m_score << '\n';
				m_user.getMoneyValue();
			}
			else if (m_dealer.m_score < m_user.m_score && m_userBust == false && m_dealerBust == false)
			{
				m_user.recieveMoney(1);
				std::cout << "You won ! Dealer: " << m_dealer.m_score << " vs. Your score: " << m_user.m_score << '\n';
				m_user.getMoneyValue();
			}
			else if (m_userBust == false && m_dealerBust == false)
			{
				std::cout << "A tie ! both have the score of: " << m_dealer.m_score << ", " << m_user.m_score << '\n';
				m_user.getMoneyValue();
			}
			else if (m_dealerBust == true)
			{
				m_user.recieveMoney(1);
				std::cout << '\n';
				m_user.getMoneyValue();
			}
			else if (m_userBust == true)
			{
				m_user.recieveMoney(0);
				std::cout << '\n';
				m_user.getMoneyValue();
			}

			if (m_user.m_money == 0)
			{
				std::cout << "You lost all your money.";
				break;
			}
			restart = m_user.playAgain();
			if (restart == 0)
			{
				break;
			}
			resetGame();
		}
	}
};


int main()
{
	Game blackJack = Game(4, 100);
	std::cout << '\n';
	blackJack.playGame();
}