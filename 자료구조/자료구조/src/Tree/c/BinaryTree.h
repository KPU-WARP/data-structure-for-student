#ifndef __BINARY_TREE__
#define __BINARY_TREE__

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
/////////////////////////////////////////////////////////////////////////////////
// 전처리 끝

// 자료형 선언
/////////////////////////////////////////////////////////////////////////////////
typedef enum {
	  BT_PreOrder
	, BT_InOrder
	, BT_PostOrder
} BT_TRAVERSAL;

typedef struct BT_NODE {
	int					key;
	struct BT_NODE*		parent;
	struct BT_NODE*		left_child;
	struct BT_NODE*		right_child;
} BT_NODE;

typedef struct BinaryTree {
	BT_NODE*			root;
	unsigned int		nDatas;
} BinaryTree;

// 함수 선언
/////////////////////////////////////////////////////////////////////////////////
void		BT_Init(BinaryTree* bt);
void		BT_Clear(BinaryTree* bt);

void		BT_Insert(BinaryTree* bt, int key);
BT_NODE*	BT_Search(BinaryTree* bt, int key);
void		BT_Delete(BinaryTree* bt, int key);

void		BT_Traversal(BinaryTree* bt, BT_TRAVERSAL type);
#endif