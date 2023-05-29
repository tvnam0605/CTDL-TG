void XuatMenu()
{
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao cay nhi phan can doi";
	cout << "\n2. Xuat Cac phan tu tren cay theo  thu tu NLR, LNR, LRN";
	cout << "\n3. Dem so nut cua cay";
	cout << "\n4. xac dinh chieu cao cua cay";
	cout << "\n5. Dem so nut cua cay o muc K";
	cout << "\n6. Dem so nut la cua cay";
	cout << "\n7. Dem so nut co dung hai nut con khac rong";
	cout << "\n8. Huy nut co khoa cho truoc";
	cout << "\n9. Chen mot khoa vao cay";
	cout << "\n10. Duyet cay theo chieu rong (BFS)";
	cout << "\n11. Duyet cay theo chieu ngang (DFS)";
}
int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("cls");
		XuatMenu();
		cout << "\nMoi ban chon 1 so trong khoang 0 => " << soMenu << " de chon chuc nang , stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}
void XuLyMenu(BSTree& root, int menu)
{
	char filename[50] ="Test.txt";
	int kq;
	int x;
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh";
		break;
	case 1:
		system("cls");
		cout << "\n1. Tao cay nhi phan can doi";
		kq = File_BST(root, filename);
		if (kq)
			cout << "\nDa chuyen thanh cong tap tin " << filename << " vao cay BST:\n";
		else
			cout << "\nKhong thanh cong!";
		cout << endl;
		break;
	case 2:
		system("cls");
		cout << "\n2. Xuat Cac phan tu tren cay theo  thu tu NLR, LNR, LRN";
		cout << "\n\nCay BST hien hanh, xuat theo thu tu truoc (NLR) :\n";
		PreOrder(root);
		system("pause");
		cout << "\n\nCay BST hien hanh, xuat theo thu tu giua (LNR) :\n";
		InOrder(root);
		system("pause");
		cout << "\n\nCay BST hien hanh, xuat theo thu tu cuoi (LRN) :\n";
		PosOrder(root);
		system("pause");
		
		break;
	case 3:
		system("cls");
		cout << "\n3. Dem so nut cua cay";
		cout << "\n\nCay BST hien hanh, xuat theo thu tu giua (LNR) :\n";
		InOrder(root);
		kq = DemSoNut(root);
		cout << "\nSO nut cua cay la: " << kq<< endl;
		break;
	case 4:
		system("cls");
		cout << "\n4. xac dinh chieu cao cua cay";
		cout << "\n\nCay BST hien hanh, xuat theo thu tu giua (LNR) :\n";
		InOrder(root);
		kq = TinhChieuCaoCuaCay(root);
		cout << "\nChieu cao cua cay la: " << kq << endl;
		break;
	case 5:
		system("cls");
		cout << "\n5. Dem so nut cua cay o muc K";
		break;
	case 6:
		system("cls");
		cout << "\n6. Dem so nut la cua cay";
		cout << "\n\nCay BST hien hanh, xuat theo thu tu giua (LNR) :\n";
		InOrder(root);
		
		kq = DemNutLa(root);
		cout << "\nSo nut la cua cay la: " << kq << endl;
		break;
	case 7:
		system("cls");
		cout << "\n7. Dem so nut co dung hai nut con khac rong";
		break;
	case 8:
		system("cls");
		cout << "\n8. Huy nut co khoa cho truoc";
		cout << "\nCay BST hien hanh, xuat theo thu tu giua :\n";
		InOrder(root);
		cout << "\nKhoa x = ";
		cin >> x;
		if (!Search(x, root))
		{
			cout << "\nkhoa x = " << x << " khong co trong cay.\n";
			_getch();
			break;
		}
		else
			if (DeleteNode(x, root) != 0)
			{
				cout << "\nCay BST sau khi xoa khoa " << x << " :\n";
				InOrder(root);
			}
		cout << endl;
		break;
	case 9:
		system("cls");
		cout << "\n9. Chen mot khoa vao cay";
		cout << "\nCay BST hien hanh, xuat theo thu tu giua :\n";
		InOrder(root);
		cout << "\nKhoa x = ";
		cin >> x;
		if (InsertNode(root, x) != 1)
			cout << "\nThem khoa " << x << " khong thanh cong\n";
		else
		{
			cout << "\nCay BST sau khi them khoa " << x << " :\n";
			InOrder(root);
		}
		cout << endl;
		break;
	case 10:
		system("cls");
		cout << "\n10. Duyet cay theo chieu rong (BFS)";
		cout << "\n\nXuat BST theo chieu rong :\n";
		BFS(root);
		system("pause");
		BFS_TheoMuc(root);
		system("pause");
		break;
	case 11:
		system("cls");
		cout << "\n11. Duyet cay theo chieu ngang (DFS)";
		cout << "\n\nXuat BST theo chieu ngang :\n";
		DFS(root);
		system("pause");

		break;
	default:
		break;
	}
	_getch();
}