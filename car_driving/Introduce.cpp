#include "Introduce.h"

void Introduce::initFont()
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

void Introduce::initText()
{
	text.setPosition(sf::Vector2f(80, 120));
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(50);
	text.setFont(font);
	errorText.setPosition(sf::Vector2f(75, 700));
	errorText.setFillColor(sf::Color::White);
	errorText.setCharacterSize(34);
	errorText.setFont(font);
	errorText.setString("Error! You entered uncorrect name! \nMake sure that your name and surname are separated by spacebar, \nare written with capital letter and don't contain any special characters.\n");
}

void Introduce::initTexture()
{
	try
	{
		if (!texture.loadFromFile("Textures/introduce.png"))
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

void Introduce::initSprite()
{
	background.setTexture(texture);
}

void Introduce::initVariables()
{
	name = "";
	correct_name = false;
	confirm = false;
	clear = false;
	backspace = false;
	wrongName = false;
}

Introduce::Introduce(std::shared_ptr<Player> player)
{
	this->player = player;
	initVariables();
	initFont();
	initText();
	initTexture();
	initSprite();
}

Introduce::~Introduce() {}

void Introduce::pollEvents(sf::Event event, sf::RenderTarget* target)
{
	if (event.type == sf::Event::TextEntered && name.size() <= 40)
	{
		if (clock.getElapsedTime().asSeconds() > 0.15)
		{
			name += static_cast <char>(event.text.unicode);
			clock.restart();
		}

	}

	if (confirm)
	{
		{
			confirm = false;
			if (check())
			{

				correct_name = true;
				set_player_name();
			}
			else
			{
				wrongName = true;
				name.clear();
			}
		}
	}

	else if (clear)
	{
		name.clear();
		clear = false;
	}


	else if (backspace)
	{
		if (clock.getElapsedTime().asSeconds() > 0.1)
		{
			if (name.size() > 0)
				name.pop_back();
			backspace = false;
			clock.restart();
		}
	}

}

void Introduce::update(sf::Event event, sf::RenderTarget* target)
{
	pollEvents(event, target);
	text.setString(name);
}

void Introduce::render(sf::RenderTarget* target)
{
	target->draw(background);
	target->draw(text);
	if (wrongName)
		target->draw(errorText);
}

bool Introduce::check()
{
	try
	{
		if (std::regex_match(name, std::regex("[A-Z]([a-z])* [A-Z]([a-z])*")))
			return true;
		else
			return false;
	}
	catch (std::runtime_error& error)
	{
		std::cout << error.what();
	}

}

bool Introduce::is_correct()
{
	return correct_name;
}

void Introduce::set_player_name()
{
	player->setName(name);
}

void Introduce::set_confirm(bool active)
{
	confirm = active;
}

void Introduce::set_clear(bool active)
{
	clear = active;
}

void Introduce::set_backspace(bool active)
{
	backspace = active;
}