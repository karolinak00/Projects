#pragma once
#include <cstdlib>
#include <crtdbg.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include "Hp.h"
#include "Points.h"

/**Klasa przechowujaca informacje na temat gracza.*/
class Player
{
	float speed;
	float factor;
	std::string name;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f position;
	std::shared_ptr<Hp> hp;
	std::shared_ptr<Points> points;

	/**Metoda inicjujaca wartosci zmiennych w klasie.*/
	void initVariables();
	/**Metoda ustawiajaca pozycje poczatkowa gracza.*/
	void setPosition(sf::RenderTarget* target);
	/**Metoda inicjujaca obiekt klasy Points.*/
	void initPoints();
	/**Metoda inicjujaca obiekt klasy Hp.*/
	void initHp();
	/**Metoda inicjujaca teksture.*/
	void initTexture();
	/**Metoda inicjujaca sprite.*/
	void initSprite();

public:
	/**Konstruktor klasy Player.*/
	Player(sf::RenderTarget* target);
	/**Destruktor klasy Player.*/
	~Player();

	/**Metoda zwracajaca sprite.*/
	const sf::Sprite& getSprite() const;
	/**Metoda umozliwiajaca ustawienie nazwy gracza.*/
	void setName(const std::string& name);
	/**Metoda zwracajaca nazwe gracza.*/
	std::string getName();

	/**Metoda odpowiedzialna za spowolnienie ruchu gracza.*/
	void slowTheCar();
	/**Metoda odpowiedzialna za ruch gracza.*/
	void move(float x, float y);
	/**Metoda odczytujaca, jakie klawisze nacisnal uzytkownik i sterujaca na tej podstawie samochodem gracza.*/
	void input(sf::Event event);
	/**Metoda uniemozliwiajaca graczowi wyjscie poza okno gry oraz poza jezdnie.*/
	void limit(const sf::RenderTarget* target);
	/**Metoda wywolujaca funkcje input() oraz aktualizujaca pozycje gracza na scenie.*/
	void update(const sf::RenderTarget* target, const sf::Event& event);
	/**Metoda wyswietlajaca gracza na scenie.*/
	void render(sf::RenderTarget* target);
	/**Metoda zwracajaca shared pointer do obiektu klasy Hp.*/
	std::shared_ptr<Hp> getHp();
	/**Metoda zwracajaca shared pointer do obiektu klasy Points.*/
	std::shared_ptr<Points> getPoints();
};

