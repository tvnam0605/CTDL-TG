#define data x


struct HocVien
{
	char maHV[8];
	char hoHV[10];
	char tenLot[10];
	char tenHV[10];
	int namSinh;
	char queQuan[20];
	double diem;
};

typedef HocVien data;

struct tagNode
{
	data info;
	tagNode* pNext;
};

typedef tagNode Node;

struct LIST
{
	Node* pHead;
	Node* pTail;
};
//=======================================================
//Khai báo nguyên mẫu các hàm
//Nhap, Xuat , he thong
void Xuat_DS(LIST l);
int DocFile(char* f, LIST& l);
Node* GetNode(data x);
void CreatLIST(LIST& l);
int IsEmpty(LIST l);
//Yêu cầu menu
void XuatSinhVienQueLamDong_DTBTren5(LIST& l);
void XuatDanhSachCoTenHoaVaNamSinh1990(LIST& l);
void XuatDanhSachSinhNam1990VaDiemNhoHon5(LIST& l);
//Các hàm cơ bản
void Xuat_KeDon();
void Xuat_KeDoi();
void Xuat_TieuDe();
void Xuat_HV(data x);
void Xuat_DS(LIST l);
void AddHead(LIST& l, data x);
void AddTail(LIST& l, data x);
//=======================================================

void CreatLIST(LIST& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
int IsEmpty(LIST l)
{
	if (l.pHead == NULL) // DS rổng
		return 1;
	return 0;
}

Node* GetNode(data x)
{
	Node* p;
	p = new Node;
	if (p != NULL)
	{
		p->info = x;
		p->pNext = NULL;
	}
	return p;
}

void Xuat_KeDon()
{
	cout << endl << '|';
	for (int i = 1; i <= 74; i++)
		cout << '_';
	cout << '|';
}

void Xuat_KeDoi()
{
	cout << endl << '|';
	for (int i = 1; i <= 74; i++)
		cout << '=';
	cout << '|';
}

void Xuat_TieuDe()
{
	Xuat_KeDoi();
	cout << endl;
	cout << setiosflags(ios::left)
		<< '|'
		<< setw(11) << "Ma HV"
		<< ':'
		<< setw(11) << "Ho"
		<< ':'
		<< setw(11) << "Ten lot"
		<< ':'
		<< setw(11) << "Ten"
		<< ':'
		<< setw(5) << "NaS"
		<< ':'
		<< setw(14) << "Que quan"
		<< ':'
		<< setw(5) << "Diem"
		<< '|';
	Xuat_KeDoi();
}

void Xuat_HV(data x)
{
	cout << endl;
	cout << setiosflags(ios::left)
		<< '|'
		<< setw(11) << x.maHV
		<< ':'
		<< setw(11) << x.hoHV
		<< ':'
		<< setw(11) << x.tenLot
		<< ':'
		<< setw(11) << x.tenHV
		<< ':'
		<< setw(5) << x.namSinh
		<< ':'
		<< setw(14) << x.queQuan
		<< ':'
		<< setw(5) << setiosflags(ios::fixed) << setprecision(1) << x.diem
		<< '|';
}


void Xuat_DS(LIST l)
{
	int i;
	Node* p = l.pHead;
	Xuat_TieuDe();
	for (i = 0; p != NULL; i++, p = p->pNext)
	{
		Xuat_HV(p->info);
		if ((i + 1) % 5 == 0)
			Xuat_KeDon();
	}
	Xuat_KeDoi();
	cout << "\n\nDanh sach tong cong co " << i << " sinh vien";
}

void AddHead(LIST& l, data x)
{
	Node* new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "\nLoi cap phat bo nho!";
		return;
	}
	if (l.pHead == NULL)
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else
	{
		new_ele->pNext = l.pHead;
		l.pHead = new_ele;
	}
}

void AddTail(LIST& l, data x)
{
	Node* new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "\nLoi cap phat bo nho!";
		return;
	}
	if (l.pHead == NULL)
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}
}



void DocFile(const char* filename, LIST& l)
{
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file!";
		return;
	}
	data x;
	in >> x.maHV;
	in >> x.hoHV;
	in >> x.tenLot;
	in >> x.tenHV;
	in >> x.namSinh;
	in >> x.queQuan;
	in >> x.diem;
	AddTail(l, x);
	while (!in.eof())
	{
		in >> x.maHV;
		in >> x.hoHV;
		in >> x.tenLot;
		in >> x.tenHV;
		in >> x.namSinh;
		in >> x.queQuan;
		in >> x.diem;
		AddTail(l, x);
	}
	in.close();
}
// ================Xử lý các yêu cầu menu=================

void XuatSinhVienQueLamDong_DTBTren5(LIST &l)
{
	
	Node* p = l.pHead;
	Xuat_TieuDe();
	while (p != NULL)
	{
		if ( p->info.diem >5 && strcmp(p->info.queQuan,"Lam_Dong")==0)
			Xuat_HV(p ->info);
		p = p->pNext;
		
	}
	Xuat_KeDoi();
}
void XuatDanhSachCoTenHoaVaNamSinh1990(LIST& l)
{
	Node* p = l.pHead;
	Xuat_TieuDe();
	while (p != NULL)
	{
		if ((strcmp(p->info.tenHV, "Hoa") == 0) && p->info.namSinh == 1990)
			Xuat_HV(p->info);
		p = p->pNext;

	}
	Xuat_KeDoi();
}
void XuatDanhSachSinhNam1990VaDiemNhoHon5(LIST& l)
{
	Node* p = l.pHead;
	Xuat_TieuDe();
	while (p != NULL)
	{
		if (p->info.namSinh == 1990 && p->info.diem < 5)
			Xuat_HV(p->info);
		p = p->pNext;
	}
	Xuat_KeDoi();
}

