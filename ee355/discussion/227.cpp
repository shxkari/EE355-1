#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main(){

	cout <<"pls enter phone number" << endl;
	string str;
	stringstream ss;
	long int num;

	cin >> str;
	cout << str << endl;
	str.erase(remove(str.begin(), str.end(), '-'), str.end());

	ss << str;
	ss >> num;
	cout << num;

	return 0;
}