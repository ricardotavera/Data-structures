

def invert(A, k, i):
 if  i==k or k==i+1:
   return 0
 else :
   t = A[k]
   A[k] = A[i]
   A[i] = t

   invert(A, k+1, i-1)


def fromBack(A,n):
  invert(A,0,n-1)
  return 0

print("Type the amount: ")
n = int(input("Amount: "))
A = []



for x in range(0,n):
  l = int(input("-"))
  A.append(l) 

fromBack(A,n)

for x in A:
  print(x) 

