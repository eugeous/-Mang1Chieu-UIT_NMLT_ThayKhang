#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[], int&);
int ViTriDuongDau(float[], int);
float TongCon(float[], int, int, int);
int ktCon(float a[], int, int, int);
void DuongLonNhat(float[], int);


int main()
{
	float a[100];
	int n;
	Nhap(a, n);
	cout << "\n Day con toan duong co tong max cua mang co (vi tri) va (so phan tu) la: ";
	DuongLonNhat(a, n);
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

int ktCon(float a[], int n, int vt, int l)
{
	int flag = 1;
	for (int i = 0; i <= l - 1; i++)
		if (a[vt + i] <= 0)
			flag = 0;
	return flag;
}

int ViTriDuongDau(float a[], int n)
{
	for (int i = 0; i < n; i++)
		if (a[i] > 0)
			return i;
	return -1;
}

void DuongLonNhat(float a[], int n)
{
	int vtd, vtc;
	int vt = ViTriDuongDau(a, n);
	if (vt == -1)
	{
		vtd = vtc = -1;
		return;
	}
	int smax = a[vt];
	vtd = vtc = vt;
	for (int l = 1; l <= n; l++)
		for (int vt = 0; vt <= n - l; vt++)
			if (ktCon(a, n, vt, l) == 1 && TongCon(a, n, vt, l) > smax)
			{

				vtd = vt;
				vtc = vt + l - 1;
				smax = TongCon(a, n, vt, l);
				cout << "a[" << vt << "]" << setw(6) << vtc;
				return;
			}

}