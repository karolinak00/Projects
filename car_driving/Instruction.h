#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <exception>
#include <iostream>

/**Klasa odpowiadajaca za inicjalizacje i wyswietlanie instrukcji.*/
class Instruction
{
	sf::Texture texture;
	sf::Sprite sprite;
	/**Metoda inicjujaca teksture.*/
	void initTexture();
	/**Metoda inicjujaca sprite.*/
	void initSprite();

public:
	/**Konstruktor klasy Instruction.*/
	Instruction();
	/**Destruktor klasy Instruction.*/
	~Instruction();
	/**Metoda wyswietlajaca instrukcje gry.*/
	void render(sf::RenderTarget* target);
};

