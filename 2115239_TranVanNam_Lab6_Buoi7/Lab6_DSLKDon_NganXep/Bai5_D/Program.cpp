#include <iostream>
#include <conio.h>

using namespace std;

#include "Thuvien.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	_getch();
	return 1;
}

void ChayChuongTrinh()
{
	char Chuoi_Nhap[MAX];
	int kq;
	cout << "\nNhap hau to : ";
	gets_s(Chuoi_Nhap);
	kq = Tinh_BT_HauTo(Chuoi_Nhap);
	cout << "\nKet qua: " << kq;
}
