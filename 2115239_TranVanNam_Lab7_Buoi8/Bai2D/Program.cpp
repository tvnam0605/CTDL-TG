//Cac thu vien
#include <iostream>
#include <fstream>
#include<conio.h>
#include <math.h>
#include <iomanip>
using namespace std;
#include "Header.h"
#include "Thuvien.h"

void ChayChuongTrinh();
//============================================
void ChayChuongTrinh()
{
	
	
	//Dieu khien menu
	
}
int main()
{
	int kq;
	LLIST l;
	char filename[MAX];
	//Dieu khien viec chon file cho dung
	do
	{
		system("CLS");
		cout << "\nNhap ten tap tin, filename = ";
		_flushall();
		cin >> filename;
		if (!File_LLIST(filename, l))
		{
			cout << "\nLoi mo file ! nhap lai\n";
			_getch();
		}
		else
		{
			cout << "\nDu lieu tap tin " << filename << " da duoc chuyen vao DSLKDV l"
				<< "\nNhan phim bat ky de tiep tuc";
			_getch();
			break;
		}
	} while (1);
	
	cout << "\nXuat ky binh\n";
	Output_Llist(l);
	CryForHelp(l);

	system("Pause");
	ChayChuongTrinh();
	return 1;
}