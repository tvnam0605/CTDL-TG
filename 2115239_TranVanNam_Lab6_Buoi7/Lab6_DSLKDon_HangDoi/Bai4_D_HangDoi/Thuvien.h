struct nhom
{
	char ns[5];
	int stt;
};

typedef nhom Data;

struct tagNode
{
	Data info;
	tagNode* pNext;
};

typedef tagNode NODE;

struct QUEUE
{
	NODE* pHead;
	NODE* pTail;
};

NODE* GetNode(Data x);
void CreatQueue(QUEUE& q);
void InsertTail(QUEUE& q, Data x);
void EnQueue(QUEUE& q, Data x);
Data DeQueue(QUEUE& q);
void TapTin_Queue(char* filename, QUEUE& q);
int SoNhom(QUEUE q);
void XuatQueue(QUEUE q);
void  XuatLichTruc(QUEUE& q, int m);

NODE* GetNode(Data x)
{
	NODE* p;
	p = new NODE;
	if (p != NULL)
	{
		p->info = x;
		p->pNext = NULL;
		return p;
	}
}

void CreatQueue(QUEUE& q)
{
	q.pHead = q.pTail = NULL;
}

void InsertTail(QUEUE& q, Data x)
{
	NODE* p = GetNode(x);
	if (p == NULL)
	{
		cout << "\nLoi cap phat bo nho!";
		return;
	}
	if (q.pHead == NULL)
	{
		q.pHead = p;
		q.pTail = q.pHead;
	}
	else
	{
		q.pTail->pNext = p;
		q.pTail = p;
		q.pTail->pNext = NULL;
	}
}

void EnQueue(QUEUE& q, Data x)
{
	InsertTail(q, x);
}

Data DeQueue(QUEUE& q)
{
	NODE* p;
	Data x;
	//if (q.pHead == NULL)
	//	return;
	p = q.pHead;
	x = p->info;
	q.pHead = q.pHead->pNext;
	if (q.pHead == NULL)
		q.pTail = NULL;
	return x;
}

void TapTin_Queue(QUEUE& q)
{
	ifstream in("Test.txt");
	if (!in)
	{
		cout << "\nLoi mo file!";
		return;
	}
	Data p;
	in >> p.ns;
	in >> p.stt;
	EnQueue(q, p);
	while (!in.eof())
	{
		in >> p.ns;
		in >> p.stt;
		EnQueue(q, p);
	}
	in.close();
}

int SoNhom(QUEUE q)
{
	int sn = 0;
	NODE* p = q.pHead;
	if (p == NULL) return sn;
	while (p != NULL)
	{
		sn++;
		p = p->pNext;
	}
	return sn;
}

void XuatQueue(QUEUE q)
{
	NODE* p = q.pHead;
	while (p != NULL)
	{
		cout << p->info.ns << '\t' << p->info.stt << endl;
		p = p->pNext;
	}
}

void Sap_Tang_TTTruc(QUEUE& q)
{
	NODE* x, * y;
	for (x = q.pHead; x != NULL; x = x->pNext)
		for (y = x->pNext; y != NULL; y = y->pNext)
		{
			if (x->info.stt > y->info.stt)
				swap(x->info, y->info);
		}
}

void  XuatLichTruc(QUEUE& q, int m)
{
	int i, sn;
	Data x;
	int vong = 1;
	sn = SoNhom(q);
	Sap_Tang_TTTruc(q);
	cout << "\nVong " << vong << " :\n";
	for (i = 1; i <= m; i++)
	{
		cout << setiosflags(ios::left);
		cout << setw(13) << "\nTruc ngay thu " << setw(4) << i << setw(10) << " la nhom : ";
		x = DeQueue(q);
		cout << setw(5);
		cout << x.ns;
		EnQueue(q, x);
		if (i % sn == 0)
		{
			cout << "\n=========================";
			vong++;
			cout << "\nVong " << vong << " :\n";
		}
	}
	cout << endl;
}