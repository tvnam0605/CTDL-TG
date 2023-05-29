#include <iostream>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
#include "Header.h"
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
	int menu, soMenu = 10;
	BSTree root = NULL;
	CreateBST(root);
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(root, menu);
		system("pause");
	} while (menu > 0);

}