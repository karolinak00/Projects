#include "Car.h"

void Car::initTexture()
{
	try
	{
		if (!texture.loadFromFile("Textures/carenemy.png"))
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

void Car::initSprite()
{
	sprite.setTexture(texture);
	sprite.scale(0.15, 0.15);
}

void Car::setPosition()
{
	position = sf::Vector2f(random.get_random_number(170 + sprite.getGlobalBounds().width, 930- sprite.getGlobalBounds().width), 1200);
}

void Car::initVariables()
{
	set_points();
	set_damage(50);
	set_speed();
	set_factor();
	set_points();
}

Car::Car()
{
	initVariables();
	initTexture();
	initSprite();
	setPosition();
	sprite.setPosition(position);
}

Car::~Car() {}

const sf::Sprite& Car::getSprite() const
{
	return sprite;
}

void Car::move()
{
	sprite.move(0.f, -get_speed());
}

void Car::update()
{
	move();
}

void Car::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}
