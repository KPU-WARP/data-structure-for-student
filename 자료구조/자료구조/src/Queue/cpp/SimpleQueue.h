#pragma once

#include <iostream>	// for Output

/*
	SIMPLE QUEUE	������_2013182027
		- �ܹ��� ���� ����Ʈ�� Ȱ���� ������ ���� �ܼ��� ������ ť�Դϴ�.

		#0. ���� �Լ� SIMPLE_QUEUE::ExampleFunction()�� �����մϴ�.
			- main.cpp���� SIMPLE_QUEUE::ExampleFunction(); �� �߰����ֽø� �˴ϴ�! :)
		#1. Int�� ������ 1���� ������ Node�� ������ �����Դϴ�.
		#2. ť �Լ��� Enqueue�� Dequeue, �� �ΰ����� �����մϴ�.
		
		!0. �ܼ��� �ڷᱸ���� ������ ���ؽ����ֱ� ���� �ڵ��, �ִ��� ���� �ڵ带 �ۼ��߽��ϴ�.
			- ����-�Ҹ���, ���ø�, ���۷��� �� �Ƹ��ٿ� �� ��� X
*/

namespace SIMPLE_QUEUE
{
	struct Node
	{
		int					data;
		Node*				pNext{ nullptr };
	};

	class SimpleQueue
	{
		Node*				pBack{ nullptr };
		Node*				pFront{ nullptr };

	public:
		void				Enqueue(int InData);
		Node*				Dequeue();
	};

	void ExampleFunction();
}