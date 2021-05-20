#include "GameOver.h"

void GameOver::initTexture()
{
	try
	{
		if (!texture.loadFromFile("Textures/game_over.png"))
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

void GameOver::initSprite()
{
	background.setTexture(texture);
}

void GameOver::initFont()
{
	try
	{
		if (!font.loadFromFile("Fonts/Dosis-Light.ttf"))
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

void GameOver::initText()
{
	text.setPosition(sf::Vector2f(380, 375));
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(40);
	text.setFont(font);
}

GameOver::GameOver(std::shared_ptr<Player> player)
{
	this->player = player;
	initTexture();
	initSprite();
	initFont();
	initText();
}

GameOver::~GameOver() {}

void GameOver::render(sf::RenderTarget* target)
{
	target->draw(background);
	text.setString("You scored " + std::to_string(player->getPoints()->getPoints()) + " points.\n");
	target->draw(text);
}
