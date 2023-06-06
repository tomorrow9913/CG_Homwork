#include <GL/glut.h>
#include "Bar.h"
void Bar::draw_bar()
{
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(pos.x, pos.y + bar_height);
    glVertex2f(pos.x + bar_width, pos.y + bar_height);
    glVertex2f(pos.x + bar_width, pos.y);
    glVertex2f(pos.x, pos.y);
    glEnd();
}