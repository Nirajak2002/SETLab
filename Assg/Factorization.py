# number=1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
# number=number+1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
# print(number)
# python program to print prime factors

import math
def primefactors(n):
   #even number divisible
   while n % 2 == 0:
      print (2),
      n = n / 2
   
   #n became odd
   for i in range(3,int(math.sqrt(n))+1,2):
    
      while (n % i == 0):
         print (i)
         n = n / i
   
   if n > 2:
      print (n)

n = 86389956293761485464
primefactors(n)
