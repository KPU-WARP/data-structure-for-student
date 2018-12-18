#pragma once

#include <iostream>	// for Output

/*
	SIMPLE STACK	������_2013182027
		- ���� �ܼ��� ������ �����Դϴ�. 

		#0. ���� �Լ� SIMPLE_STACK::ExampleFunction()�� �����մϴ�.
			- main.cpp���� SIMPLE_STACK::ExampleFunction(); �� �߰����ֽø� �˴ϴ�! :)
		#1. Int�� ������ 1���� ������ Node�� ������ �����Դϴ�.
		#2. ���� �Լ��� Push�� Pop���� �� �ΰ����� �����մϴ�.

		!0. �ܼ��� ������ ������ ���ؽ����ֱ� ���� �ڵ��, �ִ��� ���� �ڵ带 �ۼ��߽��ϴ�. 
			- ������, ���ø�, ���۷��� �� �Ƹ��ٿ� �� ��� X
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