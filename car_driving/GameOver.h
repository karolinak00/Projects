#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <string>
#include <iostream>
#include "Player.h"

/**Klasa odpowiadajaca za inicjalizacje i wyswietlanie okna konca gry.*/
class GameOver
{
	sf::Sprite background;
	sf::Text text;
	sf::Font font;
	sf::Texture texture;
	std::shared_ptr<Player> player;

	/**Metoda inicjujaca teksture.*/
	void initTexture();
	/**Metoda inicjujaca sprite.*/
	void initSprite();
	/**Metoda inicjujaca czcionke.*/
	void initFont();
	/**Metoda inicjujaca tekst informujacy o koncu gry i liczbie zebranych punktow.*/
	void initText();

public:
	/**Konstruktor klasy GameOver.
	@param player shared pointer do gracza*/
	GameOver(std::shared_ptr<Player> player);
	/**Destruktor klasy GameOver.*/
	~GameOver();
	/**Metoda wyswietlajaca ekran konca gry.*/
	void render(sf::RenderTarget* target);
};

