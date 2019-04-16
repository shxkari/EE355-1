f = open("input.txt" , "r")
A = []
B = []
k=0
m, n= 8, 8
C = [[0 for x in range(m)] for y in range(n)]
for line in f:                   ### creating the matrices A and B 
   values = line.split()
   if k < 8:
      A.append(values)
      k += 1
   else:
      B.append(values)
      
for i in range(0,8):             ### converting str values of matrix 
   for j in range(0,8):          ### into int values
      A[i][j] = int(A[i][j])
      B[i][j] = int(B[i][j])
      

import time
start = time.time()

for i in range(0,8):             ###matrix multiplcation
   for j in range(0,8):
      for k in range(0,8):
         C[i][j] = C[i][j] + int(A[i][k])*int(B[k][j])
         
end = time.time()
tot = end - start
f = open("output.txt","w+")      ###if i write C as a whole to the txt
for i in range(0,8):             ### it comes out in a different format
   for j in range (0,8):         ### that does not match output_golden
      f.write("%i " % C[i][j])   ### so i am writing each inidivual cell
   f.write("\n")


file = open("output_time.txt", "w+")
file.write("time this program took is: %.11f seconds" % tot)





      
     
