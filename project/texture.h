#include <GL/glut.h>
#include "bitmap.h"

BITMAPINFO *BitmapInfo1; /* Bitmap information */
GLubyte    *BitmapBits1; /* Bitmap data */
GLuint TexObj1;

void load_grass(void)
{
  BitmapBits1 = LoadDIBitmap("./grass.bmp", &BitmapInfo1);

  glGenTextures(1, &TexObj1);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, TexObj1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // must set to 1 for compact data
  if(MAG_OPTION == 0)
  {
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  }
  if(MAG_OPTION == 1)
  {
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  }
  if(MINI_OPTION == 0)
  {
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  }
  if(MINI_OPTION == 1)
  {
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  }
  glTexImage2D(GL_TEXTURE_2D,
    0,                // mipmap level
    GL_RGB,             // internal format
    BitmapInfo1->bmiHeader.biWidth,  // width
    BitmapInfo1->bmiHeader.biHeight, // height
    0,                // border
    GL_BGR_EXT,           // data format  (NOTE: Bitmap's format is BGR!!!!)
    GL_UNSIGNED_BYTE,       // element per pixel
    BitmapBits1);          // data

  if(TEXTURE_OPTION == 1)
  {
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  }
  if(TEXTURE_OPTION == 2)
  {
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
  }
}
