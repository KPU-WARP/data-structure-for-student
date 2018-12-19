#include "../src/Queue/cpp/SimpleQueue.h"

/*
	void Enqueue(int)
			- ���ڷ� �־��� �����͸� �Ҵ���� ��带 ����(�޸� �Ҵ�, new)�Ͽ�, ť�� Back �κп� �߰��մϴ�.

			���� : ������ ��忡 �Ҵ��� ������
			��� : void
*/
void SIMPLE_QUEUE::SimpleQueue::Enqueue(int InData)
{
	// ������ ��带 �������ݴϴ�.
	Node* pEnqueueNode = new Node;

	// �ش� ����� �����͸� �Լ��� ���ڰ����� �����մϴ�.
	pEnqueueNode->data = InData;

	// ť�� Back(������ ���)�� nullptr�� �� (== ť�� �� ������ ��)
	if (pBack == nullptr)
	{
		// ť�� ������ ��ġ�� ��带 �������ݴϴ�.
		pBack = pEnqueueNode;

		// ť�� Back(������ ���)�� nullptr�� ���� Front(�� �� ���)�� �׻� nullptr�Դϴ�.
		pFront = pEnqueueNode;

		// !0. �� �ڵ忡���� ��������, ��� �ϳ��� ���ҽ��� �������� �⺻ �����Ͱ� ����Ű�� ���� ġ������ ������ �߱��� �� �ֽ��ϴ�. 
		//		- ���� Ű���� : ��۸� ������, ����Ʈ ������(shared_ptr)
	}

	// ť�� �� ���°� �ƴ� ���
	else /* == else if (pBack != nullptr )*/
	{
		// ť�� ������ ��忡 ���� ��ġ(pNext)�� �����ϴ� ��带 �ֽ��ϴ�.
		pBack->pNext = pEnqueueNode;	

		// ���� ť�� ������ ��ġ�� �����ϴ�.
		pBack = pEnqueueNode;
	}

	return;
}


/*
	Node* Dequeue()
		- ť�� Front �κп��� ��带 ���� ��ȯ�մϴ�.

		���� : void
		��� : Dequeue�Ǵ� Node�� ������

		!1. ť�� ������� �� Dequeue�� ȣ���� ���, Waring Log�� ����ϸ�, nullptr�� ��ȯ�մϴ�. ( Queue Underflow )
		!2. ��ȯ �� ��ȯ�� ����� ��� ���� pNext�� ���� ��κ��� ��� ����ϸ� �ȵ˴ϴ�.
			- ��ȯ�ϱ� ����, pDequeueNode->pNext�� nullptr�� ������ ��, ��ȯ�ϴ� �͵� ���ƿ�! :)
			- �Ǵ� Data�� ��ȯ�ϴ� �͵� ���ƿ�! (�ڵ��, Node ��ü�� ��ȯ�ϴ� ���� ���������� �����ϴµ� �� �����ϴٰ� �Ǵ��߽��ϴ�.)
*/
SIMPLE_QUEUE::Node* SIMPLE_QUEUE::SimpleQueue::Dequeue()
{
	// ��ȯ�� ����� �����͸� �������ݴϴ�.
	Node* pDequeueNode = nullptr;

	// ť�� ����ִ� �� ���θ� �˻��մϴ�.
	if (pFront == nullptr)
	{
		std::cout << "		[Warning] Queue Underflow 'The Queue is Empty'  \n";
		return pDequeueNode; /* == nullptr */
	}

	// ť�� ������� ���� ���Դϴ�.
	else /* == else if (pFront != nullptr) */
	{
		// Front�� �մ� ��带 ��ȯ�ϱ� ����, Dequeue ��忡 �Ҵ��մϴ�. 
		pDequeueNode = pFront;

		// pFront(== pDequeueNode)�� ���� ��尡 ���� ��
		if (pFront->pNext == nullptr)
		{
			// pFront == pBack�� ��Ȳ(�� ť�� ��尡 1���� ��Ȳ)�̸�, ť�� ����°� �˴ϴ�. 
			pFront = nullptr;
			pBack = nullptr;	//!

			return pDequeueNode;
		}

		// pFront(== pDequeueNode)�� ���� ��尡 ���� ��.
		else /* == else if (pFront->pNext != nullptr) */
		{
			// pFront�� ���� Dequeue�Ǳ� ������, ���� ��带 pFront�� �ű�.
			pFront = pFront->pNext;

			return pDequeueNode;
		}
	}
}

/* ��û�� �Լ��Դϴ�. */
void SIMPLE_QUEUE::ExampleFunction()
{
	std::cout
		<< "\n\n"
		<< " [Hello] Simple Queue�� �����Լ��� �����մϴ�. \n"
		<< "\n\n"
		<< "  1. ���� ť�� 1,2,3,4,5�� ���ʴ�� Enqueue�մϴ�. ( F == pFront, B == pBack) \n"
		<< "	  - ������ �� <- �� �Դϴ�.  <------  \n";

	SimpleQueue myQueue;	// ť ����

	//�����δ� SimpleQueue�� PrintAllNodes �� ���� �Լ��� �����Ͽ� �����͸� ����ؾ��մϴ�.
	myQueue.Enqueue(1);		// 1 ����
	std::cout
		<< "\n"
		<< "	  [ F ~ B ]   \n"
		<< "	      1    (1���� ���� Back�� Front�� �����մϴ�. )\n";

	myQueue.Enqueue(2);		// 2 ����
	std::cout
		<< "\n"
		<< "	  [ F ~ B ]   \n"
		<< "	    1 - 2     \n";

	myQueue.Enqueue(3);		// 3 ����
	std::cout
		<< "\n"
		<< "	  [ F   ~   B ]   \n"
		<< "	    1 - 2 - 3     \n";

	myQueue.Enqueue(4);		// 4 ����
	std::cout
		<< "\n"
		<< "	  [ F     ~     B ]   \n"
		<< "	    1 - 2 - 3 - 4     \n";

	myQueue.Enqueue(5);		// 5 ����
	std::cout
		<< "\n"
		<< "	  [ F       ~       B ]   \n"
		<< "	    1 - 2 - 3 - 4 - 5     \n";

	std::cout
		<< "\n\n"
		<< "	2. ť���� 5�� Dequeue�մϴ�.\n";

	//�����δ� Dequeue�� ����� �����͸� Ȯ���ؾ��մϴ�.
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
		<< "	3. ť�� �� ������ ��, Dequeue�� �õ��մϴ�.\n";

	delete myQueue.Dequeue(); /* == nullptr */

	std::cout
		<< "\n\n"
		<< " [Bye] �����մϴ�. �̻����� Simple Queue�� �����Լ��� �����մϴ�.\n";

	// ���� ��Ȳ������ �߻����� ������, ������ Queue ���ο� �޸𸮰� �Ҵ�Ǿ��� �ִ� ���¿���
	// ������ ���� ������ ���� ���, �޸� ������ �߻��ϰ� �˴ϴ�.
	// �̸� �����ϱ� ����, Queue�� ���� �Ҵ�Ǿ� �ִ� �޸𸮰� �ִٸ�(���� ��尡 �����Ѵٸ�)
	// Queue�� �Ҹ��ڿ��� �̸� ��� �����δ� �۾��� �ʿ��մϴ�. 
}