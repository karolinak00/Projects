#include "Stats.h"

void Stats::initTexture()
{
	try
	{
		if (!texture.loadFromFile("Textures/statistics.png"))
			throw 1;
	}
	catch (std::fstream::failure& error)
	{
		std::cout << error.what() << std::endl;
	}
	catch (int)
	{
		exit(0);
	}
}

void Stats::initSprite()
{
	sprite.setTexture(texture);
}

Stats::Stats()
{
	initTexture();
	initSprite();
}

Stats::~Stats() {}

Stats::Stats(const Stats& s)
{
	name = s.name;
	score = s.score;
	pNext = s.pNext;
}

Stats::Stats(Stats&&s) noexcept
{
	if (this != &s)
	{
		name = s.name;
		score = s.score;
		pNext = s.pNext;
	}
}

Stats& Stats::operator=(Stats& s)
{
	name = s.name;
	score = s.score;
	pNext = s.pNext;
	return *this;
}

Stats& Stats::operator=(Stats&& s) noexcept
{
	name = s.name;
	score = s.score;
	pNext = s.pNext; 
	return *this;
}

void Stats::setVariables(std::string n, int s)
{
	name = n;
	score = s;
}

int Stats::getScore()
{
	return score;
}

std::string Stats::getName()
{
	return name;
}

void Stats::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}
