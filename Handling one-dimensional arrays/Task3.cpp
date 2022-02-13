#include <iostream>
#include <random>
#include <vector>
#include <ctime>
#include <cmath>

using namespace std;
const double eps = 0.1e-5;

void Get_Arr(int msg[], int size, int max_select)
{
	srand(time(NULL));
	minstd_rand0 generator(rand()); 
	for (int i = 0; i <= size; i++)
	{
		msg[i] = generator() % max_select + 1;
	}
}
double func(double x)
{
	return exp(-x * x / 2);
}
double simpsonIntegr(double a, double b)
{
	return ((b - a) / 6) * (func(a) + 4 * func((a + b) / 2) + func(b));
}
double LaplasFunction(double x, double eps = ::eps)
{
	double a = 0.0;
	double b = x;
	double tst, tst1, incr;
	unsigned int c = 2;
	tst1 = simpsonIntegr(a, b);
	do {
		tst = tst1;
		tst1 = 0;
		incr = (b - a) / c;
		for (unsigned int i = 0; i < c; ++i)
		{
			tst1 = tst1 + simpsonIntegr(a + incr * i, a + incr * (i + 1));
		}
		c += 1;
	} while (fabs(tst - tst1) >= eps);
	return tst1;
}
int cou(int msg[], int size, int n, int k)
{
	int i = 0;
	int cnt = 0;
	for (i; i < k; i++)
	{
		if (msg[i] <= k && msg[i] >= n) cnt++;
	}
	k += 4;
	n += 4;
	return cnt;
}

double hi(int msg[], int size)
{
	double M = 51, A = 0, sigma = M / 3;
	cout << "viborka iz " << size << " elementov" << endl;

	int Vn = 0;
	double Vexp, hiqs = 0;
	int n = 1, k = 4;
	for (int i = 1; i < 25; i++)
	{
		Vn = cou(msg, size, n, k);
		Vexp = (LaplasFunction((k - M) / sigma) - LaplasFunction((n - M) / sigma)) * size;
		hiqs += pow((Vn - Vexp), 2) / Vexp;
		n += 4;
		k += 4;
		Vn = 0;
	}
	return hiqs;
}

double rlmo(int msg[], int size)
{
	int i = 1;
	double e = 0;
	double x = 0;
	for (i; i <= size; i++)
	{
		x += (double)msg[i];
	}
	e = x / size;
	return e;
}



int main()
{
	double f = 36.41503;
	int n = 100;
	int* Arr;
	Arr = new int[50];
	Get_Arr(Arr, 50, n);
	cout << "pri raspredelenii 0.05 ";
	if (hi(Arr, 50) > f) cout << "ne norm" << endl;
	else cout << "norm";
	cout << "ozhidaemoe = " << " 51 " << endl;
	cout << "received = " << rlmo(Arr, 50) << endl << endl;

	Arr = new int[100];
	Get_Arr(Arr, 100, n);
	cout << "pri raspredelenii 0.05 ";
	if (hi(Arr, 100) > f) cout << "ne norm" << endl;
	else cout << "norm";
	cout << "ozhidaemoe = " << " 51 " << endl;
	cout << "received = " << rlmo(Arr, 100) << endl << endl;

	Arr = new int[1000];
	Get_Arr(Arr, 1000, n);
	cout << "pri raspredelenii 0.05 ";
	if (hi(Arr, 1000) > f) cout << "ne norm" << endl;
	else cout << "norm";
	cout << "ozhidaemoe = " << " 51 "<< endl;
	cout << "received = " <<  rlmo(Arr, 1000) << endl << endl;
}