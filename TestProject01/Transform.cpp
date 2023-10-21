#include <iostream>
#include "Transform.hpp"


//	Constructors:


Transform::Transform()
{
	position.x = 0.0f;
	position.y = 0.0f;
}

Transform::Transform(Vector2 position)
{
	this->position = position;
}


//	Methods:


/// <summary>
/// Translates current transform's position by a vector.
/// </summary>
/// <param name="vector">- vector added to current position</param>
void Transform::Translate(Vector2 vector)
{
	position += vector;
}