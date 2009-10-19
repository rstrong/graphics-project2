#include <vector>
#include <mathutil.h>

void generateCylinder(Mesh* i)
{
  int f;
  for(f = 0; f < 362; f+= 6)
  {
    i->m_v.push_back(Vec3f(sin(f*PI/180), cos(f*PI/180), 0));
    i->m_t.push_back(Vec3f(((float)f/362), -0.5, 0)); 
    i->m_v.push_back(Vec3f(sin(f*PI/180), cos(f*PI/180), 2));
    i->m_t.push_back(Vec3f(((float)f/362), 0.5, 0));
  }

  i->m_v.push_back(Vec3f(0,0,0));
  i->m_t.push_back(Vec3f(2, 2, 2));
  i->m_v.push_back(Vec3f(0,0,2));
  i->m_t.push_back(Vec3f(2, 2, 2));

  for(f = 0; f < (i->m_v.size() - 2) - 2; f += 2)
  {
    i->m_vi.push_back(f);
    i->m_vi.push_back(f+2);
    i->m_vi.push_back(f+1);
    
    // side of i triangle two
    i->m_vi.push_back(f+2);
    i->m_vi.push_back(f+3);
    i->m_vi.push_back(f+1);

    // top of i
    i->m_vi.push_back(f+1);
    i->m_vi.push_back(f+3);
    i->m_vi.push_back(i->m_v.size());

    //bottom of i
    i->m_vi.push_back(f);
    i->m_vi.push_back(f + 2);
    i->m_vi.push_back(i->m_v.size() -1);

  }
  
}

void generateCube(Mesh *i)
{
  i->m_v.push_back(Vec3f(1, 1, 1));
  i->m_t.push_back(Vec3f(1, 1, 0));

  i->m_v.push_back(Vec3f(1, -1, 1));
  i->m_t.push_back(Vec3f(1, 0, 0));

  i->m_v.push_back(Vec3f(-1, 1, 1));
  i->m_t.push_back(Vec3f(0, 1, 0));
  
  i->m_v.push_back(Vec3f(-1, -1, 1));
  i->m_t.push_back(Vec3f(0, 0, 0));

  i->m_v.push_back(Vec3f(1, 1, -1));
  i->m_t.push_back(Vec3f(1, 1, 0));

  i->m_v.push_back(Vec3f(1, -1,-1));
  i->m_t.push_back(Vec3f(1, 0, 0));

  i->m_v.push_back(Vec3f(-1, 1, -1));
  i->m_t.push_back(Vec3f(0, 1, 0));

  i->m_v.push_back(Vec3f(-1, -1, -1));
  i->m_v.push_back(Vec3f(0, 0, 0));

  // triangle faces
  i->m_vi.push_back(1); i->m_vi.push_back(0); i->m_vi.push_back(2);
  i->m_vi.push_back(3); i->m_vi.push_back(1); i->m_vi.push_back(2);

  i->m_vi.push_back(5); i->m_vi.push_back(4); i->m_vi.push_back(6);
  i->m_vi.push_back(7); i->m_vi.push_back(5); i->m_vi.push_back(6);

  i->m_vi.push_back(1); i->m_vi.push_back(0); i->m_vi.push_back(4);
  i->m_vi.push_back(5); i->m_vi.push_back(1); i->m_vi.push_back(4);

  i->m_vi.push_back(0); i->m_vi.push_back(4); i->m_vi.push_back(6);
  i->m_vi.push_back(2); i->m_vi.push_back(0); i->m_vi.push_back(6);

  i->m_vi.push_back(7); i->m_vi.push_back(6); i->m_vi.push_back(2);
  i->m_vi.push_back(3); i->m_vi.push_back(7); i->m_vi.push_back(2);

  i->m_vi.push_back(1); i->m_vi.push_back(5); i->m_vi.push_back(7);
  i->m_vi.push_back(3); i->m_vi.push_back(1); i->m_vi.push_back(7);

}