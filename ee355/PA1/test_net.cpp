#include "network.h"


int main(){

    Network myNet("studentDB.db");
    //myNet.printDB();

    Connection* c2 = new Connection("Connection1.txt"); 
    // Connection* c3 = new Connection("Connection2.txt");
    // Connection* c4 = new Connection("Connection3.txt");

    // cout << "[Empty network:] " << endl;
    // myNet.printDB();

    //myNet.push_front(c2);
    //myNet.printDB();
    //string fname = "Sufyan";
    //string lname = "Shaikh";
    //myNet.remove(fname, lname);
    myNet.printDB();

    delete c2;

    // myNet.push_front(c2);
    // cout << endl << "[After adding first two contact:] " << endl;
    // myNet.printDB();

    // myNet.push_front(c3);
    // cout << endl << "[After adding another contact:] " << endl;
    // myNet.printDB();

    // // myNet.push_front(c4);
    // // cout << endl << "[After adding another contact:] " << endl;
    // // myNet.printDB();

    // // Part #2:
    // // TODO: Test save and load, and push_back 
    // myNet.saveDB("myNetwork.txt");
    // myNet.push_back(c4);
    // cout << endl << "[After adding the 4th connection:] " << endl;
    // myNet.printDB();
    // myNet.loadDB("myNetwork.txt");
    // cout << endl << "[After loading networkDB:] " << endl;
    // myNet.printDB();
  

    // // Part #3: 
    // // TODO: Search is called in remove, just test remove
    // myNet.remove("Julia Scarlett Elizabeth", "Louis-Dreyfus", "1/13/1961");
    // cout << endl << "[After removing the vice president:] " << endl;
    // myNet.printDB();
   
    return 0;
}
