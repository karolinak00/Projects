#pragma once
#include "Stats.h"
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

/**Klasa odpowiadajaca za wykonywanie operacji na klasie Stats pelniacej role listy jednokierunkowej.*/
class list
{
	sf::Text text;
	sf::Font font;

	/**Metoda inicjujaca czcionke.*/
	void initFont();
	/**Metoda inicjujaca tekst.*/
	void initText();

public:
	Stats* pHead; // wskaznik na glowe listy
	/**Konstruktor bezargumentowy klasy list.*/
	list();
	/**Destruktor klasy list.*/
	~list();
	/**Konstruktor jednoargumentowy klasy list.*/
	list(Stats* p);
	/**Konstruktor kopiujacy klasy list.*/
	list(const list&);
	/**Konstruktor przenoszacy klasy list.*/
	list(list&&) noexcept;
	/**Operator przypisania klasy list.*/
	list& operator=(const list& s);
	/**Operator przeniesienia klasy list.*/
	list& operator=(list&& s) noexcept;

	/**Metoda odpowiadajaca za zaladowanie statystyk z pliku do struktury.*/
	void load(Stats*& pHead);
	/**Metoda probujaca dodac rekord do statystyk. Jezeli gracz nie uzyskal zadnych punktow lub byl juz wczesniej wpisany w statystykach i uzyskal liczbe punktow mniejsza
	od tej w statystykach zapisanych, gracz nie zostaje dodany do statystyk. W przeciwnym przypadku, jesli uzytkownik gral juz wczesniej i jego nazwa figuruje w liscie 
	ze statystykami, usuwany jest zapis z mniejszym wynikiem koncowym, a nastepnie wywolywana jest funkcja add(). Jesli gracz ma  byc wpisany do statystyk po raz
	pierwszy, od razu wywolywana jest funkcja add().*/
	void try_to_add(Stats*& pHead, const std::string& name, const int& score);
	/**Metoda dodaje gracza do statystyk.*/
	void add(Stats*& pHead, const std::string& name, const int& score);
	/**Metoda wyszukuje gracza w statystykach i jesli go znajdzie, zwraca wskaznik na odpowiedni element listy. Jesli nie znajdzie, zwraca 0.*/
	Stats* find(Stats* pHead, const std::string& name);
	/**Metoda usuwa liste ze statystykami.*/
	void delete_stats(Stats*& pHead);
	/**Metoda pobiera z listy maksymalnie 20 elementow, zapisuje je do zmiennej typu string.*/
	void prepare_to_print(Stats*& pHead, std::string& s, int counter);
	/**Metoda wyswietla na ekranie zawartosc lancucha znakowego powstalego w metodzie prepare_to_print().*/
	void print(sf::RenderTarget* target);
	/**Metoda odpowiada za przeprowadzenie operacji zapisu statystyk do pliku.*/
	void save(Stats*&pHead);
	/**Metoda odpowiada za otworzenie i wyczyszczenie pliku ze statystykami, wywolanie funkcji actual_save() i zamkniecie pliku.*/
	void open_close_file(Stats*& pHead);
	/**Metoda usuwa rekord ze statystyk.*/
	void delete_record(Stats*& pHead, Stats*& s);
	/**Metoda zapisuje co najwyzej 20 rekordow z listy ze statystykami.*/
	void actual_save(Stats*& pHead, std::fstream& file, int counter);
};