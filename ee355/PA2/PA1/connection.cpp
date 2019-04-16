
#include "connection.h"

Connection::Connection(){
    // I'm already done! 
    set_connection();
}


Connection::~Connection(){
    // TODO: Complete me
    delete birthdate;
    delete email;
    delete phone;

}


Connection::Connection(string f_name, string l_name, 
    string bdate, string email, string phone, string friendCode){
    // TODO: Complete this method!
    // phone and email strings are in full version
    string type;


    this-> f_name = f_name;
    this-> l_name = l_name;
    this-> birthdate = new Date(bdate);

    type = email.substr(1, email.find(')')-1);
    email = email.substr(email.find(')')+2);
    this-> email = new Email(type ,email);

    type = phone.substr(1, phone.find(')')-1);
    phone = phone.substr(phone.find(')')+2);

    this-> phone = new Phone(type, phone);

    this-> friendCode = friendCode;

}


Connection::Connection(string filename){
    // TODO: Complete this method!
    set_connection(filename);

}


void Connection::set_connection(){
    // prompts for the information of the user
    // first/last name can have spaces!
    // date format must be "M/D/YYYY"
    // We are sure user enters info in correct format.
    // TODO: complete this method!
    string temp;

    string type;

    cout << "First Name: ";
    getline(cin, f_name);
	cout << "Last Name: ";
    getline(cin, l_name);

    friendCode = codeName(f_name, l_name);
    cout << "Birthdate (M/D/YYYY): ";
    getline(cin, temp);
    birthdate = new Date(temp);

    
    cout << "Type of email address: ";
    getline(cin, type);
    cout << "Email address: ";
    getline(cin, temp);
    email = new Email(type, temp);


    cout << "Type of phone number: ";
    getline(cin, type);
    cout << "Phone number: ";
    getline(cin, temp);
    phone = new Phone(type, temp);
}


void Connection::set_connection(string filename){
    string temp;
    string style = "full";
    ifstream input(filename.c_str());
    string buff,type;
    getline(input,buff);
    l_name = buff.substr(0, buff.find(','));
    f_name = buff.substr(buff.find(',')+2); 
    friendCode = codeName(f_name, l_name);
    getline(input, temp);
    birthdate = new Date(temp);

    getline(input,buff);
    type = buff.substr(1, buff.find(')')-1);
    temp = buff.substr(buff.find(')')+2);
    email = new Email(type, temp);

    getline(input,buff);
    type = buff.substr(1, buff.find(')')-1);
    temp = buff.substr(buff.find(')')+2);
    phone = new Phone(type, temp);
    

    // getline (input, f_name);
    // getline (input, l_name); 
    // getline(input, temp);
    // birthdate = new Date(temp);
    // getline(input, temp);
    // email = new Email(type, temp);
    // getline(input, temp);
    // phone = new Phone(type, temp);
}


bool Connection::operator==(const Connection& rhs){
    // TODO: Complete this method!
    // Note: Difference to Lab is that from now on the combination of fname-lname is unique for any connection
    if ( (f_name == rhs.f_name) && 
         (l_name == rhs.l_name))
        return true;
    else
        return false;
}


bool Connection::operator!=(const Connection& rhs){ 
    // TODO: Complete this method!
    return !(*this == rhs);
}


void Connection::print_connection(){
    // Already implemented for you! Do not change!
	cout << l_name <<", " << f_name << endl;
	birthdate->print_date("Month D, YYYY");
    email->print();
    phone->print();
    for(int i = 0; i < myfriends.size(); i++){
        cout << codeName(myfriends[i]->f_name, myfriends[i]->l_name) << endl;
    }

}

int Connection::makeFriend(Connection* newFriend){
    int flag = 0;
    if(myfriends.size() != 0){                      //if size = 0; for loop will never run so need to put if else
        for(int i = 0; i < myfriends.size(); i++){
            if(myfriends[i] == newFriend){
                flag = 1;
                break;
            }
            else
                flag = 0;    
        }
        if(flag==0){
            myfriends.push_back(newFriend);
            return 1;
        }
        else
            return 0;
     }
     else
         myfriends.push_back(newFriend);
        return 1;
}

void Connection::writeConnection(ofstream& os){
    os << l_name <<", " << f_name << endl;
    os << birthdate->get_date() << endl;
    os << email->get_contact() << endl;
    os << phone->get_contact() << endl;
    for(int i = 0; i < myfriends.size(); i++){
        os << codeName(myfriends[i]->f_name, myfriends[i]->l_name) << endl;
    }
    os << "------------------------------" << endl;

}