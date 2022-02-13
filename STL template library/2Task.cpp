#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

enum class Schedule
{
    СLASS = 1,
    NEXT,
    VIEW
};
multimap <int, string> plan;
Schedule type;

void Class(int m[], int N, multimap <int, string>& s) {
    int i;
    string yrok;
    cin >> i;
    cin >> yrok;
    if (i <= m[N]) s.emplace(make_pair(i, yrok));
    else exit(0);
}

int Next(int m[], int N, multimap <int, string>& s) {
    int t;
    N++;
    if (N > 12) {
        N = N % 12;
    }
    for (int i = m[N] + 1; i < 32; i++) {
        t = s.count(i);
        if (t != 0) {
            for (int j = 0; j < t; j++) {
                string t = s.find(i)->second; 
                s.emplace(make_pair(m[N] - 1, t)); 
                s.erase(i);
            }
        }
    }
    return N;
}

void View(int m[], int N, multimap <int, string>& s)
{
    int i, y;
    cin >> i;
    auto range = s.equal_range(i);
    if (i <= m[N]) {
        y = s.count(i);
        if (y != 0) {
            cout << "In " << i << " day " << y << " classes in university:" << endl;
            for (auto j = range.first; j != range.second; j++) {
                cout << j->second;
                if (y > 1 && (j++) != range.second) cout << ", ";
            }
            cout << endl;
        }
        else {
            cout << "In " << i << " day we all free" << endl;
        }
    }
    else {
        exit(0);
    }
}

int main() {
    multimap <int, string> s;
    int K, N = 1, type;
    int m[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    cout << "Enter the number of teams: ";
    cin >> K;
    cout << endl;
    cout << "\nFeature List:\n1)CLASS date dicipline \n2)NEXT \n3)VIEW date \n4)EXIT\n\n";
    for (int i = 0; i < K; K--) {
        string slovo;
        cin >> slovo;
        type = 0;
        if (slovo == "CLASS") type = 1;
        if (slovo == "NEXT") type = 2;
        if (slovo == "VIEW")  type = 3;
        if (slovo == "EXIT") return 0;
        switch (Schedule(type)) {
        case Schedule::СLASS: {
            Class(m, N, s);
            break;
         }
        case Schedule::NEXT: {
            Next(m, N, s);
            break;
         }
        case Schedule::VIEW: {
            View(m, N, s);
            break;
         }
        }
    }
    return 0;
}