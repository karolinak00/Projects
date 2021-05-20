#pragma once
#include "Obstacle.h"

/**Klasa dziedziczaca po klasie Obstacle. Po klasie tej dziedzicza obiekty poruszajace sie w sposób losowy.*/
class RandomlyMovingObject : public Obstacle
{
	int points; // liczba punktow, ktore zyska gracz, jesli ominie przeszkode

public:
	/**Konstruktor klasy RandomlyMovingObject.*/
	RandomlyMovingObject();
	/**Destruktor klasy RandomlyMovingObject.*/
	~RandomlyMovingObject();

	/**Metoda pozwalajaca ustawic liczbe punktow, ktore zyska gracz, jesli ominie przeszkode.*/
	void set_points();
	/**Metoda zwracajaca liczbe punktow, ktore zyska gracz, jesli ominie przeszkode.*/
	int get_points();
};

