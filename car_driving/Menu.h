#pragma once
#include "Game.h"
#include "Button.h"
#include "list.h"
#include "Introduce.h"
#include "GameOver.h"
#include "Player.h"
#include "Instruction.h"
#include "Credits.h"
#include "Music.h"
#include <SFML/Audio.hpp>

class Menu
{
	bool menu;
	bool play;
	bool instruction;
	bool credits;
	bool stats;
	
	sf::RenderWindow* window;
	sf::Event event;
	sf::Texture background_texture;
	sf::Sprite background;

	std::shared_ptr<Game> game;
	std::shared_ptr<Button>exit_button;
	std::shared_ptr<Button>new_game_button;
	std::shared_ptr<Button>stats_button;
	std::shared_ptr<Button>credits_button;
	std::shared_ptr<Button>instruction_button;
	std::shared_ptr<Button>menu_button;
	std::shared_ptr<Button>confirm_button;
	std::shared_ptr<Button>clear_button;
	std::shared_ptr<Button>backspace_button;
	std::shared_ptr<Introduce>introduce;
	std::shared_ptr<GameOver>gameOver;
	std::shared_ptr<Player>player;
	std::shared_ptr<Music> music;

	Instruction _instruction;
	Credits _credits;
	list l;
	Stats statistics;

	/**Metoda inicjujaca wartosci zmiennych w klasie.*/
	void initVariables();
	/**Metoda inicjujaca tekstury.*/
	void initTextures();
	/**Metoda inicjujaca sprite'y.*/
	void initSprites();
	/**Metoda inicjujaca obiekt klasy Game.*/
	void initGame();
	/**Metoda inicjujaca obiekt klasy Stats.*/
	void initStats();
	/**Metoda inicjujaca okno gry.*/
	void initWindow();
	/**Metoda inicjujaca obiekt klasy Introduce.*/
	void initIntroduce();
	/**Metoda inicjujaca obiekty klasy Buttons.*/
	void initButtons();
	/**Metoda inicjujaca obiekt klasy GameOver.*/
	void initGameOver();
	/**Metoda inicjujaca obiekt klasy Player.*/
	void initPlayer();
	/**Metoda inicjujaca obiekt klasy Music.*/
	void initMusic();
	/**Metoda odpowiadajaca za odtwarzanie muzyki.*/
	void playMusic();

public:
	/**Konstruktor klasy Menu.*/
	Menu();
	/**Destruktor klasy Menu.*/
	~Menu();
	/**Metoda uruchamiajaca odpowiednie funkcje w zaleznoœci od tego, na co kliknie lub jaki klawisz nacisnie gracz.*/
	void pollEvents();
	/**Metoda odpowiedzialna za wyswietlenie menu.*/
	void render_menu();
	/**Metoda odpowiedzialna za wyswietlenie statystyk.*/
	void render_stats();
	/**Metoda odpowiedzialna za wyswietlenie przypisow.*/
	void render_credits();
	/**Metoda odpowiedzialna za wyswietlenie instrukcji.*/
	void render_instruction();
	/**Metoda odpowiedzialna za dzialanie gry.*/
	void render_game();
	/**Metoda odpowiedzialna za wyswietlenie okna przedstawienia sie gracza.*/
	void introduce_player();
	/**Metoda odpowiedzialna za wyswietlenie okna konca gry.*/
	void game_over();
	/**Metoda odpowiedzialna za wyswietlenie gry.*/
	void make_the_game();
	/**Metoda wyswietlajaca odpowiednie obiekty na ekranie.*/
	void render();
	/**Metoda wywolujaca funkcje pollEvents() oraz funkcje update() dla aktualnie wyswietlanych obiektow.*/
	void update();
	/**Metoda zwracajaca wartosc true, jesli program dziala.*/
	bool is_running();
};

