#define MAXCOT 70
typedef char KeyType[8];
struct HocVien
{
	KeyType maHV;
	char hoVaTen[25];
	int namSinh;
	char diaChi[15];
	double diem;
};
struct BSNode
{
	HocVien key;
	BSNode* left;
	BSNode* right;
};
typedef BSNode* BSTree;
//=====================================
//khai bao nguyen mau
BSNode* CreateNode(HocVien x);
void CreateBST(BSTree& root);
int InsertNode(BSTree& root, HocVien x);
void PosOrder(BSTree root);
void InOrder(BSTree root);
void PreOrder(BSTree root);
//=====================================
BSNode* CreateNode(HocVien x)
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
int InsertNode(BSTree& root, HocVien x)
{
	if (root != NULL)
	{
		if (strcmp(root->key.maHV, x.maHV) == 0)
			return 0;
		if (strcmp(root->key.maHV, x.maHV) > 0)
			return InsertNode(root->left, x);
		else
			return InsertNode(root->right, x);
	}
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
	KeyType maHV;
	int kq;
	CreateBST(root);
	HocVien x;
	while (!in.eof())
	{
		in >> x.maHV;
		in >> x.hoVaTen;
		in >> x.namSinh;
		in >> x.diaChi;
		in >> x.diem;
		kq = InsertNode(root, x);
		if (kq == 0 || kq == -1)
			return 0;
	}
	in.close();
	return 1;
}
void TieuDe()
{
	int i;
	cout << "\n:";
	for (i = 1; i <= MAXCOT; i++)
		cout << "=";
	cout << ":\n";
	cout << setiosflags(ios::left);
	cout << ':'
		<< setw(8) << "Ma NV"
		<< ':'
		<< setw(25) << "Ho va Ten"
		<< ':'
		<< setw(5) << "NS"
		<< ':'
		<< setw(15) << "Dia Chi"
		<< ':'
		<< setw(13) << "Diem"
		<< ':';
	cout << "\n:";
	for (i = 1; i <= MAXCOT; i++)
		cout << "=";
	cout << ":";
}
void Xuat1_HV(HocVien p)
{
	cout << endl;
	cout <<  setiosflags(ios::left)
		<<':'
		<< setw(8) << p.maHV
		<< ':'
		<< setw(25) << p.hoVaTen
		<< ':'
		<< setw(5) << p.namSinh
		<< ':'
		<< setw(15) << p.diaChi
		<< ':'
		<< setw(13) << setprecision(2) << setiosflags(ios::fixed) << p.diem
		<< ':';
}
void PreOrder(BSTree root)
{
	if (root != NULL)
	{
		Xuat1_HV(root->key);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
void InOrder(BSTree root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		Xuat1_HV(root->key);
		InOrder(root->right);
	}
}
void PosOrder(BSTree root)
{
	if (root != NULL)
	{
		PosOrder(root->left);
		PosOrder(root->right);
		Xuat1_HV(root->key);
	}
}
//==============================================================================================================



