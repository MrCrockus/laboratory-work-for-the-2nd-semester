def Evklid(a,b):
    X = [a,0]
    Y = [b,1]
    Q = 1
    q = 0
    c = 0
    q = 1
    while Q != 0:
        Q = X[0] % Y[0]
        q = round(X[0] / Y[0], 0)
        if Q == 0:
            z = c
        T = [X[0] % Y[0], X[1] - (q * Y[1])]
        c = T[1]
        X = Y
        Y = T
    if z < 0 :
        z += a
    return z
def encrypt(message, m):
    z = ""
    for i in message:
        x = ord(i) - m
        z += chr(x)
    return z
def mod(number, degree, p):
    degree = round(degree % (p - 1))
    number = round(number % p)
    result = 1
    i = 1
    for i in range(degree):
     result *=number
     result = result % p
    return result
def decrypt(message, m):
    z = ""
    for i in message:
        x = ord(i) + m
        z += chr(x)
    return z
    



print("Enter a prime number:")
p = int(input())
print("Enter key for user A:")
cA = int(input())
dA = Evklid(p-1, cA)
print("Enter key for user B:")
cB = int(input())
dB = Evklid(p-1, cB)
print("Enter secret base number: ")
m = int(input())
print ("Enter the message you want to encrypt: ")
message = input()
encrypted = encrypt(message, m)
print("\nEncrypted message: ", encrypted)
first = mod(m,cA,p)
second = mod(first,cB,p)
third = mod(second,dA,p)
fourth = mod(third,dB,p)
print ("\nA -> B: ", first, "\nB -> A: ", second, "\nA -> B: ", third, "\nB decrypted and get: ", fourth)
print("In theory, the value deciphered by B should coincide with m, lets chek it: ", fourth, " == ", m)
print("\nDecrypted message: ", decrypt(encrypted, fourth))