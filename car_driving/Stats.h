#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <exception>
#include <string>
#include <iostream>
#include <fstream>

/**Klasa pelniaca role listy jednokierunkowej, przechowujacej dane ze statystyk.*/
class Stats
{
	std::string name;
	int score;
	sf::Texture texture;
	sf::Sprite sprite;

	/**Metoda inicjujaca teksture.*/
	void initTexture();
	/**Metoda inicjujaca sprite.*/
	void initSprite();

public:
	Stats* pNext;

	/**Konstruktor klasy Stats.*/
	Stats();
	/**Destruktor klasy Stats.*/
	~Stats();
	/**Konstruktor kopiujacy klasy Stats.*/
	Stats(const Stats&);
	/**Konstruktor przenoszacy klasy Stats.*/
	Stats(Stats&&) noexcept;
	/**Operator przypisania klasy Stats.*/
	Stats& operator=(Stats& n);
	/**Operator przeniesienia klasy Stats.*/
	Stats& operator=(Stats&& n) noexcept;

	/**Metoda umozliwiajaca ustawienie wartosci nazwy gracza i punktow.*/
	void setVariables(std::string n, int s);
	/**Metoda zwracajaca liczbe punktow uzyskanych przez danego gracza zapisanego w statystykach.*/
	int getScore();
	/**Metoda zwracajaca nazwe gracza zapisanego w statystykach.*/
	std::string getName();
	/**Metoda wyswietlajaca okno statystyk.*/
	void render(sf::RenderTarget *target);
};