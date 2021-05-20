#pragma once
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>

/**Klasa odpowiadajaca za odtwarzanie muzyki.*/
class Music
{
	sf::Music music;
public:
	/**Konstruktor klasy Music.
	@param file sciezka do pliku z muzyka*/
	Music(std::string file);
	/**Destruktor klasy Music.*/
	~Music();
	/**Metoda odpowiadajaca za odtwarzanie muzyki.*/
	void playMusic();
};

