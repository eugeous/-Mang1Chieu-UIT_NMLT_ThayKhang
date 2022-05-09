#include <iostream>
using namespace std;

void Nhap(float[], int&);
float LonNhat(float[], int);
float NhoNhat(float[], int);
void TimDoan(float[], int);

int main()
{
	float a[100];
	int n;
	Nhap(a, n);
	TimDoan(a, n);
	return 1;
}

void Nhap(float a[], int& n)
{
	do
	{
		cout << "Nhap so phan tu mang: ";
		cin >> n;
		if (n < 3)
			cout << "Nhap lai" << endl;
	} while (n < 3);
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "]: ";
		cin >> a[i];
	}
}

float LonNhat(float a[], int n)
{
	float lc = a[0];
	for (int i = 0; i < n; i++)
		if (a[i] > lc)
			lc = a[i];
	return lc;
}

float NhoNhat(float a[], int n)
{
	float lc = a[0];
	for (int i = 0; i < n; i++)
		if (a[i] < lc)
			lc = a[i];
	return lc;
}

void TimDoan(float a[], int n)
{
	float x, y;
	x = NhoNhat(a, n);
	y = LonNhat(a, n);
	cout << "\nDoan [x,y] chua toan bo cac gia tri cua mang la: [" << x << "," << y << "]";
}



