
#ifndef CONNECTION_H
#define CONNECTION_H

#include "date.h"
#include "contact.h"
#include "misc.h"
#include "fstream"
#include <vector>
using namespace std;
class Connection{
    friend class Network;

private:
	string f_name;
	string l_name;
    string friendCode;
	Date *birthdate;
    Email *email;
    Phone *phone;
    Connection* next;
    Connection* prev;
    vector< Connection* > myfriends;

public: 
    Connection();
    ~Connection();
    Connection(string filename);
    Connection(string f_name, string l_name, string bdate, string email, string phone, string friendCode);
	void print_connection();
	void set_connection();
	void set_connection(string filename);
    bool operator==(const Connection& rhs);
    bool operator!=(const Connection& rhs);
    int makeFriend(Connection* newFriend);
    void writeConnection(ofstream& os);
};


#endif
