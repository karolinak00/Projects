#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <string>
#include <iostream>
#include <regex>
#include <exception>
#include "Player.h"

/**Klasa odpowiadajaca za pobranie imienia i nazwiska gracza oraz przekazanie tych danych do klasy Player.*/
class Introduce
{
	std::string name;
	bool correct_name;
	bool confirm; // jesli zmienna ta ma wartosc true, zostaje wywolana funkcja sprawdzajaca, czy nazwa jest poprawna. 
				  //Jesli tak, jest ona zatwierdzana i rozpoczyna sie gra,
				  //jesli nie, nazwa jest usuwana i gracz na nowo musi ja podac.

	bool clear;  // jesli zmienna ta ma wartosc true, nazwa jest usuwana. 
	bool backspace; // jesli zmienna ta ma wartosc true, usuwana jest ostatnia litera nazwy
	bool wrongName;

	sf::Font font;
	sf::Text text;
	sf::Text errorText;
	sf::Sprite background;
	sf::Texture texture;
	sf::Clock clock;
	std::shared_ptr<Player> player;

	/**Metoda inicjujaca czcionke.*/
	void initFont();
	/**Metoda inicjujaca tekst.*/
	void initText();
	/**Metoda inicjujaca teksture.*/
	void initTexture();
	/**Metoda inicjujaca sprite.*/
	void initSprite();
	/**Metoda inicjujaca wartosci zmiennych w klasie.*/
	void initVariables();

public:
	/**Konstruktor klasy Introduce.
	@param player shared pointer do gracza*/
	Introduce(std::shared_ptr<Player> player);
	/**Destruktor klasy Introduce.*/
	~Introduce();
	/**Metoda odpowiadajaca za zamiane znakow z klawiatury w tekst oraz uruchamianiu odpowiednich funkcji w zaleznosci od przycisku wybranego przez uzytkownika.*/
	void pollEvents(sf::Event event, sf::RenderTarget* target);
	/**Metoda wywolujaca funkcje pollEvents() oraz dopisujaca do zmiennej name znak wprowadzony przez uzytkownika.*/
	void update(sf::Event event, sf::RenderTarget* target);
	/**Metoda wyswietlajaca na ekranie tlo, zawartosc zmiennej name oraz ewentualne ostrzezenie o wprowadzeniu niepoprawnej wartosci zmiennej name.*/
	void render(sf::RenderTarget* target);
	/**Metoda sprawdzajaca, czy wprowadzone przez uzytkownika dane sa zgodne z szablonem.*/
	bool check();
	/**Metoda zwracajaca wartosc true, jezeli nazwa gracza zostala podana poprawnie.*/
	bool is_correct();
	/**Metoda ustawiajaca nazwe gracza na te podana przez uzytkownika.*/
	void set_player_name();
	/**Metoda ustawiajaca wartosc zmiennej confirm.*/
	void set_confirm(bool active);
	/**Metoda ustawiajaca wartosc zmiennej clear.*/
	void set_clear(bool active);
	/**Metoda ustawiajaca wartosc zmiennej backspace.*/
	void set_backspace(bool active);
};