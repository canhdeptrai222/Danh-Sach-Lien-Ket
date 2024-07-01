#include <iostream>

#define MAX 100
using namespace std;

void nhapDaThuc(int a[], int &n)
{
	cout << "Nhap so bac cua da thuc: ";
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		cout << "Nhap he so: ";
		cin >> a[i];
	}
}

void xuatDaThuc(const int a[], const int n)
{
	cout << a[0] << " + " << a[1] << "x";
	for (int i = 2; i <= n; i++)
	{
		if (a[i] != 0)
			cout << " + " << a[i] << "x^" << i;
	}
	cout << endl;
}

int solveDaThuc(int a[], int n, int x)
{
	int res = 0;
	int xMuN = 1;
	for (int i = 0; i <= n; i++)
	{
		res += (a[i] * xMuN);
		xMuN *= x;
	}
	return res;
}

int* sum2DaThuc(int a[], int n, int b[], int m, int &h)
{
	int* c;
	if (n > m)
		h = n;
	else
		h = m;
	c = new int[h + 1];
	for (int i = 0; i <= h; i++)
	{
		c[i] = 0;
	}
	for (int i = 0; i <= n; i++)
	{
		c[i] = a[i];
	}
	for (int i = 0; i <= m; i++)
	{
		c[i] += b[i];
	}
	return c;
}
// 0   1    2      3
// 1 + 2x^1 + 3x^2 + 4x^3
// 2 + 3x^1 + 4x^2 + 5x^3
// 3 + 5x^1 + 7x^2 + 9x^3

int main()
{
	int a[MAX];
	int n;
	nhapDaThuc(a, n);
	int b[MAX];
	int m;
	nhapDaThuc(b, m);
	xuatDaThuc(a, n);
	xuatDaThuc(b, m);
	int h;
	int* c = sum2DaThuc(a, n, b, m, h);
	xuatDaThuc(c, h);
	delete[]c;
	c = NULL;
	return 1;
}