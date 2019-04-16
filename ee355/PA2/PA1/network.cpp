
#include "network.h"
#include <limits>
#include "misc.h"
#include <fstream>

Network::Network(){
    head = NULL;
    tail = NULL;
    count = 0;
}


Network::Network(string fileName){
    // TODO: complete this method!
    // Implement it in one single line!
    // You may need to implement the load method before this!
    loadDB(fileName);
}

Network::~Network(){
    // Copy from lab5 
    delete head;
    delete tail;
}


void Network::push_front(Connection* newEntry){
    // Adds a new Connection (newEntry) to the front of LL
    // TA completed me in lab5 and since then I've not been changed! 
    newEntry->prev = NULL;
    newEntry->next = head;
    if (head != NULL)
        head->prev = newEntry;
    else
        tail = newEntry;
    head = newEntry;
    count++;
}


void Network::push_back(Connection* newEntry){
    // Adds a new Connection (newEntry) to the back of LL
    // Copy from your lab5
    newEntry->next = NULL;
    newEntry->prev = tail;
    if (tail != NULL)
        tail->next = newEntry;
    else
        head = newEntry;
    
    tail = newEntry;
    count++;
}


Connection* Network::search(Connection* searchEntry){
    // Searches the Network for searchEntry
    // if found, returns a pointer to it, else returns NULL
    // Copy from lab5 
    Connection* ptr = head;
    while(ptr != NULL){
        if(*searchEntry == *ptr )
            break;
            
        if(*searchEntry != *ptr)
            ptr= ptr->next;


    }
    return ptr;
}


Connection* Network::search(string fname, string lname){
    // New == for Connection, only based on fname and lname
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method
    // Note: two ways to implement this, 1st making a new Connection with fname and lname and and using search(Connection*), 2nd using fname and lname directly. 
    Connection* ptr = head;
    while(ptr != NULL){
        if((ptr->f_name == fname) && (ptr->l_name == lname))
            break;
        else
            ptr = ptr->next;
    }
    return ptr;
}

Connection* Network::search(string friendCode){
	Connection* ptr = head;
	while(ptr!=NULL){
		if(ptr->friendCode == friendCode)
			break;
		else
			ptr=ptr->next;
	}
	return ptr;
}

void Network::printDB(){
    // Leave me alone! I know how to print! 
    // Note: Notice that we don't need to update this even after adding to Connection attributes
    // This is a feature of OOP, classes are supposed to take care of themselves!
    cout << "Number of connections: " << count << endl;
    cout << "------------------------------" << endl;
    Connection* ptr = head;
    while(ptr != NULL){
        ptr->print_connection();
        cout << "------------------------------" << endl;
        ptr = ptr->next;
    }
}


void Network::saveDB(){
    // Saves the netwrok in file <filename>
    // Note: The format of the output file is very abstract, just raw data
    // Look at studentDB.txt as a template
    // TODO: Update this method with new requirements
    // Note: notice the intentional flaw in this code, as compared to the note mentioned in printDB, now the one who is responsible for implementing Network should be aware of implementation of Connection, not good! You will fix this in PA2. 
    ofstream output("myDB.db");
    Connection* ptr = head;
    while(ptr!= NULL){
        ptr->writeConnection(output);
        ptr = ptr->next;
    }
    delete ptr;

}


void Network::loadDB(string filename){
    // Loads the netwrok from file <filename>
    // The format of the input file is similar to saveDB
    // Look at network studentDB.txt as a template
    // Phone number can be with dashes or without them
    // TODO: Now you will notice you need to go back and make a new constructor to the Connection class,  
    // Connection::Connection(fname, lname, bdate, email, phone)
    // TODO: Update this method with new requirements 
    
    Connection* ptr = head;
    vector < vector<string> > friends;
    vector <string> temp;
    //vector <string> userCode;
    while(head != NULL){
        ptr = head->next;
        delete head;
        head = ptr;
        count--;
    }
    head = NULL;
    tail = NULL;
    ifstream infile;
    infile.open(filename.c_str());

    string buff, fname, lname, bdate, email, phone, friendCode;

    while(getline(infile, buff)){
        lname = buff.substr(0, buff.find(','));
        fname = buff.substr(buff.find(',')+2);
        getline(infile, bdate);
        getline(infile, email);
        getline(infile, phone);
        friendCode = (codeName(fname, lname));
        getline(infile, buff);
        while(buff.compare(0,5, "-----")!= 0){
        	temp.push_back(buff);
        	getline(infile, buff);
        }
        friends.push_back(temp);
        temp.clear();
        Connection* newEntry = new Connection(fname, lname, bdate, email, phone, friendCode);
        this->push_back(newEntry);
    }
    

    Connection* temp1 = head;
    int i=0;
    while(temp1 != NULL){
    	if(friends[i].size() != 0){
	    	for(int j=0; j <friends[i].size(); j++){
	    			Connection* temp2 = search(friends[i][j]);
	    			temp1->makeFriend(temp2);
	    			temp2->makeFriend(temp1);
	    	}
	    }
    	temp1=temp1->next;
    	i++;
   
    }
}


bool Network::remove(string fname, string lname){
    // We modified the definition of == for Connection in Connection definition itself, 
    // So we should not be worried about changes we made in Connection to modify this method!
    // Copy from lab5
    Connection* temp = head;
    Connection* ptr = search(fname, lname);
    string res;
    if(!ptr){
        delete ptr;
        return false;
    }
    else{
    	res = codeName(fname, lname);
        if(ptr->prev == NULL && ptr->next != NULL){
            Connection* ptr2 = ptr->next;
            ptr2->prev = NULL;
            head = ptr2;
            count--;
        }
        else if(ptr->next == NULL && ptr->prev !=NULL){
            Connection* ptr1 = ptr->prev;
            ptr1->next = NULL;
            tail = ptr1;
            count--;
        }
        else if(ptr->prev == NULL && ptr->next == NULL){
            Connection* ptr1 = ptr->prev;
            Connection* ptr2 = ptr->next;   
            ptr1->next = NULL;
            ptr2->prev = NULL;
            count--;
        }
        else{
            Connection* ptr1 = ptr->prev;
            Connection* ptr2 = ptr->next;
            ptr2->prev = ptr1;
            ptr1->next = ptr2;
            count--;
        }
        // delete ptr;
        Connection* temp2 = head;
        while(temp2!=NULL){
        	for(int i = 0; i < temp2->myfriends.size(); i++)
	        	if(temp2->myfriends[i] == ptr){
	        		temp2->myfriends.erase(temp2->myfriends.begin() + i); 
	        		break;
	        	}
        	temp2 = temp2->next;
        }
        delete ptr;
        delete temp2;
        return true;
    }
}

void Network::sendEmail(string addr, string subject, string content, string attachment=""){
    // Sending a command looks like:
    // echo "content" | mailx -s "subject" -a "attachment" addr;
    // TODO: Search how you can run a unix command in C++
    // TODO: You need to add double quotation character (") to both sides of strings for this command. Adding other characters (like ? in code below) should be easy, but double quotation says: I'm a character but not a typical character! 
    // string new_str = '?' + old_str + '?'
    // TODO: Complete this method
    addr = "\"" + addr + "\"";
    content = "\"" + content + "\"";
    subject = "\"" + subject + "\"";
    attachment = "\"" + attachment + "\"";
    string cmd;
    cmd = "echo " + content + " | mailx -s " + subject + " " + addr;
    cout << cmd << endl;
    system(cmd.c_str());
}


void Network::showMenu(){
    // TODO: Complete this method!
    // All the prompts are given to you, 
    // You should add code before, between and after prompts!

    int opt;
    while(1){
        cout << "\033[2J\033[1;1H";
        printMe("banner"); // from misc library

        cout << "Select from below: \n";
        cout << "1. Save network database \n";
        cout << "2. Load network database \n";
        cout << "3. Add a new connection \n";
        cout << "4. Remove a connection \n";
        cout << "5. Search \n";
        cout << "6. Send an email \n";
        cout << "7. Send an iMessage \n";
        cout << "8. Print database \n";
        cout << "9. Connect \n";
        cout << "\nSelect an option ... ";
        
        if (cin >> opt) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Wrong option! " << endl;
            return;
        }
        
        // You may need these variables! Add more if you want!
        string fname, lname, fileName, bdate, email, type1, type2, phone, friendCode;
        vector<string> str;
        int chk;
        cout << "\033[2J\033[1;1H";

        if (opt==1){
            // TODO: Complete me!
            cout << "Saving network database \n";
            // cout << "Enter the name of the save file: ";
            // getline(cin, fileName);
            saveDB();
            cout << "Network saved " << endl;
        }
        else if (opt==2){
            // TODO: Complete me!

            cout << "Loading network database \n";
            cout << "Files with extension db:\n";
         
            DIR *dir;
            struct dirent *ent;
            char targetFolderAddr[] = "./";
            string extension = "db";
            if ((dir = opendir ("./")) != NULL) {
                  while ((ent = readdir (dir)) != NULL) {
                    string fname = ent->d_name;
                    string extensionchk = fname.substr(fname.find('.')+1);
                    if (extensionchk == extension){
                        str.push_back(fname);
                        cout << fname << endl;
                    }
                  }
                  closedir (dir);
            } else { /* could not open directory */
                  perror ("No directory!");
            }

            cout << "Enter the name of the load file: "; 
            getline(cin, fileName);
            for(int i = 0; i < str.size(); i++){
                if(fileName == str[i]){
                    chk = 1;
                }
            }    
            if(chk == 1){
                loadDB(fileName);
                cout << "Network loaded from " << fileName << " with " << count << " connections \n";
            }
            else
                cout << "File " << fileName <<  " does not exist!" << endl;
            
        }
        else if (opt == 3){
            cout << "Adding a new connection \n";
            cout << "First Name: ";
            getline(cin, fname);
            cout << "Last Name: ";
            getline(cin, lname);
            if(search(fname, lname) == NULL){
                cout << "Birthdate (M/DD/YYYY): ";
                cin >> bdate;
                cout << "Type of email: ";
                cin >> type1;
                cout << "Email Address: ";
                cin >> email;
                email = "(" + type1 + ") " + email;
                cout << "Type of phone number: ";
                cin >> type2;
                cout << "Phone Number (with or without dashes): ";
                cin >> phone;
                phone = "(" + type2 + ") " + phone;
                friendCode = codeName(fname, lname);
                Connection* newEntry = new Connection(fname, lname, bdate, email, phone, friendCode);
                this->push_front(newEntry);
                cout << "Connection added successfully \n";
            }
            else
                cout << "Connection already exists!\n";




        }
        else if (opt == 4){
            // TODO: Complete me!
            cout << "Removing a connection \n";
            cout << "First name: ";
            getline(cin, fname);
            cout << "Last name: ";
            getline(cin, lname);
            if(remove(fname, lname) == true)
                cout << "Remove Successful! \n";
            else
                cout << "Connection not found! \n";
        }
        else if (opt==5){
            // TODO: Complete me!
            cout << "Searching: \n";
            cout << "First Name: ";
            getline(cin, fname);
            cout << "Last Name: ";
            getline(cin, lname);
            Connection* ptr = search(fname, lname);
            if(ptr != NULL)
                ptr->print_connection();
            else
                cout << "Not found!\n";
            delete ptr;
            // if found: print connection
            // if not, cout << "Not found! \n";
        }
        else if (opt==6){
            // Note: Completed!
            cout << "Sending email to: \n";
            cout << "First Name: ";
            std::getline (std::cin, fname);
            cout << "Last Name: ";
            std::getline (std::cin, lname);
            Connection* ptr = search(fname, lname);
            if (ptr){
                string subject, content, attachment;
                cout << "Sending email to: \n";
                ptr->print_connection();
                cout << "Subject: ";
                std::getline (std::cin, subject);
                cout << "Content: ";
                std::getline (std::cin, content);
                cout << "Attachment: ";
                std::getline (std::cin, attachment);
                string addr = ptr->email->get_contact("1");
                sendEmail(addr, subject, content, attachment);
            }
            else 
                cout << "Contact not found! \n";

        }
        else if (opt==7){
            cout << "Option currently not available\n";
        }
        else if (opt==8){
            // TODO: Complete me!
            cout << "Network Database: \n";
            printDB();
        }
        else if (opt==9){
        	cout << "Make friends... \n";
        	cout << "First Name: ";
        	getline(cin, fname);
        	cout << "Last Name: ";
        	getline(cin, lname);
        	Connection* c1 = search(fname, lname);
            if(c1 != NULL){
	        	cout << "First Name of 2nd connection: ";
	        	getline(cin, fname);
	        	cout << "Last Name of 2nd connection: ";
	        	getline(cin, lname);
	        	Connection* c2 = search(fname, lname);
	        	if(c2 != NULL){
	        		if(c1->makeFriend(c2) == 1) {
	        			c2->makeFriend(c1);
	        			cout << "These two persons are now friends!\n";
	        		}
	        		else
	        			cout << "Already friends!\n";
	        	}
	        	else
	        		cout << "Not found\n";

            }
            else
                cout << "Not found!\n";


        }
        else
            cout << "Nothing matched!\n";
        
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n\nPress Enter key to go back to main menu ... ";
        string temp;
        std::getline (std::cin, temp);
        cout << "\033[2J\033[1;1H";
    }
}


