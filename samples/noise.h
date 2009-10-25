#include <math.h>
#include "PerlinNoise.h"
ImprovedNoise noise;

double  PlainNoise(int x, int y)
{
  double scale = 0.05;
  double n;

  n = noise.noise(x * scale , y * scale, 11.5);

  return n;
}

double SumNoise(int x, int y)
{
  // always use 7 band 
  int bands = 7;
  double scale = 0.05;
  int i = 0;
  double n;
  double amp = 0.5;

  for(i = 0; i < bands; i++)
  {
    n +=  noise.noise(pow(x*scale, (i+1)), pow(y*scale, (i+1)), 11.5);
  }

  return n;
}

double MarbleNoise(int x, int y)
{
  double scale = 0.02;
  double n;

  n = cos(noise.noise(x * scale , y * scale, 11.5));

  return n;
}
