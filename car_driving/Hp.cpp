#include "Hp.h"

void Hp::initVariables()
{
	hpMax = 100;
	hp = hpMax;
}

void Hp::initShape()
{
	shape_hpMax.setFillColor(sf::Color(255, 0, 0, 75));
	shape_hpMax.setSize(sf::Vector2f(400.f, 30.f));
	shape_hpMax.setPosition(sf::Vector2f(75.f, 20.f));

	shape_hp.setFillColor(sf::Color::Red);
	shape_hp.setPosition(sf::Vector2f(75.f, 20.f));
	
}

void Hp::initFont()
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

void Hp::initText()
{
	text.setFont(font);
	text.setPosition(sf::Vector2f(25.f, 20.f));
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(25);
	text.setString("HP:");
}

Hp::Hp()
{
	initVariables();
	initShape();
	initFont();
	initText();
}

Hp::~Hp() {}

int Hp::getHp()
{
	return hp;
}

void Hp::substractHp(int substract)
{
	hp -= substract;
	if (hp < 0)
		hp = 0;
	else if (hp > hpMax)
		hp = hpMax;
}

void Hp::update()
{
	shape_hp.setSize(sf::Vector2f( 4.f * hp, 30.f));
}

void Hp::render(sf::RenderTarget* target)
{
	target->draw(shape_hpMax);
	target->draw(shape_hp);
	target->draw(text);
}
