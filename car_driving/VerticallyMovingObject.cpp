#include "VerticallyMovingObject.h"

void VerticallyMovingObject::set_points()
{
	this->points = 5;
}

VerticallyMovingObject::VerticallyMovingObject()
{
	set_points();
	set_damage(0);
	set_speed();
	set_factor();
}

VerticallyMovingObject::~VerticallyMovingObject() {}

int VerticallyMovingObject::get_points()
{
	return points;
}


