int DemSoNut(BSTree root)
{
	if (root == NULL)
		return 0;
	return 1 + DemSoNut(root->left) + DemSoNut(root->right);
}
BSTree Sreach(BSTree root, KeyType x)
{
	if (root != NULL)
	{
		if (strcmp(root->key.maNV, x) == 0)
			return root;
		else
			if (strcmp(root->key.maNV, x) > 0)
				return Sreach(root->left, x);
			else
				return Sreach(root->right, x);
	}
	return NULL;
}
BSTree SreachTen(BSTree root, KeyType x)
{
	if (root != NULL)
	{
		if (strcmp(root->key.hoVaTen, x) == 0)
			return root;
		else
			if (strcmp(root->key.hoVaTen, x) > 0)
				return Sreach(root->left, x);
			else
				return Sreach(root->right, x);
	}
	return NULL;
}
// kiểm tra nút khóa cho trước có phải là nút lá
int IsLeaf_x(BSTree root, KeyType x)
{
	int kq = 0; 
	BSTree T = Sreach(root, x);
	if (T == NULL)
		kq = -1; // x không có trong cây
	else
		kq = (T->left == NULL) && (T->right == NULL);
	return kq;
}
int DemNutLa(BSTree root)
{
	int soNutLa;
	if (root == NULL)
		soNutLa = 0;
	else
		if (root->left == NULL && root->right == NULL)
		{
			Xuat_1NV(root->key);
			soNutLa = 1;
		}
		else
			soNutLa = DemNutLa(root->left) + DemNutLa(root->right);
	return soNutLa;
}
int TinhMax(int a, int b)
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