#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <exception>
#include "Random.h"

/**Klasa wirtualna, po ktorej dziedzicza klasy odpowiedzialne za tworzenie poszczegolnych przeszkod w grze.*/
class Obstacle
{
	int damage;
	float factor;
	int maxObstacles;
	float speed;

	/**Metoda inicjujaca wartosci zmiennych w klasie.*/
	void initVariables();

public:
	Random random;
	/**Konstruktor klasy Obstacle.*/
	Obstacle();
	/**Destruktor klasy Obstacle.*/
	~Obstacle();

	/**Metoda umozliwiajaca ustawienie szkod wyrzadzanych przez przeszkode.*/
	void set_damage(int damage);
	/**Metoda umozliwiajaca ustawienie predkosci poruszania sie przeszkody.*/
	void set_speed();
	/**Metoda umozliwiajaca ustawienie mnoznika.*/
	void set_factor();
	/**Metoda przyspieszajaca ruch przeszkody.*/
	void accelerate();
	/**Metoda zwracajaca predkosc przeszkody.*/
	float get_speed();
	/**Metoda zwracajaca szkode wyrzadzana przez przeszkode.*/
	int get_damage();
	/**Metoda zwracajaca maksymalna liczbe przeszkod na scenie.*/
	int getMaxObstacles();
	/**Metoda inkrementujaca liczbe przeszkod na scenie.*/
	void addObstacles();
	/**Metoda wirtualna odpowiadajaca za ruch przeszkody.*/
	virtual void move();
};

