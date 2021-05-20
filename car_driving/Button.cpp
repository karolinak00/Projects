#include "Button.h"

void Button::initTexture(std::string path)
{
	try
	{
		if (!texture.loadFromFile(path))
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

void Button::initSprite()
{
	sprite.setTexture(texture);
}

void Button::setPosition(sf::Vector2f pos)
{
	sprite.setPosition(pos);
}

void Button::initSound()
{
	sound = std::make_shared<Sound>("Sounds/button.wav");
}

Button::Button(std::string path, sf::Vector2f pos)
{
	this->active = false;
	initTexture(path);
	initSprite();
	setPosition(pos);
	initSound();
}

Button::~Button() {}

const sf::Sprite& Button::getSprite() const
{
	return sprite;
}

void Button::playSound()
{
	sound->playSound();
}

bool Button::is_active()
{
	return active;
}

void Button::change_activity(bool activity)
{
	active = activity;
}
