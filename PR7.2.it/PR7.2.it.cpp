#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n,const int k, const int Low, const int High);
void Print(int** a, const int n, const int k);
void Sort(int** a, const int n, const int k);
int main()
{
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	int n,k;
	cout << "n = "; cin >> n;
	cout << "k = "; cin >> k;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[k];
	Create(a, n,k ,Low, High);
	Print(a, n,k);
	Sort(a, n, k);
	Print(a, n, k);
	delete[] a;
	return 0;
}
void Create(int** a, const int n,const int k, const int Low, const int High)//n-кількість радків, k-кількість стовпіців
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int n, const int k)
{
	cout << endl;
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < k; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
void Sort(int** a, const int n, const int k)
{
	for (int i = 1; i < n-1; i+=2)
	{
		int imin = 0;
		int imax = 0;
		for (int j = 0; j < k; j++)
		{
			if (a[i][j] < a[i][imin])
				imin = j;
			if (a[i + 1][j] > a[i + 1][imax])
				imax = j;
			
		}
		int temp = a[i][imin];
		a[i][imin] = a[i + 1][imax];
		a[i + 1][imax] = temp;
	}
}
//void Sort(int** a, const int n, const int k, int i) {
//	if (i < n - 1) {
//		int imin = 0;
//		int imax = 0;
//		for (int j = 0; j < k; j++)
//		{
//			if (a[i][j] < a[i][imin])
//				imin = j;
//			if (a[i + 1][j] > a[i + 1][imax])
//				imax = j;
//
//		}
//		int temp = a[i][imin];
//		a[i][imin] = a[i + 1][imax];
//		a[i + 1][imax] = temp;
//		Sort(a, n, k, i + 2);
//	}
//}