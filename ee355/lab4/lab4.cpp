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
      virtual void pancake_burnt_up() {
         for(int k=0; k < z; k++){
         	if(piles[k].get_burnt() == false)
         		piles[k].flip_pancake();
         }
      }
};


// class EncodedPancakePile : public PancakePile {
// protected:
// 	int Code;
// public:
// 	void get_code(int Code){
// 		this-> Code = Code;
// 	}
// 	void pancake_burnt_up(){
// 		for(int i = 0; i < z; i++){
// 			if(i < Code && piles[i].get_burnt() ==  false)
// 				piles[i].flip_pancake();
// 			else if(i >= Code && piles[i].get_burnt() == true)
// 				piles[i].flip_pancake();
// 		}
// 	}

	
// };

class MPancakePiles : public PancakePile {
   public:
      int X; //how many rows of piles
      int Y; //how many columns of piles
      int r, c, z;
 	  PancakePile **MPiles;
   	  PancakePile pile;

   	  void CreatePlate(int X, int Y){
   	  	this-> X = X;
   	  	this-> Y = Y;
		MPiles = new PancakePile*[X];
		for (int i=0; i< X; i++){
        	MPiles[i] = new PancakePile[Y];		//changed from encoded pancake pile to pancakepile bc didnt work
        }	
   	  }

   	  void AddToPlate(PancakePile pile, int r, int c, int z){
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

      void rearrange_last_row() {
      	for(int r = 0; r < X; r++){
      		for(int c=0; c<Y; c++){
      			if(r == X-1)
      			MPiles[r][c].pancake_burnt_up();
      		}
      	}
      }

      ~MPancakePiles(){
      	for(int i=0; i< X; i++)
        	delete []MPiles[i];			
        delete []MPiles;
   	  		
      };

};




int main() {
   
	int X, Y, Z, M, s, b, i, r, c, Code;
	Pancake p;
	PancakePile pile;
	MPancakePiles plate;

	ifstream input("input.txt");
	input >> X >> Y >> Z >> Code;                           //grab row, column, size
	M = X*Y;                                    //# of piles = X times Y
	int temp_s, temp_b;
	char str;
	plate.CreatePlate(X, Y);

	for(int h=0; h < X; h++){
		for(int k=0; k < Y; k++) {
			for(int j = 0; j < Z; j++) {
				input >> temp_s >> str >> temp_b;  
				p.pancake(temp_b, temp_s);
				pile.AddToPile(Z, i, p);
				i++;
			}
			i=0;
			plate.AddToPlate( pile, r, c, Z);
			c++;
		}
	c=0;
	r++;   
	}
	plate.rearrange_last_row();
	ofstream output("output.txt");
	output << X << " " << Y << " " << Z << endl;
	output << Code << endl;
	plate.PrintResultsPlate();
	//plate.~MPancakePiles();
 
   return 0;
}

      
      
