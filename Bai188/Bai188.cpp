#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[], int&);
float TongCon(float[], int, int, int);
void ConLonNhat(float[], int);


int main()
{
	float a[100];
	int n;
	Nhap(a, n);
	cout << "\n Day con co tong max cua mang co (vi tri dau) va (vi tri cuoi) la: ";
	ConLonNhat(a, n);
	return 1;
}

void Nhap(float a[], int& n)
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

float TongCon(float a[], int n, int vt, int l)
{
	float s = 0;
	for (int i = 0; i <= l - 1; i++)
		s = s + a[vt + i];
	return s;
}

void ConLonNhat(float a[], int n)
{
	int vtd, vtc;
	vtd = vtc = 0;
	float sln = a[0];
	for (int l = 1; l <= n; l++)
		for (int vt = 0; vt <= n - l; vt++)
			if (TongCon(a, n, vt, l) > sln)
			{
				vtd = vt;
				vtc = vt + l - 1;
				sln = TongCon(a, n, vt, l);
			}
	cout << "a[" << vtd << "] to " << setw(6) << "a[" << vtc << "]";
}
