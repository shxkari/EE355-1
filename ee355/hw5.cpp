#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream input("input.txt");
	string word[10];
	while(input >> word){
		for(int i = 0; i < 10; i++){
			cout << word[i] << endl;
		}
	}
	cout << word[3] << endl;

	return 0;
}