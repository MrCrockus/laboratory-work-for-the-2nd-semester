#include <iostream>

using namespace std;

int main()
{
    int a, b, p; 
    cout << "Enter the number: ";
    cin >> a;
    cout << "\n" << "Enter degree: ";
    cin >> b;
    cout << "\n" << "Enter a prime number: ";
    cin >> p;
   b %= (p - 1);
    a %= p;

    int result = 1;
    for (int i = 1; i <= b; i++) {
        result *= a;
        result %= p;
    }
    cout <<"\nAnswer: a ^ b mod p = "<< result;
}
