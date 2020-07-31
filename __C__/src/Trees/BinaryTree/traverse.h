#ifndef TRAVERSE_H
#define TRAVERSE_H

#include "binarytree.h"
#include "../../LinkedLists/LinkedList/linkedlist.h"

int preorder(const BiTreeNode* node, List* list);
int inorder(const BiTreeNode* node, List* list);
int postorder(const BiTreeNode* node, List* list);

#endif
