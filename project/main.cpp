#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <iostream>
#include <GL/glut.h>

// The beginnings of ours...
#include <mathutil.h>
#include <mesh.h>
#include <primitive.h>
#include <texture.h>

float eyex = 0;
float eyey = 0;
float eyez = 0;

int WIDTH = 1024;
int HEIGHT = 768;
// need to go into another .h
void redisplay_all(void);
int top_width, top_height, bottom_width, bottom_height;
int window, top, bottom;
#define GAP 15
//lighting
GLfloat AmbientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
GLfloat DiffuseLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat SpecularLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat SpecRef[] = {0.7f, 0.7f, 0.7f, 1.0f};
GLfloat LightPos[] = {-50.0f, 50.0f, 100.0f, 1.0f};
GLubyte Shine = 128;

//controls
int mouse_button;
int mouse_x     = 0;
int mouse_y     = 0;

float scale   = 1.0;
float x_angle   = 0.0;
float y_angle   = 0.0;


Mesh test;


void motion(int x, int y)
{
  if(mouse_button == GLUT_LEFT_BUTTON)
  {
    // compute the angle (0..360) around x axis, and y-axis
    y_angle += (float(x - mouse_x)/WIDTH)*360.0;
    x_angle += (float(y - mouse_y)/HEIGHT)*360.0;

  }

  if(mouse_button == GLUT_RIGHT_BUTTON)
  {
    scale += (y - mouse_y) / 1000.0;

    if(scale < 0.001)   scale = 0.001;
    if(scale > 6.0)   scale = 6.0;
  }

  mouse_x = x;    // update current mouse position
  mouse_y = y;
  redisplay_all();
}

void mouse(int button, int state, int x, int y)
{
  // button -- GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON, or GLUT_RIGHT_BUTTON.
  // state  -- GLUT_UP, GLUT_DOWN
  mouse_x = x;
  mouse_y = y;

  mouse_button = button;
  motion(x,y);
}


void main_reshape(int width, int height)
{
  WIDTH = width;
  HEIGHT = height;
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f, (float)width / (float)height, 0.1f, 20.0f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glutSetWindow(top);
  glutPositionWindow(GAP, GAP);
  top_width = width - (2 * GAP);
  top_height = (height * 0.8) - (2 * GAP);
  glutReshapeWindow(top_width, top_height);

  glutSetWindow(bottom);
  bottom_width = width - (2 * GAP);
  bottom_height = (height * 0.2) - GAP;
  glutPositionWindow(GAP,(height * 0.8));
  glutReshapeWindow(bottom_width, bottom_height);
}

void main_display()
{
  glClearColor(0.8f, 0.8f, 0.8f, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glutSwapBuffers();
}

void main_keyboard(unsigned char key, int x, int y)
{
  switch(key)
  {
    case 'u' : 
      eyex += 0.1;
      break;
    case 'i' :
      eyex -= 0.1;
      break;
    case 'j' :
      eyey += 0.1;
      break;
    case 'k' : 
      eyey -= 0.1;
      break;
    case 'n' :
      eyez += 0.1;
      break;
    case 'm' : 
      eyez -= 0.1;
      break;
    default:
      break;
  }
  std::cout << "EYEZ: " << eyex << " " << eyey << " " << eyez << std::endl;
  redisplay_all();
}

void top_reshape(int width, int height)
{
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f, (float)width / (float)height, 0.1f, 10.0f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);
}

void top_display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

 // load_textures(); 
  glShadeModel(GL_SMOOTH);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientLight);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffuseLight);
  glLightfv(GL_LIGHT0, GL_SPECULAR, SpecularLight);
  glEnable(GL_LIGHT0);
  glEnable(GL_COLOR_MATERIAL);
  glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
  glMaterialfv(GL_FRONT, GL_SPECULAR, SpecRef);
  glMateriali(GL_FRONT, GL_SHININESS, Shine);
  glEnable(GL_NORMALIZE);

  gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);
  glColor3f(0.4, 0.2, 0.2); 
  glScalef(scale, scale, scale);
  glRotatef(x_angle, 1.0f, 0.0f, 0.0f);
  glRotatef(y_angle, 0.0f, 1.0f, 0.0f);

    
  //glBindTexture(GL_TEXTURE_2D, TexObj);
  renderObject(&test);
  glutSwapBuffers();
}

void bottom_reshape(int width, int height)
{
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, width, height, 0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClearColor(0.0, 0.0, 0.0, 0.0);
}

void bottom_display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glColor3f(1.0, 0.0, 0.0);

  //bottom shit
  glutSwapBuffers();
}

void redisplay_all(void)
{
  glutSetWindow(top);
  glutPostRedisplay();
  glutSetWindow(bottom);
  glutPostRedisplay();
}

void idle()
{
  main_display();
}

void init(void)
{
  //generatePlane(&test,2);
  generatePlane(&test,2);
  generatePerFaceNormals(&test);
  generatePerVertexNormals(false, &test, 0);
}

int main(int argc, char** argv)
{
  std::cout << "Boom Boom!" << std::endl;
  init();
  std::cout << "made it past init" << std::endl;
  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
  glutInitWindowSize(WIDTH, HEIGHT);
  glutInitWindowPosition(50, 50);
  glutInit(&argc, argv);

  
  window = glutCreateWindow("Project 2");
  glutReshapeFunc(main_reshape);
  glutDisplayFunc(main_display);
  glutKeyboardFunc(main_keyboard);
  glutMouseFunc(mouse);
  glutMotionFunc(motion);
  glutIdleFunc(idle);

  top = glutCreateSubWindow(window, 1, 1, 10, 10);
  glutReshapeFunc(top_reshape);
  glutDisplayFunc(top_display);
  glutKeyboardFunc(main_keyboard);
  glutMouseFunc(mouse);
  glutMotionFunc(motion);
  glutIdleFunc(idle);

  bottom = glutCreateSubWindow(window, 1000, 1000, 50, 50);
  glutReshapeFunc(bottom_reshape);
  glutDisplayFunc(bottom_display);
  glutKeyboardFunc(main_keyboard);
  glutMouseFunc(mouse);
  glutMotionFunc(motion);
  glutIdleFunc(idle);

  
  glutMainLoop();

  return 0;

}
