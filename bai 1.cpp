#include <iostream>

#define MAX 100
using namespace std;
// This function prompts the user to enter a number within a specified range.
//
// Parameters:
// - s: A string that is displayed to the user as a prompt to enter a number.
// - min: The minimum value that the user is allowed to enter.
// - max: The maximum value that the user is allowed to enter.
//
// Returns:
// - The number that the user entered.
int NhapSoNguyen(string s, int min, int max)
{
	// Variable to store the user's input.
	int n;

	// Loop until the user enters a valid number within the specified range.
	do
	{
		// Display the prompt to the user.
		cout << s;

		// Read the user's input.
		cin >> n;

		// Check if the user entered a number outside the specified range.
		if (n < min || n > max)
		{
			// Display an error message if the user entered an invalid number.
			cout << "Nhap sai, nhap lai" << endl;
		}
		// Loop again if the user entered an invalid number.
	} while (n < min || n > max);

	// Return the valid number that the user entered.
	return n;
}

// a khai bao
//...
// b nhap danh sach
void nhapDS(int a[], int &n)
{
	n = NhapSoNguyen("Nhap n phan tu: ", 1, 100);
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "] = ";
		cin >> a[i];
	}
}
// c xuat danh sach
void xuatDS(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}
// Function: search
// Description: This function searches for a given element in an array.
// Parameters:
// - a: The array to be searched.
// - n: The size of the array.
// - x: The element to be searched for.
// Return: The index of the element if it is found, -1 otherwise.
// Algorithm:
// - Initialize a variable i to 0.
// - Loop until i is less than n.
//   - If the element at index i in the array is equal to x, return i.
//   - Increment i by 1.
// - After the loop, if no element is found, return -1.
int search(int a[], int n, int x)
{
	// Initialize a variable i to 0.
	for (int i = 0; i < n; i++)
	{
		// Check if the element at index i in the array is equal to x.
		if (a[i] == x)
		{
			// If the element is found, return its index.
			return i;
		}
	}
	// If no element is found, return -1.
	return -1;
}
// e add last
void addLast(int a[], int &n, int x)
{
	a[n] = x;
	n++;
}
// f xoa phan tu cuoi
void delLast(int a[], int &n)
{
	a[n - 1] = 0;
	n--;
}
// g xoa phan tu tai vi tri index
void delElement(int a[], int &n, int vt)
{
	if (n == 1)
	{
		n--;
	}
	else
	{
		for (int i = vt; i < n; i++)
		{
			a[i] = a[i + 1];
		}
		n--;
	}
}
// h them phan tu tai vi tri index
void addElement(int a[], int &n, int vt, int x)
{
	for (int i = n; i >= vt; i--)
	{
		a[i] = a[i - 1];
	}
	a[vt] = x;
	n++;
}

// This function searches for a given element 'x' in the array 'a' of size 'n'
// If the element is found, it is deleted from the array and the function returns 1
// If the element is not found, the function returns 0
// The size of the array 'n' is updated accordingly
int searchAndDel(int a[], int &n, int x)
{
	// Iterate through the array 'a'
	for (int i = 0; i < n; i++)
	{
		// If the current element is equal to the target element 'x'
		if (a[i] == x)
		{
			// Delete the element by calling the function 'delElement'
			// Pass the array 'a', the size 'n', and the index 'i' of the element to be deleted
			delElement(a, n, i);

			// Return 1 to indicate that the element was found and deleted
			return 1;
		}
	}

	// If the element was not found, return 0
	return 0;
}
int main()
{
	int a[MAX];
	int n;
	nhapDS(a, n);
	xuatDS(a, n);
	/*cout << "=========TIM KIEM=======\n";
	int x;
	cout << "Nhap phan tu can tim: ";
	cin >> x;
	cout << "Vi tri phan tu: " << search(a, n, x) << endl;*/
	addLast(a, n, 10);
	xuatDS(a, n);
	delElement(a, n, 2);
	addElement(a, n, 2, 100);
	xuatDS(a, n);
	cout << "========================\n";
	if (searchAndDel(a, n, 1) == 1)
	{
		xuatDS(a, n);
	}
	return 1;
}