typedef int KeyType;
struct BSNode
{
	KeyType key;
	BSNode* left;
	BSNode* right;
};
typedef BSNode* BSTree;
// khai bao nguyen mau cac ham
void PreOrder(BSTree root);
void InOrder(BSTree root);
void PosOrder(BSTree root);
//=========================

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
// khoi tao cay bst rong
void CreateBST(BSTree& root)
{
	root = NULL;
}
 // them x vao cay
int InsertNode(BSTree &root, KeyType x)
{
	// cay khongrong
	if (root != NULL)
	{
		if (root->key == x)
			return 0;
		if (root->key > x)
			return InsertNode(root->left, x);
		else
			return InsertNode(root->right, x);
	}
	root = CreateNode(x);
	if (root == NULL)
		return -1;
	return 1;
}
// Tapo cay BST tu file
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