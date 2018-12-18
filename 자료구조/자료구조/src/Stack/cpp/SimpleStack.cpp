#include "../src/Stack/cpp/SimpleStack.h"

/*
	Push(int InData)
		- 인자로 주어진 데이터를 할당받을 노드를 생성(=메모리 할당, new)하여, 스택에 추가합니다.

		인자 : 생성할 노드에 할당할 데이터(InData)
		출력 : Void
*/
void SIMPLE_STACK::SimpleStack::Push(int InData)
{
	//먼저 Push할 노드를 생성해줍니다.
	Node* pPushNode = new Node;
	
	// 해당 노드의 데이터를 인자값으로 할당해줍니다.
	pPushNode->data = InData;

	// 스택이 비어있지 않을 때
	if (pTop != nullptr)			
	{
		// Push할 노드의 아래 노드로, 스택의 현재 Top노드로 설정합니다.
		pPushNode->pDown = pTop;	

		// 스택의 새로운 Top노드를, Push노드로 설정합니다.
		pTop = pPushNode;

		return;
	}

	// 스택이 빈 상태일 때
	else /* == else if (pTop == nullptr) */ 
	{
		// 스택의 새로운 Top노드를, Push노드로 설정합니다.
		pTop = pPushNode;

		return;
	}
}

/*
	Node* Pop()
		- 스택의 Top Pointer에서 노드를 꺼내 반환합니다.

		인자 : Void
		출력 : Pop되는 Node의 포인터

		!1. Top Pointer가 Null일 때, Pop을 호출할 경우, Warning Log를 출력하며, Nullptr를 반환합니다.
*/
SIMPLE_STACK::Node* SIMPLE_STACK::SimpleStack::Pop()
{
	// Pop할 노드에 대한 포인터 변수 생성.
	Node* pPopNode = nullptr;

	// 스택이 비어있지 않을 때
	if (pTop != nullptr)
	{
		// 스택의 TopNode를 PopNode에 대입한다.
		pPopNode = pTop;

		// 스택의 TopNode를 현재 TopNode의 아래노드로 변경한다.
		pTop = pTop->pDown; /* == pPopNode->pDown */

		return pPopNode;
	}

	// [경고] 스택이 빈 상태일 때
	else /* == else if (pTop == nullptr) */
	{
		std::cout << "		[Warning] The Stack is Empty \n";
		return pPopNode; /* == nullptr */
	}
}

/* 멍청한 함수입니다. */
void SIMPLE_STACK::ExampleFunction()
{
	std::cout 
		<< "\n\n"
		<< " [Hello] Simple Stack의 예제함수를 실행합니다. \n"
		<< "\n\n"
		<< "	1. 먼저 스택에 1,2,3,4,5를 차례대로 Push합니다.\n";
		
	SimpleStack myStack;
	myStack.Push(1);
	myStack.Push(2);
	myStack.Push(3);
	myStack.Push(4);
	myStack.Push(5);

	//실제로는 SimpleStack에 PrintAllNodes 등 관련 함수를 구현하여 데이터를 출력해야합니다.
	std::cout 
		<< "\n"
		<< "											5	\n"
		<< "									4		4	\n"
		<< "		->		->		->	3	->	3	->	3	\n"
		<< "					2		2		2		2	\n"
		<< "	void		1		1		1		1		1	\n";


	std::cout 
		<< "\n\n"
		<< "	2. 스택에서 차례대로 Pop합니다.\n";

	myStack.Pop();
	myStack.Pop();
	myStack.Pop();
	myStack.Pop();
	myStack.Pop();

	//실제로는 Pop한 노드의 데이터를 확인해야합니다.
	std::cout 
		<< "\n"
		<< "	5										\n"
		<< "	4		4								\n"
		<< "	3	->	3	->	3	->		->		->	\n"
		<< "	2		2		2		2				\n"
		<< "	1		1		1		1		1		void\n";


	//이런 상황은 없어야 합니다.
	std::cout
		<< "\n\n"
		<< "	3. 스택이 빈상태일 때, Pop을 시도합니다.\n";

	myStack.Pop();

	std::cout
		<< "\n\n"
		<< " [GoodBye] 감사합니다. 이상으로 Simple Stack의 예제함수를 종료합니다.\n";
}