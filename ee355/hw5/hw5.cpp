#include <iostream>
#include <fstream>
#define MAXSIZE 10
using namespace std;
void sort(string [], int);
int main(){
	//part a
	ifstream input("input.txt");
	string word[MAXSIZE];
	if(input.is_open()){
		for(int i =0; i<MAXSIZE;i++){
			input >> word[i];
			cout << word[i] << " ";
		}
		cout << endl;
	}
	input.close();

	//part b
	ofstream output("out1b.txt");
	if(output.is_open()){
		for(int i = MAXSIZE-1; i >= 0; i--){
			if(word[i] != ""){
				output << word[i] << " ";
			}
		}

	}
	output.close();

	//part c
	ofstream outc("out1c.txt");
	if(outc.is_open()){
	    sort(word, MAXSIZE); 
	    for (int i = 0; i < MAXSIZE; i++)
	    	if(word[i] != "") 
	        	outc << word[i] << " ";
	}
	return 0;
}

void sort(string array[], int n)
{
	int minIndex;
	string minValue;

	for(int i = 0; i < (n -1); i++)
	{
	    minIndex = i;
	    minValue = array[i];
	    for(int j = i +1; j < n; j++)
	    {
	        if (array[j] < minValue)
	        {
	            minValue = array[j];
	            minIndex = j;
	        }
	    }
	    array[minIndex] = array[i];
	    array[i] = minValue;
	}
};