// Core Libraries
#include <iostream>
#include <string>
#include <math.h>
#include <glm/vec3.hpp>
#include <glm/gtx/rotate_vector.hpp>
// 3rd Party Libraries
#include <GLUT\glut.h>
#include "Collision.h"

// Defines and Core variables
#define FRAMES_PER_SECOND 60
const int FRAME_DELAY = 1000 / FRAMES_PER_SECOND; // Miliseconds per frame

int windowWidth = 800;
int windowHeight = 600;
float aspectRatio = 1.3333333; //4x3 aspect ratio = 4 / 3 = 1.333333
int mousepositionX;
int mousepositionY;

float yaw;
float pitch;
glm::vec3 cameraRotation(0);
glm::vec3 cameraPos(0, 500, 500);
glm::vec3 centerToCameraPos = cameraPos - glm::vec3(0);

GLfloat rx = 0.0f;
GLfloat ry = 0.0f;
GLfloat rz = 0.0f;
GLfloat tz = 0.0f;

glm::vec3 cube1pos(0);
glm::vec3 cube2pos(0);
glm::vec3 cube1rot(0);
glm::vec3 cube2rot(0);

Col_OBB cube1obb(glm::vec3(0, 0, 0), glm::vec3(100, 100, 100));
Col_OBB cube2obb(glm::vec3(0, 0, 0), glm::vec3(100, 100, 100));
glm::vec3 cube1StoredExtent = glm::vec3(100, 100, 100);
glm::vec3 cube2StoredExtent = glm::vec3(100, 100, 100);

bool keyDown[256];

// A few conversions to know
float degToRad = 3.14159f / 180.0f;
float radToDeg = 180.0f / 3.14159f;
void glDrawCube()
{
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_QUADS);


	//Front Face
	glColor3f(-1.0f, -1.0f, 1.0f); glVertex3f(-100.0f, -100.0f, 100.0f);
	glColor3f(-1.0f, 1.0f, 1.0f); glVertex3f(-100.0f, 100.0f, 100.0f);
	glColor3f(1.0f, 1.0f, 1.0f); glVertex3f(100.0f, 100.0f, 100.0f);
	glColor3f(1.0f, -1.0f, 1.0f); glVertex3f(100.0f, -100.0f, 100.0f);

	//Back Face
	glColor3f(1.0f, -1.0f, -1.0f); glVertex3f(100.0f, -100.0f, -100.0f);
	glColor3f(1.0f, 1.0f, -1.0f); glVertex3f(100.0f, 100.0f, -100.0f);
	glColor3f(-1.0f, 1.0f, -1.0f); glVertex3f(-100.0f, 100.0f, -100.0f);
	glColor3f(-1.0f, -1.0f, -1.0f); glVertex3f(-100.0f, -100.0f, -100.0f);

	//Top Face
	glColor3f(1.0f, 1.0f, -1.0f); glVertex3f(100.0f, 100.0f, -100.0f);
	glColor3f(1.0f, 1.0f, 1.0f); glVertex3f(100.0f, 100.0f, 100.0f);
	glColor3f(-1.0f, 1.0f, 1.0f); glVertex3f(-100.0f, 100.0f, 100.0f);
	glColor3f(-1.0f, 1.0f, -1.0f); glVertex3f(-100.0f, 100.0f, -100.0f);

	//Bottom Face
	glColor3f(-1.0f, -1.0f, -1.0f); glVertex3f(-100.0f, -100.0f, -100.0f);
	glColor3f(-1.0f, -1.0f, 1.0f); glVertex3f(-100.0f, -100.0f, 100.0f);
	glColor3f(1.0f, -1.0f, 1.0f); glVertex3f(100.0f, -100.0f, 100.0f);
	glColor3f(1.0f, -1.0f, -1.0f); glVertex3f(100.0f, -100.0f, -100.0f);

	//Right Face
	glColor3f(1.0f, -1.0f, 1.0f); glVertex3f(100.0f, -100.0f, 100.0f);
	glColor3f(1.0f, 1.0f, 1.0f); glVertex3f(100.0f, 100.0f, 100.0f);
	glColor3f(1.0f, 1.0f, -1.0f); glVertex3f(100.0f, 100.0f, -100.0f);
	glColor3f(1.0f, -1.0f, -1.0f); glVertex3f(100.0f, -100.0f, -100.0f);

	//Left Face
	glColor3f(-1.0f, -1.0f, -1.0f); glVertex3f(-100.0f, -100.0f, -100.0f);
	glColor3f(-1.0f, 1.0f, -1.0f); glVertex3f(-100.0f, 100.0f, -100.0f);
	glColor3f(-1.0f, 1.0f, 1.0f); glVertex3f(-100.0f, 100.0f, 100.0f);
	glColor3f(-1.0f, -1.0f, 1.0f); glVertex3f(-100.0f, -100.0f, 100.0f);

	glEnd();
}
//void setViewport(int v)
//{
//	if (v == 1)
//	{
//		glViewport(0, 0, windowWidth / 2, windowHeight);
//		glMatrixMode(GL_PROJECTION);
//		glLoadIdentity();
//		gluPerspective(90.0f, 1.0f, 1.0f, 10000.0f);
//	}
//	else if (v == 2)
//	{
//		glViewport(windowWidth / 2, 0, windowWidth, windowHeight);
//		glMatrixMode(GL_PROJECTION);
//		glLoadIdentity();
//		gluPerspective(90.0f, 1.0f, 1.0f, 10000.0f);
//	}
//	glMatrixMode(GL_MODELVIEW);
//}

/* function DisplayCallbackFunction(void)
* Description:
*  - this is the openGL display routine
*  - this draws the sprites appropriately
*/
void DisplayCallbackFunction(void)
{
	static int counter = 0;
	static int degRotation = 0;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();//Reset
	glColor3f(0.0f, 1.0f, 0.0f);
	gluLookAt(cameraPos.x, cameraPos.y, cameraPos.z, 0, 0, 0, 0, 1, 0);

	glTranslatef(-200, 0, 0);
	glTranslatef(cube1pos.x, cube1pos.y, cube1pos.z);
	cube1obb.position.x = cube1pos.x;
	cube1obb.position.y = cube1pos.y;
	cube1obb.position.z = cube1pos.z;
	cube1obb.position += glm::vec3(-200, 0, 0);
	

	glRotatef(cube1rot.y, 0.0f, 1.0f, 0.0f);
	cube1obb.extent = cube1StoredExtent;
	cube1obb.extent = glm::rotate(cube1obb.extent, cube1rot.y, glm::vec3(0, 1, 0));
	glDrawCube();

	glLoadIdentity();
	gluLookAt(cameraPos.x, cameraPos.y, cameraPos.z, 0, 0, 0, 0, 1, 0);

	glTranslatef(200, 0, 0);
	glTranslatef(cube2pos.x, cube2pos.y, cube2pos.z);
	cube2obb.position.x = cube2pos.x;
	cube2obb.position.y = cube2pos.y;
	cube2obb.position.z = cube2pos.z;
	cube2obb.position += glm::vec3(200, 0, 0);
	glRotatef(cube2rot.y, 0.0f, 1.0f, 0.0f);
	cube2obb.extent = cube2StoredExtent;
	cube2obb.extent = glm::rotate(cube2obb.extent, cube2rot.y, glm::vec3(0, 1, 0));
	glDrawCube();

	glutSwapBuffers();
	if (CH::OBBvOBB(cube1obb, cube2obb))
	{
		printf("COLLIDING!!! %d\n", counter);
		counter++;
	}
}

/* function void KeyboardCallbackFunction(unsigned char, int,int)
* Description:
*   - this handles keyboard input when a button is pressed
*/
void KeyboardCallbackFunction(unsigned char key, int x, int y)
{
	keyDown[key] = true;
}

/* function void KeyboardUpCallbackFunction(unsigned char, int,int)
* Description:
*   - this handles keyboard input when a button is lifted
*/
void KeyboardUpCallbackFunction(unsigned char key, int x, int y)
{
	keyDown[key] = false;
}

void idleFunc()
{

}

/* function TimerCallbackFunction(int value)
* Description:
*  - this is called many times per second
*  - this enables you to animate things
*  - no drawing, just changing the state
*  - changes the frame number and calls for a redisplay
*  - FRAME_DELAY is the number of milliseconds to wait before calling the timer again
*/
void TimerCallbackFunction(int value)
{
	/* this call makes it actually show up on screen */
	static int multi = 1;
	glutPostRedisplay();
	/*if (keyDown['16'])
	{
	multi = 5;
	}
	else
	{
	multi = 1;
	}*/
	if (keyDown['a'])
	{
		cube1pos.x -= 5 * multi;
	}
	if (keyDown['d'])
	{
		cube1pos.x += 5;
	}
	if (keyDown['w'])
	{
		cube1pos.z -= 5;
	}
	if (keyDown['s'])
	{
		cube1pos.z += 5;
	}
	if (keyDown['f'])
	{
		cube1pos.y -= 5;
	}
	if (keyDown['r'])
	{
		cube1pos.y += 5;
	}



	if (keyDown['q'])
	{
		cube1rot.y -= 3;
	}
	if (keyDown['e'])
	{
		cube1rot.y += 3;
	}


	if (keyDown['j'])
	{
		cube2pos.x -= 5 * multi;
	}
	if (keyDown['l'])
	{
		cube2pos.x += 5;
	}
	if (keyDown['i'])
	{
		cube2pos.z -= 5;
	}
	if (keyDown['k'])
	{
		cube2pos.z += 5;
	}

	if (keyDown['h'])
	{
		cube2pos.y -= 5;
	}
	if (keyDown['y'])
	{
		cube2pos.y += 5;
	}

	if (keyDown['u'])
	{
		cube2rot.y -= 3;
	}
	if (keyDown['o'])
	{
		cube2rot.y += 3;
	}
	//escape
	if (keyDown[27])
	{
		exit(0);
	}

	/* this call gives it a proper frame delay to hit our target FPS */
	glutTimerFunc(FRAME_DELAY, TimerCallbackFunction, 0);
}

/* function WindowReshapeCallbackFunction()
* Description:
*  - this is called whenever the window is resized
*  - and sets up the projection matrix properly
*/
void WindowReshapeCallbackFunction(int w, int h)
{
	windowWidth = w;
	windowHeight = h;
	float ar = (float)w / (float)h; // aspect ratio
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(90.0f, ar, 0.1f, 10000.0f);

	glViewport(0, 0, w, h);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


}

void MouseClickCallbackFunction(int button, int state, int x, int y)
{
	// Handle mouse clicks
	if (state == GLUT_DOWN)
	{
		std::cout << "Mouse x:" << x << " y:" << y << std::endl;
	}
}


/* function MouseMotionCallbackFunction()
* Description:
*   - this is called when the mouse is clicked and moves
*/
void MouseMotionCallbackFunction(int x, int y)
{
	static glm::vec2 lastMouse;

	/*yaw = lastMouse.x - x;
	pitch = lastMouse.y - y;
	//printf("%f %f\n", yaw, pitch);
	cameraRotation.x = yaw;
	cameraRotation.y = pitch;
	centerToCameraPos = glm::rotate(centerToCameraPos, yaw, glm::vec3(0, 1, 0));
	centerToCameraPos = glm::rotate(centerToCameraPos, pitch, glm::vec3(1, 0, 0));
	cameraPos = centerToCameraPos;
	lastMouse.x = x;
	lastMouse.y = y;*/
}

/* function MousePassiveMotionCallbackFunction()
* Description:
*   - this is called when the mouse is moved in the window
*/
void MousePassiveMotionCallbackFunction(int x, int y)
{
	mousepositionX = x;
	mousepositionY = y;
}

void init()
{
	///// INIT OpenGL /////
	// Set color clear value
	glClearColor(0.2f, 0.2f, 0.2f, 1.f);

	// Enable Z-buffer read and write (for hidden surface removal)
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_TEXTURE_2D); // textures for future use

	//glEnable(GL_CULL_FACE);

	glFrontFace(GL_CW);

	//Example03
	glLineWidth(4.0f);
	glPolygonMode(GL_FRONT, GL_FILL); //GL_FRONT_AND_BACK, GL_FILL
}


/* function main()
* Description:
*  - this is the main function
*  - does initialization and then calls glutMainLoop() to start the event handler
*/

int main(int argc, char **argv)
{
	/* initialize the window and OpenGL properly */
	glutInit(&argc, argv);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow("INFR1350U Cube Assignment, Jackson Rushing");

	/* set up our function callbacks */
	glutDisplayFunc(DisplayCallbackFunction);
	glutKeyboardFunc(KeyboardCallbackFunction);
	glutKeyboardUpFunc(KeyboardUpCallbackFunction);
	glutIdleFunc(idleFunc);
	glutReshapeFunc(WindowReshapeCallbackFunction);
	glutMouseFunc(MouseClickCallbackFunction);
	glutMotionFunc(MouseMotionCallbackFunction);
	glutPassiveMotionFunc(MousePassiveMotionCallbackFunction);
	glutTimerFunc(1, TimerCallbackFunction, 0);

	init(); //Setup OpenGL States

			/* start the event handler */
	glutMainLoop();
	return 0;
}