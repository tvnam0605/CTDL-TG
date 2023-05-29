void XuatMenu()
{
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Nhap du lieu";
	cout << "\n2. Xem Cay BST";
	cout << "\n3. Dem so nut";
	cout << "\n4. Dem so nut la";
	cout << "\n5. Tim kiem theo ma nv";
	cout << "\n6. Tinh muc cua cay";
	cout << "\n8. Xuat nhan vien co ten cho truoc";
}
int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("cls");
		XuatMenu();
		cout << "\nMoi ban nhap 1 so trong khoang [0..." << soMenu << "] de chon chuc nang, stt =";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}
void XuLyMenu(int menu, BSTree& root)
{
	char filename[50] = "bd.txt";
	int kq;
	KeyType x;
	BSTree p;
	int dem = 0;
	switch (menu)
	{
	case 0:
		system("cls");
		cout << "\n0. Thoat khoi chuong trinh";
		break;
	case 1:
		system("cls");
		cout << "\n1. Nhap du lieu";
		kq = File_BST(root, filename);
		if (kq)
			cout << "\nDa chuyen thanh con tap tin " << filename << " vao cay BST ";
		else

			cout << "\nChuyen khong thanh cong tap tin";
		break;
	case 2:
		system("cls");
		cout << "\n2. Xem Cay BST";
		cout << "\nXuat cay theo thu tu NLR";
		XuatTieuDe();
		PreOrder(root);
		cout << "\n";
		for (int i = 0; i <= MAXCOT; i++)
			cout << "=";
		cout << ":\n";
		cout << "\nDanh sach co " << DemSoNut(root) << " Nhan vien\n";
		system("pause");
		cout << "\nXuat bang diem theo thu tu LNR";
		XuatTieuDe();
		InOrder(root);
		cout << "\n";
		for (int i = 0; i <= MAXCOT; i++)
			cout << "=";
		cout << "=:";
		cout << "\nDanh sach co " << DemSoNut(root) << " nhan vien \n";
		system("pause");
		cout << "\nXuat bang diem theo thu tu LRN";
		XuatTieuDe();
		PosOrder(root);
		cout << "\n";
		for (int i = 0; i <= MAXCOT; i++)
			cout << "=";
		cout << "=:";
		cout << "\nDanh sach co " << DemSoNut(root) << " nhan vien \n";
		system("pause");
		break;
	case 3:
		system("cls");
		cout << "\n3. Dem so nut";
		cout << "\nXuat bang diem theo thu tu LNR";
		XuatTieuDe();
		InOrder(root);
		cout << "\n";
		for (int i = 0; i <= MAXCOT; i++)
			cout << "=";
		cout << "=:";
		cout << "\nDanh sach co " << DemSoNut(root) << " nhan vien \n";
		system("pause");
		break;
	case 4:
		system("cls");
		cout << "\n4. Dem so nut la";
		cout << "\nXuat theo thu tu RNL";
		XuatTieuDe();
		InOrder(root);
		cout << "\n";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":\n";
		

		kq = DemNutLa(root);
		cout << "\nDanh sach co " << kq << "nut la\n";
		break;
	case 5:
		system("cls");
		cout << "\n5. Tim kiem theo ma nv";
		cout << "\nXuat theo thu tu RNL";
		XuatTieuDe();
		InOrder(root);
		cout << "\n";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":\n";
		cout << "\nDanh sach co " << DemSoNut << " Nhan vien.\n";
		cout << "\nNhap ma nhan vien can tim, x= ";
		cin >> x;
		p = Sreach(root, x);
		if (p == NULL)
			cout << "\nKhong co nhan vien nao co ma " << x;
		else
		{
			cout << "\nThong tin cua nhan vien co ma " << x << " la \n";
			XuatTieuDe();
			Xuat_1NV(p->key);
			cout << "\n";
			for (int i = 1; i <= MAXCOT; i++)
				cout << "=";
			cout << ":\n";
		}
		break;
	case 6:
		system("cls");
		cout << "\n6. Tinh muc cua cay";
		break;
	case 7:
		system("cls");
		cout << "\n7. Xuat nhan vien co ten cho truoc";
		cout << "\nXuat theo thu tu RNL";
		XuatTieuDe();
		InOrder(root);
		cout << "\n";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":\n";
		cout << "\nDanh sach co " << DemSoNut << " Nhan vien.\n";
		cout << "\nNhap  ten nhan vien can tim, x= ";
		cin >> x;
		p = SreachTen(root, x);
		if (p == NULL)
			cout << "\nKhong co nhan vien nao ten " << x;
		else
		{
			cout << "\ndanh sach nhan vien co ten " << x << " la ";
			cout << "\n";
			XuatTieuDe();
			Xuat_1NV(p->key);
			for (int i = 1; i <= MAXCOT; i++)
				cout << "=";
			cout << ":\n";
		}
		
		
		

		break;
	default:
		break;
	}
}