import math
def printed(vector, q):
   print (vector[0], "\t\t\t" , vector[1],"\t\t", vector[2], "\t\t", q)

def fn1(a,b):
    X = [a,1,0]
    Y = [b,0,1]
    Q = 1
    q = 0
    c = 0
    printed(X,q)
    printed(Y,q)
    q = 1
    while Q != 0:
        Q = X[0] % Y[0]
        q = math.floor(X[0] / Y[0])
        if Q == 0:
            z = c
        T = [X[0] % Y[0], X[1] - (q * Y[1]), X[2] - (q * Y[2])]
        c = T[2]
        printed(T,q)
        X = Y
        Y = T
    if z < 0 :
        z += a
    print("\n\t Answer:", b, "^(-1) mod ", a, " = ", z)


print("The program finds the value of the expression: z = b^(-1) mod a")
print("Enter a: ")
a = int(input())
print("Enter b: ")
b = int(input())
print("\n")
print("Remains", "\t\t X","\t\t Y", "\t\t q")
fn1(a,b)