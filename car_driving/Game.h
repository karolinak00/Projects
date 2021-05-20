#pragma once
#include <cstdlib>
#include <crtdbg.h>
#include <iostream>
#include "Player.h"
#include "Collision.h"
#include "Background.h"

/**Klasa odpowiadajaca za przeprowadzenie gry.*/
class Game
{
	sf::Event event;
	std::shared_ptr<Player> player;
	std::shared_ptr<Collision> c;
	std::shared_ptr<Background> background;

	bool endGame; // zmienna informujaca o tym, czy nastapil koniec gry
	bool played; // zmienna informujaca o tym, czy juz wczesniej grano (potrzebna do tego, zeby po przegranej mozna bylo grac od nowa)

	/**Metoda inicjujaca wartosci zmiennych w klasie.*/
	void initVariables();
	/**Metoda inicjujaca obiekt klasy Background.*/
	void initBackground();
	/**Metoda inicjujaca obiekt klasy Collision.*/
	void initCollision();

public:
	/**Konstruktor klasy Game.
	@param player shared pointer do gracza*/
	Game(std::shared_ptr<Player> player);
	/**Destruktor klasy Game.*/
	~Game();
	/**Metoda zwracajaca true, jesli nastapil koniec gry. W przeciwnym przypadku zwraca wartosc false.*/
	const bool end() const;
	/**Metoda zwracajaca true, jesli gra byla juz wczesniej rozegrana. W przeciwnym przypadku zwraca wartosc false.*/
	const bool was_played() const;
	/**Metoda pozwalajaca ustawic wartosc zmiennej was_played.*/
	void set_was_played(bool was_p);
	/**Metoda sprawdzajaca, czy nastapil koniec gry. Jezeli nie, zostaja wywolane funkcje update() dla obiektow klas Player, Collision i Background.*/
	void update(sf::RenderTarget* target);
	/**Metoda wywolujaca funkcje render() dla obiektow klas Player, Collision i Background.*/
	void render(sf::RenderTarget* target);
};

