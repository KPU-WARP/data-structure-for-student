#include "BinaryTree.h"

#include <stdio.h>
#include <stdlib.h>
/////////////////////////////////////////////////////////////////////////////////
// 전처리 끝

// 비공개 함수 선언
/////////////////////////////////////////////////////////////////////////////////
BT_NODE*	BT_CreateNode(int key);

void		BT_ClearRecursive(BT_NODE* node);
int			BT_InsertRecursive(int key, BT_NODE** node, BT_NODE* parent);
BT_NODE*	BT_SearchRecursive(int key, BT_NODE* node);

void		BT_PreOrderPrintNode(BT_NODE* node);
void		BT_InOrderPrintNode(BT_NODE* node);
void		BT_PostOrderPrintNode(BT_NODE* node);

// 함수 정의 시작
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

	// 후처리 대상
	BT_NODE * temp = NULL;

	// 지울 노드의 자식이 없는 경우
	if (del->left_child == NULL && del->right_child == NULL) {
		// 아무것도 할 필요가 없다.
	}
	// 지울 노드의 왼쪽 자식이 없고 오른쪽 자식이 있는 경우
	else if (del->left_child == NULL && del->right_child != NULL) {
		temp = del->right_child;
		temp->parent = del->parent;
	}
	// 지울 노드의 오른쪽 자식이 없고 왼쪽 자식이 있는 경우
	else if (del->left_child != NULL && del->right_child == NULL) {
		temp = del->left_child;
		temp->parent = del->parent;
	}
	// 지울 노드의 왼쪽, 오른쪽 자식이 모두 있는 경우
	else if (del->left_child != NULL && del->right_child != NULL) {
		temp = del->right_child;
		// 지울 노드의 오른쪽 자식의 왼쪽 자식이 있는 경우
		if (temp->left_child != NULL) {
			// 지울 노드의 오른쪽 자식의 맨 왼쪽자식 찾음.
			while (temp->left_child != NULL)
				temp = temp->left_child;
			// temp는 맨 왼쪽자식이기 때문에 left_child가 NULL이다.
			// temp의 위치를 지울 노드와 바꿔야 하므로 temp의 오른쪽 자식을 temp->parent의 left_child에 붙여준다. (NULL도 상관없음)
			temp->parent->left_child = temp->right_child;
			// temp의 부모에 붙여준 right_child가 존재한다면, right_child의 parent를 갱신한다.
			if (temp->right_child != NULL)
				temp->right_child->parent = temp->parent;
			// 지울 노드의 오른쪽 자식의 맨 왼쪽자식(대체할 노드)을 트리에서 떼는데 성공했으므로 지울 노드가 가지고 있던 연결 정보를 계승한다.
			temp->right_child = del->right_child;	// 대체할 노드 오른쪽 자식을 지울 노드의 오른쪽 자식으로 설정
			del->right_child->parent = temp;		// 지울 노드의 오른쪽 자식이 부모를 대체할 노드로 설정
		}

		// 지울 노드의 오른쪽 자식의 왼쪽 자식이 없는 경우 바로 대체 가능
		temp->parent = del->parent;
		temp->left_child = del->left_child;			// 대체할 노드 왼쪽 자식을 지울 노드의 왼쪽 자식으로 설정
		del->left_child->parent = temp;				// 지울 노드의 왼쪽 자식의 부모를 대체할 노드로 설정
	}

	// 지울 노드가 Root가 아닐 경우 부모의 연결정보 갱신
	if (del->parent != NULL) {
		if (del->parent->left_child == del) {
			del->parent->left_child = temp;
		}
		else {
			del->parent->right_child = temp;
		}
	}
	// 지울 노드가 Root일 경우 갱신
	else {
		bt->root = temp;
	}
	
	// 목표 노드를 삭제
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