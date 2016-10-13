////// Core Libraries
////#include <iostream>
////#include <string>
////#include <math.h>
////
////// 3rd Party Libraries
////#include <GLUT\glut.h>
////
////// Defines and Core variables
////#define FRAMES_PER_SECOND 60
////const int FRAME_DELAY = 1000 / FRAMES_PER_SECOND; // Miliseconds per frame
////
////int windowWidth = 800;
////int windowHeight = 600;
////float aspectRatio = 1.3333333; //4x3 aspect ratio = 4 / 3 = 1.333333
////int mousepositionX;
////int mousepositionY;
////
////GLfloat rx = 0.0f;
////GLfloat ry = 0.0f;
////GLfloat rz = 0.0f;
////GLfloat tz = 0.0f;
////
////bool keyDown[256];
////
////// A few conversions to know
////float degToRad = 3.14159f / 180.0f;
////float radToDeg = 180.0f / 3.14159f;
////void glDrawCube()
////{
////	glBegin(GL_QUADS);
////
////	//Front Face
////	glColor3f(-1.0f, -1.0f, 1.0f); glVertex3f(-100.0f, -100.0f, 100.0f);
////	glColor3f(-1.0f, 1.0f, 1.0f); glVertex3f(-100.0f, 100.0f, 100.0f);
////	glColor3f(1.0f, 1.0f, 1.0f); glVertex3f(100.0f, 100.0f, 100.0f);
////	glColor3f(1.0f, -1.0f, 1.0f); glVertex3f(100.0f, -100.0f, 100.0f);
////
////	//Back Face
////	glColor3f(1.0f, -1.0f, -1.0f); glVertex3f(100.0f, -100.0f, -100.0f);
////	glColor3f(1.0f, 1.0f, -1.0f); glVertex3f(100.0f, 100.0f, -100.0f);
////	glColor3f(-1.0f, 1.0f, -1.0f); glVertex3f(-100.0f, 100.0f, -100.0f);
////	glColor3f(-1.0f, -1.0f, -1.0f); glVertex3f(-100.0f, -100.0f, -100.0f);
////
////	//Top Face
////	glColor3f(1.0f, 1.0f, -1.0f); glVertex3f(100.0f, 100.0f, -100.0f);
////	glColor3f(1.0f, 1.0f, 1.0f); glVertex3f(100.0f, 100.0f, 100.0f);
////	glColor3f(-1.0f, 1.0f, 1.0f); glVertex3f(-100.0f, 100.0f, 100.0f);
////	glColor3f(-1.0f, 1.0f, -1.0f); glVertex3f(-100.0f, 100.0f, -100.0f);
////
////	//Bottom Face
////	glColor3f(-1.0f, -1.0f, -1.0f); glVertex3f(-100.0f, -100.0f, -100.0f);
////	glColor3f(-1.0f, -1.0f, 1.0f); glVertex3f(-100.0f, -100.0f, 100.0f);
////	glColor3f(1.0f, -1.0f, 1.0f); glVertex3f(100.0f, -100.0f, 100.0f);
////	glColor3f(1.0f, -1.0f, -1.0f); glVertex3f(100.0f, -100.0f, -100.0f);
////
////	//Right Face
////	glColor3f(1.0f, -1.0f, 1.0f); glVertex3f(100.0f, -100.0f, 100.0f);
////	glColor3f(1.0f, 1.0f, 1.0f); glVertex3f(100.0f, 100.0f, 100.0f);
////	glColor3f(1.0f, 1.0f, -1.0f); glVertex3f(100.0f, 100.0f, -100.0f);
////	glColor3f(1.0f, -1.0f, -1.0f); glVertex3f(100.0f, -100.0f, -100.0f);
////
////	//Left Face
////	glColor3f(-1.0f, -1.0f, -1.0f); glVertex3f(-100.0f, -100.0f, -100.0f);
////	glColor3f(-1.0f, 1.0f, -1.0f); glVertex3f(-100.0f, 100.0f, -100.0f);
////	glColor3f(-1.0f, 1.0f, 1.0f); glVertex3f(-100.0f, 100.0f, 100.0f);
////	glColor3f(-1.0f, -1.0f, 1.0f); glVertex3f(-100.0f, -100.0f, 100.0f);
////
////	glEnd();
////}
//////void setViewport(int v)
//////{
//////	if (v == 1)
//////	{
//////		glViewport(0, 0, windowWidth / 2, windowHeight);
//////		glMatrixMode(GL_PROJECTION);
//////		glLoadIdentity();
//////		gluPerspective(90.0f, 1.0f, 1.0f, 10000.0f);
//////	}
//////	else if (v == 2)
//////	{
//////		glViewport(windowWidth / 2, 0, windowWidth, windowHeight);
//////		glMatrixMode(GL_PROJECTION);
//////		glLoadIdentity();
//////		gluPerspective(90.0f, 1.0f, 1.0f, 10000.0f);
//////	}
//////	glMatrixMode(GL_MODELVIEW);
//////}
////
/////* function DisplayCallbackFunction(void)
////* Description:
////*  - this is the openGL display routine
////*  - this draws the sprites appropriately
////*/
////void DisplayCallbackFunction(void)
////{
////	static int degRotation = 0;
////	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
////	glLoadIdentity();//Reset
////	glColor3f(0.0f, 1.0f, 0.0f);
////	gluLookAt(0, 0, 500, 0, 0, 0, 0, 1, 0);
////
////	glTranslatef(-200, 0, 0);
////	glRotatef(degRotation, 0.0f, 1.0f, 0.0f);
////	glDrawCube();
////
////	glLoadIdentity();
////	gluLookAt(0, 0, 500, 0, 0, 0, 0, 1, 0);
////
////	glTranslatef(200, 0, 0);
////	glRotatef(-degRotation, 0.0f, 1.0f, 0.0f);
////	glDrawCube();
////
////	glutSwapBuffers();
////	degRotation++;
////}
////
/////* function void KeyboardCallbackFunction(unsigned char, int,int)
////* Description:
////*   - this handles keyboard input when a button is pressed
////*/
////void KeyboardCallbackFunction(unsigned char key, int x, int y)
////{
////	keyDown[key] = true;
////}
////
/////* function void KeyboardUpCallbackFunction(unsigned char, int,int)
////* Description:
////*   - this handles keyboard input when a button is lifted
////*/
////void KeyboardUpCallbackFunction(unsigned char key, int x, int y)
////{
////	keyDown[key] = false;
////}
////
////void idleFunc()
////{
////
////}
////
/////* function TimerCallbackFunction(int value)
////* Description:
////*  - this is called many times per second
////*  - this enables you to animate things
////*  - no drawing, just changing the state
////*  - changes the frame number and calls for a redisplay
////*  - FRAME_DELAY is the number of milliseconds to wait before calling the timer again
////*/
////void TimerCallbackFunction(int value)
////{
////	/* this call makes it actually show up on screen */
////	static int multi = 1;
////	glutPostRedisplay();
////	/*if (keyDown['16'])
////	{
////	multi = 5;
////	}
////	else
////	{
////	multi = 1;
////	}*/
////	if (keyDown['a'])
////	{
////		ry += 1 * multi;
////	}
////	else if (keyDown['A'])
////	{
////		ry += 5;
////	}
////	if (keyDown['d'])
////	{
////		ry -= 1;
////	}
////	if (keyDown['w'])
////	{
////		rx += 1;
////	}
////	if (keyDown['s'])
////	{
////		rx -= 1;
////	}
////	//escape
////	if (keyDown[27])
////	{
////		exit(0);
////	}
////
////	/* this call gives it a proper frame delay to hit our target FPS */
////	glutTimerFunc(FRAME_DELAY, TimerCallbackFunction, 0);
////}
////
/////* function WindowReshapeCallbackFunction()
////* Description:
////*  - this is called whenever the window is resized
////*  - and sets up the projection matrix properly
////*/
////void WindowReshapeCallbackFunction(int w, int h)
////{
////	windowWidth = w;
////	windowHeight = h;
////	float ar = (float)w / (float)h; // aspect ratio
////	glMatrixMode(GL_PROJECTION);
////	glLoadIdentity();
////
////	gluPerspective(90.0f, ar, 0.1f, 10000.0f);
////
////	glViewport(0, 0, w, h);
////
////	glMatrixMode(GL_MODELVIEW);
////	glLoadIdentity();
////
////
////}
////
////void MouseClickCallbackFunction(int button, int state, int x, int y)
////{
////	// Handle mouse clicks
////	if (state == GLUT_DOWN)
////	{
////		std::cout << "Mouse x:" << x << " y:" << y << std::endl;
////	}
////}
////
////
/////* function MouseMotionCallbackFunction()
////* Description:
////*   - this is called when the mouse is clicked and moves
////*/
////void MouseMotionCallbackFunction(int x, int y)
////{
////	ry = x * 0.5;
////	rx = -y * 0.5;
////}
////
/////* function MousePassiveMotionCallbackFunction()
////* Description:
////*   - this is called when the mouse is moved in the window
////*/
////void MousePassiveMotionCallbackFunction(int x, int y)
////{
////	mousepositionX = x;
////	mousepositionY = y;
////}
////
////void init()
////{
////	///// INIT OpenGL /////
////	// Set color clear value
////	glClearColor(0.2f, 0.2f, 0.2f, 1.f);
////
////	// Enable Z-buffer read and write (for hidden surface removal)
////	glEnable(GL_DEPTH_TEST);
////
////	glEnable(GL_TEXTURE_2D); // textures for future use
////
////	glEnable(GL_CULL_FACE);
////
////	glFrontFace(GL_CW);
////
////	//Example03
////	glLineWidth(4.0f);
////	glPolygonMode(GL_FRONT, GL_FILL); //GL_FRONT_AND_BACK, GL_FILL
////}
////
////
/////* function main()
////* Description:
////*  - this is the main function
////*  - does initialization and then calls glutMainLoop() to start the event handler
////*/
////
////int main(int argc, char **argv)
////{
////	/* initialize the window and OpenGL properly */
////	glutInit(&argc, argv);
////	glutInitWindowSize(windowWidth, windowHeight);
////	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
////	glutCreateWindow("INFR1350U Cube Assignment, Jackson Rushing");
////
////	/* set up our function callbacks */
////	glutDisplayFunc(DisplayCallbackFunction);
////	glutKeyboardFunc(KeyboardCallbackFunction);
////	glutKeyboardUpFunc(KeyboardUpCallbackFunction);
////	glutIdleFunc(idleFunc);
////	glutReshapeFunc(WindowReshapeCallbackFunction);
////	glutMouseFunc(MouseClickCallbackFunction);
////	glutMotionFunc(MouseMotionCallbackFunction);
////	glutPassiveMotionFunc(MousePassiveMotionCallbackFunction);
////	glutTimerFunc(1, TimerCallbackFunction, 0);
////
////	init(); //Setup OpenGL States
////
////			/* start the event handler */
////	glutMainLoop();
////	return 0;
////}
//// Core Libraries
//#include <iostream>
//#include <string>
//#include <math.h>
//#include <fstream>
//using namespace std;
//
//// 3rd Party Libraries
//#include <GLUT\glut.h>
//#include <IL\ilut.h>
//
//ILuint texture_handle;
//GLuint textureID;
//GLuint filter;
//
//// Defines and Core variables
//#define FRAMES_PER_SECOND 60
//const int FRAME_DELAY = 1000 / FRAMES_PER_SECOND; // Miliseconds per frame
//
//int windowWidth = 800;
//int windowHeight = 600;
//
//int mousepositionX;
//int mousepositionY;
//
//// Wed Sep 30
//int keyDown[256];
//
////Example 06
//GLfloat xRot = 0.0f;
//GLfloat yRot = 0.0f;
//GLfloat zstep = 0.0f;
//GLboolean light = true;
//GLboolean model = true;
//GLint polyMode = GL_FILL;
//
//// A few conversions to know
//float degToRad = 3.14159f / 180.0f;
//float radToDeg = 180.0f / 3.14159f;
//
///* function DisplayCallbackFunction(void)
//* Description:
//*  - this is the openGL display routine
//*  - this draws the sprites appropriately
//*/
//void DisplayCallbackFunction(void)
//{
//	/* clear the screen */
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glLoadIdentity(); // clear our the transform matrix
//
//					  /* This is where we draw thigns */
//
//					  //Transformations
//
//	glPolygonMode(GL_FRONT_AND_BACK, polyMode);
//	glTranslatef(0.f, 0.f, -300);
//
//	glTranslatef(0.f, 0.f, zstep);
//
//	glRotatef(xRot, 1.f, 0.f, 0.f);
//	glRotatef(yRot, 0.f, 1.f, 0.f);
//
//	glMatrixMode(GL_TEXTURE);
//	glBindTexture(GL_TEXTURE_2D, textureID);
//	glRotatef(1.0f, 0.0f, 0.0f, 1.0f);
//	glMatrixMode(GL_MODELVIEW);
//	
//
//	// Draws a cube
//	glBegin(GL_QUADS);
//	// Front Face
//	glNormal3f(0.0f, 0.0f, 1.0f);
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-100.0f, -100.0f, 100.0f);
//	glTexCoord2f(2.0f, 0.0f); glVertex3f(100.0f, -100.0f, 100.0f);
//	glTexCoord2f(2.0f, 2.0f); glVertex3f(100.0f, 100.0f, 100.0f);
//	glTexCoord2f(0.0f, 2.0f); glVertex3f(-100.0f, 100.0f, 100.0f);
//	// Back Face
//	glNormal3f(0.0f, 0.0f, -1.0f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(-100.0f, -100.0f, -100.0f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(-100.0f, 100.0f, -100.0f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(100.0f, 100.0f, -100.0f);
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(100.0f, -100.0f, -100.0f);
//	// Top Face
//	glNormal3f(0.0f, 1.0f, 0.0f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(-100.0f, 100.0f, -100.0f);
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-100.0f, 100.0f, 100.0f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(100.0f, 100.0f, 100.0f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(100.0f, 100.0f, -100.0f);
//	// Bottom Face
//	glNormal3f(0.0f, -1.0f, 0.0f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(-100.0f, -100.0f, -100.0f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(100.0f, -100.0f, -100.0f);
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(100.0f, -100.0f, 100.0f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(-100.0f, -100.0f, 100.0f);
//	// Right face
//	glNormal3f(1.0f, 0.0f, 0.0f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(100.0f, -100.0f, -100.0f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(100.0f, 100.0f, -100.0f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(100.0f, 100.0f, 100.0f);
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(100.0f, -100.0f, 100.0f);
//	// Left Face
//	glNormal3f(-1.0f, 0.0f, 0.0f);
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-100.0f, -100.0f, -100.0f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(-100.0f, -100.0f, 100.0f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(-100.0f, 100.0f, 100.0f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(-100.0f, 100.0f, -100.0f);
//	glEnd();
//
//
//
//
//	//	gluSphere(quadratic, 100.0f, 32, 32); //draw a sphere
//
//	/* Swap Buffers to Make it show up on screen */
//	glutSwapBuffers();
//}
//
///* function void KeyboardCallbackFunction(unsigned char, int,int)
//* Description:
//*   - this handles keyboard input when a button is pressed
//*/
//void KeyboardCallbackFunction(unsigned char key, int x, int y)
//{
//	std::cout << "Key Down:" << (int)key << std::endl;
//	keyDown[key] = 1;
//
//
//	switch (key)
//	{
//	case 32: // the space bar
//		break;
//	case 'k':
//		if (polyMode == GL_FILL)
//			polyMode = GL_LINE;
//		else polyMode = GL_FILL;
//		break;
//	case 'l':
//		if (light) {
//			glDisable(GL_LIGHTING);
//			light = false;
//		}
//		else {
//			glEnable(GL_LIGHTING);
//			light = true;
//		}
//		break;
//	case 'm':
//		if (model) {
//			glShadeModel(GL_FLAT);
//			model = 0;
//		}
//		else {
//			glShadeModel(GL_SMOOTH);
//			model = 1;
//		}
//		break;
//	case 'f':
//		if (filter) {
//			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//			filter = 0;
//		}
//		else {
//			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//			filter = 1;
//		}
//		break;
//
//	case 27: // the escape key
//	case 'q': // the 'q' key
//		exit(0);
//		break;
//	}
//}
//
///* function void KeyboardUpCallbackFunction(unsigned char, int,int)
//* Description:
//*   - this handles keyboard input when a button is lifted
//*/
//void KeyboardUpCallbackFunction(unsigned char key, int x, int y)
//{
//	keyDown[key] = 0;
//}
//
//void idleFunc()
//{
//
//}
//
///* function TimerCallbackFunction(int value)
//* Description:
//*  - this is called many times per second
//*  - this enables you to animate things
//*  - no drawing, just changing the state
//*  - changes the frame number and calls for a redisplay
//*  - FRAME_DELAY is the number of milliseconds to wait before calling the timer again
//*/
//void TimerCallbackFunction(int value)
//{
//	/* this call makes it actually show up on screen */
//	glutPostRedisplay();
//
//	if (keyDown['a'])
//		yRot += 5.0;
//	else if (keyDown['d'])
//		yRot -= 5.0;
//	if (keyDown['w'])
//		zstep -= 5.0;
//	else if (keyDown['s'])
//		zstep += 5.0;
//
//
//	/* this call gives it a proper frame delay to hit our target FPS */
//	glutTimerFunc(FRAME_DELAY, TimerCallbackFunction, 0);
//}
//
///* function WindowReshapeCallbackFunction()
//* Description:
//*  - this is called whenever the window is resized
//*  - and sets up the projection matrix properly
//*/
//void WindowReshapeCallbackFunction(int w, int h)
//{
//	// switch to projection because we're changing projection
//	float asp = (float)w / (float)h;
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//
//	// Setup a perspective projection
//	gluPerspective(70.f, asp, 1.f, 1000.f); // (fov, aspect, near z, far z)	
//
//											//gluOrtho2D(0, w, 0, h);
//
//	windowWidth = w;
//	windowHeight = h;
//	glViewport(0, 0, windowWidth, windowHeight);
//
//	//switch back to modelview
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//void MouseClickCallbackFunction(int button, int state, int x, int y)
//{
//	// Handle mouse clicks
//	if (state == GLUT_DOWN)
//	{
//		std::cout << "Mouse x:" << x << " y:" << y << std::endl;
//	}
//}
//
//
///* function MouseMotionCallbackFunction()
//* Description:
//*   - this is called when the mouse is clicked and moves
//*/
//void MouseMotionCallbackFunction(int x, int y)
//{
//}
//
///* function MousePassiveMotionCallbackFunction()
//* Description:
//*   - this is called when the mouse is moved in the window
//*/
//void MousePassiveMotionCallbackFunction(int x, int y)
//{
//	mousepositionX = x;
//	mousepositionY = y;
//}
//
//void init()
//{
//	///// INIT OpenGL /////
//	// Set color clear value
//	glClearColor(0.2f, 0.2f, 0.2f, 1.f);
//
//	// Enable Z-buffer read and write (for hidden surface removal)
//	glEnable(GL_DEPTH_TEST);
//
//
//	////// EXAMPLE 12 /////
//	glEnable(GL_TEXTURE_2D);
//
//	/* Init Image Library */
//	ilInit();
//	iluInit();
//	ilutRenderer(ILUT_OPENGL);
//
//	//	ilGenImages(1, &texture_handle);
//	//	ilBindImage(texture_handle);
//
//	/* Create and load textures to OpenGL */
//	glGenTextures(1, &textureID); /* Texture name generation */
//	glBindTexture(GL_TEXTURE_2D, textureID);
//
//	/* Load a texture */
//	textureID = ilutGLLoadImage("./img//crate.jpg");
//
//	//	ILubyte *data = ilGetData();
//
//	/* Convert image to RGBA with unsigned byte data type */
//	//	ilConvertImage(IL_RGB, IL_UNSIGNED_BYTE);
//
//	std::cout << "Image width         : " << ilGetInteger(IL_IMAGE_WIDTH) << std::endl;
//	std::cout << "Image height        : " << ilGetInteger(IL_IMAGE_HEIGHT) << std::endl;
//	std::cout << "Image bits per pixel: " << ilGetInteger(IL_IMAGE_BITS_PER_PIXEL) << std::endl;
//
//
//	glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_BPP),
//		ilGetInteger(IL_IMAGE_WIDTH), ilGetInteger(IL_IMAGE_HEIGHT),
//		0, ilGetInteger(IL_IMAGE_FORMAT), GL_UNSIGNED_BYTE,
//		ilGetData()); /* Texture specification */
//
//					  //	glGenTextures(1, &texture_handle);
//					  //	glBindTexture(GL_TEXTURE_2D, texture_handle);
//					  //	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, type, data);
//
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//
//	//socrative.com
//
//	// example06 //////
//	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//	GLfloat mat_shininess[] = { 50.0 };
//	GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
//	GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
//
//	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
//	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
//
//	GLfloat light_position[] = { 100.0, 100.0, 100.0, 1.0 };
//	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//
//	glEnable(GL_COLOR_MATERIAL); // final polygon color will be based on glColor and glMaterial
//
//								 ///////////////// 
//	glFrontFace(GL_CCW);
//	glCullFace(GL_BACK);
//	//	glEnable(GL_CULL_FACE);
//}
//
//
///* function main()
//* Description:
//*  - this is the main function
//*  - does initialization and then calls glutMainLoop() to start the event handler
//*/
//
//int main(int argc, char **argv)
//{
//	/* initialize the window and OpenGL properly */
//	glutInit(&argc, argv);
//	glutInitWindowSize(windowWidth, windowHeight);
//	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
//	glutCreateWindow("INFR1350U - Example");
//
//	/* set up our function callbacks */
//	glutDisplayFunc(DisplayCallbackFunction);
//	glutKeyboardFunc(KeyboardCallbackFunction);
//	glutKeyboardUpFunc(KeyboardUpCallbackFunction);
//	glutIdleFunc(idleFunc);
//	glutReshapeFunc(WindowReshapeCallbackFunction);
//	glutMouseFunc(MouseClickCallbackFunction);
//	glutMotionFunc(MouseMotionCallbackFunction);
//	glutPassiveMotionFunc(MousePassiveMotionCallbackFunction);
//	glutTimerFunc(1, TimerCallbackFunction, 0);
//
//	init(); //Setup OpenGL States
//
//			/* start the event handler */
//	glutMainLoop();
//	return 0;
//}
// Core Libraries
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
using namespace std;

// 3rd Party Libraries
#include <GLUT\glut.h>
#include <IL\ilut.h>

GLuint texture_handle[3];
GLuint filter;
int textureID = 1;

// Defines and Core variables
#define FRAMES_PER_SECOND 60
const int FRAME_DELAY = 1000 / FRAMES_PER_SECOND; // Miliseconds per frame

int windowWidth = 800;
int windowHeight = 600;

int mousepositionX;
int mousepositionY;

// Wed Sep 30
int keyDown[256];

//Example 06
GLfloat xRot = 0.0f;
GLfloat yRot = 0.0f;
GLfloat zstep = 0.0f;
GLboolean light = true;
GLboolean model = true;
GLint polyMode = GL_FILL;

// A few conversions to know
float degToRad = 3.14159f / 180.0f;
float radToDeg = 180.0f / 3.14159f;

/* function DisplayCallbackFunction(void)
* Description:
*  - this is the openGL display routine
*  - this draws the sprites appropriately
*/
void DisplayCallbackFunction(void)
{
	/* clear the screen */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity(); // clear our the transform matrix

					  /* This is where we draw thigns */

					  //Transformations

	glPolygonMode(GL_FRONT_AND_BACK, polyMode);
	glTranslatef(0.f, 0.f, -300);

	glTranslatef(0.f, 0.f, zstep);

	glRotatef(xRot, 1.f, 0.f, 0.f);
	glRotatef(yRot, 0.f, 1.f, 0.f);

	glBindTexture(GL_TEXTURE_2D, texture_handle[0]);

	// Draws a cube
	glBegin(GL_QUADS);
	// Front Face
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-100.0f, -100.0f, 100.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(100.0f, -100.0f, 100.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(100.0f, 100.0f, 100.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-100.0f, 100.0f, 100.0f);
	// Back Face
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-100.0f, -100.0f, -100.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-100.0f, 100.0f, -100.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(100.0f, 100.0f, -100.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(100.0f, -100.0f, -100.0f);
	// Top Face
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-100.0f, 100.0f, -100.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-100.0f, 100.0f, 100.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(100.0f, 100.0f, 100.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(100.0f, 100.0f, -100.0f);
	// Bottom Face
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-100.0f, -100.0f, -100.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(100.0f, -100.0f, -100.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(100.0f, -100.0f, 100.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-100.0f, -100.0f, 100.0f);
	// Right face
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(100.0f, -100.0f, -100.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(100.0f, 100.0f, -100.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(100.0f, 100.0f, 100.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(100.0f, -100.0f, 100.0f);
	// Left Face
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-100.0f, -100.0f, -100.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-100.0f, -100.0f, 100.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-100.0f, 100.0f, 100.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-100.0f, 100.0f, -100.0f);
	glEnd();

	//// FLOOR
	glLoadIdentity();

	glBindTexture(GL_TEXTURE_2D, texture_handle[textureID]);

	glMatrixMode(GL_TEXTURE);
	glPushMatrix();
	glLoadIdentity();

	glScalef(4.f, 4.f, 1.f);
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1000.0, -100.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1000.0, -100.0, -2000.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1000.0, -100.0, -2000.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1000.0, -100.0, 0.0);
	glEnd();

	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);


	//	gluSphere(quadratic, 100.0f, 32, 32); //draw a sphere

	/* Swap Buffers to Make it show up on screen */
	glutSwapBuffers();
}

/* function void KeyboardCallbackFunction(unsigned char, int,int)
* Description:
*   - this handles keyboard input when a button is pressed
*/
void KeyboardCallbackFunction(unsigned char key, int x, int y)
{
	std::cout << "Key Down:" << (int)key << std::endl;
	keyDown[key] = 1;


	switch (key)
	{
	case 32: // the space bar
		break;
	case 'k':
		if (polyMode == GL_FILL)
			polyMode = GL_LINE;
		else polyMode = GL_FILL;
		break;
	case 'l':
		if (light) {
			glDisable(GL_LIGHTING);
			light = false;
		}
		else {
			glEnable(GL_LIGHTING);
			light = true;
		}
		break;
	case 'm':
		if (model) {
			glShadeModel(GL_FLAT);
			model = 0;
		}
		else {
			glShadeModel(GL_SMOOTH);
			model = 1;
		}
		break;
		/*	case 'f':
		if (filter) {
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		filter = 0;
		}
		else {
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		filter = 1;
		}
		break;
		*/
	case '1':
		textureID = 1;
		break;

	case '2':
		textureID = 2;
		break;

	case 27: // the escape key
	case 'q': // the 'q' key
		exit(0);
		break;
	}
}

/* function void KeyboardUpCallbackFunction(unsigned char, int,int)
* Description:
*   - this handles keyboard input when a button is lifted
*/
void KeyboardUpCallbackFunction(unsigned char key, int x, int y)
{
	keyDown[key] = 0;
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
	glutPostRedisplay();

	if (keyDown['a'])
		yRot += 5.0;
	else if (keyDown['d'])
		yRot -= 5.0;
	if (keyDown['w'])
		zstep -= 5.0;
	else if (keyDown['s'])
		zstep += 5.0;


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
	// switch to projection because we're changing projection
	float asp = (float)w / (float)h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Setup a perspective projection
	gluPerspective(70.f, asp, 1.f, 5000.f); // (fov, aspect, near z, far z)	

											//gluOrtho2D(0, w, 0, h);

	windowWidth = w;
	windowHeight = h;
	glViewport(0, 0, windowWidth, windowHeight);

	//switch back to modelview
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


	////// EXAMPLE 12 /////
	glEnable(GL_TEXTURE_2D);

	/* Init Image Library */
	ilInit();
	iluInit();
	ilutRenderer(ILUT_OPENGL);

	//	ilGenImages(1, &texture_handle);
	//	ilBindImage(texture_handle);

	/* Create and load textures to OpenGL */
	glGenTextures(3, &texture_handle[0]); /* Texture name generation */
	glBindTexture(GL_TEXTURE_2D, texture_handle[0]);

	/* Load a texture */
	texture_handle[0] = ilutGLLoadImage("./img//crate.jpg");

	//	ILubyte *data = ilGetData();

	/* Convert image to RGBA with unsigned byte data type */
	//	ilConvertImage(IL_RGB, IL_UNSIGNED_BYTE);

	std::cout << "Image width         : " << ilGetInteger(IL_IMAGE_WIDTH) << std::endl;
	std::cout << "Image height        : " << ilGetInteger(IL_IMAGE_HEIGHT) << std::endl;
	std::cout << "Image bits per pixel: " << ilGetInteger(IL_IMAGE_BITS_PER_PIXEL) << std::endl;


	glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_BPP),
		ilGetInteger(IL_IMAGE_WIDTH), ilGetInteger(IL_IMAGE_HEIGHT),
		0, ilGetInteger(IL_IMAGE_FORMAT), GL_UNSIGNED_BYTE,
		ilGetData()); /* Texture specification */

					  //	glGenTextures(1, &texture_handle);
					  //	glBindTexture(GL_TEXTURE_2D, texture_handle);
					  //	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, type, data);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	////// Example 14 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Floor Texture
	// Create and load textures to OpenGL

	/* Load a texture */
	texture_handle[1] = ilutGLLoadImage("./img//checker.jpg");

	glBindTexture(GL_TEXTURE_2D, texture_handle[1]);


	glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_BPP),
		ilGetInteger(IL_IMAGE_WIDTH), ilGetInteger(IL_IMAGE_HEIGHT),
		0, ilGetInteger(IL_IMAGE_FORMAT), GL_UNSIGNED_BYTE,
		ilGetData()); /* Texture specification */

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


	//FLOOR MIPMAPS
	glBindTexture(GL_TEXTURE_2D, texture_handle[2]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, ilGetInteger(IL_IMAGE_WIDTH), ilGetInteger(IL_IMAGE_HEIGHT), ilGetInteger(IL_IMAGE_FORMAT), GL_UNSIGNED_BYTE, ilGetData());

	/////////////////////////////////////////////////////////////// Ex14 //////////////////////////////////////////////////////////////



	// example06 //////
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);

	GLfloat light_position[] = { 100.0, 100.0, 100.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL); // final polygon color will be based on glColor and glMaterial

								 ///////////////// 
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	//	glEnable(GL_CULL_FACE);
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
	glutCreateWindow("INFR1350U - Example");

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