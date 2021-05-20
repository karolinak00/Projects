#pragma once
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>

/**Klasa odpowiadajaca za odtwarzanie efektow dzwiekowych.*/
class Sound
{
	sf::SoundBuffer buffer;
	sf::Sound sound;

	/**Metoda odpowiadajaca za inicjalizacje bufora.*/
	void initBuffer(std::string file);
	/**Metoda odpowiadajaca za inicjalizacje dzwieku.*/
	void initSound();
public:
	/**Konstruktor klasy Sound.
	@param file sciezka do pliku z dzwiekiem*/
	Sound(std::string file);
	/**Destruktor klasy Sound.*/
	~Sound();
	/**Metoda odpowiadajaca za odtworzenie dzwieku.*/
	void playSound();
};

