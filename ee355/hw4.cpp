
#include <iostream>
#include <cstring>
using namespace std;

int main(){
const int W=5;
const int X=5;
const int Y=5;
const int Z=5;

int ****arr4D = new int***[W];
for(int h=0; h < W; h++) {
    arr4D[h] = new int**[X];
    for(int i =0; i<X; i++){
       arr4D[h][i] = new int*[Y];
       for(int j =0; j<Y; j++){
           arr4D[h][i][j] = new int[Z];
           for(int k = 0; k<Z;k++){
              arr4D[h][i][j][k] = 2;
              if (k == 3)
                arr4D[h][i][j][k]=9;
           }
       }
    }
}

cout << arr4D[4][4][4][3] << endl;

for(int h=0; h < W; h++) {
    for(int i =0; i<X; i++){
       for(int j =0; j<Y; j++)
          delete[] arr4D[h][i][j];
       delete[] arr4D[h][i];
    }
    delete[] arr4D[h];     
}
delete[] arr4D;


}


