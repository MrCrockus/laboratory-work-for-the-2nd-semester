#include <iostream>
#include <cmath>
#include <iomanip>
#include <map>
#include <stdio.h>

using namespace std;

void Printmap(map <float, float> m) {
    for (auto i : m) cout  << setprecision(2) << i.first   << setw(10)  << fixed  << i.second << endl;
}

int main()
{
    float xmin = -1;
    float a;
    float xmax = 1;
    float dx = 0.25;
    const float pi = 3.14;
    map <float, float> mp;
    int n;
    cout <<"Table of function value calculations: arcctgx ( -1 <= x <= 1)" << endl;
    cout << "Enter the accuracy: ";
    float N;
    cin >> N;
    cout << endl;
    float x;
    cout << setw(25) << "values of function with step = 0.25\n";
    cout<<endl;
    cout  << setw(2) << "X" << setw(12) << "F(x)" << endl;
    float summ;
    for (x = xmin; x <= xmax; x += dx) {
        summ = 0;
        for (n = 0; n <= 100; n++) {
            if (abs(((pow((-1), (n + 1)) * pow(x, ((2.0 * n) + 1))) / ((2.0 * n) + 1))) <= N) break;
            summ = summ + ((pow((-1), (n + 1)) * pow(x, ((2.0 * n) + 1))) / ((2.0 * n) + 1));
          } 
        summ = summ + (pi / 2);
        mp[x] = summ;
    }
   Printmap(mp);
}


