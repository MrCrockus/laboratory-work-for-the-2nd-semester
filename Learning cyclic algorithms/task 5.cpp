

#include <iostream>
#include <vector>
using namespace std;

int mod(int number, int degree, int p) {
    degree = degree % (p - 1);
    number = number % p;
    int result = 1;
    for (int i = 1; i <= degree; i++) {
        result *= number;
        result = result % p;
    }
    return result;
}
int Evklid(int a, int b) {
    vector<int> X = { a, 0 };
    vector<int> Y = { b, 1 };
    int Q = 1;
    int q = 1;
    int  c = 0;
    int z;
    
    while (Q != 0)
    {
        Q = X[0] % Y[0];
        q = X[0] / Y[0];

        if (Q == 0) z = c;
        vector <int> T = { X[0] % Y[0], X[1] - q * Y[1] };
        c = T[1];
        X = Y;
        Y = T;

    }
    if (z < 0) z += a;
    return z;
}
string encrypt(string message, int m) {
     for (int i = 0; message[i] != 0; i++) {
         message[i] = (char)(message[i]-m);
    }
     return message;
}
string decrypt(string message, int k) {
    for (int i = 0; message[i] != 0; i++) {
        message[i] = (char)(message[i] + k);
    }
    return message;
}

int main()
{
    cout << "Enter a prime number: ";
    int p;
    cin >> p;
    cout << "\nEnter key for user A: ";
    int cA;
    cin >> cA;
    int dA = Evklid(p - 1, cA);
    cout << "\nEnter key for user B: ";
    int cB;
    cin >> cB;
    int dB = Evklid(p - 1, cB);
    cout << "\nEnter secret base number: ";
    int m;
    cin >> m;
    cout << "\nEnter the message you want to encrypt: ";
    string message;
    cin >> message;
   string encrypted =  encrypt(message, m);
   cout << "\nEncrypted message: " << encrypted << endl;
   int first = mod(m, cA, p); // A -> B
   cout << "\n A --> B : " << first << endl;
   int second = mod(first, cB, p); // B -> A
   cout << "B --> A : " << second << endl;
   int third = mod(second, dA, p); // A -> B
   cout << "A --> B : " << third << endl;
   int fourth = mod(third, dB, p); // B decrypted
   cout << "B decrypted and get:  " << fourth << endl;
   cout << "\nIn theory, the value deciphered by B should coincide with m, lets chek it: " << fourth << " == " << m << endl;
   cout << "\n Decrypted message: " << decrypt(encrypted, fourth) << endl;
}

