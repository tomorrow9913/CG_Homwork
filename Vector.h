#pragma once
class Vector
{
public:
	Vector(float xx = 0, float yy = 0) : x(xx), y(yy) {}
	void change(float xx, float yy);
	void change(Vector a);
	float dot_product(Vector a);
	float cross_product(Vector a);
	float size();
	float x, y;
};