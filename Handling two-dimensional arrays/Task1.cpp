

#include <iostream>
using namespace std;

bool shag(short y, short x, bool** arr, short& m, short& n)
{
    if (y == m - 1 && x == n - 1) return 1;
    arr[y][x] = 1;
    bool result1 = 0, result2 = 0, result3 = 0, result4 = 0;

    if (y - 1 >= 0)
        if (arr[y - 1][x] == 0)
            result1 = shag(y - 1, x, arr, m, n);

    if (y + 1 < m)
        if (arr[y + 1][x] == 0)
            result2 = shag(y + 1, x, arr, m, n);

    if (x - 1 >= 0)
        if (arr[y][x - 1] == 0)
            result3 = shag(y, x - 1, arr, m, n);

    if (x + 1 < n)
        if (arr[y][x + 1] == 0)
            result4 = shag(y, x + 1, arr, m, n);

    return (result1 || result2 || result3 || result4);
}

int main()
{
    short m, n;
    cout << "Enter the number of lines: ";
    cin >> m;
    cout << "\nEnter the number of columns: ";
    cin >> n;
    srand(time(NULL));
    bool** arr = new bool* [m];
    for (short i = 0; i < m; i++)
        arr[i] = new bool[n];

    for (short i = 0; i < m; i++)
        for (short j = 0; j < n; j++)
            arr[i][j] = rand() % 2;
    arr[0][0] = 0;
    arr[m - 1][n - 1] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "   " << arr[i][j];
        }
        cout << endl;
    }
    cout << (shag(0, 0, arr, m, n) ? "YES" : "NO");
    return 0;
}