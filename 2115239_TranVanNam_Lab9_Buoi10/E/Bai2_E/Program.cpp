#include <iostream>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
#include "Header.h"
#include "Thuvien.h"
#include "Menu.h"
void ChayChuongTrinh();
int main()
{
	ChayChuongTrinh();
	return 0;
}
void ChayChuongTrinh()
{
	BSTree root = NULL;
	int menu, soMenu = 6;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, root);
		system("pause");
	} while (menu > 0);
}