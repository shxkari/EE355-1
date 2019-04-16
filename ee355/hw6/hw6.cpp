#include <iostream>
#include <fstream>

using namespace std;
	int main(){

	double array[] = {1,4,423,599,53,72,-120.5}; //can be taken from cin or input file. easy
	int arraysize = 7;
	int count[arraysize] = {};
	for(int i = 0; i < arraysize; i++){
		for(int j = 0; j < arraysize; j++){
			if(array[j] < array[i]){
				count[i]++;
			}
		}
	}

	for(int i = 0; i < arraysize; i++){
		cout << array[i] << ":" << count[i];
		if(i != arraysize-1)
			cout <<", ";
	}
	cout << endl;

	return 0;
}