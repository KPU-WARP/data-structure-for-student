#pragma once
#define WIN32_LEAN_AND_MEAN // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
#include <windows.h>

#include <iostream>
#include <chrono>

extern "C" { // �߰�ȣ ������ �ڵ���� C��� ��Ģ�� ����
#include "List/c/SingleList.h"
#include "Tree/c/BinaryTree.h"
}

//cpp
#include "../src/Stack/cpp/SimpleStack.h"
#include "../src/Queue/cpp/SimpleQueue.h"
#include "../src/Tree/cpp/Custom_RedBlackTree.h"


// TEST CODE
int main()
{
	const int range = 1000;
	const int num_data = 1000;
	const int num_delete_test = 100000;
	int del_count = 0;
	BinaryTree bt;
	srand((unsigned int)time(NULL));

	BT_Init(&bt);
	for (int i = 0; i < num_data; ++i)
		BT_Insert(&bt, rand() % range);

	del_count += bt.nDatas;
	for (int i = 0; i < num_delete_test; ++i) 
		BT_Delete(&bt, rand() % range);
	del_count -= bt.nDatas;

	for (int i = 0; i < num_data; ++i)
		BT_Insert(&bt, rand() % range);

	del_count += bt.nDatas;
	for (int i = 0; i < num_delete_test; ++i)
		BT_Delete(&bt, rand() % range);
	del_count -= bt.nDatas;

	for (int i = 0; i < num_data; ++i)
		BT_Insert(&bt, rand() % range);
	
	BT_Traversal(&bt, BT_InOrder);
	printf("the num of datas: %d || delete count: %d\n", bt.nDatas, del_count);
	BT_Clear(&bt);

	system("pause");
	return 0;
}