#pragma once
#include <cstdlib>
#include <crtdbg.h>
#include <vector>
#include "Player.h"
#include "Car.h"
#include "Cat.h"
#include "Dog.h"
#include "Bonus.h"
#include "Pedestrian.h"
#include "Puddle.h"
#include "Background.h"

/**Klasa odpowiadajaca za inicjalizacje przeszkod, wykrywanie kolizji przeszkod z graczem oraz usuwanie obiektow ze sceny.*/
class Collision
{
	Random random;
	std::shared_ptr<Obstacle> o;
	int slower, faster, more;
	std::vector <Obstacle*> obstacles;
	/**Metoda inicjujaca obiekt klasy Obstacle.*/
	void initObstacle();

public:
	/**Konstruktor klasy Collision.
	@param o shared pointer do obiektu klasy Obstacle*/
	Collision();
	/**Destruktor klasy Collision.*/
	~Collision();

	/**Metoda tworzaca nowe przeszkody.*/
	void spawnObstacles();
	/**Metoda wykrywajaca kolizje przeszkod z graczem. Jesli nastapi kolizja, graczowi odbierane sa punkty zycia, a przeszkoda usuwana jest ze sceny.*/
	void collision(std::shared_ptr<Player> player);
	/**Metoda usuwajaca obiekty, ktore znalazly sie poza polem gry.*/
	void delete_from_scene(std::shared_ptr<Player> player);
	/**Metoda aktualizuje stan przeszkod, tzn. sprawdza, czy nastapila kolizja, czy obiekt znalazl sie poza polem gry oraz czy nalezy dodac nowe przeszkody.*/
	void update(std::shared_ptr<Player> player, std::shared_ptr<Background> background, sf::RenderTarget* target);
	/**Metoda utrudniajaca gre. Jesli gracz zbierze liczbe punktow podzielna przez 200, samochod gracza zwalnia, a ruch tla staje sie szybszy.
	Jesli gracz zbierze liczbe punktow podzielna przez 100, liczba przeszkod na scenie zostaje zinkrementowana.
	Jesli gracz zbierze liczbe punktow podzielna przez 50, przeszkody przyspieszaja.
	Naraz moze zostac wprowadzone tylko jedno utrudnienie
	(np. gdy gracz zbierze liczbe punktow rown¹ 300, zostaje zinkrementowana liczba przeszkod, ale przeszkody nie przyspieszaja).*/
	void make_harder(std::shared_ptr<Player> player, std::shared_ptr<Background> background);
	/**Metoda wywolujaca funkcje update() dla wszystkich przeszkod na scenie.*/
	void updateObstacles();
	/**Metoda wywolujaca funkcje render() dla wszystkich przeszkod na scenie.*/
	void render(sf::RenderTarget* target);
};

