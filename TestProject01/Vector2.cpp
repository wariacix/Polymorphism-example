#include <iostream>
#include "Vector2.hpp"


//	Constructors:


Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}


//	Operators:


void Vector2::operator+=(const Vector2 obj)
{
	x += obj.x;
	y += obj.y;
}

void Vector2::operator-=(const Vector2 obj)
{
	x -= obj.x;
	y -= obj.y;
}

bool Vector2::operator==(Vector2 obj)
{
	bool isEqual = false;
	return (x == obj.x && y == obj.y)? true : false;
}