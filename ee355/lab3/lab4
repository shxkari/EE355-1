#include <iostream>
#include <fstream>

using namespace std;

class Pancake {
   protected:
      bool burnt;
      int size;
   public:
      void flip_pancake() {
         if (burnt == true) 
            burnt = false;
         else 
            burnt = true;
         }
       bool get_burnt(){return burnt;}
       void set_burnt(bool b) {this->burnt = burnt;}
       int get_size(){return size;}
       void set_size(int size){this->size = size;}
       void pancake(bool, int);


};

void Pancake::pancake(bool burnt, int size) {
	this->burnt = burnt;
	this-> size = size;
}


class PancakePile : public Pancake {
   protected:
      int z;
      int i;
      Pancake piles[100];
      Pancake p;

   public:
   	  void AddToPile(int z, int i, Pancake p){
   	  	this-> z = z;
   	  	this-> i = i;
   	  	this-> p = p;
   	  	piles[i] = p;
   	  }

   	 
   	  void printPile(){
   	  	for(int k = 0; k < z; k++)
   	  		cout << piles[k].get_size() << "," << piles[k].get_burnt() << " ";
   	  	cout << endl;
   	  }


   	  void printResultsPile(){
   	  	ofstream output("output.txt", ios_base::app);
   	  	for(int k = 0; k < z; k++)
   	  		output << piles[k].get_size() << "," << piles[k].get_burnt() << " ";
   	  	output << endl;
   	  }

      void pancake_burnt_down() {
         for(int k=0; k < z; k++){
         	if(piles[k].get_burnt() == true)
         		piles[k].flip_pancake();
         }
      }
      void pancake_burnt_up() {
         for(int k=0; k < z; k++){
         	if(piles[k].get_burnt() == false)
         		piles[k].flip_pancake();
         }
      }
};
   
class MPancakePiles : public PancakePile {
   protected:
      int X; //how many rows of piles
      int Y; //how many columns of piles
      int r, c, z;
      PancakePile MPiles[100][100];
      PancakePile pile;
   public:
   	  void AddToPlate(int X, int Y, PancakePile pile, int r, int c, int z){
   	  	this-> X = X;
   	  	this-> Y = Y;
   	  	this-> r = r;
   	  	this-> c = c;
   	  	this-> z = z;
   	  	this-> pile = pile;
   	  	MPiles[r][c] = pile;
   	  }
   	  void PrintPlate(){
   	  	for(int r = 0; r < X; r++){
   	  		for(int c=0; c < Y; c++) 
   	  			MPiles[r][c].printPile();
   	  	}
   	  }
   	    void PrintResultsPlate(){
   	  	for(int r = 0; r < X; r++){
   	  		for(int c=0; c < Y; c++) 
   	  			MPiles[r][c].printResultsPile();
   	  	}
   	  }



      void rearrange_interior() {
      	for(int r  = 1; r < X-1; r++){
      		for(int c=1; c < Y-1; c++){
      			MPiles[r][c].pancake_burnt_down();
      		}
      	}
      }
      void rearrange_exterior() {
      	for(int r  = 0; r < X; r++){
      		for(int c=0; c < Y ; c++){
      			if((r == 0) || (r == X-1))
      				MPiles[r][c].pancake_burnt_up();
      			else if(c == 0 || c == Y-1)
      				MPiles[r][c].pancake_burnt_up();
      		}
      	}
      }
};




int main() {
   
   int X, Y, Z, M, s, b, i, r, c;
   Pancake p;
   PancakePile pile;
   MPancakePiles plate;

   ifstream input("input.txt");
   input >> X >> Y >> Z;                           //grab row, column, size
   //cout << X << " " << Y << " " << Z << endl;
   M = X*Y;                                    //# of piles = X times Y
   //cout<< M << endl;
   int temp_s, temp_b;
   char str;

for(int h=0; h < X; h++){
  for(int k=0; k < Y; k++) {

      for(int j = 0; j < Z; j++) {
          input >> temp_s >> str >> temp_b;  
          p.pancake(temp_b, temp_s);
          //if(temp_b != 0)
          //p.flip_pancake();
          pile.AddToPile(Z, i, p);
          i++;
      }

      i=0;
      //pile.printPile();
      //cout <<"this is M[" << r << "][" << c << "]\n";
      //pile.pancake_burnt_up();
      plate.AddToPlate(X, Y, pile, r, c, Z);
      c++;
  }
   c=0;
   r++;   
}
	plate.rearrange_interior();
	plate.rearrange_exterior();
	//plate.PrintPlate();
	ofstream output("output.txt");
	output << X << " " << Y << " " << Z << endl;
	plate.PrintResultsPlate();


       
   




   
   return 0;
}

      
      
