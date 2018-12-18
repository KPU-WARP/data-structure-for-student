#pragma once

#include <iostream>	// for Output

/*
	SIMPLE STACK	원성연_2013182027
		- 가장 단순한 형태의 스택입니다. 

		#0. 예시 함수 SIMPLE_STACK::ExampleFunction()을 제공합니다.
			- main.cpp에서 SIMPLE_STACK::ExampleFunction(); 를 추가해주시면 됩니다! :)
		#1. Int형 데이터 1개를 가지는 Node로 구성된 스택입니다.
		#2. 스택 함수는 Push와 Pop만을 단 두개만을 제공합니다.

		!0. 단순히 스택의 원리를 이해시켜주기 위한 코드로, 최대한 쉽게 코드를 작성했습니다. 
			- 생성자, 템플릿, 레퍼런스 등 아름다운 것 사용 X
*/

namespace SIMPLE_STACK
{
	struct Node
	{
		int					data;
		Node*				pDown{ nullptr };
	};

	class SimpleStack
	{
		Node*				pTop{ nullptr };

	public:
		void				Push(int InData);
		Node*				Pop();
	};

	void ExampleFunction();
}