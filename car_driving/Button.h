#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include "Sound.h"

/**Klasa odpowiedzialna za dzialanie przyciskow w grze.*/
class Button
{
	bool active; // zmienna okreslajaca, czy przycisk w danej chwili jest aktywny, czy nie
	sf::Texture texture;
	sf::Sprite sprite;
	std::shared_ptr<Sound> sound;

	/**Metoda inicjujaca teksture.*/
	void initTexture(std::string path);
	/**Metoda inicjujaca sprite.*/
	void initSprite();
	/**Metoda ustawiajaca pozycje przycisku.*/
	void setPosition(sf::Vector2f pos);
	/**Metoda inicjujaca dzwiek wydawany przez przycisk w czasie jego nacisniecia.*/
	void initSound();
	
public:
	/**Konstruktor klsy Button.
	@param path sciezka do pliku z grafika, ktora ma sie znalezc na przycisku
	@param pos pozycja przycisku na scenie*/
	Button(std::string path, sf::Vector2f pos);
	/**Destruktor klasy Button.*/
	~Button();
	/**Metoda zwracajaca sprite.*/
	const sf::Sprite& getSprite() const;
	/**Metoda wywolujaca funkcje klasy Sound, ktora odtwarza dzwiek.*/
	void playSound();
	/**Metoda zwracajaca wartosc true, jesli przycisk jest aktualnie aktywny i false, jezeli nie jest aktywny.*/
	bool is_active();
	/**Metoda zmieniajaca aktywnosc przycisku.*/
	void change_activity(bool activity);
};

