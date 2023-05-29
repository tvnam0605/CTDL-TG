int DemSoNut(BSTree root)
{
	if (root == NULL)
		return 0;
	return 1 + DemSoNut(root->left) + DemSoNut(root->right);
}
BSTree Search(BSTree root, KeyType x)
{
	if (root != NULL)
	{
		if (strcmp(root->key.maNV, x) == 0)
			return root;
		else if (strcmp(root->key.maNV, x) > 0)
			return Search(root->left, x);
		else
			return Search(root->right, x);

	}
	return NULL;
}
void Xuat_HV_Ten(BSTree root, char ten[8])
{
	int dem = 0;
	if (root != NULL)
	{
		if (_strcmpi(root->key.hoVaTen, ten) == 0)
		{
			dem++;
			Xuat_NV(root->key);
		}
		Xuat_HV_Ten(root->left, ten);
		Xuat_HV_Ten(root->right, ten);
	}
}

// tinh chieu cao
int TinhMax(int a, int b)
{
	if (a >= b)
		return a;
	return b;
}
int TinhChieuCao(BSTree root)
{
	int h = 0;
	if (root == NULL)
		h = -1;
	else if (root->left == NULL && root->right == NULL)
		h = 1;
	else
		h = 1 + TinhMax(TinhChieuCao(root->left), TinhChieuCao(root->right));
	return h;
}
// dem nut la
int DemNutLa(BSTree root)
{
	int soNutLa = 0;
	if (root == NULL)
		soNutLa = 0;
	else if (root->left == NULL && root->right == NULL)
	{
		Xuat_NV(root->key);
		soNutLa = 1;
	}
	else
		soNutLa = DemNutLa(root->left) + DemNutLa(root->right);
	return soNutLa;

}
// kiem tra x co phai nut la
int KiemtTraNutla_x(BSTree root, KeyType x)
{
	int kq = 0;
	BSTree T = Search(root, x);
	if (T == NULL)
		kq = -1; // x khong ton tai
	else
		kq = (T->left == NULL) && (T->right == NULL);
	return kq;
}
BSTree DeleteMax(BSTree& root)
{
	BSTree k = 0;
	if (root->right == NULL)
	{
		k = root;
		root = root->left;
		return k;
	}
	return DeleteMax(root->right);
}
int DeleteNode(BSTree& root, KeyType x)
{
	if (root != NULL)
	{
		if (strcmp(root->key.maNV, x) == 0)
		{
			if (root->left == NULL && root->right == NULL)
				root = NULL;
			else if (root->left == NULL)
			{
				root = root->right;
			}
			else if (root->right == NULL)
			{
				root = root->left;
			}
			else
				root = DeleteMax(root->right);
		}
		else if (strcmp(root->key.maNV, x) > 0)
		{
			DeleteNode(root->left,x);
		}
		else
			DeleteNode(root->right, x);
		return 1;
	}
	return 0;
}
int DeleteNode_LamDong(BSTree& root, KeyType x)
{
	if (root != NULL)
	{
		if (strcmp(root->key.diaChi, x) == 0)
		{
			if (root->left == NULL && root->right == NULL)
				root = NULL;
			else if (root->left == NULL)
			{
				root = root->right;
			}
			else if (root->right == NULL)
			{
				root = root->left;
			}
			else
				root = DeleteMax(root->right);
			DeleteNode(root->right, x);
			DeleteNode(root->left, x);
		}
		else
		{
			DeleteNode(root->right, x);
			DeleteNode(root->left, x);
		}
		
			
		return 1;
	}
	return 0;
}
int TimMuc_X(BSTree root, KeyType x)
{
	int muc;
	muc = 0;
	BSTree T = root;
	while (T != NULL)
	{
		if (T->key.maNV == x)
			break;
		else
		{
			muc++;
			if (T->key.maNV > x)
				T = T->left;
			else
				T = T->right;
		}
	}
	return muc;

}
int KiemTra(BSTree root, KeyType x)
{
	int kq;
	BSTree T = Search(root, x);
	if (T == NULL)
		kq = -1;
	else
		kq = (T->left==NULL) && (T->right==NULL);
	return kq;
}