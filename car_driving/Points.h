#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <iostream>

/**Klasa odpowiadajaca za przechowywanie i operacje na punktach gracza.*/
class Points
{
	int points;
	sf::Text text;
	sf::Font font;

	/**Metoda inicjujaca tekst.*/
	void initText();
	/**Metoda inicjujaca czcionkê.*/
	void initFont();

public:
	/**Konstruktor klasy Points.*/
	Points();
	/**Destruktor klasy Points.*/
	~Points();

	/**Metoda dodajaca punkty, jesli gracz ominal przeszkode.*/
	void addPoints(int p);
	/**Metoda zwracajaca liczbe punktow gracza.*/
	int getPoints();
	/**Metoda aktualizaujaca liczbe punktow gracza.*/
	void update();
	/**Metoda odpowiedzialna za wyswietlenie liczby punktow gracza na scenie.*/
	void render(sf::RenderTarget *target);
};

