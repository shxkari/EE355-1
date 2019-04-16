#include "bmplib.h"

int main() {
   unsigned char src[SIZE][SIZE][RGB];
   unsigned char dest[SIZE][SIZE][RGB];
   readRGBBMP("fruit.bmp", src);
   for (int i=0; i<SIZE; i++) {
      for (int j=0; j<SIZE; j++) {
         for (int c=0; c<3; c++) {
            dest[i][j][c] = 255-src[i][j][c];
         }
      }
   }
   showRGBBMP(dest);
   writeRGBBMP("fruit-inverse.bmp", dest);
}
