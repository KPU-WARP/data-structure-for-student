#pragma once

#include <iostream>	// for Output

/*
	SIMPLE QUEUE	원성연_2013182027
		- 단방향 연결 리스트를 활용해 구현한 가장 단순한 형태의 큐입니다.

		#0. 예시 함수 SIMPLE_QUEUE::ExampleFunction()을 제공합니다.
			- main.cpp에서 SIMPLE_QUEUE::ExampleFunction(); 를 추가해주시면 됩니다! :)
		#1. Int형 데이터 1개를 가지는 Node로 구성된 스택입니다.
		#2. 큐 함수는 Enqueue와 Dequeue, 단 두개만을 제공합니다.
		
		!0. 단순히 자료구조의 원리를 이해시켜주기 위한 코드로, 최대한 쉽게 코드를 작성했습니다.
			- 생성-소멸자, 템플릿, 레퍼런스 등 아름다운 것 사용 X
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