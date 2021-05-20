#include "Cat.h"

void Cat::initTexture()
{
	try
	{
		if (!texture.loadFromFile("Textures/cat.png"))
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

void Cat::initSprite()
{
	sprite.setTexture(texture);
	sprite.scale(0.15, 0.15);
}

void Cat::setPosition()
{
	position = sf::Vector2f(random.get_random_number(170 + sprite.getGlobalBounds().width, 930 - sprite.getGlobalBounds().width), -100);
}

void Cat::initVariables()
{
	set_points();
	set_damage(20);
	set_speed();
	set_factor();
	set_points();
}

Cat::Cat()
{
	initVariables();
	initTexture();
	initSprite();
	setPosition();
	sprite.setPosition(position);
}

Cat::~Cat() {}

const sf::Sprite& Cat::getSprite() const
{
	return sprite;
}

void Cat::move()
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

void Cat::limit()
{
	// Left
	if (sprite.getGlobalBounds().left <= 170)
		sprite.setPosition(170, sprite.getGlobalBounds().top);

	// Right
	else if (sprite.getGlobalBounds().left + sprite.getGlobalBounds().width >= 930)
		sprite.setPosition(930 - sprite.getGlobalBounds().width, sprite.getGlobalBounds().top);
}

void Cat::update()
{
	limit();
	move();
}

void Cat::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}