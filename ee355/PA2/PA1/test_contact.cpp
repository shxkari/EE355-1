#include <iostream>
#include "contact.h"


int main(){
	string type = "USC";
	string style = "full";
	string email_addr = "sufyansh@usc.edu";
	Email c1(type, email_addr);
	// cout << c1.get_contact(style) << endl;
	c1.print();
	// cout << c1.get_contact(style) << endl;


	type = "cell";
	string phone_num = "310-738-0479";
	Phone c2(type, phone_num);
	//cout << c2.get_contact(style) << endl;
	// c2.set_contact();
	// cout << c2.get_contact(style) << endl;
	c2.print();

	return 0;
}