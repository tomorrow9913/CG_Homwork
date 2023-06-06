#pragma once
#define _USE_MATH_DEFINES

#include <math.h>
#include <GL/glut.h>

#define	PI				M_PI
#define	polygon_num		50

#define	WIDTH 			800
#define	HEIGHT			600

template<typename T>
void Safe_Delete(T& obj)
{
    if (obj)
    {
        delete obj;
        obj = nullptr;
    }
}