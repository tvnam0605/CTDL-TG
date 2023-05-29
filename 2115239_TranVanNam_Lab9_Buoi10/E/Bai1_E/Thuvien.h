//List <-> Queue + Stack
//Kieu thanh phan du lieu cua cac nut trong Queue, stack la BSNode* <-> BSTree
//Kieu cac nut trong Queue, Stack
struct NODE
{
	BSTree info;
	NODE* pNext;
};
struct List //Queeue, Stack
{
	NODE* pHead;
	NODE* pTail;
};
//Tao nut rong
NODE* GetNode(BSTree info)
{
	NODE* p = new NODE;
	if (p != NULL)
	{
		p->info = info;
		p->pNext = NULL;
	}
	return p;
}
//Tao List rong (Queue, Stack)
void CreateList(List& l)
{
	l.pHead = l.pTail = NULL;
}
int IsEmpty(List l)
{
	if (l.pHead == NULL) return 1;
	return 0;
}
//Them cuoi : EnQueue -> phuc vu cho Queue
void Insertail(List& l, BSTree info)
{
	NODE* x = GetNode(info);
	if (x == NULL)
		return;
	if (l.pHead == NULL)
	{
		l.pHead = x;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = x;
		l.pTail = x;
		l.pTail->pNext = NULL;
	}
}
//Xoa dau, tra ve du lieu nut bi xoa : ->Phuc vu cho Queue, Stack : DeQueue , Pop
BSTree RemoHead(List& l)//lay ra va huy ptu dau list.
{
	NODE* p;
	BSTree x;
	if (l.pHead == NULL)
		return NULL;
	else
	{
		p = l.pHead;
		x = p->info;
		l.pHead = p->pNext;
		delete p;
		return x;
	}
}
//Them dau, phuc vu cho Stack : Push
void InsertHead(List& s, BSTree info)
{
	NODE* x = GetNode(info);
	if (x == NULL)
		return;
	if (s.pHead == NULL)
	{
		s.pHead = x;
		s.pTail = s.pHead;
	}
	else
	{
		x->pNext = s.pHead->pNext;
		s.pHead->pNext = x;
		s.pHead = x;
	}
}
//==========================================================
int DemSoNut(BSTree root)
{
	if (root == NULL)
		return 0;
	return 1 + DemSoNut(root->left) + DemSoNut(root->right);
}
// xac dinh chieu cao
int TinhMax(int a, int b)
{
	if (a >= b)
		return a;
	return b;
}
int TinhChieuCaoCuaCay(BSTree root)
{
	int h;
	if (root == NULL)
		h = -1;
	else
		if (root->left == NULL && root->right == NULL)
			h = 0;
		else
			h = 1 + TinhMax(TinhChieuCaoCuaCay(root->left), TinhChieuCaoCuaCay(root->right));
	return h;
}

// dem so nut la
int DemNutLa(BSTree root)
{
	int soNutLa;
	if (root == NULL)
		soNutLa = 0;
	else
		if (root->left == NULL && root->right == NULL)
		{
			cout << root->key << '\t';
			soNutLa = 1;
		}
		else
			soNutLa = DemNutLa(root->left) + DemNutLa(root->right);
	return soNutLa;
}
//==========================================
//Xuat theo chieu rong (tung muc) : Dung Queue
void BFS(BSTree root)
{
	List q;
	NODE* t;
	BSTree p;
	CreateList(q);
	if (root == NULL)
		cout << "\n Cay rong.";
	else
	{
		t = GetNode(root);
		Insertail(q, t->info);
		do
		{
			p = RemoHead(q);
			cout << p->key << '\t';
			if (p->left != NULL)
			{
				t = GetNode(p->left);
				Insertail(q, t->info);
			}
			if (p->right != NULL)
			{
				t = GetNode(p->right);
				Insertail(q, t->info);
			}
		} while (IsEmpty(q) == 0);
		cout << endl;
	}
}
//Xuat nut muc k
void BFS_Muc_k(BSTree root, int k)
{
	List q;
	NODE* t;
	BSTree p;
	CreateList(q);
	if (root == NULL)
		cout << "\n Cay rong.";
	else
	{
		t = GetNode(root);
		Insertail(q, t->info);
		do
		{
			p = RemoHead(q);
			if (TimMuc_x(root, p->key) == k)
				cout << p->key << '\t';
			if (p->left != NULL)
			{
				t = GetNode(p->left);
				Insertail(q, t->info);
			}
			if (p->right != NULL)
			{
				t = GetNode(p->right);
				Insertail(q, t->info);
			}
		} while (IsEmpty(q) == 0);
		cout << endl;
	}
}
//Xuat theo muc
void BFS_TheoMuc(BSTree root)
{
	int i, h;
	h = TinhChieuCaoCuaCay(root);
	cout << "\n\nXuat BST theo chieu rong (tung muc):\n";
	for (i = 0; i <= h; i++)
	{
		cout << endl << "Muc " << i << " : ";
		BFS_Muc_k(root, i);
	}
}
//----------------------------------------------
// Stack
//----------------------------------------------
//Xuat theo chieu sau : dung Stack
void DFS(BSTree root)
{
	List s;
	NODE* t;
	BSTree p;
	CreateList(s);
	if (root == NULL)
		cout << "\n Cay rong.";
	else
	{
		t = GetNode(root);
		InsertHead(s, t->info);
		do
		{
			p = RemoHead(s);
			cout << p->key << '\t';
			if (p->left != NULL)
				DFS(p->left);
			if (p->right != NULL)
			{
				t = GetNode(p->right);
				InsertHead(s, t->info);
			}
		} while (IsEmpty(s) == 0);
		cout << endl;
	}
}
// tim kiem nut khoa x cho truoc
BSTree Search(KeyType x, BSTree root)
{
	if (root != NULL)
	{
		if (root->key == x) //Tim thay x
			return root;
		else
			if (root->key < x)
				return Search(x, root->right); //tim x trong cay con phai
			else
				return Search(x, root->left); //tim x trong cay con trai
	}
	return NULL; //khong co
}
//Huy nut co gia tri lon nhat cua cay con trai cua root
//Input root
//Output : root (da xoa duoc nut co gia tri lon nhat cua cay con trai root
// x; khoa cua nut bi xoa
KeyType DeleteMax(BSTree& root)
{
	KeyType k;
	if (root->right == NULL)
	{
		k = root->key;
		root = root->left;
		return k;
	}
	else
		return DeleteMax(root->right);
}
//Huy mot nut co khoa cho truoc ra khoi cay
//Input : x, root
//Output : 1, root (cay BST ket qua root) neu thanh cong
// 0; khong thanh cong
int DeleteNode(KeyType x, BSTree& root)
{
	if (root != NULL)
	{
		if (x < root->key)
			DeleteNode(x, root->left);
		else
			if (x > root->key)
				DeleteNode(x, root->right);
			else //x == root->key
				if ((root->left == NULL) && (root->right == NULL))
					//khong co con trai, khong co con phai
					root = NULL;
				else
					if (root->left == NULL)
						//co 1 con : con phai, khong co con trai
						root = root->right;
					else
						if (root->right == NULL)
							//co 1 con : con trai, khong co con phai
							root = root->left;
						else //co ca 2 con trai, phai
							root->key = DeleteMax(root->right);
		return 1; //Thanh cong
	}
	return 0;//khong thanh cong
}