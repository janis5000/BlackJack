#include "Player.h"

bool Dealer::HitStand(User user)
{
	int user_score = user.getScore();
	std::cout << "USER SCORE: " << user_score << " DEALER SCORE: " << Player::m_score << '\n';
	if (user_score <= 16)
	{
		if (m_score >= 16)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else if (user_score > 16)
	{
		if (m_score < user_score)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}