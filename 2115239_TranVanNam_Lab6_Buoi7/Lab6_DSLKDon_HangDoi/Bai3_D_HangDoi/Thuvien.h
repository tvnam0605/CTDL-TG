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
	q.pHead = q.pTail = NULL;
}


void InsertTail(QUEUE& q, Data x)
{
	NODE* new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "\nLoi!";
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

void TapTin_Queue(char* filename, QUEUE& q)
{
	Data x;
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file!";
		return;
	}
	in >> x;
	EnQueue(q, x);
	while (!in.eof())
	{
		in >> x;
		EnQueue(q, x);
	}
	in.close();
}

void XuatQueue(QUEUE q)
{
	NODE* p = q.pHead;
	while (p != NULL)
	{
		cout << p->info << ' ';
		p = p->pNext;
	}
}

void Radix(QUEUE& q)
{
	int k, j, du, thuong;
	if (q.pHead == NULL)
	{
		cout << "\nDS rong";
		return;
	}
	int max, m;
	max = q.pHead->info;
	m = 0;
	NODE* p;
	for (p = q.pHead->pNext; p != NULL; p = p->pNext)
		if (p->info > max)
			max = p->info;
	while (max != 0)
	{
		max = max / 10;
		m++;
	}
	QUEUE q0, q1, q2, q3, q4, q5, q6, q7, q8, q9;
	CreatQueue(q0);
	CreatQueue(q1);
	CreatQueue(q2);
	CreatQueue(q3);
	CreatQueue(q4);
	CreatQueue(q5);
	CreatQueue(q6);
	CreatQueue(q7);
	CreatQueue(q8);
	CreatQueue(q9);
	k = 0;
	while (k < m)
	{
		while (q.pHead != NULL)
		{
			thuong = q.pHead->info;
			for (j = 0; j <= k; j++)
			{
				du = thuong % 10;
				thuong = thuong / 10;
			}
			switch (du)
			{
			case 0:
				EnQueue(q0, q.pHead->info);
				DeQueue(q);
				break;
			case 1:
				EnQueue(q1, q.pHead->info);
				DeQueue(q);
				break;
			case 2:
				EnQueue(q2, q.pHead->info);
				DeQueue(q);
				break;
			case 3:
				EnQueue(q3, q.pHead->info);
				DeQueue(q);
				break;
			case 4:
				EnQueue(q4, q.pHead->info);
				DeQueue(q);
				break;
			case 5:
				EnQueue(q5, q.pHead->info);
				DeQueue(q);
				break;
			case 6:
				EnQueue(q6, q.pHead->info);
				DeQueue(q);
				break;
			case 7:
				EnQueue(q7, q.pHead->info);
				DeQueue(q);
				break;
			case 8:
				EnQueue(q8, q.pHead->info);
				DeQueue(q);
				break;
			case 9:
				EnQueue(q9, q.pHead->info);
				DeQueue(q);
				break;
			}
		}
		while (q0.pHead != NULL)
		{
			EnQueue(q, q0.pHead->info);
			DeQueue(q0);
		}
		while (q1.pHead != NULL)
		{
			EnQueue(q, q1.pHead->info);
			DeQueue(q1);
		}
		while (q2.pHead != NULL)
		{
			EnQueue(q, q2.pHead->info);
			DeQueue(q2);
		}
		while (q3.pHead != NULL)
		{
			EnQueue(q, q3.pHead->info);
			DeQueue(q3);
		}
		while (q4.pHead != NULL)
		{
			EnQueue(q, q4.pHead->info);
			DeQueue(q4);
		}
		while (q5.pHead != NULL)
		{
			EnQueue(q, q5.pHead->info);
			DeQueue(q5);
		}
		while (q6.pHead != NULL)
		{
			EnQueue(q, q6.pHead->info);
			DeQueue(q6);
		}
		while (q7.pHead != NULL)
		{
			EnQueue(q, q7.pHead->info);
			DeQueue(q7);
		}
		while (q8.pHead != NULL)
		{
			EnQueue(q, q8.pHead->info);
			DeQueue(q8);
		}
		while (q9.pHead != NULL)
		{
			EnQueue(q, q9.pHead->info);
			DeQueue(q9);
		}
		k++;
	}
}