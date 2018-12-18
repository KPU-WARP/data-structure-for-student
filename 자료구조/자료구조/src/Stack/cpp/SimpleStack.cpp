#include "../src/Stack/cpp/SimpleStack.h"

/*
	Push(int InData)
		- ���ڷ� �־��� �����͸� �Ҵ���� ��带 ����(=�޸� �Ҵ�, new)�Ͽ�, ���ÿ� �߰��մϴ�.

		���� : ������ ��忡 �Ҵ��� ������(InData)
		��� : Void
*/
void SIMPLE_STACK::SimpleStack::Push(int InData)
{
	//���� Push�� ��带 �������ݴϴ�.
	Node* pPushNode = new Node;
	
	// �ش� ����� �����͸� ���ڰ����� �Ҵ����ݴϴ�.
	pPushNode->data = InData;

	// ������ ������� ���� ��
	if (pTop != nullptr)			
	{
		// Push�� ����� �Ʒ� ����, ������ ���� Top���� �����մϴ�.
		pPushNode->pDown = pTop;	

		// ������ ���ο� Top��带, Push���� �����մϴ�.
		pTop = pPushNode;

		return;
	}

	// ������ �� ������ ��
	else /* == else if (pTop == nullptr) */ 
	{
		// ������ ���ο� Top��带, Push���� �����մϴ�.
		pTop = pPushNode;

		return;
	}
}

/*
	Node* Pop()
		- ������ Top Pointer���� ��带 ���� ��ȯ�մϴ�.

		���� : Void
		��� : Pop�Ǵ� Node�� ������

		!1. Top Pointer�� Null�� ��, Pop�� ȣ���� ���, Warning Log�� ����ϸ�, Nullptr�� ��ȯ�մϴ�.
*/
SIMPLE_STACK::Node* SIMPLE_STACK::SimpleStack::Pop()
{
	// Pop�� ��忡 ���� ������ ���� ����.
	Node* pPopNode = nullptr;

	// ������ ������� ���� ��
	if (pTop != nullptr)
	{
		// ������ TopNode�� PopNode�� �����Ѵ�.
		pPopNode = pTop;

		// ������ TopNode�� ���� TopNode�� �Ʒ����� �����Ѵ�.
		pTop = pTop->pDown; /* == pPopNode->pDown */

		return pPopNode;
	}

	// [���] ������ �� ������ ��
	else /* == else if (pTop == nullptr) */
	{
		std::cout << "		[Warning] The Stack is Empty \n";
		return pPopNode; /* == nullptr */
	}
}

/* ��û�� �Լ��Դϴ�. */
void SIMPLE_STACK::ExampleFunction()
{
	std::cout 
		<< "\n\n"
		<< " [Hello] Simple Stack�� �����Լ��� �����մϴ�. \n"
		<< "\n\n"
		<< "	1. ���� ���ÿ� 1,2,3,4,5�� ���ʴ�� Push�մϴ�.\n";
		
	SimpleStack myStack;
	myStack.Push(1);
	myStack.Push(2);
	myStack.Push(3);
	myStack.Push(4);
	myStack.Push(5);

	//�����δ� SimpleStack�� PrintAllNodes �� ���� �Լ��� �����Ͽ� �����͸� ����ؾ��մϴ�.
	std::cout 
		<< "\n"
		<< "											5	\n"
		<< "									4		4	\n"
		<< "		->		->		->	3	->	3	->	3	\n"
		<< "					2		2		2		2	\n"
		<< "	void		1		1		1		1		1	\n";


	std::cout 
		<< "\n\n"
		<< "	2. ���ÿ��� ���ʴ�� Pop�մϴ�.\n";

	myStack.Pop();
	myStack.Pop();
	myStack.Pop();
	myStack.Pop();
	myStack.Pop();

	//�����δ� Pop�� ����� �����͸� Ȯ���ؾ��մϴ�.
	std::cout 
		<< "\n"
		<< "	5										\n"
		<< "	4		4								\n"
		<< "	3	->	3	->	3	->		->		->	\n"
		<< "	2		2		2		2				\n"
		<< "	1		1		1		1		1		void\n";


	//�̷� ��Ȳ�� ����� �մϴ�.
	std::cout
		<< "\n\n"
		<< "	3. ������ ������� ��, Pop�� �õ��մϴ�.\n";

	myStack.Pop();

	std::cout
		<< "\n\n"
		<< " [GoodBye] �����մϴ�. �̻����� Simple Stack�� �����Լ��� �����մϴ�.\n";
}