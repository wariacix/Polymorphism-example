#include <iostream>

struct Vector2
{
public:

	float x, y;

	Vector2();
	Vector2(float x, float y);

	void operator+=(const Vector2 obj);
	void operator-=(const Vector2 obj);
	bool operator==(Vector2 obj);

};