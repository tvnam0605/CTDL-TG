#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
#include "Bstree.H"
#include "LIST.H"
//#include "Menu.h"
void ChayChuongTrinh();
int main()
{
	ChayChuongTrinh();
	return 1;
}
void ChayChuongTrinh()
{
	char* filename;
	filename = new char[50];
	BSTree root;
	int kq;
	do
	{
		cout << "\nFilename : ";
		cin >> filename;
		kq = File_BST(root, filename);
	} while (!kq);
	cout << "\n\nXuat BST theo thu tu truoc:\n";
	PreOrder(root);
	cout << "\n\nXuat BST theo thu tu giua:\n";
	InOrder(root);
	cout << "\n\nXuat BST theo thu tu sau:\n";
	PosOrder(root);
	cout << "\n\nXuat BST theo chieu sau :\n";
	DFS(root);
	system("pause");
	cout << "\n\nXuat BST theo chieu rong :\n";
	BFS(root);
	system("pause");
	BFS_TheoMuc(root);
	system("pause");}