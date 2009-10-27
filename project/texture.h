#include <GL/glut.h>
#include "bitmap.h"

BITMAPINFO *BitmapInfo; /* Bitmap information */
GLubyte    *BitmapBits; /* Bitmap data */
GLuint TexObj;

void load_textures(void)
{
  BitmapBits = LoadDIBitmap("./dyingSun.bmp", &BitmapInfo);

  glGenTextures(1, &TexObj);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, TexObj);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // must set to 1 for compact data
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexImage2D(GL_TEXTURE_2D,
    0,                // mipmap level
    GL_RGB,             // internal format
    BitmapInfo->bmiHeader.biWidth,  // width
    BitmapInfo->bmiHeader.biHeight, // height
    0,                // border
    GL_BGR_EXT,           // data format  (NOTE: Bitmap's format is BGR!!!!)
    GL_UNSIGNED_BYTE,       // element per pixel
    BitmapBits);          // data

  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

}
