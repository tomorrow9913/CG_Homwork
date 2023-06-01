#define _USE_MATH_DEFINES

#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h> // (or others, depending on the system in use)
#include <math.h>
#include <vector>

#include "GameManager.h"

using namespace std;

#define	WIDTH 			400
#define	HEIGHT			600

int		left = 0;
int		bottom = 0;
int		collision_count = 0;

GameManager* gm;

void init(void) {
	gm = new GameManager();

}
void MyReshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left, left + WIDTH, bottom, bottom + HEIGHT); // mouse2()
}

void RenderScene(void) {
	glClearColor(1.0, 1.0, 0.0, 0.0); // Set display-window color to Yellow
	glClear(GL_COLOR_BUFFER_BIT);

	// 충돌 처리 부분
	gm->Collision_Detection_to_Walls();			// 공과 벽의 충돌 함수
	gm->Collision_Detection_Between_Blocks();


	// 움직이는 공의 위치 변화
	gm->MoveBalls();
	
	// 움직이는 공 그리기
	glColor3f(0.0, 0.0, 1.0);
	gm->DrawBlocks();

	glutSwapBuffers();
	glFlush();
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
	glutMainLoop();
}