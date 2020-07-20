#include "traverse.h"

int preorder(const BiTreeNode* node, List* list)
{
	if (!(node == NULL))
	{
		if (list_insert_next(list, list->tail, node->data) != 0)
		{
			return -1;	
		}
		if (!(node->left == NULL))
		{
			if (preorder(node->left, list) != 0)
			{
				return -1;
			}
		}
		if (!(node->right == NULL))
		{
			if (preorder(node->right, list) != 0)
			{
				return -1;
			}
		}
	}
	return 0;
}

int inorder(const BiTreeNode* node, List* list)
{
	if (!(node == NULL))
	{
		if (!(node->left == NULL))
		{
			if (inorder(node->left, list) != 0)
			{
				return -1;
			}
		}
		if (list_insert_next(list, list->tail, node->data) != 0)
		{
			return -1;	
		}
		if (!(node->right == NULL))
		{
			if (inorder(node->right, list) != 0)
			{
				return -1;
			}
		}
	}
	return 0;
}
int postorder(const BiTreeNode* node, List* list)
{
	if (!(node == NULL))
	{
		if (!(node->left == NULL))
		{
			if (postorder(node->left, list) != 0)
			{
				return -1;
			}
		}
		if (!(node->right == NULL))
		{
			if (postorder(node->right, list) != 0)
			{
				return -1;
			}
		}
		if (list_insert_next(list, list->tail, node->data) != 0)
		{
			return -1;	
		}
	}
	return 0;
}
