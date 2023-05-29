#define MAX 1000

struct HocVien
{
	char maHV[8];
	char ho[15];
	char tenLot[15];
	char ten[15];
	int NamS;
	char queQuan[11];
	double diem;
};

int ReadFile(char* filename, HocVien a[MAX], int& n)
{
	ifstream in(filename);
	if (!in)
	{
		return 0;
	}
	n = 0;
	while (!in.eof())
	{
		in >> a[n].maHV;
		in >> a[n].ho;
		in >> a[n].tenLot;
		in >> a[n].ten;
		in >> a[n].NamS;
		in >> a[n].queQuan;
		in >> a[n].diem;
		n++;

	}
	in.close();
	return 1;
}

void XuatTieuDe()
{
	int i;
	cout << "\n";
	cout << ':';
	for (i = 1; i <= 100; i++)
		cout << '=';
	cout << ':';
	cout << "\n";
	cout << setiosflags(ios::left);
	cout << setw(9) << "Ma HV"
		<< '	'
		<< setw(11) << "Ho"
		<< '	'
		<< setw(11) << "Ho Dem"
		<< '	'
		<< setw(11) << "Ten"
		<< '	'
		<< setw(6) << "NS"
		<< '	'
		<< setw(11) << "Que_Quan"
		<< '	'
		<< setw(6) << "Diem"
		<< '	';
	cout << "\n";
	cout << ':';
	for (i = 1; i <= 100; i++)
		cout << '=';
	cout << ':';
	cout << "\n";
}

void XuatKeNgangDon()
{
	cout << endl;
	cout << ':';
	for (int i = 0; i < 100; i++)
	{
		cout << '-';
	}
	cout << ':';
	cout << endl;
}

void XuatKeNgangDoi()
{
	cout << endl;
	cout << ':';
	for (int i = 0; i < 100; i++)
	{
		cout << '=';
	}
	cout << ':';
	cout << endl;
}

void Xuat1_HV(HocVien a)
{
	cout << endl;
	cout << setiosflags(ios::left)
		<< setw(9) << a.maHV
		<< '	'
		<< setw(11) << a.ho
		<< '	'
		<< setw(11) << a.tenLot
		<< '	'
		<< setw(11) << a.ten
		<< '	'
		<< setw(6) << a.NamS
		<< '	'
		<< setw(11) << a.queQuan
		<< '	'
		<< setw(6) << a.diem
		<< '	';
	cout << endl;
}
void HoanVi(HocVien& x, HocVien& y)
{
	HocVien t;
	t = x;
	x = y;
	y = t;
}

void XuatDanhSachHocVien(HocVien a[MAX], int n)
{
	XuatTieuDe();
	for (int i = 0; i < n; i++)
	{
		Xuat1_HV(*(a + i));
	}
	XuatKeNgangDoi();
}
void SelectionSort(HocVien a[MAX], int n)
{
	int cs_min, i, j;
	for (i = 0; i < n; i++)
	{
		cs_min = i;
		for (j = i + 1; j < n; j++)
			if (_strcmpi(a[cs_min].maHV, a[j].maHV) > 0)
				cs_min = j;
		swap(a[cs_min], a[i]);
	}
}
void Partition(HocVien a[MAX], int l, int r)
{
	int i, j;
	HocVien x;
	x = a[(l + r) / 2];
	i = l; j = r;
	do
	{
		while (a[i].diem < x.diem)
			i++;
		while (a[j].diem > x.diem)
			j--;
		if (i <= j)
		{
			HoanVi(a[i], a[j]);
			i++; j--;
		}
	} while (i <= j);
	if (l < j)
		Partition(a, l, j);
	if (i < r)
		Partition(a, i, r);

}
void QuickSort(HocVien a[MAX], int n)
{
	Partition(a, 0, n - 1);
}

void SapTangTheoTen(HocVien a[MAX], int n)
{
	int cs_min, i, j;
	for (i = 0; i < n; i++)
	{
		cs_min = i;
		for (j = i + 1; j < n; j++)
			if (_strcmpi(a[cs_min].ten, a[j].ten) > 0)
				cs_min = j;
		swap(a[cs_min], a[i]);
	}
}
