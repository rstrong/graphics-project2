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


Mesh cylinder;
float eyex = 0;
float eyey = 0;
float eyez = 0;

int WIDTH = 640;
int HEIGHT = 480;

const int checkImageHeight = 64;
const int checkImageWidth = 64;
static GLubyte checkImage[checkImageHeight][checkImageWidth][4];
static GLuint texName;

//sample checkerboard bs
void makeCheckImage(void)
{
  int i, j, c;
         
  for (i = 0; i < checkImageHeight; i++) {
    for (j = 0; j < checkImageWidth; j++) {
    c = ((((i&0x8)==0)^((j&0x8))==0))*255;
    checkImage[i][j][0] = (GLubyte) c;
    checkImage[i][j][1] = (GLubyte) c;
    checkImage[i][j][2] = (GLubyte) c;
    checkImage[i][j][3] = (GLubyte) 255;
    }
  }
}



void main_reshape(int width, int height)
{
  WIDTH = width;
  HEIGHT = height;
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f, (float)width / (float)height, 0.1f, 10.0f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();


  gluLookAt(eyex, eyey, eyez, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
}

void texture(void)
{
  glGenTextures(1, &texName);
  glBindTexture(GL_TEXTURE_2D, texName);
 
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST );
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth, checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, checkImage);
  //glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER, );
}

void main_display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glShadeModel(GL_FLAT);
  //glEnable(GL_DEPTH_TEST);
  texture();
  glColor3f(1.0, 0.3, 0.2); 
  //glEnable(GL_TEXTURE_2D);
  
  renderObject(&cylinder);
  glColor3f(1.0, 0.6, 0.8);
  renderPerFaceNormals(&cylinder);
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
  main_reshape(WIDTH, HEIGHT);
}

void idle()
{
  main_display();
}

void init(void)
{
  makeCheckImage();
  generateCube(&cylinder);
  generatePerFaceNormals(&cylinder);
}
main(int argc, char** argv)
{
  std::cout << "Boom Boom!" << std::endl;
  init();
  std::cout << "made it past init" << std::endl;
  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
  glutInitWindowSize(WIDTH, HEIGHT);
  glutInitWindowPosition(50, 50);
  glutInit(&argc, argv);

  int window = glutCreateWindow("Demo");
  glutReshapeFunc(main_reshape);
  glutDisplayFunc(main_display);
  glutKeyboardFunc(main_keyboard);
  glutIdleFunc(idle);



  glutMainLoop();

  return 0;

}
