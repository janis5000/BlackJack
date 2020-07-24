#pragma once
#include <array>
enum CardValue
{
	ACE,
	VALUE_2,
	VALUE_3,
	VALUE_4,
	VALUE_5,
	VALUE_6,
	VALUE_7,
	VALUE_8,
	VALUE_9,
	VALUE_10,
	JACK,
	QUEEN,
	KING,
};

struct Cards
{
	std::array<CardValue, 13> cross;
	std::array<CardValue, 13> spade;
	std::array<CardValue, 13> check;
	std::array<CardValue, 13> heart;
};
