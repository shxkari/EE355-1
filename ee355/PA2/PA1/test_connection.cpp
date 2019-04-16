#include "connection.h"
#include <iostream>

int main(){
	Connection* c1 = new Connection("Connection1.txt"); 
    Connection* c2 = new Connection("Connection2.txt");
	c1->print_connection();
	c2->print_connection();


	return 0;
}