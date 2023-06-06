
#include <cmath>
#include "Vector.h"

void Vector::change(float xx, float yy)
{
	x = xx;
	y = yy;
}
void Vector::change(Vector a)
{
	x = a.x;
	y = a.y;
}
float Vector::dot_product(Vector a)
{
	return ((a.x * x) + (a.y * y));
}
float Vector::cross_product(Vector a)
{
	return abs(a.x * y - a.y * x);
}
float Vector::size()
{
	return sqrt(pow(x, 2) + pow(y, 2));
}