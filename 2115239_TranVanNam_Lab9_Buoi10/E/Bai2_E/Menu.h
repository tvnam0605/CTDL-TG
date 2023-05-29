void XuatMenu()
{
	cout << "\n=============================He thong chuc nang=============================";
	cout << "\n0. Thoat Khoi chuong trinh";
	cout << "\n1. Tao bang diem hoc vien";
	cout << "\n2. Xem bang diem theo thu tu NLR, LNR, LRN";
	cout << "\n3. Thay doi dia chi cua hoc vien khi biet ma hoc vien";
	cout << "\n4. Huy hoc vien co ma hoc vien cho truoc ra khoi bang diem";
	cout << "\n5. Huy cac hoc vien co diem <5";
}
int ChonMenu(int soMenu)
{
	
	int stt;
	for (;;)
	{
		system("cls");
		XuatMenu();
		cout << "\nMoi ban chon 1 so trong khoang [0..." << soMenu << "] de chon chuc nang, stt = ";
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
	char dc;
	char diaChi[15];
	//HocVien x;
	//char diaChi[15];
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat Khoi chuong trinh";
		break;
	case 1:
		system("cls");
		cout << "\n1. Tao bang diem hoc vien";
		kq = File_BST(root, filename);
		if (kq)
			cout << "\nDa chuyen thanh cong file " << filename << " vao cay BST." << endl;
		else
			cout << "\nChuyen khong thanh cong";
		break;
	case 2:
		system("cls");
		cout << "\n2. Xem bang diem theo thu tu NLR, LNR, LRN";
		cout << "\nXuat bang diem theo thu tu NLR";
		TieuDe();
		PreOrder(root);
		cout << "\n";
		for (int i = 0; i <= MAXCOT; i++)
			cout << "=";
		cout << "=:";
		cout << "\nDanh sach co " << DemSoNut(root) << " nhan vien \n";
		system("pause");
		cout << "\nXuat bang diem theo thu tu LNR";
		TieuDe();
		InOrder(root);
		cout << "\n";
		for (int i = 0; i <= MAXCOT; i++)
			cout << "=";
		cout << "=:";
		cout << "\nDanh sach co " << DemSoNut(root) << " nhan vien \n";
		system("pause");
		cout << "\nXuat bang diem theo thu tu LRN";
		TieuDe();
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
		cout << "\n3. Thay doi dia chi cua hoc vien khi biet ma hoc vien";
		cout << "\nXuat bang diem theo thu tu LNR";
		TieuDe();
		InOrder(root);
		cout << "\n";
		for (int i = 0; i <= MAXCOT; i++)
			cout << "=";
		cout << "=:";
		cout << "\nDanh sach co " << DemSoNut(root) << " nhan vien \n";
		
		cout << "\nNhap ma nhan vien (khong co ky tu trang, co phan biet ky tu thuong, HOA):\nmaNV = ";
		cin >> x;
		p = Search(root, x);
		if (p == NULL)
			cout <<"\nKhong co hoc vien nao co ma " << x;
		else
		{
			cout << "\nThong tin cua nhan vien co ma " << x << endl;
			TieuDe();
			Xuat1_HV(p->key);
			cout << "\n";
			for (int i = 1; i <= MAXCOT; i++)
				cout << "=";
			cout << "=:";
			cout << "\nNhap dia chi moi cua hoc vien, dia chi = ";
			cin >> dc;
			p->key.diaChi[15] = dc;
			cout << "\nBANG DIEM SAU KHI CAP NHAT" << x << endl;
			TieuDe();
			PreOrder(root);
			cout << "\n";
			for (int i = 1; i <= MAXCOT; i++)
				cout << "=";
			cout << "=:";

		}
		cout << endl;

		break;
	case 4:
		system("cls");
		cout << "\n4. Huy hoc vien co ma hoc vien cho truoc ra khoi bang diem";
		cout << "\nDanh sach ban dau\n";
		TieuDe();
		InOrder(root);
		cout << "\n";
		for (int i = 0; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		cout << "\nDanh sach co " << DemSoNut(root) << " nhan vien \n";


		cout << "\nNhap ma nhan vien can xoa: ";
		cin >> x;
		kq = DeleteNode(root, x);
		if (kq == 0)
		{
			cout << "\nDanh sach khong co nhan vien me " << x << endl;
		}
		else
		{
			cout << "\nDanh sach sau khi xoa\n";
			TieuDe();
			PreOrder(root);
			cout << endl;
			for (int i = 1; i <= MAXCOT; i++)
				cout << "=";
			cout << ":\n";

		}
		
		break;
	case 5:
		system("cls");
		cout << "\n5. Huy cac hoc vien co diem <5";
		break;
	default:
		break;
	}

}