#include <vector>
#include <mathutil.h>
#include "noise.h"

void generateCylinder(Mesh* i)
{
  unsigned int f;
  for(f = 0; f < 362; f+= 6)
  {
    i->m_v.push_back(Vec3f(sin(f*PI/180), 0, cos(f*PI/180)));
    i->m_t.push_back(Vec3f(((float)f/362), -0.5, 0)); 
    i->m_v.push_back(Vec3f(sin(f*PI/180), 2, cos(f*PI/180)));
    i->m_t.push_back(Vec3f(((float)f/362), 0.5, 0));
  }

  i->m_v.push_back(Vec3f(0,0,0));
  i->m_t.push_back(Vec3f(2, 2, 2));
  i->m_v.push_back(Vec3f(0,2,0));
  i->m_t.push_back(Vec3f(2, 2, 2));
 // TODO Need to fix order of texture coordinates
  for(f = 0; f < (i->m_v.size() - 2) - 2; f += 2)
  {
    i->m_vi.push_back(f+1); i->m_ti.push_back(f+1);
    i->m_vi.push_back(f+2); i->m_ti.push_back(f+2);
    i->m_vi.push_back(f); i->m_ti.push_back(f+2);
    
    // side of i triangle two
    i->m_vi.push_back(f+1); i->m_ti.push_back(f+1);
    i->m_vi.push_back(f+3); i->m_ti.push_back(f+3);
    i->m_vi.push_back(f+2); i->m_ti.push_back(f+2);

    // top of i
    i->m_vi.push_back(f+1); i->m_ti.push_back(f+1);
    i->m_vi.push_back(i->m_v.size()-1); i->m_ti.push_back(i->m_v.size()-1);
    i->m_vi.push_back(f+3); i->m_ti.push_back(f+3);
    
    //bottom of i
    i->m_vi.push_back(f + 2); i->m_ti.push_back(f+2);
    i->m_vi.push_back(i->m_v.size()); i->m_ti.push_back(i->m_v.size());
    i->m_vi.push_back(f); i->m_ti.push_back(f);
  }
  
}

void generateCube(Mesh *i)
{
  i->m_v.push_back(Vec3f(1, 1, 1));
  i->m_v.push_back(Vec3f(1, -1, 1));
  i->m_v.push_back(Vec3f(-1, 1, 1));
  i->m_v.push_back(Vec3f(-1, -1, 1));
  i->m_v.push_back(Vec3f(1, 1, -1));
  i->m_v.push_back(Vec3f(1, -1,-1));
  i->m_v.push_back(Vec3f(-1, 1, -1));
  i->m_v.push_back(Vec3f(-1, -1, -1));
  
  i->m_t.push_back(Vec3f(0,0,0));
  i->m_t.push_back(Vec3f(0,1,0));
  i->m_t.push_back(Vec3f(1,0,0));
  i->m_t.push_back(Vec3f(1,1,0));

  // triangle faces
  i->m_vi.push_back(1); i->m_vi.push_back(0); i->m_vi.push_back(2);
  i->m_vi.push_back(3); i->m_vi.push_back(1); i->m_vi.push_back(2);
  i->m_ti.push_back(1); i->m_ti.push_back(0); i->m_ti.push_back(2);
  i->m_ti.push_back(3); i->m_ti.push_back(1); i->m_ti.push_back(2);

  i->m_vi.push_back(6); i->m_vi.push_back(4); i->m_vi.push_back(5);
  i->m_vi.push_back(6); i->m_vi.push_back(5); i->m_vi.push_back(7);
  i->m_ti.push_back(2); i->m_ti.push_back(0); i->m_ti.push_back(1);
  i->m_ti.push_back(2); i->m_ti.push_back(1); i->m_ti.push_back(3);
  
  i->m_vi.push_back(4); i->m_vi.push_back(0); i->m_vi.push_back(1);
  i->m_vi.push_back(4); i->m_vi.push_back(1); i->m_vi.push_back(5);
  i->m_ti.push_back(2); i->m_ti.push_back(0); i->m_ti.push_back(1);
  i->m_ti.push_back(2); i->m_ti.push_back(1); i->m_ti.push_back(3);
  
  i->m_vi.push_back(0); i->m_vi.push_back(4); i->m_vi.push_back(6);
  i->m_vi.push_back(2); i->m_vi.push_back(0); i->m_vi.push_back(6);
  i->m_ti.push_back(1); i->m_ti.push_back(0); i->m_ti.push_back(2);
  i->m_ti.push_back(3); i->m_ti.push_back(1); i->m_ti.push_back(2);
  
  i->m_vi.push_back(2); i->m_vi.push_back(6); i->m_vi.push_back(7);
  i->m_vi.push_back(2); i->m_vi.push_back(7); i->m_vi.push_back(3);
  i->m_ti.push_back(2); i->m_ti.push_back(0); i->m_ti.push_back(1);
  i->m_ti.push_back(2); i->m_ti.push_back(1); i->m_ti.push_back(3);

  i->m_vi.push_back(7); i->m_vi.push_back(5); i->m_vi.push_back(1);
  i->m_vi.push_back(7); i->m_vi.push_back(1); i->m_vi.push_back(3);
  i->m_ti.push_back(2); i->m_ti.push_back(0); i->m_ti.push_back(1);
  i->m_ti.push_back(2); i->m_ti.push_back(1); i->m_ti.push_back(3);
}

// 0 -> flat
// 1 -> 
// 2 -> marble
void generatePlane(Mesh *i, int type)
{
  int x,y;

  for(x = -250; x < 251; x++)
  {
    for(y = -250; y < 251; y++)
    {
      if(type == 0)
      {
        i->m_v.push_back(Vec3f(x, 0, y));
        i->m_t.push_back(Vec3f(((float)(x+250)/500),((float)(y+250)/500),0));
      }
      if(type == 1)
      {
        i->m_v.push_back(Vec3f(x,SumNoise(x,y),y));
        i->m_t.push_back(Vec3f(((float)(x+250)/500),((float)(y+250)/500),0));
      }
      if(type == 2)
      {
        i->m_v.push_back(Vec3f(x, MarbleNoise(x,y),y));
        i->m_t.push_back(Vec3f(((float)(x+250)/500),((float)(y+250)/500),0));
      }
    }
  }


  for(x = 0; x < 499; x++)
  {
    for(y = 0; y < 499; y++)
    {
      i->m_vi.push_back(y + (x*500)); i->m_ti.push_back(y + (x*500));
      i->m_vi.push_back(y+ (x*500) + 500); i->m_ti.push_back(y+ (x*500) + 500);
      i->m_vi.push_back(y + (x*500) + 501); i->m_ti.push_back(y + (x*500) + 501);

      i->m_vi.push_back(y + (x*500) + 1); i->m_ti.push_back(y + (x*500) + 1);
      i->m_vi.push_back(y + (x*500) + 501); i->m_ti.push_back(y + (x*500) + 501);
      i->m_vi.push_back(y + (x*500) + 2); i->m_ti.push_back(y + (x*500) + 2);
    }
  }
}
