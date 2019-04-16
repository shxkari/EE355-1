#include <iostream>
#include <fstream>
using namespace std;

class Ticket {
public:
	long int ID;		//an 11 digit unique numbber to identify ticket
	//bool valid; //bool variable to indicate expired or not
	void print_ID(){
		cout << ID << endl;
	}

	void set_id(long int ID){
		this-> ID = ID;
	}
	long int get_id(){return ID;}

	bool is_valid(){return true;}
};

class VIPTicket : public Ticket {
public:
	string TickChar;
	long int win_ID;
	int Won;
	int almostWon;

	void set_tickchar(string TickChar){
		this-> TickChar = TickChar;
	}
	string get_tickchar(){return TickChar;}

	int check_if_won(){
		if(almostWon == 1){
			if (TickChar == "20Z")
				Won = 1;
			else 
				Won = 0;
		}
		return Won;
	}


	void set_the_Winner(long int win_ID){
		this -> win_ID = win_ID;
		for(int i = 0; i < 5; i ++){
			if( ID == win_ID )
				int almostWon = 1;
			else
				int almostWon = 0;
		}
	}
};

int main(){
	//VIPTicket *pTicket;
	VIPTicket pTicket[5] = {};
	long int win_ID;
	int numTick, Won;
	long int temp_a;
	long  int temp_ID;
	string temp_b;


	cout << "Please enter your ticket number:" << endl;
	cin >> win_ID;
	ifstream input("input.txt");
	input >> temp_b >> temp_b >> temp_b >> temp_b >> numTick;
	input >> temp_b >> temp_b;
	cout << temp_b << endl;
	cout << numTick << endl;
	//cout << temp_a << endl;

	for(int i = 0; i < numTick; i++){
		input >> temp_ID >> temp_b;
	 	//cout << temp_ID << " " << temp_b << endl;
	 	pTicket[i].set_id(temp_ID);
	 	//pTicket[i].print_ID();
	 	pTicket[i].set_tickchar(temp_b);
	 	cout << pTicket[i].get_id() << " ";
	 	cout << pTicket[i].get_tickchar() << endl;
	}
	for(int i = 0; i < numTick; i++){
		pTicket[i].set_the_Winner(win_ID);
	}

	for(int i = 0; i < numTick; i++){
		pTicket[i].check_if_won();
	}

	ofstream output("output.txt");
	for(int i = 0; i < 5; i++){
		if(Won)
			output << "Congrats Your Ticket " << pTicket[i].get_id() << " is a WINNER!" << endl;
		else
			output << "No Bernies, Your ticket " << pTicket[i].get_id() << " did not win. Maybe in 2024!" << endl;
	}

	return 0;
}

