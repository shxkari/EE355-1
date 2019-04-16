#include <iostream>
#include <stdio.h>


int main() {
   int money, orphan;
   int z = 0;
   std::cout << "How much money do you wanna donate? " ;
   std::cin >> money;
   std::cout << "how many orphans will you be donating this money to? " ;
   std::cin >> orphan;
   
   int array [orphan];

   while (money!=0) 
   {
      for (int i = 1; i < (orphan+1); i++) 
      {
         if (z == 0) 
         {
            if (money >= i)
            {
               money = money - i;
               array[i-1] = i;              
            }
            else 
            {
               if (money!=0) 
               {
                  array[i-1] = money;
                  money=0;
               }
               else
                  array[i-1] = 0;
            }
         }
         else 
         {
            if (money >= (i+z)) 
            {
               money = money - (i+z);
               array[i-1] = i + z + array[i-1];
            }
            else 
            {
               if (money!=0) 
               {
                  array[i-1] = money;
                  money = 0;
                  break; 
               }
               else
                  break;
            }
         }
         }
         z++;
      }
   int i=0;
   for (int k = 1; k < (orphan+1) ; k++) 
   {
      std::cout << "Orphan #" << k << " gets " << array[i] << " dollars\n";
      i++;
   }
   return 0; 
}      
            
          
          
               
            
