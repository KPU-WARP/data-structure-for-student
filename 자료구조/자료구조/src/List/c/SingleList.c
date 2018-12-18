#include "SingleList.h"

#include <stdio.h>	// printf ���
#include <stdlib.h> // malloc | free ���
/////////////////////////////////////////////////////////////////////////////////
// ��ó�� ��

// �Լ� ���� ����
/////////////////////////////////////////////////////////////////////////////////
void SL_Init(SList * pList)
{
	// pList ���ο� �����Ͱ� ������� free�� ������� �����Ƿ� �޸� ���� �߻��Ѵ�.
	pList->nDatas = 0;
	pList->head.pNext = &pList->tail; // ��������� ������带 ���Ϸ� ����
}

void SL_Clear(SList * pList)
{
	SL_NODE *prev = NULL, *curr = NULL;
	prev = &pList->head;			// ������� = �������
	curr = prev->pNext;				// ������ = ��������� �������
	while (curr != &pList->tail) {	// �����尡 ���ϳ�尡 �ƴ϶�� �ݺ��� ����
		prev->pNext = curr->pNext;	// ��������� ������ �������� �������� ���� (������ ���� ������)
		free(curr);					// ����Ʈ���� ������ �������� �޸� �Ҵ� ����
		curr = prev->pNext;			// �����Ⱚ�� �� �����带 ���� ����� �������� ����
	}								// �����尡 ���ϳ���̸� �ݺ��� Ż�� (�����Ͱ� ���̻� ����)
	pList->nDatas = 0;				// ����Ʈ�� �����Ͱ� ���� ���������Ƿ� ������ ���� 0
}

void SL_InsertNode(SList * pList, SL_NODE * pNode)
{
	SL_NODE *prev = NULL, *curr = NULL;
	prev = &pList->head;
	curr = prev->pNext;
	while (curr != &pList->tail) {
		if (curr->data.key > pNode->data.key) break; 
		prev = curr;
		curr = curr->pNext;
	} // �����Ϸ��� ��� Ű���� ������庸�� ���ų� ũ�� ������庸�� ������ �ݺ��� Ż��
	prev->pNext = pNode; // ��������� ������带 ���Գ��� ����
	pNode->pNext = curr; // ���Գ���� ������带 ������� ����
	pList->nDatas++;
}

void SL_Insert(SList* pList, int key)
{
	SL_NODE *prev = NULL, *curr = NULL, *new_node = NULL;
	prev = &pList->head;
	curr = prev->pNext;
	while (curr != &pList->tail) {
		if (curr->data.key > key) break;
		prev = curr;
		curr = curr->pNext;
	} // �����Ϸ��� Ű���� ������庸�� ���ų� ũ�� ������庸�� ������ �ݺ��� Ż��
	new_node = (SL_NODE*)malloc(sizeof(SL_NODE));
	new_node->data.key = key;
	new_node->pNext = curr;
	prev->pNext = new_node;
	pList->nDatas++;
}

void SL_Delete(SList * pList, int key)
{
	SL_NODE *prev = NULL, *curr = NULL;
	prev = &pList->head;
	curr = prev->pNext;
	while (curr != &pList->tail) {
		if (curr->data.key == key) {	// �����尡 ���� Ű���� ���� Ű�� ������
			prev->pNext = curr->pNext;	// ��������� ������ �������� �������� ���� (������ ���� ������)
			free(curr);					// ����Ʈ���� ������ �������� �޸� �Ҵ� ����
			curr = prev->pNext;			// �����Ⱚ�� �� �����带 ���� ����� �������� ����
			pList->nDatas--;			// ��尡 �ϳ� ���������Ƿ� ������ ���� -1
		}
		else { // �������� �̵�
			prev = curr;
			curr = curr->pNext;
		}
	}
}

SL_NODE* SL_Search(SList * pList, int key)
{
	SL_NODE *prev = NULL, *curr = NULL;
	prev = &pList->head;
	curr = pList->head.pNext;
	while (curr != &pList->tail) {
		if (curr->data.key == key) return curr; // ���� Ű���� ���� ��带 ã���� ��ȯ
		prev = curr;
		curr = curr->pNext;
	}
	return NULL; // ���� Ű���� ���� ��带 ��ã���� ��ȯ
}

void SL_PrintData(const SL_NODE * pNode)
{
	printf("[key]: %d\n", pNode->data.key);
	// printf("[f]: %f\n", pNode->data.value);
	// printf("[s]: %s\n", pNode->data.value);
	// printf("[c]: %c\n", pNode->data.value);
}

void SL_PrintALL(const SList * pList)
{
	if (pList->nDatas == 0) return;
	int max = 100;
	SL_NODE *ptr = NULL;
	ptr = pList->head.pNext;
	printf("The number of data: %d\n", pList->nDatas);
	while (ptr != &pList->tail) {
		SL_PrintData(ptr);
		ptr = ptr->pNext;
		if (--max == 0) break;
	}
}