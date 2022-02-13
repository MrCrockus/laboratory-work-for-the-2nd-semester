import math 
x = -7
dx = 1
i = 0
values = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18]
print("\t\t Table of function value calculations ")
print("Step", "\t\t     Argument (x)", "\t\tFunction value")
for element in values:
    if x <= 3 : values[i] = 3;
    if -3 < x <= 3: values[i] = (6.0 - math.sqrt(36.0 - (4.0 * x * x)))/2.0
    if 3 < x <= 6: values[i] = 9 - (2 * x)
    if 6 < x <= 11: values[i] = x - 9;
    print (dx, "\t\t\t", x, "\t\t\t", values[i])
    i += 1
    x += 1
    
