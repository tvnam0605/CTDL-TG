void XuatMenu()
{
	cout << "==============================================================";
	cout << "\n0. Thoat khoi chuong trinh.";
	cout << "\n1. Nhap file";
	cout << "\n2. Xuat File du lieu";
	cout << "\n3. Xuat thong tin hoc vien khi biet ma hoc vien";
	cout << "\n4. Xac dinh so nut cua cay";
	cout << "\n5. Xac dinh chieu cao cua cay";
	cout << "\n6. Xac dinh muc cua nut khi biet ma hoc vien";
	cout << "\n7. Xuat cac hoc vien co ten cho truoc";
	cout << "\n8. Huy nut khi biet ma hoc vien";
}
int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\nNhap 1 so trong khoang [0,...," << soMenu << "] de chon menu, stt = ";
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
	switch (menu)
	{
	case 0:
		system("cls");
		cout << "\n0. Thoat khoi chuong trinh";
		break;
	case 1:
		system("cls");
		cout << "\n1. Tao cay BST";
		kq = FIle_BST(root, filename);
		if (kq)
			cout << "\nDa chuyen du lieu tap tin tu " << filename << " vao BSTTree thanh cong\n";
		break;
	case 2:
		system("cls");		
		cout << "\n2. Xuat BST";
		cout << "\n\nCay BST hien hanh, xuat theo thu tu truoc (NLR) :\n";
		Title();
		PreOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		system("PAUSE");
		cout << "\n\nCay BST hien hanh, xuat theo thu tu giua (LNR) :\n";
		Title();
		InOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		system("PAUSE");
		cout << "\n\nCay BST hien hanh, xuat theo thu tu cuoi (LRN) :\n";
		Title();
		PosOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		cout << "\nDanh sach co " << DemSoNut(root) << " nhan vien ";
		system("PAUSE");
		cout << endl;
		break;
	case 3:
		system("cls");
		cout << "\n3. Xuat thong tin nhan vien khi biet ma nhan vien";
		cout << "\n\nCay BST hien hanh, xuat theo thu tu giua (LNR) :\n";
		Title();
		InOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		cout << "\nDanh sach co " << DemSoNut(root) << " nhan vien ";
		cout << "\nNhap ma nhan vien (khong co ky tu trang, co phan biet ky tu thuong, HOA):\nmaNV = ";
		cin >> x;
		p = TimKiem_maHV(root, x);
		if (p == NULL)
			cout << "\nkhong co nhan vien nao co ma " << x;
		else
		{
			cout << "\nThong tin nhan vien co ma " << x << " :\n";
			Title();
			Xuat_HV(p->info);
			cout << "\n:";
			for (int i = 1; i <= MAXCOT; i++)
				cout << "=";
			cout << ":";
		}
		break;
	case 4:		
		system("cls");

		cout << "\n4. Xac dinh so nut cua cay";
		cout << "\nDanh sach co " << DemSoNut(root) << " nhan vien ";
		break;
	case 5:
		system("cls");

		cout << "\n5. Xac dinh chieu cao cua cay";
		Title();
		InOrder(root);
		cout << "\n";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		cout << "\nDanh sach co " << DemSoNut(root) << " nhan vien ";
		cout << "\nChieu cao cua cay BST: h= " << TinhChieuCao(root);
		cout << endl;
		break;
	case 6:
		system("cls");
		cout << "\n6. Xac dinh muc cua nut khi biet ma hoc vien";
		Title();
		InOrder(root);
		cout << "\n";
		for (int i = 1; i < MAXCOT; i++)
			cout << "=";
		cout << ":";
		cout << "\nDanh sach co " << DemSoNut(root) << " cac nhan vien ";
		cout << "\n\nNhap ma nhan vien(khong co KT trang, co phan biet KT thuong, HOA), x = ";
		cin >> x;
		p = TimKiem_maHV(root, x);
		if (p == NULL)
			cout << "\nKhong co hoc vien nao co ma " << x;
		else
			cout << "\nMuc cua hoc vien co ma " << x << " la " << TimMuc_X(root, x);
		
			
		cout << endl;
		break;

	case 7:
		system("cls");

		cout << "\n7. Xuat cac hoc vien co ten cho truoc";
		cout << "\n\nCay BST hien hanh, xuat theo thu tu giua (LNR) :\n";
		Title();
		InOrder(root);
		cout << "\n";
		for (int i = 1; i < MAXCOT; i++)
			cout << "=";
		cout << ":";
		cout << "\n\nNhap Ten hoc vien(khong co KT trang, co phan biet KT thuong, HOA), x = ";
		cin >> x;
		p = TimKiem_TenHV(root, x);
		if (p == NULL)
			cout << "\nkhong co hoc vien nao co ten " << x;
		else
		{
			cout << "\nThong tin hoc vien co ten " << x << " :\n";
			Title();
			Xuat_HV(p->info);
			cout << "\n:";
			for (int i = 1; i <= MAXCOT; i++)
				cout << "=";
			cout << ":";
		}
		break;
	case 8:
		system("cls");

		cout << "\n8. Huy nut khi biet ma hoc vien";
		cout << "\n\nCay BST hien hanh, xuat theo thu tu giua (LNR) :\n";
		Title();
		InOrder(root);
		cout << "\n";
		for (int i = 1; i < MAXCOT; i++)
			cout << "=";
		cout << ":";
		cout << "\n\nNhap Ten hoc vien(khong co KT trang, co phan biet KT thuong, HOA), x = ";
		cin >> x;
		p = TimKiem_TenHV(root, x);
		if (p == NULL)
			cout << "\nkhong co hoc vien nao co ten " << x;
		else
		{
			cout << "\nThong tin hoc vien co ten " << x << " :\n";
			Title();
			Xuat_HV(p->info);
			cout << "\n:";
			for (int i = 1; i <= MAXCOT; i++)
				cout << "=";
			cout << ":";
		}
		break;
	

	default:
		break;
	}
}
