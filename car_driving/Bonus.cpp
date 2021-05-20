#include "Bonus.h"

void Bonus::initTexture()
{
	try
	{
		if (!texture.loadFromFile("Textures/bonus.png"))
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

void Bonus::initSprite()
{
	sprite.setTexture(texture);
	sprite.scale(0.5, 0.5);
}

void Bonus::setPosition()
{
	position = sf::Vector2f(1200.f, random.get_random_number(0 + sprite.getGlobalBounds().height, 1100 - sprite.getGlobalBounds().height - 200));
}

void Bonus::initVariables()
{
	set_points();
	set_damage(-10);
	set_speed();
	set_factor();
	set_points();
}

Bonus::Bonus()
{
	initVariables();
	initTexture();
	initSprite();
	setPosition();
	sprite.setPosition(position);
}

Bonus::~Bonus() {}

const sf::Sprite& Bonus::getSprite() const
{
	return sprite;
}

void Bonus::move()
{
	sprite.move(-get_speed(), 0);
}

void Bonus::update()
{
	move();
}

void Bonus::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}