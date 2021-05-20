#include "HorizontallyMovingObject.h"

HorizontallyMovingObject::HorizontallyMovingObject()
{
	set_points();
	set_damage(0);
	set_speed();
	set_factor();
}

HorizontallyMovingObject::~HorizontallyMovingObject() {}

void HorizontallyMovingObject::set_points()
{
	this->points = 10;
}

int HorizontallyMovingObject::get_points()
{
	return points;
}