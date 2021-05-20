#include "Random.h"

int Random::get_random_number(int begin, int end)
{
	std::mt19937 gen(rd());
	std::uniform_int_distribution <> dis(begin, end);
	return dis(gen);
}

Random::Random() {}

Random::~Random() {}
