#include <iostream>
using namespace std;

int fib_dp(int n) { 
  
  int f[n+2];
  int i; 
  f[0] = 0; 
  f[1] = 1; 
  
  for (i = 2; i <= n; i++)
      f[i] = f[i-1] + f[i-2]; 
  return f[n]; 
} 
  
int main (){ 
  int n;
  cout << "what fib number would you like?" << endl;
  cin >> n;
  cout<< fib_dp(n) << endl;
  return 0; 
} 