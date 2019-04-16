#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

unsigned char in[SIZE][SIZE];
unsigned char out[SIZE][SIZE];

int main()
{
  readGSBMP("elephant.bmp", in);

  for(int i=0; i < SIZE; i++){
    for(int j=0; j < SIZE; j++){
      out[i][j] = in[SIZE/4 + i/2][SIZE/4 + j/2];
    }
  }

  writeGSBMP("elephant-zoom.bmp", out);
  return 0;
}
