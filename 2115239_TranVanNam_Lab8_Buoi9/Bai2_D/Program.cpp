#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
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
	int menu, soMenu = 8;
	BTree root = NULL;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, root);
		cout << endl;
		system("PAUSE");
	} while (menu > 0);
}