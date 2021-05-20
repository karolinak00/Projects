#include "Points.h"

void Points::initText()
{
	text.setFont(font);
	text.setPosition(sf::Vector2f(920, 20));
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(25);
}

void Points::initFont()
{
	try
	{
		if (!font.loadFromFile("Fonts/Dosis-Light.ttf"))
			throw 1;
	}
	catch (std::runtime_error& error)
	{
		std::cout << error.what() << std::endl;
	}
	catch (int)
	{
		exit(0);
	}
}

Points::Points()
{
	points = 0;
	initFont();
	initText();
}

Points::~Points() {}

void Points::addPoints(int p)
{
	points += p;
}

int Points::getPoints()
{
	return points;
}

void Points::update()
{
	text.setString("Points: " + std::to_string(points));
}

void Points::render(sf::RenderTarget* target)
{
	target->draw(text);
}
