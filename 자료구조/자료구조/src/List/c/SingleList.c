#include "SingleList.h"

#include <stdio.h>	// printf 사용
#include <stdlib.h> // malloc | free 사용
/////////////////////////////////////////////////////////////////////////////////
// 전처리 끝

// 함수 정의 시작
/////////////////////////////////////////////////////////////////////////////////
void SL_Init(SList * pList)
{
	// pList 내부에 데이터가 있을경우 free를 사용하지 않으므로 메모리 릭이 발생한다.
	pList->nDatas = 0;
	pList->head.pNext = &pList->tail; // 더미헤더의 다음노드를 테일로 설정
}

void SL_Clear(SList * pList)
{
	SL_NODE *prev = NULL, *curr = NULL;
	prev = &pList->head;			// 이전노드 = 더미헤더
	curr = prev->pNext;				// 현재노드 = 더미헤더의 다음노드
	while (curr != &pList->tail) {	// 현재노드가 테일노드가 아니라면 반복문 수행
		prev->pNext = curr->pNext;	// 이전노드의 다음을 현재노드의 다음으로 변경 (현재노드 연결 누락됨)
		free(curr);					// 리스트에서 누락된 현재노드의 메모리 할당 해제
		curr = prev->pNext;			// 쓰레기값이 된 현재노드를 지운 노드의 다음노드로 설정
	}								// 현재노드가 테일노드이면 반복문 탈출 (데이터가 더이상 없음)
	pList->nDatas = 0;				// 리스트에 데이터가 전부 지워졌으므로 데이터 개수 0
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
	} // 삽입하려는 노드 키값이 이전노드보다 같거나 크고 다음노드보다 작으면 반복문 탈출
	prev->pNext = pNode; // 이전노드의 다음노드를 삽입노드로 설정
	pNode->pNext = curr; // 삽입노드의 다음노드를 현재노드로 설정
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
	} // 삽입하려는 키값이 이전노드보다 같거나 크고 다음노드보다 작으면 반복문 탈출
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
		if (curr->data.key == key) {	// 현재노드가 지울 키값과 같은 키를 가지면
			prev->pNext = curr->pNext;	// 이전노드의 다음을 현재노드의 다음으로 변경 (현재노드 연결 누락됨)
			free(curr);					// 리스트에서 누락된 현재노드의 메모리 할당 해제
			curr = prev->pNext;			// 쓰레기값이 된 현재노드를 지운 노드의 다음노드로 설정
			pList->nDatas--;			// 노드가 하나 지워졌으므로 데이터 개수 -1
		}
		else { // 다음노드로 이동
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
		if (curr->data.key == key) return curr; // 같은 키값을 가진 노드를 찾으면 반환
		prev = curr;
		curr = curr->pNext;
	}
	return NULL; // 같은 키값을 가진 노드를 못찾으면 반환
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