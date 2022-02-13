// 4task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

 void Print(vector <int> v) {
   for (auto i : v) cout << setw(10) << i << setw(10) ;
}

 void fn1(int a, int b)
{
    vector<int> X = { a, 1, 0 };
    vector<int> Y = { b, 0, 1 };
    int Q = 1;
    int q = 1;
    
    int  c = 0;
    

    Print(X);
    cout <<  endl;
    Print(Y);
    int z;
    cout <<  endl;

    while (Q != 0)
    {
        Q = X[0] % Y[0];
        q = X[0] / Y[0];

        if (Q == 0) z = c;
        vector <int> T = { X[0] % Y[0], X[1] - (q * Y[1]), X[2] - (q * Y[2])};
        c = T[2];
        Print(T);
        cout << setw(5) << " | " << setw(5) << q << endl;
        X = Y;
        Y = T;
       
    }

    if (z < 0) z += a;
    cout << "\n\n" << setw(5) << "Answer : " <<b << "^(-1) mod " << a << " = " << z << endl;
}

int main()
{
    cout << "The program finds the value of the expression: z = b^(-1) mod a " << endl;
    int a, b;
    cout << "Enter a: ";
    cin >> a;
    cout << "\nEnter b: ";
    cin >> b;
    cout << endl << setw(13) << "Remains" << setw(7) << "X" << setw(11) << " Y " << setw(10) << " q "<<endl;
    cout << "----------------------------------------" << endl;
    fn1(a, b);
}




