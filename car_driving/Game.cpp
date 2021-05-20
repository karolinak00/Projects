#include "Game.h"

void Game::initVariables()
{
	endGame = false;
	played = false;
}

void Game::initBackground()
{
	background = std::make_shared<Background>();
}

void Game::initCollision()
{
	c = std::make_shared<Collision>();
}

Game::Game(std::shared_ptr<Player> player)
{
	this->player = player;
	initVariables();
	initBackground();
	initCollision();
}

Game::~Game() {}

const bool Game::end() const
{
	return endGame;
}

void Game::set_was_played(bool was_p)
{
	played = was_p;
}

const bool Game::was_played() const
{
	return played;
}

void Game::update(sf::RenderTarget* target)
{
	if (player->getHp()->getHp() == 0)
		endGame = true;

	player->update(target, event);
	background->update();
	c->update(player, background, target);
}

void Game::render(sf::RenderTarget* target)
{
	background->render(target);
	c->render(target);
	player->render(target);
}
