#pragma once
#include "Obstacle.h"

/**Klasa dziedziczaca po klasie Obstacle. Po klasie tej dziedzicza obiekty poruszajace sie horyzontalnie.*/
class HorizontallyMovingObject : public Obstacle
{
	int points; // liczba punktow, ktore zyska gracz, jesli ominie przeszkode

public:
	/**Konstruktor klasy HorizontallyMovingObject.*/
	HorizontallyMovingObject();
	/**Destruktor klasy HorizontallyMovingObject.*/
	~HorizontallyMovingObject();

	/**Metoda pozwalajaca ustawic liczbe punktow, ktore zyska gracz, jesli ominie przeszkode.*/
	void set_points();
	/**Metoda zwracajaca liczbe punktow, ktore zyska gracz, jesli ominie przeszkode.*/
	int get_points();
};

