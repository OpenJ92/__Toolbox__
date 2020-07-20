#include "bistree.h"


void bistree_init(BisTree* tree, 
		int (*compare)(const void* key1, const void* key2),
		void (*destroy)(void* data))
{
	bitree_init(tree, destroy);
	tree->compare = compare;
	return;
}

// Wow! This is very complicated. Come back and spend some time drawing 
// out this implementation of rotation with Lx configuration.
static void rotate_left(BiTreeNode** node)
{
	BiTreeNode* left; BiTreeNode* grandchild;
	left = bitree_left(*node);

	if (((AvlNode*)bitree_data(left))->factor == AVL_LFT_HEAVY)
	{
		// LL rotation
		bitree_left(*node) = bitree_right(left);
		bitree_right(left) = *node;
		((AvlNode*)bitree_data(*node))->factor = AVL_BALANCED;
		((AvlNode*)bitree_data(left))->factor = AVL_BALANCED;
		*node = left;
	}
	else
	{
		//LR rotation
		grandchild = bitree_right(left);
		bitree_right(left) = bitree_left(grandchild);
		bitree_left(grandchild) = left;
		bitree_left(*node) = bitree_right(grandchild);
		bitree_right(grandchild) = *node;

		switch (((AvlNode*)(bitree_data(grandchild)))->factor)
		{
			case AVL_LFT_HEAVY:
				((AvlNode*)bitree_data(*node))->factor = AVL_RGT_HEAVY;
				((AvlNode*)bitree_data(left))->factor = AVL_BALANCED;
				break;
			case AVL_BALANCED:
				((AvlNode*)bitree_data(*node))->factor = AVL_BALANCED;
				((AvlNode*)bitree_data(left))->factor = AVL_BALANCED;
				break;
				
			case AVL_RGT_HEAVY:
				((AvlNode*)bitree_data(*node))->factor = AVL_BALANCED;
				((AvlNode*)bitree_data(left))->factor = AVL_LFT_HEAVY;
				break;
		}

		((AvlNode*)bitree_data(grandchild))->factor = AVL_BALANCED;
		*node = grandchild;
	}

	return;
}

// Wow! This is very complicated. Come back and spend some time drawing 
// out this implementation of rotation with Rx configuration.
static void rotate_right(BiTreeNode** node)
{
	BiTreeNode* right;
	BiTreeNode* grandchild;

	right = bitree_right(*node);

	if (((AvlNode*)bitree_data(right))->factor == AVL_RGT_HEAVY)
	{
		// RR rotation
		bitree_right(*node) = bitree_left(right);
		bitree_left(right) = *node;
		((AvlNode*)bitree_data(*node))->factor = 0;
		((AvlNode*)bitree_data(right))->factor = 0;
		*node = right;
	}
	else
	{
		// RL rotation
		grandchild = bitree_left(right);
		bitree_left(right) = bitree_right(grandchild);
		bitree_right(grandchild) = right;
		bitree_right(*node) = bitree_left(grandchild);
		bitree_left(grandchild) = *node;

		switch (((AvlNode*)bitree_data(grandchild))->factor)
		{
			case AVL_LFT_HEAVY:
				((AvlNode*)bitree_data(*node))->factor = AVL_BALANCED;
				((AvlNode*)bitree_data(right))->factor = AVL_RGT_HEAVY;
				break;
			case AVL_BALANCED:
				((AvlNode*)bitree_data(*node))->factor = AVL_BALANCED;
				((AvlNode*)bitree_data(right))->factor = AVL_BALANCED;
				break;
			case AVL_RGT_HEAVY:
				((AvlNode*)bitree_data(*node))->factor = AVL_LFT_HEAVY;
				((AvlNode*)bitree_data(right))->factor = AVL_BALANCED;
				break;
		}

		((AvlNode*)bitree_data(grandchild))->factor = AVL_BALANCED;
		*node = grandchild;
	}
	return;
}

static void destroy_left(BisTree* tree, BiTreeNode* node)
{
	BiTreeNode** position;

	if (bitree_size(tree) == 0){ return; }

	if (node == NULL){ position = &tree->root; }
	else { position = &node->left; }

	if (*position != NULL)
	{
		destroy_left(tree, *position);
		destroy_right(tree, *position);

		if (tree->destroy != NULL)
		{
			tree->destroy(((AvlNode*)(*position)->data)->data);
		}

		free((*position)->data);
		free(*position);
		*position = NULL;
		tree->size--;
	}
	return;
}

static void destroy_right(BisTree* tree, BiTreeNode* node)
{
	BiTreeNode** position;

	if (bitree_size(tree) == 0){ return; }

	if (node == NULL){ position = &tree->root; }
	else { position = &node->right; }

	if (*position != NULL)
	{
		destroy_left(tree, *position);
		destroy_right(tree, *position);

		if (tree->destroy != NULL)
		{
			tree->destroy(((AvlNode*)(*position)->data)->data);
		}

		free((*position)->data);
		free(*position);
		*position = NULL;
		tree->size--;
	}
	return;
}

static int insert(BisTree* tree, BiTreeNode* node, const void* data, int* balanced)
{ return 0; }
