#include <iostream>
using namespace std;

void print(int i)
{
   cout<< "because an integer was the input, this one was called. int = "    << i << endl;
}
void print(double f)
{
   cout << "because a decimal value was the input, this func was called. float = " << f << endl;
}
void print(char const* c)
{
   cout << "because a char was the input, this func was called. char* = " << c << endl;
}

int main()
{
   print(2019);
   print(2019.01);
   print("twenty nineteen");
   return 0;
}



