#define MAXCOT 70

typedef char KeyType[8];
struct HocVien
{
	KeyType maHV;
	char hoHV[25];
	char tenLot[20];
	char tenHV[15];
	int namSinh;
	char queQuan[15];
	double diem;
};
// Kiểu dữ liệu của các nút
struct BSNode
{
	HocVien info;
	BSNode* left;
	BSNode* right;
};
// kiểu cây nhị phân tìm kiếm
typedef BSNode* BSTree;
//====================
BSNode* CreateNode(HocVien x);
//====================
// tạo nút với x cho trước
BSNode* CreateNode(HocVien x)
{
	BSNode* p = new BSNode;
	if (p != NULL)
	{
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}
// khởi tạo cây BST rỗng
void CreateBST(BSTree& root)
{
	root = NULL;
}
// thêm x vào cây BST
int InsertNode(BSTree& root, HocVien x)
{
	// cây khác rỗng
	if (root != NULL)
	{
		if (strcmp(root->info.maHV, x.maHV) == 0)
			return 0; // x đã có sẵn
		if ((strcmp(root->info.maHV, x.maHV) > 0))
			return InsertNode(root->left, x);
		else
			return InsertNode(root->right, x);
	}// root == NULL : chèn vị trí nút ngoài thích hợp - là nút sau khi chèn xong
	root = CreateNode(x);
	if (root == NULL)
		return -1;
	return 1; // thành công
}
// tạo cây BST từ file
int FIle_BST(BSTree& root, char* filename)
{
	ifstream in(filename);
	if (!in)
		return 0;
	KeyType maHV; // dùng đẻ đưa dữ liệu lên cây
	int kq;
	CreateBST(root);
	HocVien x;
	while (!in.eof())
	{
		in >> x.maHV;
		in >> x.hoHV;
		in >> x.tenLot;
		in >> x.tenHV;
		in >> x.namSinh;
		in >> x.queQuan;
		in >> x.diem;
		kq = InsertNode(root, x);
		if (kq == 0 || kq == -1)
			return 0;
	}
	in.close();
	return 1;
}
// Xuất tiêu đề;
void Title()
{
	int i;
	cout << "\n:";
	for (i = 1; i <= MAXCOT; i++)
		cout << "=";
	cout << ":\n";
	cout << setiosflags(ios::left);
	cout << ':'
		<< setw(8) << "Ma HV"
		<< ':'
		<< setw(10) << "Ho"
		<< ':'
		<< setw(10) << "Ten Lot"
		<< ':'
		<<setw(7) << "Ten"
		<< ':'
		<< setw(4) << "NS"
		<< ':'
		<< setw(14) << "Que Quan"
		<< ':'
		<< setw(12) << "Diem"
		<< ':';
	cout << "\n:";
	for (i = 1; i <= MAXCOT; i++)
		cout << "=";
	cout << ":";
}
// xuất 1 học viên
void Xuat_HV(HocVien p)
{
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(8) << p.maHV
		<< ':'
		<< setw(10) << p.hoHV
		<< ':'
		<< setw(10) << p.tenLot
		<< ':'
		<< setw(5) << p.tenHV
		<< ':'
		<< setw(5) << p.namSinh
		<< ':'
		<< setw(15) << p.queQuan
		<< ':'
		<< setw(12) << setprecision(2) << setiosflags(ios::fixed) << p.diem
		<< ':';
}
//Xuất cây theo thứ tự trước : LNR
void PreOrder(BSTree root)
{
	if (root != NULL)
	{
		Xuat_HV(root->info);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
//XUất cây theo thứ tự giữa : LNR
void InOrder(BSTree root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		Xuat_HV(root->info);
		InOrder(root->right);
	}
}
//Xuất cây theo thứ t : LRN
void PosOrder(BSTree root)
{
	if (root != NULL)
	{
		PosOrder(root->left);
		PosOrder(root->right);
		Xuat_HV(root->info);
	}
}
// Các yêu cầu của menu
// đếm số nút
int DemSoNut(BSTree root)
{
	if (root == NULL)
		return 0;
	return 1 + DemSoNut(root->left) + DemSoNut(root->right);
}
// XUất thong tin học viên khi biết mã học viên
BSTree TimKiem_maHV(BSTree root, KeyType x)
{
	if (root != NULL)
	{
		if (strcmp(root->info.maHV, x) == 0) // đã tìm thấy x
			return root;
		else
			if (strcmp(root->info.maHV, x) < 0)
				return TimKiem_maHV(root->right, x); // tìm x trong cây con phải
			else 
				return TimKiem_maHV(root->left, x); // tìm x trong cây con trái
	}
	return NULL; // không tồn tại
}
// hàm tính max
int TinhMax(int a, int b)
{
	if (a >= b)
		return a;
	return b;
}
// xác định chiều cao của cây
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
// xác định số nút của học viên khi biết mã học viên
int TimMuc_X(BSTree root, KeyType x)
{
	int muc;
	muc = 0;
	BSTree T = root;
	while (T != NULL)
	{
		if (strcmp(T->info.maHV, x) == 0)
			return muc;
		else
		{
			muc++;
			if (strcmp(T->info.maHV, x) > 0)
				T = T->left;
			else
				T = T->right;
		}
	}
	return -1; // T rỗng hoặc không có nút chứa x
}
// XUẤT CÁC HỌC VIÊN CÓ TÊN CHO TRƯỚC
BSTree TimKiem_TenHV(BSTree root, KeyType x)
{
	if (root != NULL)
	{
		if (_strcmpi(root->info.tenHV, x) == 0) // đã tìm thấy x
			return root;

		else
			if (_strcmpi(root->info.tenHV, x) < 0)
				return TimKiem_TenHV(root->right, x);
				// tìm x trong cây con phải
			else
				return TimKiem_TenHV(root->left, x); // tìm x trong cây con trái
		root++;
	}
	return NULL;
}
//BSTree XoaTheoMS(BSTree &root, KeyType x)
//{
//	if (root != NULL)
//		if (strcmp(root->info.maHV, x) == 0);
//	root--;
//	
//}
//int DeleteNode(HocVien x, BSTree& root)
//{
//	if (root != NULL)
//	{
//		if (strcmp(x.maHV, root->info.maHV) < 0)
//			return DeleteNode(x, root->left);
//		else
//			if (strcmp(x.maHV, root->info.maHV) > 0)
//				return DeleteNode(x, root->right);
//			else //x == root->key
//				if ((root->left == NULL) && (root->right == NULL)) //khong co con trai, khong co con
//
//					root = NULL;
//				else
//					if (root->left == NULL) //co 1 con : con phai, khong co con trai
//						root = root->right;
//					else
//						if (root->right == NULL) //co 1 con : con trai, khong co con phai
//							root = root->left;
//						else //co ca 2 con trai, phai
//							root->info = XoaTheoMS(root->right); //Huy nut co gia tri nho
//							 //nhat cua cay con phai x
//		return 1; //Thanh cong
//	}
//	return 0;
//}
