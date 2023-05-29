#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <string>

using namespace std;

#include "2115239_Header.h"
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
	int menu, soMenu = 9;
	BSTree root = NULL;
	CreateBST(root);
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(root, menu);
		system("pause");

	} while (menu > 0);
}
