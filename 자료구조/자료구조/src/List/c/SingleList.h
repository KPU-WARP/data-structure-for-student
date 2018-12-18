#ifndef __SINGLE_LIST__ // '__SINGLE_LIST__'라는 텍스트가 정의되어있지 않았다면
#define __SINGLE_LIST__ // '__SINGLE_LIST__'를 정의하고 이하 선언 
/* #pragma once 로 대체가능
위의 전처리기문들은 main이나 다른 파일에서 #include "SingleList.h"를 여러번 했을경우 
처음 한번만 아래 내용이 선언되도록 하여 중복선언(재정의)를 방지하는 기능을 한다. */

typedef struct _SL_Data {
	int					key;
//  float				f_value;
//  char*				str_value;
//  ...
} SL_Data;

typedef struct _SL_NODE { // typedef [타입(struct 구조체_이름) {}] [별명(SL_NODE)] ;
	SL_Data				data;		// 노드 데이터
	struct _SL_NODE*	pNext;		// 노드 링크, 별명설정이 끝나지 않아서 타입이 [struct 구조체_이름]
} SL_NODE;

typedef struct _SINGLE_LIST { // typedef [타입(struct 구조체_이름) {}] [별명(SList)] ;
	unsigned int		nDatas;		// 리스트 내부 데이터 개수
	SL_NODE				head, tail; // 더미 헤더와 테일
} SList;

void		SL_Init(SList* pList);	// 리스트 내부 변수 초기화 (데이터가 들어있는 리스트 고려 안함)
void		SL_Clear(SList* pList); // 리스트의 모든 데이터 할당해제

void		SL_InsertNode(SList* pList, SL_NODE* pNode); // 리스트에 노드 추가 (자동정렬)
void		SL_Insert(SList* pList, int key); // 리스트에 새 노드 추가 (자동정렬)
void		SL_Delete(SList* pList, int key); // 리스트에서 같은 키값을 가진 모든 노드 삭제 
SL_NODE*	SL_Search(SList* pList, int key); // 리스트에서 같은 키값을 가진 노드중 첫번째 노드 반환

void		SL_PrintData(const SL_NODE* pNode); // 노드 데이터 출력
void		SL_PrintALL(const SList* pList);	// 리스트가 가진 노드 데이터 출력 (최대 100개)

#endif // 전처리기 if문이 끝날때 반드시 사용 #pragma once를 사용하면 필요없음