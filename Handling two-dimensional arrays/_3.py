N = 4

exp = 3

a = [[0.87, -0.04, 0.21, -18, -1.24],

[ 0.25, -1.23, -0.19, -0.09, 1.08],

[-0.21, -0.19, 0.8, -0.13, 2.56],

[ 0.15, -1.31, 0.06, 1.08, 0.87]]

x = [0,0,0,0,0]

print("Метод Гаусса с выбором главного элемента: ")

for k in range (0,N):

 aa = abs(a[k][k])

 i = k

 for m in range (k+1,N):

  if (abs(a[m][k]) > aa):

   i = m

   aa = abs(a[m][k])

 if (aa==0):

  break

 if (i!=k):

  for j in range (k,N+1):

   bb = a[k][j]

   a[k][j] = a[i][j]

   a[i][j] = bb

 aa = a[k][k]

 a[k][k]=1

 for j in range (k+1,N+1):

  a[k][j] = a[k][j] / aa;

 for i in range (k+1,N):

  bb = a[i][k]

  a[i][k] = 0

  if (bb!=0):

   for j in range (k+1,N+1):

    a[i][j] = a[i][j] - bb*a[k][j]

i = N-1

j = N

while (i >= 0 ):

 x[i] = 0

 aa = a[i][N]

 j=N

while (j > i):

 aa = aa - a[i][j]*x[j]

 j-=1
x[i] = aa

i-=1

print( "Решение системы:" )

for i in range (0,N):

 print("x(",end='')

 print(i+1,end='')

 print(") = ",end='')

 print( round(x[i],3))