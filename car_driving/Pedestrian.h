#pragma once
#include "HorizontallyMovingObject.h"

/**Klasa dziedziczaca po klasie HorizontallyMovingObject, inicjujaca i wyswietlajaca przeszkode w postaci pieszego.*/
class Pedestrian : public HorizontallyMovingObject
{
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f position;
	sf::Clock clock;
	sf::IntRect frame;

	/**Metoda inicjujaca teksture.*/
	void initTexture();
	/**Metoda inicjujaca sprite.*/
	void initSprite();
	/**Metoda ustawiajaca w sposob losowy pozycje poczatkowa obiektu.*/
	void setPosition();
	/**Metoda inicjujaca wartosci zmiennych w klasie.*/
	void initVariables();

public:
	/**Konstruktor klasy Pedestrian.*/
	Pedestrian();
	/**Destruktor klasy Pedestrian.*/
	~Pedestrian();

	/**Metoda zwracajaca sprite.*/
	const sf::Sprite& getSprite() const;
	/**Metoda odpowiadajaca za ruch obiektu.*/
	void move() override;
	/**Metoda odpowiadajaca za animowany ruch pieszego.*/
	void pedestrianMovement();
	/**Metoda aktualizujaca pozycje obiektu na scenie oraz jego animowany ruch.*/
	void update();
	/**Metoda wyswietlajaca obiekt na scenie.*/
	void render(sf::RenderTarget* target);
};

