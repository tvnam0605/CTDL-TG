#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

#include "Header.h"
#include "Thuvien.h"
#include "Menu.h"
void ChayChuongTrinh();
int main()
{
	ChayChuongTrinh();
	return 1;
}
void ChayChuongTrinh()
{
	int menu, soMenu = 7;
	BSTree root = NULL;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, root);
		system("pause");
	} while (menu > 0);
}