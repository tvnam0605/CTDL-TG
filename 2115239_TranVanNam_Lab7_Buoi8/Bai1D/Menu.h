void XuatMenu()
{
	//Tim kiem
	cout <<"\n0. Thoat Khoi chuong trinh";
	cout << "\n1. Tao du lieu ";
	cout << "\n2. Xem du lieu";
	cout << "\n3. Tim x - Co / Khong";
	cout << "\n4. Tim x - Tra ve vi tri nut dau tien xuat hien neu co";
	cout << "\n5. Tim x - Tra ve vi tri nut cuoi cung xuat hien neu co";
	cout << "\n6. Tim x - Xuat cac vi tri xuat hien neu co";
	cout << "\n7. Xuat DS moi, voi Head moi tro toi nut x xuat hien cuoi cung";
	cout << "\n8. Chen x vao dau danh sach vong";
	cout << "\n9. Chen x vao cuoi danh sach vong";
	cout << "\n10. Huy nut dau danh sach vong";
	cout << "\n11.Huy nut cuoi danh sach vong";
	cout << "\n12. Huy toan bo danh sach vong";
	cout << "\n13. Dem so nut danh sach vong";
}
int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("cls");
		XuatMenu();
		cout << "Nhap mot so ( 0 <= so <=" << soMenu << ") de chon menu, stt = ";
		cin >> stt;
		if (0 <= stt <= soMenu)
			break;
	}
	return stt;
}
void XuLyMenu(int menu, LLIST l)
{
	char filename [MAX];
	int kq;
	int x = 0;
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh ";
			break;
	case 1:
		system("cls");
			cout << "\n1. Tao du lieu ";
			do
			{
				system("CLS");
				cout << "\nNhap ten tap tin, filename = ";
				_flushall();
				cin >> filename;
				if (!File_LLIST(filename, l))
				{
					cout << "\nLoi mo file ! nhap lai\n";
					_getch();
				}
				else
				{
					cout << "\nDu lieu tap tin " << filename << " da duoc chuyen vao DSLKDV l"
						<< "\nNhan phim bat ky de tiep tuc";
					_getch();
					break;
				}
			} while (1);
			break;
	case 2:
		system("cls");
			cout << "\n2. Xem du lieu";
			cout << "\nDu lieu ban vua nhap la:\n ";
			Output_Llist(l);
			cout << endl;
			break;
	case 3:
		system("cls");
			cout << "\n3. Tim x - Co / Khong";
			cout << "\nNhap phan tu x can tim, x = ";
			cin >> x;
			kq = Search(l, x);
			if (kq == 0)
				cout << "\nKhong co phan tu x trong mang.";
			cout << "\nco phan tu x trong mang.";
				
				
			break;
	case 4:
		system("cls");
			cout << "\n4. Tim x - Tra ve vi tri nut dau tien xuat hien neu co";
			Search_Pos_First(l, x);
			break;
	case 5:
		system("cls");
			cout << "\n5. Tim x - Tra ve vi tri nut cuoi cung xuat hien neu co";
			Search_Pos_End(l, x);
			break;
	case 6:
		system("cls");
			cout << "\n6. Tim x - Xuat cac vi tri xuat hien neu co";
			break;
	case 7:
		system("cls");
			cout << "\n7. Xuat DS moi, voi Head moi tro toi nut x xuat hien cuoi cung";
			break;
	case 8:
		system("cls");
			cout << "\n8. Chen x vao dau danh sach vong";
			break;
	case 9:
		system("cls");
			cout << "\n9. Chen x vao cuoi danh sach vong";		
			break;
	case 10:
		system("cls");
			cout << "\n10. Huy nut dau danh sach vong";
			break;
	case 11:
		system("cls");
			cout << "\n11.Huy nut cuoi danh sach vong";
			break;
	case 12:
		system("cls");
			cout << "\n12. Huy toan bo danh sach vong";
			break;
	case 13:
		system("cls");
			cout << "\n13. Dem so nut danh sach vong";
			break;
	default:
		break;
	}
}