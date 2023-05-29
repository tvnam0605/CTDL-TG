void XuatMenu()
{
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. tao cay BST tu file";
	cout << "\n2. Xuat Cay theo thu tu";
	cout << "\n3. Dem so nut cua cay";
	cout << "\n4. Dem nut la";
	cout << "\n5. Tinh chieu cao cua cay";
	cout << "\n6. Kiem tra nut x co phai la nut la";
	cout << "\n7. Xoa nhan vien co nam sinh cho truoc";
	cout << "\n8. Thay doi noi sinh cua nhan vien khi biet ma nhan vien";
	cout << "\n9. Tim kiem theo ten";
}
int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("cls");
		XuatMenu();
		cout << "\nMoi ban chon so trong khoang [0..." << soMenu << "] de chon chuc nang, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}
void XuLyMenu(BSTree& root, int menu)
{
	char filename[50] = "LyLich.txt";
	int kq;
	
	char tenSreach;
	char maNV;
	double newNoiSinh;
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
		cout << "\n1. tao cay BST tu file";
		kq = File_BST(root, filename);
		if (kq)
			cout << "\nDa chuyen thanh cong tap tin " << filename << " vao cay BST!";
		else
			cout << "\nChuyen khong thanh cong, vui long kiem tra lai";
		cout << endl;
		break;
	case 2:
		system("cls");
		cout << "\n2. Xuat Cay theo thu tu";
		cout << "\nXuat Cay theo thu tu truoc NLR\n";
		XuatTieuDe();
		PreOrder(root);
		cout << "\n";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":\n";
		system("pause");
		cout << "\nXuat Cay theo thu tu giua LNR\n";
		XuatTieuDe();
		InOrder(root);
		cout << "\n";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":\n";
		system("pause");
		cout << "\nXuat Cay theo thu tu sau LRN\n";
		XuatTieuDe();
		PosOrder(root);
		cout << "\n";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":\n";
	
		break;
	case 3:
		system("cls");
		cout << "\n3. Dem so nut cua cay";
		cout << "\nXuat Cay\n";
		XuatTieuDe();
		PosOrder(root);
		cout << "\n";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":\n";
		kq = DemSoNut(root);
		cout << "\nDanh sach co " << DemSoNut(root) << " Nhan Vien \n";
		break;
	case 4:
		system("cls");
		cout << "\n4. Dem nut la";
		cout << "\nXuat Cay\n";
		XuatTieuDe();
		PosOrder(root);
		cout << "\n";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":\n";
		kq = DemNutLa(root);
		cout << "\nDanh sach co " << DemNutLa(root) << " nut la\n";
		break;
	case 5:
		system("cls");
		cout << "\n5. Tinh chieu cao cua cay";
		cout << "\nXuat Cay\n";
		XuatTieuDe();
		PosOrder(root);
		cout << "\n";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":\n";
		kq = TinhChieuCao(root);
		cout << "\nCay co chieu cao la: h= " << TinhChieuCao(root) << endl;
		break;
	case 6:
		system("cls");
		cout << "\n6. Kiem tra nut x co phai la nut la";
		break;
	case 7:
		system("cls");
		cout << "\n7. Xoa nhan vien co nam sinh cho truoc";
		cout << "\nXuat Cay\n";
		XuatTieuDe();
		PosOrder(root);
		cout << "\n";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":\n";
		cout << "\nDanh sach co " << DemSoNut(root) << " nhan vien \n";
		
		cout << "\nNhap ma nhan vien can xoa: ";
		cin >>x;
		kq = DeleteNode(root, x);

		//if (kq == 0) {
		//	cout << "\nKhong co nhan vien " << x;
		//}
		//else
		//{
		//	cout << "\nDanh sach sau khi xoa\n";
		//	XuatTieuDe();
		//	InOrder(root);
		//	cout << "\n";
		//	for (int i = 0; i <= MAXCOT; i++)
		//		cout << "=";
		//	cout << "=:";
		//	cout << "\nDanh sach co " << DemSoNut(root) << " nhan vien \n";
		//}
		if (kq == 0)
		{
			cout << "\nKhong co nhan vine nao co ma " << x << endl;
		}
		else
		{
			cout << "\nDanh sach sau khi xoa\n";
			XuatTieuDe();
			PreOrder(root);
			cout << "\n";
			for (int i = 1; i < MAXCOT; i++)
				cout << "=";
			cout << "=:";
			cout << "\nDanh sach co " << DemSoNut(root) << " Nhan vien \n";
		}
		
		break;
	case 8:
		system("cls");
		cout << "\n8. Thay doi noi sinh cua nhan vien khi biet ma nhan vien";
		cout << "\nXuat Cay\n";
		XuatTieuDe();
		PosOrder(root);
		cout << "\n";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":\n";
		p = Search_MaNV(root, x);
		cout << "\nNhap ma nhan vien can doi noi sinh: ";
		cin >> x;
		p = Search_MaNV(root, x);
		if (p == NULL)
			cout << "\nkhong co nhan vien nao co ma " << x;
		else
		{
			/*cout << "\nThong tin nhan vien co ma " << x << " :\n";
			XuatTieuDe();
			Xuat_NV(p->key);
			cout << "\n:";
			for (int i = 1; i <= MAXCOT; i++)
				cout << "=";
			cout << ":";*/
			cout << "\nNhap dia chi moi cua nhan vien: ";
			cin >> newNoiSinh;
			p->key.diaChi[15] = newNoiSinh;
			cout << "\nDanh sach sau khi cap nhat";
			XuatTieuDe();
			PosOrder(root);
			cout << "\n";
			for (int i = 1; i <= MAXCOT; i++)
				cout << "=";
			cout << ":\n";
		}
		break;
	case 9:
		system("cls");
		cout << "\n9. tim kiem theo ten";
		cout << "\nXuat Cay\n";
		XuatTieuDe();
		PosOrder(root);
		cout << "\n";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":\n";
		
		cout << "\nMoi ban nhap ten nhan vien can tim: ";
		cin >> x;
		
		p = Search_Ten(root, x);
		if (p == NULL)
			cout << "\nkhong co nhan vien nao co ten " << x;
		else
		{
			cout << "\nThong tin nhan vien co ten " << x << " :\n";
			XuatTieuDe();
			Xuat_NV(p->key);
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