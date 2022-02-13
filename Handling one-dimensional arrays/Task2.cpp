#include <iostream>
using namespace std;

int main() {
    cout << "Enter number of students: ";
    int n;
    cin >> n;
    int* A = new int[n];
    cout << "\nEnter the height of each student: ";
    for (int i = 1; i <= n; i++) {
        cout << "\nStudent  N" << i << " : ";
        cin >> A[i-1];
    }
    cout << "\nEnter the height of a late student: ";
    int height;
    cin >> height;
    int number = 1;
    for (int i = 0; i <= n; i++) {
        if (height <= A[i]) number++;
    }
    cout << "\nThe latecomer's number will be: " << number;
}

