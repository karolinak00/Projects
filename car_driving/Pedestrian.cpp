#include "Pedestrian.h"

void Pedestrian::initTexture()
{
	try
	{
		if (!texture.loadFromFile("Textures/pedestrian.png"))
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

void Pedestrian::initSprite()
{
	sprite.setTexture(texture);
	frame = sf::IntRect(0, 0, 60, 120);
	sprite.setTextureRect(frame);
}

void Pedestrian::setPosition()
{
	position = sf::Vector2f(-200.f, random.get_random_number(0 + sprite.getGlobalBounds().height, 1100 - sprite.getGlobalBounds().height - 120));
}

void Pedestrian::initVariables()
{
	set_points();
	set_damage(100);
	set_speed();
	set_factor();
	set_points();
}

Pedestrian::Pedestrian()
{
	initVariables();
	initTexture();
	initSprite();
	setPosition();
	sprite.setPosition(position);
}

Pedestrian::~Pedestrian() {}

const sf::Sprite& Pedestrian::getSprite() const
{
	return sprite;
}

void Pedestrian::move()
{
	sprite.move(get_speed(), 0);
}

void Pedestrian::pedestrianMovement()
{
	if (clock.getElapsedTime().asSeconds() > 0.1)
	{
		frame.left += 54;
		if (frame.left > 200)
			frame.left = 0;
		clock.restart();
		sprite.setTextureRect(frame);
	}
}

void Pedestrian::update()
{
	pedestrianMovement();
	move();
}

void Pedestrian::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}