#include "Player.h"

void Player::initVariables()
{
	speed = 10.f;
	factor = 0.2;
	name = "";
}

void Player::setPosition(sf::RenderTarget* target)
{
	position = sf::Vector2f(550.f, target->getSize().y - sprite.getGlobalBounds().height);
}

void Player::initPoints()
{
	points = std::make_shared<Points>();
}

void Player::initHp()
{
	hp = std::make_shared<Hp>();
}

void Player::initTexture()
{
	try
	{
		if (!texture.loadFromFile("Textures/car.png"))
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

void Player::initSprite()
{
	sprite.setTexture(texture);
	sprite.scale(0.15, 0.15);
}

Player::Player(sf::RenderTarget* target)
{
	initTexture();
	initSprite();
	setPosition(target);
	initVariables();
	sprite.setPosition(position);
	initPoints();
	initHp();

}

Player::~Player() {}

std::shared_ptr<Points> Player::getPoints()
{
	return points;
}

const sf::Sprite& Player::getSprite() const
{
	return sprite;
}

void Player::setName(const std::string& name)
{
	this->name = name;
}

std::string Player::getName()
{
	return name;
}
void Player::slowTheCar()
{
	speed -= speed * factor;
}
void Player::move(float x, float y)
{
	sprite.move(speed * x, speed * y);
}

void Player::input(sf::Event event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		move(0.f, 1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		move(0.f, -1.f);
}

void Player::limit(const sf::RenderTarget* target)
{
	// Left
	if (sprite.getGlobalBounds().left <= 170)
		sprite.setPosition(170, sprite.getGlobalBounds().top);

	// Right
	else if (sprite.getGlobalBounds().left + sprite.getGlobalBounds().width >= 930)
		sprite.setPosition(930 - sprite.getGlobalBounds().width, sprite.getGlobalBounds().top);

	// Top
	if (sprite.getGlobalBounds().top <= 0.f)
		sprite.setPosition(sprite.getGlobalBounds().left, 0.f);

	// Bottom
	else if (sprite.getGlobalBounds().top + sprite.getGlobalBounds().height >= target->getSize().y)
		sprite.setPosition(sprite.getGlobalBounds().left, target->getSize().y - sprite.getGlobalBounds().height);

}

void Player::update(const sf::RenderTarget* target, const sf::Event& event)
{
	input(event);
	limit(target);
	hp->update();
	points->update();
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(sprite);
	hp->render(target);
	points->render(target);
}

std::shared_ptr<Hp> Player::getHp()
{
	return hp;
}
