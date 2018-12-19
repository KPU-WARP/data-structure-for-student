#include "../src/Queue/cpp/SimpleQueue.h"

/*
	void Enqueue(int)
			- 인자로 주어진 데이터를 할당받을 노드를 생성(메모리 할당, new)하여, 큐에 Back 부분에 추가합니다.

			인자 : 생성할 노드에 할당할 데이터
			출력 : void
*/
void SIMPLE_QUEUE::SimpleQueue::Enqueue(int InData)
{
	// 삽입할 노드를 생성해줍니다.
	Node* pEnqueueNode = new Node;

	// 해당 노드의 데이터를 함수의 인자값으로 변경합니다.
	pEnqueueNode->data = InData;

	// 큐의 Back(마지막 노드)가 nullptr일 때 (== 큐가 빈 상태일 때)
	if (pBack == nullptr)
	{
		// 큐의 마지막 위치에 노드를 삽입해줍니다.
		pBack = pEnqueueNode;

		// 큐의 Back(마지막 노드)가 nullptr일 때는 Front(맨 앞 노드)도 항상 nullptr입니다.
		pFront = pEnqueueNode;

		// !0. 이 코드에서는 괜찮으나, 사실 하나의 리소스를 여러개의 기본 포인터가 가리키는 것은 치명적인 문제를 야기할 수 있습니다. 
		//		- 관련 키워드 : 댕글링 포인터, 스마트 포인터(shared_ptr)
	}

	// 큐가 빈 상태가 아닐 경우
	else /* == else if (pBack != nullptr )*/
	{
		// 큐의 마지막 노드에 다음 위치(pNext)에 삽입하는 노드를 넣습니다.
		pBack->pNext = pEnqueueNode;	

		// 이제 큐의 마지막 위치는 제껍니다.
		pBack = pEnqueueNode;
	}

	return;
}


/*
	Node* Dequeue()
		- 큐의 Front 부분에서 노드를 꺼내 반환합니다.

		인자 : void
		출력 : Dequeue되는 Node의 포인터

		!1. 큐가 비어있을 때 Dequeue을 호출한 경우, Waring Log를 출력하며, nullptr를 반환합니다. ( Queue Underflow )
		!2. 반환 후 반환된 노드의 멤버 변수 pNext는 거의 대부분의 경우 사용하면 안됩니다.
			- 반환하기 전에, pDequeueNode->pNext를 nullptr로 변경한 후, 반환하는 것도 좋아요! :)
			- 또는 Data만 반환하는 것도 좋아요! (코드는, Node 자체를 반환하는 것이 개념적으로 이해하는데 더 적합하다고 판단했습니다.)
*/
SIMPLE_QUEUE::Node* SIMPLE_QUEUE::SimpleQueue::Dequeue()
{
	// 반환할 노드의 포인터를 생성해줍니다.
	Node* pDequeueNode = nullptr;

	// 큐가 비어있는 지 여부를 검사합니다.
	if (pFront == nullptr)
	{
		std::cout << "		[Warning] Queue Underflow 'The Queue is Empty'  \n";
		return pDequeueNode; /* == nullptr */
	}

	// 큐가 비어있지 않을 때입니다.
	else /* == else if (pFront != nullptr) */
	{
		// Front에 잇는 노드를 반환하기 위해, Dequeue 노드에 할당합니다. 
		pDequeueNode = pFront;

		// pFront(== pDequeueNode)의 다음 노드가 없을 때
		if (pFront->pNext == nullptr)
		{
			// pFront == pBack인 상황(즉 큐의 노드가 1개인 상황)이며, 큐는 빈상태가 됩니다. 
			pFront = nullptr;
			pBack = nullptr;	//!

			return pDequeueNode;
		}

		// pFront(== pDequeueNode)의 다음 노드가 있을 때.
		else /* == else if (pFront->pNext != nullptr) */
		{
			// pFront는 이제 Dequeue되기 때문에, 다음 노드를 pFront로 옮김.
			pFront = pFront->pNext;

			return pDequeueNode;
		}
	}
}

/* 멍청한 함수입니다. */
void SIMPLE_QUEUE::ExampleFunction()
{
	std::cout
		<< "\n\n"
		<< " [Hello] Simple Queue의 예제함수를 실행합니다. \n"
		<< "\n\n"
		<< "  1. 먼저 큐에 1,2,3,4,5를 차례대로 Enqueue합니다. ( F == pFront, B == pBack) \n"
		<< "	  - 방향은 우 <- 좌 입니다.  <------  \n";

	SimpleQueue myQueue;	// 큐 생성

	//실제로는 SimpleQueue에 PrintAllNodes 등 관련 함수를 구현하여 데이터를 출력해야합니다.
	myQueue.Enqueue(1);		// 1 삽입
	std::cout
		<< "\n"
		<< "	  [ F ~ B ]   \n"
		<< "	      1    (1개일 때는 Back과 Front가 동일합니다. )\n";

	myQueue.Enqueue(2);		// 2 삽입
	std::cout
		<< "\n"
		<< "	  [ F ~ B ]   \n"
		<< "	    1 - 2     \n";

	myQueue.Enqueue(3);		// 3 삽입
	std::cout
		<< "\n"
		<< "	  [ F   ~   B ]   \n"
		<< "	    1 - 2 - 3     \n";

	myQueue.Enqueue(4);		// 4 삽입
	std::cout
		<< "\n"
		<< "	  [ F     ~     B ]   \n"
		<< "	    1 - 2 - 3 - 4     \n";

	myQueue.Enqueue(5);		// 5 삽입
	std::cout
		<< "\n"
		<< "	  [ F       ~       B ]   \n"
		<< "	    1 - 2 - 3 - 4 - 5     \n";

	std::cout
		<< "\n\n"
		<< "	2. 큐에서 5번 Dequeue합니다.\n";

	//실제로는 Dequeue한 노드의 데이터를 확인해야합니다.
	for (int i = 0; i < 5; ++i)
	{
		Node* pDequeuedNode = myQueue.Dequeue();
		delete pDequeuedNode;
	}

	std::cout
		<< "\n"
		<< "	  [ F     ~     B ]   \n"
		<< "	    2 - 3 - 4 - 5     \n"
		<< "\n"
		<< "	  [ F   ~   B ]   \n"
		<< "	    3 - 4 - 5     \n"
		<< "\n"
		<< "	  [ F ~ B ]   \n"
		<< "	    4 - 5     \n"
		<< "\n"
		<< "	  [ F~B ]   \n"
		<< "	     5     \n"
		<< "\n"
		<< "	  [ F ~ B ]   \n"
		<< "	    void     \n";

	std::cout
		<< "\n\n"
		<< "	3. 큐가 빈 상태일 때, Dequeue을 시도합니다.\n";

	delete myQueue.Dequeue(); /* == nullptr */

	std::cout
		<< "\n\n"
		<< " [Bye] 감사합니다. 이상으로 Simple Queue의 예제함수를 종료합니다.\n";

	// 현재 상황에서는 발생하지 않으나, 실제로 Queue 내부에 메모리가 할당되어져 있는 상태에서
	// 변수의 범위 밖으로 나갈 경우, 메모리 누수가 발생하게 됩니다.
	// 이를 방지하기 위해, Queue에 아직 할당되어 있는 메모리가 있다면(아직 노드가 존재한다면)
	// Queue의 소멸자에서 이를 모두 돌려두는 작업이 필요합니다. 
}