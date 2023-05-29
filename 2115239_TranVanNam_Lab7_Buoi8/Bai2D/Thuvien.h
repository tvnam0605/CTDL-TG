 
//so ngau nhien n
int TaoSoNgauNhien()
{
	int n;
	srand(time(NULL));
	n = rand() % MAX + 1;
	return n;
}
//ham tra ve con tro tro den nut thu n-1
NODE* Node_q(LLIST l, int n)
{
	NODE* q;
	int dem = 1;//dem nut da qua
	q = l.pHead;
	if (q != NULL)
	{
		while (dem < n - 1)
		{
			q = q->pNext;
			dem++;
		}
	}
	return q;
}
//Huy nut sau q : huy xong, chuyen nut ke tiep la nut dau, q la cuoi
void Remove_Node_After_q(LLIST& l, NODE* q)
{
	if (l.pHead == NULL)
	{
		cout << "\nDanh sach rong!";
		_getch();
		return;
	}
	NODE* p = q->pNext;
	q->pNext = p->pNext;
	delete p;
	l.pHead = q->pNext;
	if (l.pHead == NULL) //con lai rong
		l.pTail = NULL;
	else
		if (l.pHead != l.pTail) //khong phai con lai 1 nut
			l.pTail = q; //cap nhat tail
}
//dem nut
int SoNut(LLIST l)
{
	int dem;
	NODE* p = l.pHead;
	if (p == NULL)
		dem = 0;
	else
	{
		dem = 1;
		while (p != l.pTail)
		{
			dem++;
			p = p->pNext;
		}
	}
	return dem;
}
//Xuat cac binh si ra khoi vong, binh si chon di cau cuu
void CryForHelp(LLIST l)
{
	int n = TaoSoNgauNhien();
	int sn = SoNut(l);
	NODE* q;
	int lan = 0;
	cout << "\nSo ngau nhien: n = " << n;
	cout << "\n KET QUA TUYEN CHON:\n";
	while (sn > 1)
	{
		q = Node_q(l, n); //tro den nut thu n-1
		lan++;
		cout << setiosflags(ios::left);
		cout << setw(21) << "\nRa khoi vong lan thu " << setw(4) << lan << setw(13)
			<< " la binh si : " << q->pNext->info;
		Remove_Node_After_q(l, q);
		sn--;
	}
	cout << "\n\n Binh si duoc cu di cau cuu la : " << l.pHead->info;
}