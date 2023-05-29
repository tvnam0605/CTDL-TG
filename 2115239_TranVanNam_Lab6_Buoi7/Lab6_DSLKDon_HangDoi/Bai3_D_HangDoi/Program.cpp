#include <conio.h>
#include <iostream>
#include <fstream>

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
	char filename[MAX];
	QUEUE q;
	CreatQueue(q);
	cout << "\nNhap file : ";
	cin >> filename;
	TapTin_Queue(filename, q);
	cout << "\nDanh sach ban dau: \n";
	XuatQueue(q);
	Radix(q);
	cout << "\nSau khi sap xep: \n";
	XuatQueue(q);
}