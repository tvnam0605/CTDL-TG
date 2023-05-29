#define MAX 80
typedef char KeyType[8];
struct NhanVien
{
	KeyType maNV;
	char hoVaTen[25];
	int namSinh;
	char diaChi[15];
	double luong;
};
struct BSNode
{
	NhanVien key;
	BSNode* left;
	BSNode *right;
};
typedef BSNode* BSTree;
BSNode* CreateNode(NhanVien x)
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
int InsertNode(BSTree& root, NhanVien x)
{
	if (root != NULL)
	{
		if (strcmp(root->key.maNV, x.maNV) == 0)
			return 0;
		else if (strcmp(root->key.maNV, x.maNV) > 0)
			return InsertNode(root->left, x);
		else
			return InsertNode(root->right, x);
	}
	root = CreateNode(x);
	if (root != NULL)
		return 1;
	return -1;
}
int File_BST(BSTree& root, char* filename)
{
	ifstream in(filename);
	if (!in)
		return 0;
	KeyType maNV;
	CreateBST(root);
	NhanVien x;
	int kq;
	
	
	while (!in.eof())
	{
		in >> x.maNV;
		in >> x.hoVaTen;
		in >> x.namSinh;
		in >> x.diaChi;
		in >> x.luong;
		kq = InsertNode(root,x);
		if (kq == 0 || kq == -1)
			return 0;

	}
	in.close();
	return 1;
}
void TieuDe()
{
	cout << "\n";
	for (int i = 0; i <= MAX; i++)
		cout << "=";
	cout << ":";
	cout << endl;
	cout << setiosflags(ios::left);
	cout << ':'
		<< setw(10) << "Ma NV"
		<< ':'
		<< setw(15) << "Ho va Ten"
		<< ':'
		<< setw(15) << "NamSinh"
		<< ':'
		<< setw(15) << "Dia Chi"
		<< ':'
		<< setw(5) << "Luong"
		<< ':';
	cout << "\n";
	for (int i = 1; i <= MAX; i++)
		cout << "=";
	cout << ":";
	
}
void Xuat_NV(NhanVien p)
{
	cout << "\n";
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(10) << p.maNV
		<< ':'
		<< setw(15) << p.hoVaTen
		<< ':'
		<< setw(15) << p.namSinh
		<< ':'
		<< setw(15) << p.diaChi
		<< ':'
		<< setw(20) <<setprecision(0)<< setiosflags(ios::fixed)<< p.luong
		<< ':';
}
void PreOrder(BSTree root)
{
	if (root != NULL)
	{
		Xuat_NV(root->key);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
void InOrder(BSTree root)
{
	if (root != NULL)
	{
		
		InOrder(root->left);
		Xuat_NV(root->key);
		InOrder(root->right);
	}
}
void PosOrder(BSTree root)
{
	if (root != NULL)
	{

		PosOrder(root->left);
		PosOrder(root->right);
		Xuat_NV(root->key);

	}
}
