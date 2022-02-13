

#include <iostream>
#include <cmath>
using namespace std;

int mod(int number, int degree, int prime) {
	
	degree = degree % (prime - 1);
	number = number % prime;
	int result = 1;
	for (int i = 1; i <= degree; i++) {
		result = result * number;
		result = result % prime;
	}
	return result;
}

int main() {
	cout << "Value finding program: 2^x mod 30803 = 16190" << "\na = 2; p = 30803; b = 16190";
	int a = 2;                         // 3
	int p = 30539;   //30803     // 61   //11
	int b = 28620;   // 16190    // 45    // 5
	int k = sqrt(p) + 1;
	int m = k;
	cout << "\n\nFind the values of m and k" << endl;
	cout << "m = k = " << m << endl;
	cout << "\nFind the values of the series: (a^(i*m)) mod p";
	int A[300];
	for (int i = 1; i < 300; i++) {
		A[i] = mod(a, i * m, p);
		
	}
	int B[300];
	int j = 0;
	int l = 0;
	cout << "\n\nFind the values of the series: (a^(m) * b) mod p";
	for (int i = 1; i < 300; i++) {
		B[i] = mod(a, i, p);
		B[i] *= mod(b, 1, p);
		B[i] = mod(B[i], 1, p);
		
	}
	for (int i = 1; i < 300; i++) {
		for (int v = 1; v < 300; v++) {
			if (A[i] == B[v]) {
				j = i;
				l = v;
			}
			if (j != 0) break;
		}
		if (j != 0) break;
	}
	cout << "\n\nj = " << j << "    l = " << l << endl;
	cout << "Find x: x = j * m - l = " << j * m - l;
}

