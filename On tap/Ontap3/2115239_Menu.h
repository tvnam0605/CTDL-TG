void XuatMenu()
{
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Doc file";
	cout << "\n2. Xuat File theo thu tu";
	cout << "\n3. Tinh so nut";
	cout << "\n4. Tinh chieu cao";
	cout << "\n5. Dem nut la";
	cout << "\n6. Kiem tra x co phai nut la";
	cout << "\n7. Xoa nhan vien co ma cho truoc ra khoi bang";
	cout << "\n8. Xoa nhan vien que lam dong";
	cout << "\n9. Thay doi nam sinh khi biet ma";
	cout << "\n10. Tim theo ten";

}
int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("cls");
		XuatMenu();
		cout << "\nMoi ban chon so trong khoang [0..." << soMenu << "] de chon chuc nang, stt= ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}
void XuLyMenu(BSTree& root, int menu)
{
	char filename[50] = "bangluong.txt";
	int kq;
	KeyType x;
	int newNS;
	BSTree p;
	char ten[8];
	
	switch (menu)
	{
	case 0:
		system("cls");
		cout << "\n0. Thoat khoi chuong trinh";
		break;
	case 1:
		system("cls");
		cout << "\n1. Doc file";
		kq = File_BST(root, filename);
		if (kq)
			cout << "\nDa chuyen thanh cong tap tin " << filename << " vao cay BST!";
		else
			cout << "\nChuyen khong thanh cong, vui long kiem tra lai";
		cout << endl;
		break;
	case 2:
		system("cls");
		cout << "\n2. Xuat File theo thu tu";
		cout << "\nXuat theo thu tu NLR";
		TieuDe();
		PreOrder(root);
		cout << "\n";
		for (int i = 1; i <= MAX; i++)
			cout << "=";
		cout << ":\n";
		system("pause");
		cout << "\nXuat theo thu tu LNR";
		TieuDe();
		InOrder(root);
		cout << "\n";
		for (int i = 1; i <= MAX; i++)
			cout << "=";
		cout << ":\n";
		system("pause");
		cout << "\nXuat theo thu tu LRN";
		TieuDe();
		PosOrder(root);
		cout << "\n";
		for (int i = 1; i <= MAX; i++)
			cout << "=";
		cout << ":\n";
		
		break;
	case 3:
		system("cls");
		cout << "\n3. Tinh so nut";
		cout << "\nXuat theo thu tu LNR";
		TieuDe();
		InOrder(root);
		cout << "\n";
		for (int i = 1; i <= MAX; i++)
			cout << "=";
		cout << ":\n";
		cout << "\nDanh sach co " << DemSoNut(root) << " Nhan Vien\n";
		break;
	case 4:
		system("cls");
		cout << "\n4. Tinh chieu cao";
		cout << "\nXuat theo thu tu LNR";
		TieuDe();
		InOrder(root);
		cout << "\n";
		for (int i = 1; i <= MAX; i++)
			cout << "=";
		cout << ":\n";
		cout << "\nCHieu cao cua danh sach la. h= " << TinhChieuCao(root) << endl;
		break;
	case 5:
		system("cls");
		cout << "\n5. Dem nut la";
		cout << "\nXuat theo thu tu LNR";
		TieuDe();
		InOrder(root);
		cout << "\n";
		for (int i = 1; i <= MAX; i++)
			cout << "=";
		cout << ":\n";
		cout << "\nDanh sach co " << DemNutLa(root) << " nut la\n";
		break;
	case 6:
		system("cls");
		cout << "\n6. Kiem tra x co phai nut la";
		cout << "\nXuat theo thu tu LNR";
		TieuDe();
		InOrder(root);
		cout << "\n";
		for (int i = 1; i <= MAX; i++)
			cout << "=";
		cout << ":\n";
		cout << "\nNhap x can kiem tra: ";
		cin >> x;
		kq = KiemtTraNutla_x(root, x);
		if (!kq)
			cout << "\n" << x << " Khong phai la nut la\n";
		else
			cout << "\n " << x << " la nut la \n";
		break;
	case 7:
		system("cls");
		cout << "\n7. Xoa nhan vien co ma cho truoc ra khoi bang";
		cout << "\nXuat theo thu tu LNR";
		TieuDe();
		InOrder(root);
		cout << "\n";
		for (int i = 1; i <= MAX; i++)
			cout << "=";
		cout << ":\n";
		cout << "\nDanh sach co " << DemSoNut(root) << " Nhan vien ";
		cout << "\nNhap x can xoa: ";
		cin >> x;
		kq = DeleteNode(root, x);
		if (kq == 0) {
			cout << "\nKhong co nhan vien " << x << " trong bang ";
		}
		else
		{
			cout << "\nDanh sach sau khi xoa\n";
			TieuDe();
			InOrder(root);
			cout << "\n";
			for (int i = 1; i <= MAX; i++)
				cout << "=";
			cout << ":\n";
			cout << "\nDanh sach co " << DemSoNut(root) << " Nhan vien ";
		}
		break;
	case 8:
		system("cls");
		cout << "\n8. Xoa nhan vien que lam dong";
		cout << "\nXuat theo thu tu LNR";
		TieuDe();
		InOrder(root);
		cout << "\n";
		for (int i = 1; i <= MAX; i++)
			cout << "=";
		cout << ":\n";
		cout << "\nDanh sach co " << DemSoNut(root) << " Nhan vien ";
		cout << "\nNhap dia chi can xoa: ";
		cin >> x;
		kq = DeleteNode_LamDong(root, x);
		if (kq == 0) {
			cout << "\nKhong co nhan vien nao que o " << x << endl;
		}
		else
		{
			cout << "\nDanh sach sau khi xoa nhan vien que o " << x  << endl;
			TieuDe();
			InOrder(root);
			cout << "\n";
			for (int i = 1; i <= MAX; i++)
				cout << "=";
			cout << ":\n";
			cout << "\nDanh sach co " << DemSoNut(root) << " Nhan vien ";
		
		}
		break;
	case 9:
		system("cls");
		cout << "\n9. Thay doi nam sinh khi biet ma";
		cout << "\nDanh sach Ban dau\n";
		TieuDe();
		InOrder(root);
		cout << "\n";
		for (int i = 1; i <= MAX; i++)
			cout << "=";
		cout << ":\n";
		cout << "\nDanh sach co " << DemSoNut(root) << " Nhan vien ";
		cout << "\nNhap Ma so can doi: ";
		cin >> x;
		p = Search(root, x);
		if (p == 0) {
			cout << "\nKhong co nhan vien nao co ma " << x << endl;
		}
		else
		{
			cout << "\nNhap nam sinh moi: ";
			cin >> newNS;
			p->key.namSinh == newNS;
			cout << "\nThong tin nhan vien co ma " << x << " :\n";
			TieuDe();
			Xuat_NV(p->key);
			cout << "\n:";
			for (int i = 1; i <= MAX; i++)
				cout << "=";
			cout << ":";
		}
		
		break;
	case 10:
		system("cls");
		cout << "\n10. Tim theo ten";
		cout << "\nDanh sach Ban dau\n";
		TieuDe();
		InOrder(root);
		int dem = 0;
		cout << "\n";
		for (int i = 1; i <= MAX; i++)
			cout << "=";
		cout << ":\n";
		cout << "\nDanh sach co " << DemSoNut(root) << " Nhan vien ";
		cout << "\nNhap ten HV can tim : ten = ";
		cin >> ten;
		dem = 0;
		cout << "\nDanh sach hoc vien co ten " << ten;
		cout << endl;
		TieuDe();
		Xuat_HV_Ten(root, ten);
		cout << "\n:";
		for (int i = 1; i <= MAX; i++)
			cout << "=";
		cout << ":";
		if (dem == 0)
			cout << "\nKhong co hoc vien nao ten " << ten;
		else
			cout << "\nCo " << dem << " hoc vien ten " << ten;
		break;

	
	}
}