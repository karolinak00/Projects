#include "RandomlyMovingObject.h"

RandomlyMovingObject::RandomlyMovingObject()
{
	set_points();
	set_damage(0);
	set_speed();
	set_factor();
}

RandomlyMovingObject::~RandomlyMovingObject() {}


void RandomlyMovingObject::set_points()
{
	this->points = 20;
}

int RandomlyMovingObject::get_points()
{
	return points;
}