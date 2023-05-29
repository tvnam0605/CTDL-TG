void XuatMenu()
{
	cout << "\n========================= HE THONG CHUC NANG =========================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao bang diem mon hoc";
	cout << "\n2. Xem bang diem mon hoc";
	cout << "\n3. Xuat danh sach hoc vien que Lam Dong va diem > 5";
	cout << "\n4. Xuat hoc vien co ten la Hoa va nam sinh 1990";
	cout << "\n5. Xuat hoc vien co diem <5 va nam sinh 1990";
	cout << "\n======================================================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap mot so trong khoang tu [0,..," << soMenu << "] de chon chuc nang, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}
void XuLyMenu(int menu, LIST& l)
{
	
	
	system("cls");
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		cout << "\n1. Tao bang diem mon hoc\n";
		DocFile("bd.txt", l);
		Xuat_DS(l);
		break;
	case 2:
		cout << "\n2. Xem bang diem mon hoc\n";
		Xuat_DS(l);
		break;
	case 3:
		cout << "\n3. Xuat DS Hoc vien que Lam Dong va diem > 5";
		 
		cout << "\nDanh sach sinh vien que Lam Dong va co diem > 5 la:\n ";
		XuatSinhVienQueLamDong_DTBTren5(l);
		break;
	case 4:
		cout << "\n4. Xuat DS hoc vien ten la Hoa sinh nam 1990";
		cout << "\nDanh sach hoc vien ten Hoa va sinh nam 1990 la:\n";
		XuatDanhSachCoTenHoaVaNamSinh1990(l);
		break;
	case 5:
		cout << "\n5. Xuat DS hoc vien sinh nam 1990 va diem < 5";
		cout << "\nDanh sach hoc vien sinh nam 1990 va diem <5 la:\n";
		XuatDanhSachSinhNam1990VaDiemNhoHon5(l);
		break;
	default:
		break;
	}
	_getch();
}