#include "bmplib.h"

int main() {
   unsigned char src[SIZE][SIZE][RGB];
   unsigned char dest[SIZE][SIZE];
   readRGBBMP("fruit.bmp", src);
   for (int i=0; i<SIZE; i++) {
      for (int j=0; j<SIZE; j++) {
         unsigned char r = src[i][j][0];
         unsigned char g = src[i][j][1];
         unsigned char b = src[i][j][2];
         dest[i][j] = (unsigned char)(.299*r + .587*g + .114*b);
      }
   }
   writeGSBMP("fruit-grayscale.bmp", dest);
   showGSBMP(dest);
}
