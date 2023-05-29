
#define MAXCOT 70
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
	BSNode* right;
};
typedef BSNode* BSTree;
// khai báo nguyên mẫu hàm
BSNode* CreateNode(NhanVien x);
void CreateBST(BSTree& root);
int InsretNode(BSTree& root, NhanVien x);
void PosOrder(BSTree root);
void InOrder(BSTree root);
void PreOrder(BSTree root);
//=======================
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
int InsretNode(BSTree& root, NhanVien x)
{
	if (root != NULL)
	{
		if (strcmp(root->key.maNV, x.maNV) == 0) // đã tồn tại x
			return 0;
		if (strcmp(root->key.maNV, x.maNV) > 0)
			return InsretNode(root->left, x);//tìm x bên cây con trái
		else
			return InsretNode(root->right, x); // tìm x bên cây con phải
	}
	root = CreateNode(x);
	if (root != NULL)
		return 1;
	return -1; // chèn thành công

}
int File_BST(BSTree& root, char* filename)
{
	ifstream in(filename);
	if (!in)
		return 0;
	KeyType maNV;
	int kq;
	CreateBST(root);
	NhanVien x;
	while (!in.eof())
	{
		in >> x.maNV;
		in >> x.hoVaTen;
		in >> x.namSinh;
		in >> x.diaChi;
		in >> x.luong;
		kq = InsretNode(root, x);
		if (kq == 0 || kq == -1)
			return 0;
	}
	in.close();
	return 1;

}
// xuất tiêu đề
void XuatTieuDe()
{
	int i;
	cout << "\n";
	for (int i = 1; i <= MAXCOT; i++)
		cout << "=";
	cout << "\n";
	cout << setiosflags(ios::left);
	cout << ':'
		<< setw(8) << "Ma Nv"
		<< ':'
		<< setw(25) << "Ho va Ten"
		<< ':'
		<< setw(5) << "NS"
		<< ':'
		<< setw(15) << "Dia Chi"
		<< ':'
		<< setw(13) << "Luong"
		<< ':';
	cout << "\n";
	for (int i = 1; i <= MAXCOT; i++)
		cout << "=";
	cout << ":";
}
// xuất 1 nhân viên
void Xuat_1NV(NhanVien p)
{
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(8) << p.maNV
		<< ':'
		<< setw(25) << p.hoVaTen
		<< ':'
		<< setw(5) << p.namSinh
		<< ':'
		<< setw(15) << p.diaChi
		<< ':'
		<< setw(13) << setprecision(2) << setiosflags(ios::fixed) << p.luong
		<< ':';
}
// xuất theo NLR
void PreOrder(BSTree root)
{
	if (root != NULL)
	{
		Xuat_1NV(root->key);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
// xuất theo LNR
void InOrder(BSTree root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		Xuat_1NV(root->key);
		InOrder(root->right);
	}
}
// xuất theo LRN
void PosOrder(BSTree root)
{
	if (root != NULL)
	{

		PosOrder(root->left);
		PosOrder(root->right);
		Xuat_1NV(root->key);
	}
}