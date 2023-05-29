void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao bang diem hoc vien ";
	cout << "\n2. Xuat bang diem hoc vien";
	cout << "\n3. Sap bang diem tang dan theo ma hoc vien bang thuat giai chon truc tiep.";
	cout << "\n4. Sap bang diem tang dan theo diem bang thuat giai QuickSotr";
	cout << "\n5. Sap xep bang diem theo cac yeu cau sau.\n - Tang dan theo ten hoc vien bang thuat giai chon truc tiep.\n - neu trung ten thi tang dan theo ho hoc vien.\n - neu van co hoc vien trung nhau thi tang dan theo ten lot hoc vien.";
	cout << "\n====================================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap 1 so trong khoang tu [0,..," << soMenu << "] de chon chuc nang, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}
void XuLyMenu(int menu, HocVien a[MAX], int& n)
{
	
	char filename[MAX];
	int kq;
	switch (menu)
	{
	case 0:
		system("cls");
		cout << "\n0. Thoat Khoi chuong trinh";
		break;
	case 1:
		system("cls");
		cout << "\n1. Tao bang diem hoc vien ";
		cout << "\nNhap ten file can mo:  ";
		cin >> filename;
		kq = ReadFile(filename, a, n);
		if (kq != 0)
		{
			cout << "\nDanh sach hoc vien hien tai co " << n << " nhan vien ";
			XuatDanhSachHocVien(a, n);
		}
		_getch();
		break;
	case 2:
		system("cls");
		cout << "\n2. Xuat bang diem hoc vien";
		cout << "\nDanh sach hoc vien hien tai co " << n << " nhan vien ";
		XuatDanhSachHocVien(a, n);
		_getch();
		break;
	case 3:
		system("cls");

		cout << "\n3. Sap bang diem tang dan theo ma hoc vien bang thuat giai chon truc tiep.";
		cout << "\nDanh sach hoc vien truoc khi sap xep\n";
		XuatDanhSachHocVien(a, n);
		SelectionSort(a, n);
		cout << "\nDanh sach sau khi sap xep la\n";
		XuatDanhSachHocVien(a, n);
		_getch();
		
		break;
	case 4:
		system("cls");

		cout << "\n4. Sap bang diem tang dan theo diem bang thuat giai QuickSotr";
		cout << "\nDanh sach hoc vien truoc khi sap xep\n";
		XuatDanhSachHocVien(a, n);
		QuickSort(a,n);
		cout << "\nDanh sach sau khi sap xep la\n";
		XuatDanhSachHocVien(a, n);
		_getch();
		break;
	case 5:
		system("cls");
		cout << "\n5. Sap xep bang diem theo cac yeu cau sau.\n - Tang dan theo ten hoc vien bang thuat giai chon truc tiep.\n - neu trung ten thi tang dan theo ho hoc vien.\n - neu van co hoc vien trung nhau thi tang dan theo ten lot hoc vien.";
		cout << "\nDanh sach hoc vien truoc khi sap xep\n";
		XuatDanhSachHocVien(a, n);
		SapTangTheoTen(a, n);
		cout << "\nDanh sach sau khi sap xep la\n";
		XuatDanhSachHocVien(a, n);
		_getch();
		break;

	}
}
