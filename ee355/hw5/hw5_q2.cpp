#include <iostream>
#include <fstream>

using namespace std;

int main(){
	int X, k, j;
	int num[100];
	cout << "enter integer:" << endl;
	cin >> X;
	cout << "enter k:" << endl;
	cin >> k;
	cout << X << "," << k << endl;

	while(X > 0){
		num[j] = X%10;
		X /= 10;
		j++;
		
	}

	for(int i = j-1; i >=0; i--){
		 cout << num[i];
		}
	cout << endl;

	

	return 0;
}