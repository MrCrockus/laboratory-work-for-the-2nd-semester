import math
PI = 3.14
dx = 0.25
x = -1.0
n = 0
i = 0
values = [0, 1, 2, 3, 4, 5, 6, 7, 8]
print ("\t\t Table of function value calculations: arcctgx ( -1 <= x <= 1)")
print ("Enter the accuracy: ")
N = int(input())
print("\n")
print("Step(dx)", "\t\tX", "\t\t F(x)", "\t\tAccuracy")
for element in values:
    summ = 0
    for n in range(N + 1):
        summ = summ + ((pow((-1), (n + 1)) * pow(x, ((2.0 * n) + 1))) / ((2.0 * n) + 1))
    summ = summ + (PI / 2)
    values[i] = round (summ, 2)
    print(dx, "\t\t     ", x, "\t\t", values[i], "\t\t ", n)
    i += 1
    x += dx
