void XuatMenu()
{
	cout << "\n\t\t\tHE THONG CHUC NANG\t\t\t\t";
	cout << "\n0. Thoat Khoi chuong trinh";
	cout << "\n1. Tao danh sach nhan vien";
	cout << "\n2. Xuat bang luong nhan vien theo thu tu";
	cout << "\n3. Xuat thong tin nhan vien khi biet ma nhan vien";
	cout << "\n4. Sua nam sinh cua nhan vien co ma nhan vien CT26032 thanh 1991";
	cout << "\n5. Xoa nhan vien co ma CT13425 ra khoi danh sach nhan vien.";
	cout << "\n6. Tinh so nut cua cay";
	cout << "\n7. Tinh chieu cao cua cay";
	cout << "\n8. Xac dinh muc chua nhan vien khi biet ma nhan vien";
	cout << "\n9. Xuat thong tin cac nhan vien luu tru o nut la ra man hinh";
	cout << "\n=========================================================================";
}
int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("cls");
		XuatMenu();
		cout << "\nMoi ban nhap so trong khoan [0..." << soMenu << "] de chon chuc nang, stt= ";
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
	KeyType x;
	NhanVien a;
	BSTree d;
	char maNV_CN[8] = "CT26032";
	char maNV_Xoa[8] = "CT13452";
	int namSNew = 1991;
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat Khoi chuong trinh";
		break;
	case 1:
		system("cls");
		cout << "\n1. Tao danh sach nhan vien";
		kq = File_BST(root, filename);
		if (kq)
			cout << "\nDa chuyen thanh cong tap tin " << filename << " vao cay BST ";
		else
			cout << "\nChuyen khong thanh cong";
		break;
	case 2:
		system("cls");
		cout << "\n2. Xuat bang luong nhan vien theo thu tu";

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

		break;
	case 3:
		system("cls");
		cout << "\n3. Xuat thong tin nhan vien khi biet ma nhan vien";
		cout << "\nXuat bang diem theo thu tu LNR";
		XuatTieuDe();
		InOrder(root);
		cout << "\n";
		for (int i = 0; i <= MAXCOT; i++)
			cout << "=";
		cout << "=:";
		cout << "\nDanh sach co " << DemSoNut(root) << " nhan vien \n";
		cout << "\nMoi ban nhap ma nhan vien can tim, x =";
		cin >> x;
		d = Search_MaNV(root, x);
		if (d == NULL) {
			cout << "\nKhong tim thay nhan vien " << x;
		}
		else {
			XuatTieuDe();
			Xuat_NV(d->key);
			cout << "\n";
			for (int i = 1; i < MAXCOT; i++)
				cout << "=";
		}
		break;
	case 4:
		system("cls");
		cout << "\n4. Sua nam sinh cua nhan vien co ma nhan vien CT26032 thanh 1991";
		cout << "\nDanh sach ban dau\n";
		XuatTieuDe();
		InOrder(root);
		cout << "\n";
		for (int i = 0; i <= MAXCOT; i++)
			cout << "=";
		cout << "=:";
		cout << "\nDanh sach co " << DemSoNut(root) << " nhan vien \n";

		d = Search_MaNV(root, maNV_CN);
		if (d == NULL) {
			cout << "\nKhong co nhan vien " << maNV_CN;
		}
		else
		{
			d->key.ntns.namSinh = namSNew;
			cout << "\nDanh sach sau khi cap nhat\n";
			XuatTieuDe();
			InOrder(root);
			cout << "\n";
			for (int i = 0; i <= MAXCOT; i++)
				cout << "=";
			cout << "=:";
			cout << "\nDanh sach co " << DemSoNut(root) << " nhan vien \n";
		}
		break;
	case 5:
		system("cls");
		cout << "\n5. Xoa nhan vien co ma CT13425 ra khoi danh sach nhan vien.";

		cout << "\nDanh sach ban dau\n";
		XuatTieuDe();
		InOrder(root);
		cout << "\n";
		for (int i = 0; i <= MAXCOT; i++)
			cout << "=";
		cout << "=:";
		cout << "\nDanh sach co " << DemSoNut(root) << " nhan vien \n";

		kq = DeleteNode(root, maNV_Xoa);

		if (kq == 0) {
			cout << "\nKhong co nhan vien " << maNV_Xoa;
		}
		else
		{
			cout << "\nDanh sach sau khi xoa\n";
			XuatTieuDe();
			InOrder(root);
			cout << "\n";
			for (int i = 0; i <= MAXCOT; i++)
				cout << "=";
			cout << "=:";
			cout << "\nDanh sach co " << DemSoNut(root) << " nhan vien \n";
		}
		break;
	case 6:
		system("cls");
		cout << "\n6. Tinh so nut cua cay";
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
	case 7:
		system("cls");
		cout << "\n7. Tinh chieu cao cua cay";
		cout << "\nXuat bang diem theo thu tu LNR";
		XuatTieuDe();
		InOrder(root);
		cout << "\n";
		for (int i = 0; i <= MAXCOT; i++)
			cout << "=";
		cout << "=:";
		cout << "\nDanh sach co " << DemSoNut(root) << " nhan vien \n";
		kq = TinhChieuCao(root);
		cout << "\nChieu cao cua cay la " << kq;
		break;
	case 8:
		system("cls");
		cout << "\n8. Xac dinh muc chua nhan vien khi biet ma nhan vien";

		cout << "\nXuat bang diem ban dau";
		XuatTieuDe();
		InOrder(root);
		cout << "\n";
		for (int i = 0; i <= MAXCOT; i++)
			cout << "=";
		cout << "=:";

		cout << "\nNhap ma nhan vien can tim muc, x = ";
		cin >> x;
		d = Search_MaNV(root, x);
		if (d == NULL)
			cout << "\nKhong co nhan vien nao co ma la " << x << endl;
		else
		{			
			cout << "\nMuc cua nhan vien co ma " << x << " la " << TimMuc_x(root, x) << endl;
		}


		break;
	case 9:
		system("cls");
		cout << "\n9. Xuat thong tin cac nhan vien luu tru o nut la ra man hinh";
		cout << "\nXuat bang diem theo thu tu LNR";
		XuatTieuDe();
		InOrder(root);
		cout << "\n";
		for (int i = 0; i <= MAXCOT; i++)
			cout << "=";
		cout << "=:";
		cout << "\nDanh sach co " << DemSoNut(root) << " nhan vien \n";
		kq = DemNutLa(root);
		cout << "\nDanh sach co " << kq << " nut la \n";
		
		break;



	}
	_getch();
}