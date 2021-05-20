#include "Menu.h"

void Menu::initVariables()
{
	this->menu = true;
	this->play = false;
	this->instruction = false;
	this->credits = false;
	this->stats = false;
}

void Menu::initTextures()
{
	try
	{
		if (!background_texture.loadFromFile("Textures/menu.png"))
			throw 1;
	}
	catch (std::runtime_error& error)
	{
		std::cout << error.what() << std::endl;
	}
	catch (int)
	{
		exit(0);
	}
}

void Menu::initSprites()
{
	background.setTexture(background_texture);
}

void Menu::initGame()
{
	game = std::make_shared<Game>(player);
}

void Menu::initStats()
{
	l.load(l.pHead);
}

void Menu::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(1100, 950), "Watch out!", sf::Style::Close | sf::Style::Titlebar);
	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(false);
}

void Menu::initIntroduce()
{
	introduce = std::make_shared<Introduce>(player);
}

void Menu::initButtons()
{
	exit_button = std::make_shared<Button>("Textures/exitButton.png", sf::Vector2f(300, 775));
	new_game_button = std::make_shared<Button>("Textures/playButton.png", sf::Vector2f(300, 75));
	stats_button = std::make_shared<Button>("Textures/statisticsButton.png", sf::Vector2f(300, 600));
	credits_button = std::make_shared<Button>("Textures/creditsButton.png", sf::Vector2f(300, 430));
	instruction_button = std::make_shared<Button>("Textures/instructionButton.png", sf::Vector2f(300, 250));
	menu_button = std::make_shared<Button>("Textures/menuButton.png", sf::Vector2f(375, 815));
	confirm_button = std::make_shared<Button>("Textures/confirm.png", sf::Vector2f(300, 325));
	clear_button = std::make_shared<Button>("Textures/clear_name.png", sf::Vector2f(300, 445));
	backspace_button = std::make_shared<Button>("Textures/backspace.png", sf::Vector2f(300, 555));
}

void Menu::initGameOver()
{
	gameOver = std::make_shared<GameOver>(player);
}

void Menu::initPlayer()
{
	player = std::make_shared<Player>(window);
}

void Menu::initMusic()
{
	music = std::make_shared<Music>("Music/game_music.ogg");
}

void Menu::playMusic()
{
	music->playMusic();
}

void Menu::render_menu()
{
	new_game_button->change_activity(true);
	instruction_button->change_activity(true);
	credits_button->change_activity(true);
	stats_button->change_activity(true);
	exit_button->change_activity(true);
	menu_button->change_activity(false);
	confirm_button->change_activity(false);
	clear_button->change_activity(false);
	backspace_button->change_activity(false);

	window->draw(background);
	window->draw(new_game_button->getSprite());
	window->draw(instruction_button->getSprite());
	window->draw(credits_button->getSprite());
	window->draw(stats_button->getSprite());
	window->draw(exit_button->getSprite());
}

void Menu::render_stats()
{
	new_game_button->change_activity(false);
	instruction_button->change_activity(false);
	credits_button->change_activity(false);
	stats_button->change_activity(false);
	exit_button->change_activity(false);
	menu_button->change_activity(true);
	confirm_button->change_activity(false);
	clear_button->change_activity(false);
	backspace_button->change_activity(false);

	statistics.render(window);
	window->draw(menu_button->getSprite());
	l.print(window);
}

void Menu::render_credits()
{
	new_game_button->change_activity(false);
	instruction_button->change_activity(false);
	credits_button->change_activity(false);
	stats_button->change_activity(false);
	exit_button->change_activity(false);
	menu_button->change_activity(true);
	confirm_button->change_activity(false);
	clear_button->change_activity(false);
	backspace_button->change_activity(false);

	_credits.render(window);
	window->draw(menu_button->getSprite());
}

void Menu::render_instruction()
{
	new_game_button->change_activity(false);
	instruction_button->change_activity(false);
	credits_button->change_activity(false);
	stats_button->change_activity(false);
	exit_button->change_activity(false);
	menu_button->change_activity(true);
	confirm_button->change_activity(false);
	clear_button->change_activity(false);
	backspace_button->change_activity(false);

	_instruction.render(window);
	window->draw(menu_button->getSprite());
}

void Menu::render_game()
{
	game->update(window);
	game->render(window);
}

void Menu::introduce_player()
{
	confirm_button->change_activity(true);
	clear_button->change_activity(true);
	backspace_button->change_activity(true);
	introduce->update(event, window);
	introduce->render(window);
	window->draw(confirm_button->getSprite());
	window->draw(clear_button->getSprite());
	window->draw(backspace_button->getSprite());
}

void Menu::game_over()
{
	gameOver->render(window);
	window->draw(menu_button->getSprite());
	l.try_to_add(l.pHead, player->getName(), player->getPoints()->getPoints());
}

void Menu::make_the_game()
{
	new_game_button->change_activity(false);
	instruction_button->change_activity(false);
	credits_button->change_activity(false);
	stats_button->change_activity(false);
	exit_button->change_activity(false);
	menu_button->change_activity(false);
	confirm_button->change_activity(false);
	clear_button->change_activity(false);
	backspace_button->change_activity(false);

	if (!introduce->is_correct())
		introduce_player();
	else if (!game->end())
		render_game();
	else
	{
		menu_button->change_activity(true);
		game_over();
	}
}

Menu::Menu()
{
	initMusic();
	playMusic();
	initVariables();
	initTextures();
	initSprites();
	initWindow();
	initStats();
	initButtons();
	initPlayer();
	initIntroduce();
	initGame();
	initGameOver();
}

Menu::~Menu()
{
	l.save(l.pHead);
	l.delete_stats(l.pHead);
	delete window;
}

void Menu::pollEvents()
{
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				window->close();
			break;
		case sf::Event::MouseButtonReleased:
			if (event.MouseLeft)
			{
				sf::Vector2f pos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window));
				if (menu_button->getSprite().getGlobalBounds().contains(pos) && menu_button->is_active())
				{
					menu_button->playSound();
					menu = true;
					play = false;
					instruction = false;
					credits = false;
					stats = false;
					game->set_was_played(true);
				}

				else if (new_game_button->getSprite().getGlobalBounds().contains(pos) && new_game_button->is_active())
				{
					new_game_button->playSound();
					menu = false;
					play = true;
					instruction = false;
					credits = false;
					stats = false;
				}

				else if (instruction_button->getSprite().getGlobalBounds().contains(pos) && instruction_button->is_active())
				{
					instruction_button->playSound();
					menu = false;
					play = false;
					instruction = true;
					credits = false;
					stats = false;
				}

				else if (credits_button->getSprite().getGlobalBounds().contains(pos) && credits_button->is_active())
				{
					credits_button->playSound();
					menu = false;
					play = false;
					instruction = false;
					credits = true;
					stats = false;
				}

				else if (stats_button->getSprite().getGlobalBounds().contains(pos) && stats_button->is_active())
				{
					stats_button->playSound();
					menu = false;
					play = false;
					instruction = false;
					credits = false;
					stats = true;
				}

				else if (exit_button->getSprite().getGlobalBounds().contains(pos) && exit_button->is_active())
				{
					exit_button->playSound();
					menu = false;
					play = false;
					instruction = false;
					credits = false;
					stats = false;
					window->close();
					break;
				}
				else if (confirm_button->getSprite().getGlobalBounds().contains(pos) && confirm_button->is_active())
				{
					confirm_button->playSound();
					introduce->set_confirm(true);
					break;
				}
				else if (clear_button->getSprite().getGlobalBounds().contains(pos) && clear_button->is_active())
				{
					clear_button->playSound();
					introduce->set_clear(true);
					break;
				}
				else if (backspace_button->getSprite().getGlobalBounds().contains(pos) && backspace_button->is_active())
				{
					backspace_button->playSound();
					introduce->set_backspace(true);
					break;
				}
			}
			break;
		}


	}
}

void Menu::render()
{
	window->clear();
	if (menu)
		render_menu();
	else if (play)
	{
		if(!game->was_played())
			make_the_game();
		else
		{
			player.reset(new Player(window));
			introduce.reset(new Introduce(player));
			game.reset(new Game(player));
			gameOver.reset(new GameOver(player));
			make_the_game();
		}
	}

	else if (instruction)
		render_instruction();
	else if (credits)
		render_credits();
	else if (stats)
		render_stats();
	else if (exit)
		window->close();
	window->display();
}

void Menu::update()
{
	pollEvents();
}

bool Menu::is_running()
{
	return window->isOpen();
}
