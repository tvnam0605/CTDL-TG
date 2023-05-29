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
		if (strcmp(root->key.maHV, x) == 0) //Tim thay x
			return root;
		else
			if (strcmp(root->key.maHV, x) < 0)
				return Search(root->right, x); //tim x trong cay con phai
			else
				return Search(root->left, x); //tim x trong cay con trai
	}
	return NULL; //khong co
}
//BSTree DeleteMax(BSTree& root)
//{
//	BSTree k = 0;
//	if (k->right == NULL)
//	{
//		k = root;
//		root = root->left;
//		return k;
//	}
//	return DeleteMax(root->right);
//
//}
//int DeleteNode(BSTree& root, KeyType x)
//{
//	if (root != NULL)
//	{
//		if (_strcmpi(root->key.maHV, x) == 0)
//		{
//			if (root->left == NULL && root->right == NULL)
//				root = NULL;
//			else if (root->left == NULL)
//				root = root->right;
//			else if (root->right == NULL)
//				root = root->left;
//			else
//				root = DeleteMax(root->right);
//		}
//		else if (_strcmpi(root->key.maHV, x) > 0)
//			 DeleteNode(root->left, x);
//		else
//			 DeleteNode(root->right, x);
//	}
//	return 0;
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
		if (_strcmpi(root->key.maHV, x) == 0)
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
		else if (_strcmpi(root->key.maHV, x) > 0)
			 DeleteNode(root->left, x);
		else
			DeleteNode(root->right, x);
	}
	return 0;
}