#include "Puddle.h"

void Puddle::initTexture()
{
	try
	{
		if (!texture.loadFromFile("Textures/puddle.png"))
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

void Puddle::initSprite()
{
	sprite.setTexture(texture);
	sprite.scale(0.15, 0.15);
}

void Puddle::setPosition()
{
	position = sf::Vector2f(random.get_random_number(170 + sprite.getGlobalBounds().width, 930 - sprite.getGlobalBounds().width), -200);
}

void Puddle::initVariables()
{
	set_points();
	set_damage(5);
	set_speed();
	set_factor();
	set_points();
}

Puddle::Puddle()
{
	initVariables();
	initTexture();
	initSprite();
	setPosition();
	sprite.setPosition(position);
}

Puddle::~Puddle() {}

const sf::Sprite& Puddle::getSprite() const
{
	return sprite;
}

void Puddle::move()
{
	sprite.move(0, get_speed());
}

void Puddle::update()
{
	move();
}

void Puddle::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}