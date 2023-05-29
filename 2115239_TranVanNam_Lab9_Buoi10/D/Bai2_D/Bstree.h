//Dinh nghia Cau truc du lieu :BST
typedef int KeyType; //Kieu du lieu cua thanh phan du lieu cua cac nut trong cay la int
//Kieu cac nut cua cay : BSNode
struct BSNode
{
	KeyType key;
	BSNode* left; //Chua dia chi cay con trai
	BSNode* right; //Chua dia chi cay con phai
};
//Kieu CTDL Cay nhi phan tim kiem : kieu con tro tro den cac nut kieu BSNode
typedef BSNode* BSTree;
//==================================
//Khai bao nguyen mau cac ham
//Cac ham he thong
void CreateBST(BSTree& root); //Tao cay BST rong
BSNode* CreateNode(KeyType x);
//Chen
int InsertNode(BSTree& root, KeyType x); //Chen x vao cay BST
//Nhap, xuat (duyet va in)
int File_BST(BSTree& root, char* filename); //Tao cay BST tu file
void PreOrder(BSTree root);//NLR
void InOrder(BSTree root); //LNR
void PosOrder(BSTree root); //LRN
KeyType TinhMax(KeyType a, KeyType b);
int TinhChieuCao(BSTree root);
int TimMuc_x(BSTree root, KeyType x);
//============================
BSNode* CreateNode(KeyType x)
{
	BSNode* p = new BSNode;
	if (p != NULL)
	{
		p->key = x;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}
void CreateBST(BSTree& root)
{
	root = NULL;
}
int InsertNode(BSTree& root, KeyType x)
{
	//Cay khac rong
	if (root != NULL)
	{
		if (root->key == x)
			return 0; // x da co san
		if (root->key > x)
			return InsertNode(root->left, x);
		else
			return InsertNode(root->right, x);
	}//root == NULL
	root = CreateNode(x);
	if (root == NULL)
		return -1;
	return 1;
}
int File_BST(BSTree& root, char* filename)
{
	ifstream in(filename);
	if (!in)
		return 0;
	KeyType x;
	int kq;
	CreateBST(root);
	while (!in.eof())
	{
		in >> x;
		kq = InsertNode(root, x);
			if (kq == 0 || kq == -1)
				return 0;
	}
	in.close();
	return 1;
}
void PreOrder(BSTree root)
{
	if (root != NULL)
	{
		cout << root->key << '\t';
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
void InOrder(BSTree root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		cout << root->key << '\t';
		InOrder(root->right);
	}
}
void PosOrder(BSTree root)
{
	if (root != NULL)
	{
		PosOrder(root->left);
		PosOrder(root->right);
		cout << root->key << '\t';
	}
}
KeyType TinhMax(KeyType a, KeyType b)
{
	if (a >= b)
		return a;
	return b;
}
int TinhChieuCao(BSTree root)
{
	int h;
	if (root == NULL)
		h = -1;
	else

		if (root->left == NULL && root->right == NULL)
			h = 0;
		else
			h = 1 + TinhMax(TinhChieuCao(root->left), TinhChieuCao(root->right));
	return h;
		
}
int TimMuc_x(BSTree root, KeyType x)
{
	int muc;
	muc = 0;
	BSTree T = root;
	while (T != NULL)
	{
		if (T->key == x)
			break;
		else
		{
			muc++;
			if (T->key > x)
				T = T->left;
			else
				T = T->right;
		}
	}
	return muc;
}