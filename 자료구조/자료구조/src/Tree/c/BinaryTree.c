#include "BinaryTree.h"

#include <stdio.h>
#include <stdlib.h>
/////////////////////////////////////////////////////////////////////////////////
// ��ó�� ��

// ����� �Լ� ����
/////////////////////////////////////////////////////////////////////////////////
BT_NODE*	BT_CreateNode(int key);

void		BT_ClearRecursive(BT_NODE* node);
int			BT_InsertRecursive(int key, BT_NODE** node, BT_NODE* parent);
BT_NODE*	BT_SearchRecursive(int key, BT_NODE* node);

void		BT_PreOrderPrintNode(BT_NODE* node);
void		BT_InOrderPrintNode(BT_NODE* node);
void		BT_PostOrderPrintNode(BT_NODE* node);

// �Լ� ���� ����
/////////////////////////////////////////////////////////////////////////////////
BT_NODE * BT_CreateNode(int key)
{
	BT_NODE* new_node = NULL;
	new_node = (BT_NODE*)malloc(sizeof(BT_NODE));
	new_node->key = key;
	new_node->parent = NULL;
	new_node->right_child = NULL;
	new_node->left_child = NULL;
	return new_node;
}

void BT_Init(BinaryTree * bt)
{
	bt->root = NULL;
	bt->nDatas = 0;
}

void BT_Clear(BinaryTree * bt)
{
	BT_ClearRecursive(bt->root);
	BT_Init(bt);
}

void BT_ClearRecursive(BT_NODE * node)
{
	if (node == NULL) return;
	BT_ClearRecursive(node->left_child);
	BT_ClearRecursive(node->right_child);
	free(node);
}

void BT_Insert(BinaryTree * bt, int key)
{
	if (BT_InsertRecursive(key, &bt->root, bt->root)) {
		bt->nDatas++;
	}
}

int BT_InsertRecursive(int key, BT_NODE ** node, BT_NODE * parent)
{
	BT_NODE* curr_node = *node;
	if (curr_node == NULL) {
		curr_node = BT_CreateNode(key);
		curr_node->parent = parent;
		*node = curr_node;
		return TRUE;
	}
	if (curr_node->key > key) {
		return BT_InsertRecursive(key, &curr_node->left_child, curr_node);
	}
	else if (curr_node->key < key) {
		return BT_InsertRecursive(key, &curr_node->right_child, curr_node);
	}
	else {
		printf("Error: Same key insert!\n");
	}
	return FALSE;
}

BT_NODE * BT_Search(BinaryTree * bt, int key)
{
	return BT_SearchRecursive(key, bt->root);
}

BT_NODE * BT_SearchRecursive(int key, BT_NODE * node)
{
	if (node == NULL) return NULL;
	if (node->key > key) {
		BT_SearchRecursive(key, node->left_child);
	}
	else if (node->key < key) {
		BT_SearchRecursive(key, node->right_child);
	}
	else {
		return node;
	}
	return NULL;
}

void BT_Delete(BinaryTree * bt, int key)
{
	BT_NODE* del = BT_Search(bt, key);
	if (del == NULL) return;

	// ��ó�� ���
	BT_NODE * temp = NULL;

	// ���� ����� �ڽ��� ���� ���
	if (del->left_child == NULL && del->right_child == NULL) {
		// �ƹ��͵� �� �ʿ䰡 ����.
	}
	// ���� ����� ���� �ڽ��� ���� ������ �ڽ��� �ִ� ���
	else if (del->left_child == NULL && del->right_child != NULL) {
		temp = del->right_child;
		temp->parent = del->parent;
	}
	// ���� ����� ������ �ڽ��� ���� ���� �ڽ��� �ִ� ���
	else if (del->left_child != NULL && del->right_child == NULL) {
		temp = del->left_child;
		temp->parent = del->parent;
	}
	// ���� ����� ����, ������ �ڽ��� ��� �ִ� ���
	else if (del->left_child != NULL && del->right_child != NULL) {
		temp = del->right_child;
		// ���� ����� ������ �ڽ��� ���� �ڽ��� �ִ� ���
		if (temp->left_child != NULL) {
			// ���� ����� ������ �ڽ��� �� �����ڽ� ã��.
			while (temp->left_child != NULL)
				temp = temp->left_child;
			// temp�� �� �����ڽ��̱� ������ left_child�� NULL�̴�.
			// temp�� ��ġ�� ���� ���� �ٲ�� �ϹǷ� temp�� ������ �ڽ��� temp->parent�� left_child�� �ٿ��ش�. (NULL�� �������)
			temp->parent->left_child = temp->right_child;
			// temp�� �θ� �ٿ��� right_child�� �����Ѵٸ�, right_child�� parent�� �����Ѵ�.
			if (temp->right_child != NULL)
				temp->right_child->parent = temp->parent;
			// ���� ����� ������ �ڽ��� �� �����ڽ�(��ü�� ���)�� Ʈ������ ���µ� ���������Ƿ� ���� ��尡 ������ �ִ� ���� ������ ����Ѵ�.
			temp->right_child = del->right_child;	// ��ü�� ��� ������ �ڽ��� ���� ����� ������ �ڽ����� ����
			del->right_child->parent = temp;		// ���� ����� ������ �ڽ��� �θ� ��ü�� ���� ����
		}

		// ���� ����� ������ �ڽ��� ���� �ڽ��� ���� ��� �ٷ� ��ü ����
		temp->parent = del->parent;
		temp->left_child = del->left_child;			// ��ü�� ��� ���� �ڽ��� ���� ����� ���� �ڽ����� ����
		del->left_child->parent = temp;				// ���� ����� ���� �ڽ��� �θ� ��ü�� ���� ����
	}

	// ���� ��尡 Root�� �ƴ� ��� �θ��� �������� ����
	if (del->parent != NULL) {
		if (del->parent->left_child == del) {
			del->parent->left_child = temp;
		}
		else {
			del->parent->right_child = temp;
		}
	}
	// ���� ��尡 Root�� ��� ����
	else {
		bt->root = temp;
	}
	
	// ��ǥ ��带 ����
	free(del);
	bt->nDatas--;
}

void BT_Traversal(BinaryTree * bt, BT_TRAVERSAL type)
{
	switch (type) {
	case BT_PreOrder:	BT_PreOrderPrintNode(bt->root);		return;	
	case BT_InOrder:	BT_InOrderPrintNode(bt->root);		return;
	case BT_PostOrder:	BT_PostOrderPrintNode(bt->root);	return;
	}
	printf("Error: Invalid traversal type!\n");
}

void BT_PreOrderPrintNode(BT_NODE * node)
{
	if (node == NULL) return;
	printf("%d\n", node->key);
	BT_PreOrderPrintNode(node->left_child);
	BT_PreOrderPrintNode(node->right_child);
}

void BT_InOrderPrintNode(BT_NODE * node)
{
	if (node == NULL) return;
	BT_InOrderPrintNode(node->left_child);
	printf("%d\n", node->key);
	BT_InOrderPrintNode(node->right_child);
}

void BT_PostOrderPrintNode(BT_NODE * node)
{
	if (node == NULL) return;
	BT_PostOrderPrintNode(node->left_child);
	BT_PostOrderPrintNode(node->right_child);
	printf("%d\n", node->key);
}