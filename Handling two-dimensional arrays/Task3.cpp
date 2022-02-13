// Task3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
using namespace std;


int main() {
	cout << "The program considers the solution of a system of linear equations: \n" << endl;
	cout << " Mx(1) - 0,04x(2) + 0,21x(3) - 18x(4) = -1,24 \n 0,25x(1) - 1,23x(2) + Nx(3) - 0,09x(4) = P \n -0,21x(1) + Nx(2) + 0,8x(3) - 0,13x(4) = 2,56 \n 0,15x(1) -1,31x(2) + 0,06x(3) + Px(4) = M \n";
	cout << "\nPlease enter M: ";
	double M;
	cin >> M;
	cout << "\nPlease enter N: ";
	double N;
	cin >> N;
	cout << "\nPlease enter P: ";
	double P;
	cin >> P;
	double** a;
	a = new double* [4];
	cout << endl;
	for (int i = 0; i < 4; i++) {
		a[i] = new double[5];
	}
	a[0][0] = M;
	a[0][1] = -0.04;
	a[0][2] = 0.21;
	a[0][3] = -18;
	a[0][4] = -1.24;

	a[1][0] = 0.25;
	a[1][1] = -1.23;
	a[1][2] = N;
	a[1][3] = 0.09;
	a[1][4] = P;

	a[2][0] = -0.21;
	a[2][1] = N;
	a[2][2] = 0.8;
	a[2][3] = -0.13;
	a[2][4] = 2.56;

	a[3][0] = 0.15;
	a[3][1] = -1.31;
	a[3][2] = 0.06;
	a[3][3] = P;
	a[3][4] = M;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			cout << left << setw(10) << a[i][j];
		}
		cout << endl;
	}
	
	double first_element;
	for (int i = 0; i < 4; i++) {
		first_element = a[i][0];
		for (int j = 0; j < 5; j++) {
			a[i][j] = round(a[i][j] / first_element * 1000) / 1000 ;
			if (i > 0) a[i][j] = a[i][j] - a[0][j];
		}
	}
	cout << "\n\nEach line was divided into 1 of their element and subtract 1 line from each line (starting from 2): \n" << endl ;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			cout << left << setw(10) << a[i][j];
		}
		cout << endl;
	}
	for (int i = 1; i < 4; i++) {
		first_element = a[i][1];
		for (int j = 1; j < 5; j++) {
			a[i][j] = round(a[i][j] / first_element * 1000) / 1000;
			if (i > 1) a[i][j] = a[i][j] - a[1][j];
		}
	}
	cout << "\n\nEach line was divided into 2 of their element and subtract 2 line from each line (starting from 3): \n" << endl ;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			cout << left << setw(10) << a[i][j];
		}
		cout << endl;
	}
	for (int i = 2; i < 4; i++) {
		first_element = a[i][2];
		for (int j = 2; j < 5; j++) {
			a[i][j] = round(a[i][j] / first_element * 1000) / 1000;
			if (i > 2) a[i][j] = a[i][j] - a[2][j];
		}
	}
	cout << "\n\nEach line was divided into 3 of their element and subtract 3 line from each line (starting from 4): \n" << endl ;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			cout << left << setw(10) << a[i][j];
		}
		cout << endl;
	}

	double x[4] = { 0,0,0,round((a[3][4] / a[3][3]) * 1000) / 1000 };

	int l = 3;
	for (int i = 2; i >= 0; i--) {
		first_element = a[i][4];
		for (int j = 3; j > 0; j--) {
			if ((j == 0) && (a[i][j] == 1)) break;
			if ((a[i][j] == 1) && (a[i][j - 1] == 0)) break;
			first_element -= a[i][j] * x[j];
		}
		x[l-1] = round(first_element * 1000) / 1000;
		l--;
	}
	
	cout << "\n\nAnswer: ";
	for (int i = 0; i <= 3; i++) {
		cout << "\nx[" << i + 1 << "] = " << x[i];
	}
}


