#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <iostream>

/**Klasa odpowiadajaca za przechowywanie i operacje na punktach zycia gracza.*/
class Hp
{
	int hpMax;
	int hp;
	
	sf::RectangleShape shape_hpMax;
	sf::RectangleShape shape_hp;
	sf::Font font;
	sf::Text text;

	/**Metoda inicjujaca wartosci zmiennych w klasie.*/
	void initVariables();
	/**Metoda inicjujaca ksztalt prostokatny obrazujacy poziom punktow zycia gracza.*/
	void initShape();
	/**Metoda inicjujaca czcionke.*/
	void initFont();
	/**Metoda inicjujaca tekst.*/
	void initText();

public:
	/**Konstruktor klasy Hp.*/
	Hp();
	/**Destruktor klasy Hp.*/
	~Hp();
	/**Metoda zwracajaca liczbe punktow zycia gracza.*/
	int getHp();
	/**Metoda odejmujaca punkty zycia gracza po kolizji z przeszkoda.*/
	void substractHp(int substract);
	/**Metoda aktualizujaca ksztalt odpowiadajacy poziomowi punktow zycia gracza.*/
	void update();
	/**Metoda odpowiedzialna za wyswietlenie poziomu punktow zycia gracza.*/
	void render(sf::RenderTarget* target);
};

