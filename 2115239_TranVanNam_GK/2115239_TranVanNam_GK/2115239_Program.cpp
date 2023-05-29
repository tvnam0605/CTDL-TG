// MSSV:2115239
//Họ và tên: Trần Văn Nam
#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <string.h>

using namespace std;

#include "2115239_Thuvien.h"
#include "2115239_Menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
	int menu, soMenu = 5;
	LIST CTDL;
	CreatLIST(CTDL);
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, CTDL);
	} while (menu > 0);
}