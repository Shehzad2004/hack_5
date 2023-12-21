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
  return ( 0.21 * ( *r )) + (0.72 * (* g)) + (0.07 * (*b));

}


}

int toSepia(int *r, int *g, int *b) {
  
   *r =  (0.393 * *r) + (0.769 * *g) + (0.189 * *b);

   *g =  (0.349 * *r ) + (0.686 * *g) + (0.168 * *b);

   *b = (0.272 * *r) + (0.534 * *g) + (0.131 * *b);


}
