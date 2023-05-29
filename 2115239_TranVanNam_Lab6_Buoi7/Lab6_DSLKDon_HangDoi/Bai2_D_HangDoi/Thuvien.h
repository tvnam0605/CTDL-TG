#define MAX 100
#define NULLDATA ' '

typedef char Data;

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

NODE* GetNode(Data x)
{
	NODE* p;
	p = new NODE;
	if (p != NULL)
	{
		p->info = x;
		p->pNext = NULL;
	}
	return p;
}

void CreatQueue(QUEUE& q)
{
	q.pHead = NULL;
	q.pTail = NULL;
}

int IsEmpty(QUEUE q)
{
	if (q.pHead == NULL)
		return 1;
	return 0;
}

void InsertTail(QUEUE& q, Data x)
{
	NODE* new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "\nLoi cap phat bo nho!";
		return;
	}
	if (q.pHead == NULL)
	{
		q.pHead = new_ele;
		q.pTail = q.pHead;
	}
	else
	{
		q.pTail->pNext = new_ele;
		q.pTail = new_ele;
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
	if (q.pHead == NULL)
		return NULLDATA;
	p = q.pHead;
	x = p->info;
	q.pHead = q.pHead->pNext;
	delete p;
	if (q.pHead == NULL)
		q.pTail = NULL;
	return x;
}

void File_String(char a[MAX])
{
	ifstream in("test.txt");
	if (!in)
	{
		cout << "\nLoi mo file!";
		return;
	}
	in >> a;
	in.close();
}

void Xuat_Queue(QUEUE q)
{
	NODE* p = q.pHead;
	while (p != NULL)
	{
		cout << p->info;
		p = p->pNext;
	}
}

void XuLy_ThaoTac(char a[MAX])
{
	QUEUE q;
	CreatQueue(q);
	char c;
	int i;
	for (i = 0; a[i] != NULL; i++)
	{
		c = a[i];
		if ('A' <= c && c <= 'Z')
		{
			EnQueue(q, c);
			Xuat_Queue(q);
		}
		else if (c == '*')
		{
			if (DeQueue(q))
				Xuat_Queue(q);
		}
	}
	cout << "\nKet qua sau khi thuc hien chuoi thao tac \"" << a << "\":\n";
	Xuat_Queue(q);
	cout << endl;
	_getch();
}
