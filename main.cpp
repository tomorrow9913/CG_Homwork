#define _USE_MATH_DEFINES

#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h> // (or others, depending on the system in use)
#include <math.h>
#include <vector>
#include <iostream>

#include "Point.h"
#include "GameManager.h"

int _left = 0;
int _bottom = 0;

GameManager* gm;

void init(void) {
	gm = new GameManager(_left, _bottom, WIDTH, HEIGHT);
}

void MyReshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(_left, _left + WIDTH, _bottom, _bottom + HEIGHT); // mouse2()
}

void RenderScene(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0); // Set display-window color to Yellow
	glClear(GL_COLOR_BUFFER_BIT);
	
	// 벽돌 그리기
	gm->DrawBricks();

	// 공 이동
	gm->MoveBalls();

	// 충돌 처리 부분
	gm->Collision_Detection_to_Walls();			// 공과 벽의 충돌 함수
	gm->Collision_Detection_Between_Blocks();

	// 움직이는 공 그리기
	gm->DrawBalls();
	gm->DrawBar();

	glutSwapBuffers();
	glFlush();
}

void MyKey(unsigned char key, int x, int y)
{

	switch (key) {
	case 's': 
		gm->GamePause(); break;
	case 'u': 
		gm->GameSpeed(1.1); break;
	case 'd':
		gm->GameSpeed(0.9); break;
	case 'r':
		gm->Reset();
	default:   break;
	}
	glutPostRedisplay();
}
void SpecialKey(int key, int x, int y) // bar를 방향키로 조절
{
	switch (key)
	{
	case GLUT_KEY_LEFT: gm->MoveBar(-30);      break;
	case GLUT_KEY_RIGHT: gm->MoveBar(30);      break;
	default: break;
	}
	glutPostRedisplay();
}


void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Bouncing Ball & Wall");
	init();
	glutReshapeFunc(MyReshape);
	glutDisplayFunc(RenderScene);
	glutIdleFunc(RenderScene);
	glutKeyboardFunc(MyKey);
	glutSpecialFunc(SpecialKey);
	
	glutMainLoop();
}