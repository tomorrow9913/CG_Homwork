#pragma once
class Point
{
public:
	Point() : x(0), y(0) {}
	Point(float xx, float yy) : x(xx), y(yy) {}
	Point collision_point(Point a, Point b);
	void point_substitution(Point a);
	void change(float xx, float yy);
	void change(Point a);
	float dist(Point a);
	float point_to_segment(Point a, Point b);
	float x, y;
};
