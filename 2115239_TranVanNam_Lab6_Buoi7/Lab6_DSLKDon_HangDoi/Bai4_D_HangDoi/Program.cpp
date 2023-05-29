#include <iostream>
#include <conio.h>
#include <iomanip>
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
	QUEUE q;
	CreatQueue(q);
	int m;
	char filename[100];
	TapTin_Queue(q);
	cout << endl << "Nhap vao so ngay truc: ";
	cin >> m;
	cout << endl << "Danh sach ban dau: \n";
	XuatQueue(q);
	Sap_Tang_TTTruc(q);
	cout << endl << "Danh sach sau khi sap xep: \n";
	XuatQueue(q);
	cout << endl << "Lich truc: \n";
	XuatLichTruc(q, m);
}