#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string.h>
#include <string>
#include <fstream>


using namespace std;
#include "2115239_ThuVien.h"
#include "2115239_Menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
	int soMenu = 5, n = 0, menu;
	HocVien a[MAX];
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, a, n);
	} while (menu > 0);
}