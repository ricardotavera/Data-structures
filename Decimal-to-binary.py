def binary(n):
  
  if n==1:
      print(1, end =" ")
  else :
     binary(int(n/2))
     print(n%2, end =" ")
     
     

n = int(input("Type number "))

binary(n)

