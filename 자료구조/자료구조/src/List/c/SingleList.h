#ifndef __SINGLE_LIST__ // '__SINGLE_LIST__'��� �ؽ�Ʈ�� ���ǵǾ����� �ʾҴٸ�
#define __SINGLE_LIST__ // '__SINGLE_LIST__'�� �����ϰ� ���� ���� 
/* #pragma once �� ��ü����
���� ��ó���⹮���� main�̳� �ٸ� ���Ͽ��� #include "SingleList.h"�� ������ ������� 
ó�� �ѹ��� �Ʒ� ������ ����ǵ��� �Ͽ� �ߺ�����(������)�� �����ϴ� ����� �Ѵ�. */

typedef struct _SL_Data {
	int					key;
//  float				f_value;
//  char*				str_value;
//  ...
} SL_Data;

typedef struct _SL_NODE { // typedef [Ÿ��(struct ����ü_�̸�) {}] [����(SL_NODE)] ;
	SL_Data				data;		// ��� ������
	struct _SL_NODE*	pNext;		// ��� ��ũ, �������� ������ �ʾƼ� Ÿ���� [struct ����ü_�̸�]
} SL_NODE;

typedef struct _SINGLE_LIST { // typedef [Ÿ��(struct ����ü_�̸�) {}] [����(SList)] ;
	unsigned int		nDatas;		// ����Ʈ ���� ������ ����
	SL_NODE				head, tail; // ���� ����� ����
} SList;

void		SL_Init(SList* pList);	// ����Ʈ ���� ���� �ʱ�ȭ (�����Ͱ� ����ִ� ����Ʈ ��� ����)
void		SL_Clear(SList* pList); // ����Ʈ�� ��� ������ �Ҵ�����

void		SL_InsertNode(SList* pList, SL_NODE* pNode); // ����Ʈ�� ��� �߰� (�ڵ�����)
void		SL_Insert(SList* pList, int key); // ����Ʈ�� �� ��� �߰� (�ڵ�����)
void		SL_Delete(SList* pList, int key); // ����Ʈ���� ���� Ű���� ���� ��� ��� ���� 
SL_NODE*	SL_Search(SList* pList, int key); // ����Ʈ���� ���� Ű���� ���� ����� ù��° ��� ��ȯ

void		SL_PrintData(const SL_NODE* pNode); // ��� ������ ���
void		SL_PrintALL(const SList* pList);	// ����Ʈ�� ���� ��� ������ ��� (�ִ� 100��)

#endif // ��ó���� if���� ������ �ݵ�� ��� #pragma once�� ����ϸ� �ʿ����