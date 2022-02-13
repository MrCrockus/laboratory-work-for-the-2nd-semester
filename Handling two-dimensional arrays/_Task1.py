import random

def shag(y,x,A, m, n):
    if ((y == m-1) and (x == n-1)): 
        return 1
    A[y][x] = 1
    result1 = 0
    result2 = 0
    result3 = 0
    result4 = 0
    if(y-1 >=0):
        if(A[y-1][x] == 0):
            result1=shag(y-1,x,A,m,n)
    if (y + 1 < m):
        if (A[y + 1][x] == 0):
            result2 = shag(y + 1, x, A, m, n);

    if (x - 1 >= 0):
        if (A[y][x - 1] == 0):
            result3 = shag(y, x - 1, A, m, n);

    if (x + 1 < n):
        if (A[y][x + 1] == 0):
            result4 = shag(y, x + 1, A, m, n);

    return (result1 or result2 or result3 or result4);



print("Enter the number of lines:")               
M = int(input())
print("Enter the number of columns:")
N = int(input())
A= [0] * M
for i in range(len(A)):
    A[i] = [0] * N

for i in range(len(A)):
    for j in range(len(A[i])):
        A[i][j] = random.randint(0,1)

A[0][0] = 0
A[M-1][N-1] = 0

for i in range(len(A)):
    for j in range(len(A[i])):
        print(A[i][j], end= "   ")
    print()
print()
print()
z = shag(0,0,A,M,N)
if (z == 1):
    print("YES")
if (z == 0):
    print("NO")