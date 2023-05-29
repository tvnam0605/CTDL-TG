#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <string.h>

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
	int menu, soMenu = 11;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(root, menu);
		system("pause");
	} while (menu > 0);
}