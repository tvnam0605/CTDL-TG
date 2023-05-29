#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>

using namespace std;
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
	BSTree root = NULL;
	int menu, soMenu = 8;
	do
	{
		//XuatMenu();
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, root);
		cout << endl;
		system("pause");
	} while (menu > 0);
}