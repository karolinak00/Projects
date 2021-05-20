#pragma once
#include <iostream>
#include <random>

/**Klasa odpowiedzialna za generowanie liczb losowych.*/
class Random
{
	std::random_device rd;

public:
	/**Metoda zwracajaca liczbe losowa.*/
	int get_random_number(int begin, int end);
	/**Konstruktor klasy Random.*/
	Random();
	/**Destruktor klasy Random.*/
	~Random();
};