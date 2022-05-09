#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[], int&);
int DemCon(int[], int, int[], int);

int main()
{
	int a[100], b[100];
	int n, m;
	Nhap(a, n);
	Nhap(b, m);
	cout << "\nSo lan xuat hien cua mang A trong mang B la: " << DemCon(a, n, b, m);
	return 1;
}

void Nhap(int a[], int& n)
{
	do
	{
		cout << "Nhap so phan tu mang: ";
		cin >> n;
		if (n < 0)
			cout << "Nhap lai" << endl;
	} while (n < 0);
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "]: ";
		cin >> a[i];
	}
}

int DemCon(int a[], int n, int b[], int m)
{
	if (n > m)
		return 0;
	int dem = 0;
	for (int vt = 0; vt <= m - n; vt++)
	{
		int flag = 1;
		for (int i = 0; i < n; i++)
			if (a[i] != b[vt + i])
				flag = 0;
		if (flag == 1)
			dem++;
	}
	return dem;
}