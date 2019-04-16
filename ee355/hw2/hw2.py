x = input("How much money do you wanna donate?")
y = input("How many orphans will you be donating this money to?")

k = []
z = 0


while x != 0:
   for i in range(1, y+1):
      if z == 0:
         if x >= i:
            x = x - i
            ins = i 
            k.append(ins)
         else:
            if x != 0:
               ins = x 
               x=0
               k.append(ins)
            else:
               k.append(0)
      else:
         if x >= (i + z):
            x = x -(i+z)
            k[i-1] = i + z + k[i-1]
         else:
            if x != 0:
               k[i-1] = x + k[i-1]
               x=0
               break
            else:
               break
   z += 1
for i in range(1,y+1):
   print("Orphan #%i gets %i dollars" % (i,k[i-1]))
