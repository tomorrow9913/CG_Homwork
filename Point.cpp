#include <cmath>

#include "Point.h"
#include "Vector.h"

Point Point::collision_point(Point a, Point b)
{
    Point tem;
    float m1, k1, m2, k2;
    if (a.y == b.y) // 수평
    {
        tem.x = x; tem.y = a.y;
    }
    else if (a.x == b.x) // 수직
    {
        tem.x = a.x; tem.y = y;
    }
    else
    {
        m1 = (a.y - b.y) / (a.x - b.x); // ab ----> a.y = (a.y - b.y)/(a.x - b.x) * a.x
        k1 = -m1 * a.x + a.y;

        m2 = -1.0 / m1; // 두 직선은 직교하기 때문에 곱했을때 값이 -1
        k2 = y - m2 * x; // y = m1x + k1, y = m2x + k2의 교점

        tem.x = (k2 - k1) / (m1 - m2);
        tem.y = m1 * x + k1;
    }
    return tem;
}
void Point::point_substitution(Point a)
{
    x = a.x;
    y = a.y;
}
void Point::change(float xx, float yy)
{
    x = xx;
    y = yy;
}
void Point::change(Point a)
{
    x = a.x;
    y = a.y;
}
float Point::dist(Point a)
{
    return sqrt(pow(a.x - x, 2) + pow(a.y - y, 2));
}
float Point::point_to_segment(Point a, Point b)
{
    Vector ap(x - a.x, y - a.y);
    Vector ab(b.x - a.x, b.y - a.y);
    float dot_p = ap.x * ab.x + ap.y * ab.y;
    float cross_p = ap.cross_product(ab);
    if (dot_p < 0) return dist(a);
    else if (dot_p / ab.size() > ab.size()) return dist(b);
    else return cross_p / ab.size();
}