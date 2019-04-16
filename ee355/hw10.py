
def print_combinations(array, k): 
    n = len(array)  
    print_combinations_rec(array, "", n, k) 


def print_combinations_rec(array, pre, n, k): 
    if (k == 0) : 
        print(pre) 
        return

    for i in range(n): 
        pre_new = pre + str(array[i])
        print_combinations_rec(array, pre_new, n, k - 1) 
  
   
print("Test 1") 
set1 = [1, 2] 
k = 3
print_combinations(set1, k) 
  
print("Test 2") 
set2 = [1, 2, 3] 
k = 2
print_combinations(set2, k)

print("Test 3")
set3 = [1,4]
k = 3
print_combinations(set3, k)