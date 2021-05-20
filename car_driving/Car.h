#pragma once
#include "VerticallyMovingObject.h"

/**Klasa dziedziczaca po klasie VerticallyMovingObject, inicjujaca i wyswietlajaca przeszkode w postaci samochodu.*/
class Car : public VerticallyMovingObject
{
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f position;

	/**Metoda inicjujaca teksture.*/
	void initTexture();
	/**Metoda inicjujaca sprite.*/
	void initSprite();
	/**Metoda ustawiajaca w sposob losowy pozycje poczatkowa obiektu.*/
	void setPosition();
	/**Metoda inicjujaca wartosci zmiennych w klasie.*/
	void initVariables();

public:
	/**Konstruktor klasy Car.*/
	Car();
	/**Destruktor klasy Car.*/
	~Car();

	/**Metoda zwracajaca sprite.*/
	const sf::Sprite& getSprite() const;
	/**Metoda odpowiadajaca za ruch obiektu.*/
	void move() override;
	/**Metoda aktualizujaca pozycje obiektu na scenie.*/
	void update();
	/**Metoda wyswietlajaca obiekt na scenie.*/
	void render(sf::RenderTarget* target);
};

