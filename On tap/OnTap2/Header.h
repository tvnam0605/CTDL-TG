#define MAXCOT 80
typedef char KeyType[8];
struct NgayThangNam
{
	unsigned ngaySinh;
	unsigned thangSinh;
	unsigned namSinh;
};
struct NhanVien
{
	KeyType maNV;
	char hoVaTen[25];
	NgayThangNam ntns;
	char diaChi[15];
	double bacLuong;
};
struct BSNode
{
	NhanVien key;
	BSNode* left;
	BSNode* right;
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
int InSertNode(BSTree& root, NhanVien x)
{
	if (root != NULL)
	{
		if (strcmp(root->key.maNV, x.maNV) == 0)
			return 0;
		else if (strcmp(root->key.maNV, x.maNV) > 0)
			return InSertNode(root->left, x);
		else
			return InSertNode(root->right, x);
	}
	root = CreateNode(x);
	if (root == NULL)
		return -1;
	return 1;
}
int File_BST(BSTree& root, char *filename)
{
	ifstream in(filename);
	if (!in)
		return 0;
	CreateBST(root);
	KeyType maNV;
	NhanVien x;
	int kq;
	while (!in.eof())
	{
		in >> x.maNV;
		in >> x.hoVaTen;
		in >> x.ntns.ngaySinh;
		in >> x.ntns.thangSinh;
		in >> x.ntns.namSinh;
		in >> x.diaChi;
		in >> x.bacLuong;
		kq = InSertNode(root, x);
		if (kq == 0 || kq == -1)
			return 0;
	}
	in.close();
	return 1;
}
void XuatTieuDe()
{
	int i;
	cout << "\n";
	for (int i = 1; i <= MAXCOT; i++)
		cout << "=";
	cout << "\n";
	cout << setiosflags(ios::left);
	cout << ':'
		<< setw(10) << "Ma NV"
		<< ':'
		<< setw(15) << "Ho va Ten"
		<< ':'
		<< setw(5) << "NgayS"
		<< ':'
		<< setw(5) << "ThangS"
		<<':'
		<<setw(15) << "NamS"
		<< ':'
		<< setw(10) << "Dia Chi"
		<< ':'
		<< setw(10) << "Bac luong"
		<< ':';
	cout << "\n";
	for (int i = 1; i <= MAXCOT; i++)
		cout << "=";
	cout << ":";

}
void Xuat_NV(NhanVien p)
{
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(10) << p.maNV
		<< ':'
		<< setw(15) << p.hoVaTen
		<< ':'
		<< setw(5) << p.ntns.ngaySinh
		<< ':'
		<< setw(5) << p.ntns.thangSinh
		<< ':'
		<< setw(15) << p.ntns.namSinh
		<<':'
		<< setw(10) << p.diaChi
		<< ':'
		<< setw(10) << setprecision(2) <<setiosflags(ios::fixed)<< p.bacLuong
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