#include "Obstacle.h"

void Obstacle::initVariables()
{
	set_damage(0);
	set_speed();
	set_factor();
	this->maxObstacles = 3;
}

Obstacle::Obstacle()
{
	initVariables();
}

Obstacle::~Obstacle() {}

void Obstacle::set_damage(int damage)
{
	this->damage = damage;
}

void Obstacle::set_speed()
{
	this->speed = 2.f;
}

void Obstacle::set_factor()
{
	this->factor = 0.5;
}

void Obstacle::accelerate()
{
	speed += speed * factor;
}

float Obstacle::get_speed()
{
	return speed;
}

int Obstacle::get_damage()
{
	return damage;
}

int Obstacle::getMaxObstacles()
{
	return maxObstacles;
}

void Obstacle::addObstacles()
{
	maxObstacles++;
}

void Obstacle::move() {}