#include <iostream>
using namespace std;

class parent {
   public:
      void disp() {
         cout << "this is the parent" << endl;
      }
};

class child: public parent{
   public:
      void disp()
      {
         cout<< "this is the child" << endl;
      }
};

int main() {
   child x = child();
   x.disp();
   parent y = child();
   y.disp();
   return 0;
}

