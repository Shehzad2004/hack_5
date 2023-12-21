#include <stdlib.h>
#include <math.h>

#include "colorUtils.h"

int max(int a, int b, int c) {
  return (a > b) ? (a > c ? a : c) : (b > c ? b: c);
}

int min(int a, int b, int c) {
  return (a < b) ? (a < c ? a : c) : (b < c ? b : c);
}

int toGrayScale(int *r, int *g, int *b, Mode mode) {
  
if (mode==AVERAGE)
{

  return (*r + *g + *b) / 3;

}

else if( mode==LIGHTNESS ){

return (min(*r,*g,*b) + max(*r,*g,*b)) / 2;

}

else if(mode==LUMINOSITY){