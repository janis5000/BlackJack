#include "cardLogic.h"

cardLogic::cardLogic() : m_deck(52), m_randomNumbers(52), m_deckamount(1)
{
	m_cardAmount.assign(13, m_deckamount * 4); //13 ints with each value of m_deckamount*4
	m_allAvailableCards = std::accumulate(m_cardAmount.begin(), m_cardAmount.end(), 0);
}

cardLogic::cardLogic(int deckamount) : m_deck(m_deckamount * 52), m_randomNumbers(m_deckamount * 52), m_deckamount(deckamount)
{
	m_cardAmount.assign(13, m_deckamount * 4); //13 ints with each value of m_deckamount*4
	m_allAvailableCards = std::accumulate(m_cardAmount.begin(), m_cardAmount.end(), 0);
}

void cardLogic::shuffleCard()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(m_randomNumbers.begin(), m_randomNumbers.end(), std::default_random_engine(seed));
	std::vector<CardValue> olddeck(m_deckamount * 52);
	olddeck = m_deck;
	for (int x = 0; x < m_deckamount * 52; x++)
	{
		m_deck[x] = olddeck[m_randomNumbers[x]];
	}
}

void cardLogic::cardPrint(CardValue deckNumb)
{
	switch (deckNumb)
	{
	case ACE:
		std::cout << "ACE";// << '\n';
		break;
	case VALUE_2:
		std::cout << "2";// << '\n';
		break;
	case VALUE_3:
		std::cout << "3";// << '\n';
		break;
	case VALUE_4:
		std::cout << "4";// << '\n';
		break;
	case VALUE_5:
		std::cout << "5";// << '\n';
		break;
	case VALUE_6:
		std::cout << "6";// << '\n';
		break;
	case VALUE_7:
		std::cout << "7";// << '\n';
		break;
	case VALUE_8:
		std::cout << "8";// << '\n';
		break;
	case VALUE_9:
		std::cout << "9";// << '\n';
		break;
	case VALUE_10:
		std::cout << "10";// << '\n';
		break;
	case JACK:
		std::cout << "JACK";// << '\n';
		break;
	case QUEEN:
		std::cout << "QUEEN";// << '\n';
		break;
	case KING:
		std::cout << "KING";// << '\n';
		break;
	default:
		std::cout << "This shouldn't happen";// << '\n';
		break;
	}
}

std::vector<CardValue> cardLogic::cardDist(int deckamount)
{
	int cardCount = 0;
	for (unsigned int k = 0; k < m_deckamount * 52; k++)
	{
		if (cardCount < 12)
		{
			m_deck[k] = static_cast<CardValue>(cardCount);
			cardCount += 1;
		}
		else
		{
			m_deck[k] = static_cast<CardValue>(cardCount);
			cardCount = 0;
		}
		m_randomNumbers[k] = k;
	}
	std::cout << "----New game of blackjack, cards being shuffled now----" << '\n' << '\n';
	shuffleCard();
	return m_deck;
}

void cardLogic::displayCardAmount()
{
	m_allAvailableCards = std::accumulate(m_cardAmount.begin(), m_cardAmount.end(), 0);
	for (int x = 0; x < 13; x++)
	{
		switch (x)
		{
		case ACE:
			std::cout << "ACE: ";// << '\n';
			std::cout << m_cardAmount[x] << '\t' << '\t';
			std::cout << " Possibility: " << static_cast<float>(m_cardAmount[x]) / m_allAvailableCards;
			std::cout << '\n';
			break;
		case VALUE_2:
			std::cout << "2: ";// << '\n';
			std::cout << m_cardAmount[x] << '\t' << '\t';
			std::cout << " Possibility: " << static_cast<float>(m_cardAmount[x]) / m_allAvailableCards;
			std::cout << '\n';
			break;
		case VALUE_3:
			std::cout << "3: ";// << '\n';
			std::cout << m_cardAmount[x] << '\t' << '\t';
			std::cout << " Possibility: " << static_cast<float>(m_cardAmount[x]) / m_allAvailableCards;
			std::cout << '\n';
			break;
		case VALUE_4:
			std::cout << "4: ";// << '\n';
			std::cout << m_cardAmount[x] << '\t' << '\t';
			std::cout << " Possibility: " << static_cast<float>(m_cardAmount[x]) / m_allAvailableCards;
			std::cout << '\n';
			break;
		case VALUE_5:
			std::cout << "5: ";// << '\n';
			std::cout << m_cardAmount[x] << '\t' << '\t';
			std::cout << " Possibility: " << static_cast<float>(m_cardAmount[x]) / m_allAvailableCards;
			std::cout << '\n';
			break;
		case VALUE_6:
			std::cout << "6: ";// << '\n';
			std::cout << m_cardAmount[x] << '\t' << '\t';
			std::cout << " Possibility: " << static_cast<float>(m_cardAmount[x]) / m_allAvailableCards;
			std::cout << '\n';
			break;
		case VALUE_7:
			std::cout << "7: ";// << '\n';
			std::cout << m_cardAmount[x] << '\t' << '\t';
			std::cout << " Possibility: " << static_cast<float>(m_cardAmount[x]) / m_allAvailableCards;
			std::cout << '\n';
			break;
		case VALUE_8:
			std::cout << "8: ";// << '\n';
			std::cout << m_cardAmount[x] << '\t' << '\t';
			std::cout << " Possibility: " << static_cast<float>(m_cardAmount[x]) / m_allAvailableCards;
			std::cout << '\n';
			break;
		case VALUE_9:
			std::cout << "9: ";// << '\n';
			std::cout << m_cardAmount[x] << '\t' << '\t';
			std::cout << " Possibility: " << static_cast<float>(m_cardAmount[x]) / m_allAvailableCards;
			std::cout << '\n';
			break;
		case VALUE_10:
			std::cout << "10: ";// << '\n';
			std::cout << m_cardAmount[x] << '\t' << '\t';
			std::cout << " Possibility: " << static_cast<float>(m_cardAmount[x]) / m_allAvailableCards;
			std::cout << '\n';
			break;
		case JACK:
			std::cout << "JACK: ";// << '\n';
			std::cout << m_cardAmount[x] << '\t';
			std::cout << " Possibility: " << static_cast<float>(m_cardAmount[x]) / m_allAvailableCards;
			std::cout << '\n';
			break;
		case QUEEN:
			std::cout << "QUEEN: ";// << '\n';
			std::cout << m_cardAmount[x] << '\t';
			std::cout << " Possibility: " << static_cast<float>(m_cardAmount[x]) / m_allAvailableCards;
			std::cout << '\n';
			break;
		case KING:
			std::cout << "KING: ";// << '\n';
			std::cout << m_cardAmount[x] << '\t';
			std::cout << " Possibility: " << static_cast<float>(m_cardAmount[x]) / m_allAvailableCards;
			std::cout << '\n';
			break;
		default:
			std::cout << "This shouldn't happen";// << '\n';
			break;
		}
	}
}

void cardLogic::setCardAmount(CardValue deckNumb)
{
	switch (deckNumb)
	{
	case ACE:
		m_cardAmount[0] -= 1;
		break;
	case VALUE_2:
		m_cardAmount[1] -= 1;
		break;
	case VALUE_3:
		m_cardAmount[2] -= 1;
		break;
	case VALUE_4:
		m_cardAmount[3] -= 1;
		break;
	case VALUE_5:
		m_cardAmount[4] -= 1;
		break;
	case VALUE_6:
		m_cardAmount[5] -= 1;
		break;
	case VALUE_7:
		m_cardAmount[6] -= 1;
		break;
	case VALUE_8:
		m_cardAmount[7] -= 1;
		break;
	case VALUE_9:
		m_cardAmount[8] -= 1;
		break;
	case VALUE_10:
		m_cardAmount[9] -= 1;
		break;
	case JACK:
		m_cardAmount[10] -= 1;
		break;
	case QUEEN:
		m_cardAmount[11] -= 1;
		break;
	case KING:
		m_cardAmount[12] -= 1;
		break;
	default:
		std::cout << "This shouldn't happen";// << '\n';
		break;
	}
}

float cardLogic::getImportantProb(int score)
{
	int neededscore = 21 - score;
	float prob = 0;
	if (neededscore >= 10)
		neededscore = 13;
	for (int x = 0; x < neededscore; x++)
	{
		prob += static_cast<float>(m_cardAmount[x]) / m_allAvailableCards;
	}
	return prob;
}