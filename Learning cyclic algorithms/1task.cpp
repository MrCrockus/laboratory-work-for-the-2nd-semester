// 1task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

void printmap(map <float, float> m) {
    for (auto i : m) cout << setw(6)<< i.first <<  setw(38) << i.second << endl;
}

int main()
{
    int xmin = -7;
    int xmax = 11;
    float x;
    float dx;
    cout << "Enter dx: ";
    cin >> dx;
    int R = 3;
    map <float, float> mp;
    cout << setw(41)<< "\nvalues of function with step dx = " << dx << endl << endl;
    cout << setw(6)<<"X" << setw(39) << "F(x)" << endl << endl;
    for (x = xmin; x <= xmax; x += dx) {
        if (x <= -3)              mp[x] = 3;
        if ((x > -3) && (x <= 3)) mp[x] = (6.0 - sqrt(36.0 - (4.0 * x * x))) / 2.0; 
        if ((x > 3) && (x <= 6))  mp[x] = 9 - (2 * x);
        if ((x > 6) && (x <= 11)) mp[x] = x - 9;
    }
    printmap(mp);
}

