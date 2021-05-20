#include "Instruction.h"

void Instruction::initTexture()
{
	try
	{
		if (!texture.loadFromFile("Textures/instruction.png"))
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

void Instruction::initSprite()
{
	sprite.setTexture(texture);
}

Instruction::Instruction()
{
	initTexture();
	initSprite();
}

Instruction::~Instruction() {}

void Instruction::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}
