#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <exception>
#include <iostream>

/**Klasa odpowiadajaca za inicjalizacje i wyswietlanie przypisow.*/
class Credits
{
	sf::Texture texture;
	sf::Sprite sprite;
	/**Metoda inicjujaca teksture.*/
	void initTexture();
	/**Metoda inicjujaca sprite.*/
	void initSprite();

public:
	/**Konstruktor klasy Credits.*/
	Credits();
	/**Destruktor klasy Credits.*/
	~Credits();
	/**Metoda wyswietlajaca przypisy.*/
	void render(sf::RenderTarget* target);
};

