#include <iostream>
#include "Vector2.hpp"

class Transform
{
public:

	Vector2 position;

	Transform();
	Transform(Vector2 position);

	void Translate(Vector2 vector);

};