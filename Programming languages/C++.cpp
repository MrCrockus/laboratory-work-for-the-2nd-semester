#include <iostream>
using namespace std;

void fn1() {
	cout << "Enter the value of the radius (R) and I will find the length and area of the circle: ";
	int R;
	auto pi = 3.14;
	cin >> R;
	cout << "The lenght of a circle: L = 2 * pi * R = 2 * " << pi << " * " << R << " = " << 2 * pi * R << endl;
	cout << "Are of a circle: S = pi * R * R = " << pi << " * " << R << " * " << R << " = " << pi * R * R << "\n" << endl;
}
// Task №1. Finding the length and area of a circle.

void fn2() {
	error:
	cout << "Enter a positive integer number in the range from 1 to 27 and I will tell you it is my number or not: ";
	int number;
	cin >> number;
	if ((number >= 1) && (number <= 27)) {
		if (number == 7) cout << "This is my number" << endl;
		else cout << "This is not my number \n"; 
		cout << "Want to try again? \n" << "1.Yes  2.No" << endl;
		int tr;
		cin >> tr;
		if (tr == 1) goto error;
		cout << "\n";
	}
	else {
		cout << "Input Error. Please try again.\n";
		goto error;
	}
}
// Task №2. My number.

void fn3() {
	cout << "The program calculates the calue of the difference (-1) ^ (n+1) * n. Where n = 17" << endl;
	int summ = 0;
	for (int n = 1; n <= 17; n++) {
		int power = -1;
		for (int i = 0; i <= n + 1; i++) {                              
			power *= -1;
		}
		int composition;
		composition = power * n;
		summ += composition;
		cout << " (" << composition << ")  + ";
	}
	cout << "(0) = " << summ << endl;
}
// Task №3.

int main()
{
	menu: 
	cout << "Select a task :\n" << "1. Find the length of a circle and the area of a circle of a given radius \n" << "2. My serial number in the journal \n" << "3. Counting the difference \n" << "4. Exit \n" <<endl ;
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		fn1();
		goto menu;
		break;
	case 2: 
		fn2();
		goto menu;
		break;
	case 3:
		fn3();
		goto menu;
		break;
	case 4: 
		return 0;
	default:
		cout << "There is no such function. Select again." << endl;
		goto menu;

	}
}

