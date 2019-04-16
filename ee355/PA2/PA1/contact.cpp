
#include "contact.h"
#include <sstream>
#include <algorithm>

Email::Email(string type, string email_addr){
    this->type = type;
    this->email_addr=email_addr;
}


void Email::set_contact(){
    // TODO: Do not change the prompts!
	
    cout << "Enter the type of email address: ";
    cin >> type;

    cout << "Enter email address: ";
    cin >> email_addr;
}


string Email::get_contact(string style){
    // Note: We have default argument in declaration and not in definition!
    if (style=="full")
	    return "(" + type + "):" + email_addr;
    else 
        return email_addr;
}


void Email::print(){
    // Note: get_contact is called with default argument
	cout << get_contact() << endl;
}


Phone::Phone(string type, string num){
    // TODO: It is possible that num includes "-" or not, manage it!
    // TODO: Complete this method!
    // Note: We don't want to use C++11! stol is not valid!
    // The code has been covered in the discussion session
    stringstream ss;
    long int phone;

    this->type = type;
    string str = num;
    str.erase(remove(str.begin(), str.end(), '-'), str.end());
    ss << str;
    ss >> phone;
    this->phone_num = phone;


    /* Note: Understand your own TA's bug!
     * This code has a bug, can you understand why?
    long int area_code = atoi(num.substr(0, 3).c_str());
    long int  number = atoi(num.substr(3).c_str()); 
    this->phone_num = area_code*10000000 + number; 
    */
}


void Phone::set_contact(){
    // TODO: Complete this method
    // Use the same prompts as given!
    string str;
    stringstream ss;

	cout <<"Enter the type of phone number: ";
    cin >> type;
	cout << "Enter the phone number: ";
    cin >> str;

    str.erase(remove(str.begin(), str.end(), '-'), str.end());
    ss << str;
    ss >> phone_num;
    
}


string Phone::get_contact(string style){
    // TODO: Complete this method, get hint from Email 
    // The code has been covered in discussion session 
   stringstream ss;
   string str;
   ss << phone_num;
   ss >> str;
   //str = str.substr(0, 3) + "-" + str.substr(3, 3) + "-" + str.substr(6);

    if (style=="full")
        return "(" + type + "): " + str;
    else 
        return str;
    /* Note: Understand your own TA's bug!
     * This code has a bug, can you understand it!
    int x1 = (phone_num/10000000);
	int x2 = ((phone_num)/10000)%1000;
	int x3 = phone_num%10000;
    */ 
}


void Phone::print(){
    // Note: get_contact is called with default argument

	cout << get_contact() << endl;
}


