#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <exception>
#include <iostream>

/**Klasa odpowiadajaca za inicjalizacje, wyswietlanie i przesuwanie tla podczas gry.*/
class Background
{
	sf::Texture texture;
	sf::Sprite sprite;
	sf::IntRect frame;
	sf::Clock clock;

	float timer;
	float factor;
	/**Metoda inicjujaca teksture.*/
	void initTexture();
	/**Metoda inicjujaca sprite.*/
	void initSprite();

public:
	/**Konstruktor klasy Background*/
	Background();
	/**Destruktor klasy Background*/
	~Background();
	/**Metoda przyspieszajaca ruch tla (skrocony zostaje czas zegara wykorzystywany w funkcji update()).*/
	void faster_background();
	/**Metoda aktualizujaca tlo (tutaj zaimplementowane jest przesuwanie sie tla).*/
	void update();
	/**Metoda odpowiadajaca za wyswietlenie tla na ekranie.*/
	void render(sf::RenderTarget* target);
};

