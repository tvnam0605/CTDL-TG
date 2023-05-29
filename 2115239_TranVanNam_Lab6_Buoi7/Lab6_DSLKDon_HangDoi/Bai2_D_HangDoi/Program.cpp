#include <conio.h>
#include <iostream>
#include <fstream>

using namespace std;

#include "Thuvien.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();

	_getch();
	return 1;
}

void ChayChuongTrinh()
{
	char a[MAX];
	File_String(a);
	XuLy_ThaoTac(a);
}