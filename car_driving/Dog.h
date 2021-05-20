#pragma once
#include "RandomlyMovingObject.h"

/**Klasa dziedziczaca po klasie RandomlyMovingObject, inicjujaca i wyswietlajaca przeszkode w postaci psa.*/
class Dog : public RandomlyMovingObject
{
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f position;
	sf::Clock clock;

	/**Metoda inicjujaca teksture.*/
	void initTexture();
	/**Metoda inicjujaca sprite.*/
	void initSprite();
	/**Metoda ustawiajaca w sposob losowy pozycje poczatkowa obiektu.*/
	void setPosition();
	/**Metoda inicjujaca wartosci zmiennych w klasie.*/
	void initVariables();

public:
	/**Konstruktor klasy Dog.*/
	Dog();
	/**Destruktor klasy Dog.*/
	~Dog();

	/**Metoda zwracajaca sprite.*/
	const sf::Sprite& getSprite() const;
	/**Metoda odpowiadajaca za ruch obiektu.*/
	void move() override;
	/**Metoda odpowiadajaca za to, by obiekt nie pojawial sie poza polem ruchu gracza.*/
	void limit();
	/**Metoda aktualizujaca pozycje obiektu na scenie.*/
	void update();
	/**Metoda wyswietlajaca obiekt na scenie.*/
	void render(sf::RenderTarget* target);
};

