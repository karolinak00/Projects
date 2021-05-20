#include "Credits.h"

void Credits::initTexture()
{
	try
	{
		if (!texture.loadFromFile("Textures/credits.png"))
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

void Credits::initSprite()
{
	sprite.setTexture(texture);
}

Credits::Credits()
{
	initTexture();
	initSprite();
}

Credits::~Credits() {}

void Credits::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}
