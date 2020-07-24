#include "Player.h"

int Player::getScore()
{
	std::cout << "Your current score is " << m_score << '\n';
	return m_score;
}

int Player::cardToNumb(CardValue deckNumb)
{
	switch (deckNumb)
	{
	case ACE:
		if (m_score <= 10)
			return 11;
		else
			return 1;
	case VALUE_2:
		return 2;
	case VALUE_3:
		return 3;
	case VALUE_4:
		return 4;
	case VALUE_5:
		return 5;
	case VALUE_6:
		return 6;
	case VALUE_7:
		return 7;
	case VALUE_8:
		return 8;
	case VALUE_9:
		return 9;
	case VALUE_10:
		return 10;
	case JACK:
		return 10;
	case QUEEN:
		return 10;
	case KING:
		return 10;
	default:
		return 0;
	}
}

void Player::setScore(int score)
{
	m_score = score;
}
