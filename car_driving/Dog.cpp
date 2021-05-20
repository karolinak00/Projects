#include "Dog.h"

void Dog::initTexture()
{
	try
	{
		if (!texture.loadFromFile("Textures/dog.png"))
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

void Dog::initSprite()
{
	sprite.setTexture(texture);
	sprite.scale(0.15, 0.15);
}

void Dog::setPosition()
{
	position = sf::Vector2f(random.get_random_number(170 + sprite.getGlobalBounds().width, 930 - sprite.getGlobalBounds().width), -200);
}

void Dog::initVariables()
{
	set_points();
	set_damage(25);
	set_speed();
	set_factor();
	set_points();
}

Dog::Dog()
{
	initVariables();
	initTexture();
	initSprite();
	setPosition();
	sprite.setPosition(position);
}

Dog::~Dog() {}

const sf::Sprite& Dog::getSprite() const
{
	return sprite;
}

void Dog::move()
{
	int tmp = random.get_random_number(0, 4);
	if (clock.getElapsedTime().asSeconds() > 0.05)
	{
		if (tmp == 0)
			sprite.move(get_speed() * random.get_random_number(10, 20), get_speed() * random.get_random_number(10, 20));

		else if (tmp == 1)
			sprite.move(-get_speed() * random.get_random_number(10, 20), get_speed() * random.get_random_number(10, 20));

		else if (tmp == 2)
			sprite.move(-get_speed() * random.get_random_number(10, 20), 0);

		else if (tmp == 3)
			sprite.move(get_speed() * random.get_random_number(10, 20), 0);

		else
			sprite.move(0, get_speed() * random.get_random_number(10, 20));

		clock.restart();
	}
}

void Dog::limit()
{
	// Left
	if (sprite.getGlobalBounds().left <= 170)
		sprite.setPosition(170, sprite.getGlobalBounds().top);

	// Right
	else if (sprite.getGlobalBounds().left + sprite.getGlobalBounds().width >= 930)
		sprite.setPosition(930 - sprite.getGlobalBounds().width, sprite.getGlobalBounds().top);
}

void Dog::update()
{
	limit();
	move();
}

void Dog::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}