print("The program calculates: a^b mod p")
print ("Enter the number: ")
a = int(input())
print("Enter degree: ")
b = int(input())
print("Enter a prime number")
p = int(input())
b = b % (p - 1)
a = a % p
result = 1
i = 1
for i in range(b):
    result *=a
    result = result % p
print("Answer: a^b mod p = ", result)