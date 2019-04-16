#include <iostream> 
using namespace std;

int main(){

	int a[7] = {5,3,4,7,8,3,1};
	int *p = a;
	int *q = &(a[6]);

	int b = 3;
	int c =3;

	b+=c;
	cout << b << endl;
	while (p!=q){
		cout << *q << ", " << *p << endl;

		*q += *p;
		p++;
		q--;
	}

	return 0;
}