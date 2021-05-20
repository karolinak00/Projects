#pragma once
#include "HorizontallyMovingObject.h"

/**Klasa dziedziczaca po klasie HorizontallyMovingObject, inicjujaca i wyswietlajaca obiekt, po zderzeniu z ktorym gracz otrzymuje dodatkowe punkty zycia.*/
class Bonus : public HorizontallyMovingObject
{
	sf::Texture texture;
	sf::Sprite sprite;
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
	/**Konstruktor klasy Bonus.*/
	Bonus();
	/**Destruktor klasy Bonus.*/
	~Bonus();

	/**Metoda zwracajaca sprite.*/
	const sf::Sprite& getSprite() const;
	/**Metoda odpowiadajaca za ruch obiektu.*/
	void move() override;
	/**Metoda aktualizujaca pozycje obiektu na scenie.*/
	void update();
	/**Metoda wyswietlajaca obiekt na scenie.*/
	void render(sf::RenderTarget* target);
};

