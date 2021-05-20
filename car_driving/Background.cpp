#include "Background.h"

void Background::initTexture()
{
	try
	{
		if (!texture.loadFromFile("Textures/road.png"))
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

void Background::initSprite()
{
	sprite.setTexture(texture);
	frame = sf::IntRect(0, 0, 1100, 950);
	sprite.setTextureRect(frame);
}

Background::Background()
{
	timer = 0.1;
	factor = 0.01;
	initTexture();
	initSprite();
}

Background::~Background() {}

void Background::faster_background()
{
	timer -= timer * factor;
}

void Background::update()
{
	if (clock.getElapsedTime().asSeconds() > timer)
	{
		frame.top -= 50;
		if (frame.top < 0)
			frame.top = 5800;
		clock.restart();
		sprite.setTextureRect(frame);
	}
}

void Background::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}
