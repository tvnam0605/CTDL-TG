#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

#include "ThuVien.h"

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
	char Chuoi_KQ[MAX];
	cout << "\nNhap trung to : ";
	_flushall();
	gets_s(Chuoi_Nhap, MAX);
	TrungTo_HauTo(Chuoi_Nhap, Chuoi_KQ);
	cout << "\n hau to : ";
	cout << Chuoi_KQ;
}