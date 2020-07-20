#include "binarytree.h"

void bitree_init(BiTree* tree, void (*destroy)(void* data))
{
	tree->size = 0;
	tree->destroy = destroy;
	tree->root = NULL;
	return;
}

int bitree_insert_left(BiTree* tree, BiTreeNode* node, const void* data)
{
	BiTreeNode* new_node;
	BiTreeNode** position;

	if (node == NULL)
	{
		if (tree->size == 0){ return -1; }
		position = &tree->root;
	}
	else
	{
		if (node->left != NULL){ return -1; }
		position = &node->left;
	}

	if ((new_node = (BiTreeNode*)malloc(sizeof(BiTreeNode))) == NULL)
	{ return -1; }

	new_node->data = (void*)data;
	new_node->left = NULL;
	new_node->right = NULL;
	*position = new_node;

	tree->size++; return 0;
}

int bitree_insert_right(BiTree* tree, BiTreeNode* node, const void* data)
{
	BiTreeNode* new_node;
	BiTreeNode** position;

	if (node == NULL)
	{
		if (tree->size == 0){ return -1; }
		position = &tree->root;
	}
	else
	{
		if (node->left != NULL){ return -1; }
		position = &node->right;
	}

	if ((new_node = (BiTreeNode*)malloc(sizeof(BiTreeNode))) == NULL)
	{ return -1; }

	new_node->data = (void*)data;
	new_node->left = NULL;
	new_node->right = NULL;
	*position = new_node;

	tree->size++; return 0;
}

void bitree_remove_left(BiTree* tree, BiTreeNode* node)
{
	BiTreeNode** position;

	if (tree->size == 0){ return; }

	if (node == NULL){ position = &tree->root; }
	else { position = &node->left; }

	if (position != NULL)
	{
		bitree_remove_left(tree, *position);
		bitree_remove_right(tree, *position);
		if (tree->destroy != NULL)
		{
			tree->destroy((*position)->data);
		}
		free(*position); *position = NULL; tree->size--;
	}

	return;
}

void bitree_remove_right(BiTree* tree, BiTreeNode* node)
{
	BiTreeNode** position;

	if (tree->size == 0){ return; }

	if (node == NULL){ position = &tree->root; }
	else { position = &node->right; }

	if (position != NULL)
	{
		bitree_remove_right(tree, *position);
		bitree_remove_left(tree, *position);
		if (tree->destroy != NULL)
		{
			tree->destroy((*position)->data);
		}
		free(*position); *position = NULL; tree->size--;
	}

	return;
}

void bitree_destroy(BiTree* tree)
{
	bitree_remove_left(tree, NULL);
	memset(tree, 0, sizeof(BiTree));
	return;
}

int bitree_merge(BiTree* merge, BiTree* left, BiTree* right, const void* data)
{
	bitree_init(merge, left->destroy);
	if (bitree_insert_left(merge, NULL, data) != 0)
	{
		bitree_destroy(merge); return -1;
	}

	merge->root->left = left->root;
	merge->root->right = right->root;

	merge->size = merge->size + left->size + right->size;

	left->root = NULL; left->size = 0;
	right->root = NULL; right->size = 0;

	return 0;
}
