int DemSoNut(BSTree root)
{
	if (root == NULL)
		return 0;
	return 1 + DemSoNut(root->left) + DemSoNut(root->right);
}
int DemNutLa(BSTree root)
{
	int soNutLa = 0;
	if (root == NULL)
		soNutLa = 0;
	else if (root->left == NULL && root->right == NULL)
		soNutLa = 1;
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
	int h = 0;
	if (root == NULL)
		h = -1;
	else if (root->left == NULL && root->right == NULL)
		h = 1;
	else
		h = 1+ TinhMax(TinhChieuCao(root->left), TinhChieuCao(root->right));
	return h;
}
BSTree Search_MaNV(BSTree root, KeyType x)
{
	if (root != NULL)
	{
		if (strcmp(root->key.maNV, x) == 0)
			return root;
		else
			if (strcmp(root->key.maNV, x) > 0)
				return Search_MaNV(root->left, x);
			else
				return Search_MaNV(root->right, x);
	}
	return NULL;
}
BSTree Search_Ten(BSTree root, char *Ten)
{
	if (root != NULL)
	{
		if (strcmp(root->key.hoVaTen, Ten) == 0)
			return root;
		else
			if (strcmp(root->key.hoVaTen, Ten) > 0)
				return Search_Ten(root->left, Ten);
			else
				return Search_Ten(root->right, Ten);
	}
	return NULL;
}
//BSTree DeleteMax(BSTree root)
//{
//	BSTree k=0;
//	if (root->right == NULL)
//	{
//		k = root;
//		root = root->left;
//		return k;
//	}
//	return DeleteMax(root->right);
//}
//int DeleteNode(BSTree& root, KeyType x)
//{
//	if (root != NULL)
//	{
//		if (_strcmpi(root->key.maNV, x) == 0)
//		{
//			if (root->left == NULL && root->right == NULL)
//				root = NULL;
//			else
//				if (root->left == NULL)
//					root = root->right;
//			else if (root->right == NULL)
//				root = root->left;
//			else
//				root = DeleteMax(root->right);
//		}
//		if (_strcmpi(root->key.maNV, x) > 0)
//			return DeleteNode(root->left, x);
//		else
//			return DeleteNode(root->right, x);
//	}
//}
BSTree DeleteMax(BSTree& root)
{
	BSTree k = 0;
	if (k->right == NULL)
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
		if (_strcmpi(root->key.maNV, x) == 0)
		{
			if (root->left == NULL && root->right == NULL)
				root = NULL;
			else if (root->left == NULL) { // chi co nut ben phai
				root = root->right;
			}
			else if (root->right == NULL)
			{
				root = root->left;
			}
			else // co ca 2 nut
			{
				root = DeleteMax(root->left);
			}
		}
		else if (_strcmpi(root->key.maNV, x) > 0)
			return DeleteNode(root->left, x);
		else
			return DeleteNode(root->right, x);
	}
}