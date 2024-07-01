#include <iostream>

#define MAX 100
using namespace std;
int NhapSoNguyen(string s, int min, int max) {
	int n;
	do {
		cout << s;
		cin >> n;
		if (n < min || n > max) cout << "Nhap sai, nhap lai" << endl;
	} while (n < min || n > max);
	return n;
}

//a khai bao
void nhapDS(int a[], int& n) {
	n = NhapSoNguyen("Nhap n phan tu: ", 1, 100);
	for (int i = 0; i < n; i++) {
		cout << "Nhap a[" << i << "] = ";
		cin >> a[i];
	}
}
//c xuat phan tu
void xuatDS(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}cout << endl;
}
//b them phan tu
void addElement(int a[], int& n, int vt, int x) {
	for (int i = n; i >= vt; i--) {
		a[i] = a[i - 1];
	}
	a[vt] = x;
	n++;
}
void delElement(int a[], int& n, int vt) {
	if (n == 1) {
		n--;
	}
	else {
		for (int i = vt; i < n; i++) {
			a[i] = a[i + 1];
		}
		n--;
	}
}
//d linear search
int linearSearch(int a[], int n, int x) {
	for (int i = 0; i < n; i++) {
		if (a[i] == x)
			return i;
	}return -1;
}
void swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}
void interChangeSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}
//sort tnag dan truoc khi tim kiem
int binarySearch(int a[], int n, int x) {
	int left = 0;
	int right = n - 1;
	while (left <= right) {
		int mid = (right + left) / 2;
		if (a[mid] == x)
			return mid;
		else if (a[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}
//sort first
int searchAndDel(int a[], int n, int x) {
	int left = 0;
	int right = n - 1;
	while (left <= right) {
		int mid = (right + left) / 2;
		if (a[mid] == x) {
			delElement(a, n, x);
			return 1;
		}
		else if (a[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return 0;
}
int* concate2Arr(int a[], int b[], int n, int m) {
	int* c = new int[n + m];
	int count = 0;
	for (int i = 0; i < n; i++) {
		c[count++] = a[i];
	}
	for (int j = 0; j < m; j++) {
		c[count++] = b[j];
	}
	interChangeSort(c, n + m);
	return c;
}
int main() {
	int a[MAX];
	int n;
	nhapDS(a, n);
	xuatDS(a, n);
	/*cout << "=========LINEAR SEARCH=======\n";
	cout << linearSearch(a, n, 4) << endl;
	cout << "=========BINARY SEARCH========\n";
	sort first
	interChangeSort(a, n);
	xuatDS(a, n);
	cout << binarySearch(a, n, 4) << endl;*/
	int b[MAX];
	int m;
	nhapDS(b, m);
	xuatDS(b, m);
	cout << "=======SORT 2 DANH SACH=======\n";
	interChangeSort(a, n);
	xuatDS(a, n);
	interChangeSort(b, m);
	xuatDS(b, m);
	cout << "=========DANH SACH SAU KHI GOP======\n";
	int* c = concate2Arr(a, b, n, m);
	xuatDS(c, n + m);
	delete[]c;
	c = NULL;
	return 1;
}