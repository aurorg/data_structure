#include <stdio.h>
#include <stdlib.h>

#define M 100

typedef struct BinaryTree_Node {
	char value;
	struct BinaryTree_Node* lChild;
	struct BinaryTree_Node* rChild;
} *BT_Node;

typedef struct stack {
	BT_Node elements[M];
	int top;
} seqstack;
//定义一个储存树类型地址的栈，方便遍历的时候追踪到树的地址。

BT_Node root;//定义一个树根
seqstack s;//定义栈

//初始化栈
void setnull() {
	s.top = 0;
}
//入栈操作
void push(BT_Node temp) {
	s.elements[s.top++] = temp;
}
//取栈顶并出栈顶
BT_Node pop() {
	return s.elements[--s.top];
}
//判空
int empty() {
	return s.top == 0;
}
//创建
BT_Node Create_BinaryTree() {
	BT_Node root = (BT_Node)malloc(sizeof(struct BinaryTree_Node));
	char temp;
	scanf("%c", &temp);
	if (temp != '#') {
		root->value = temp;
		root->lChild = Create_BinaryTree();
		root->rChild = Create_BinaryTree();
	} else {
		root = NULL;
	}
	return root;
}
//前序遍历的非递归算法
void Preorder_traverse(BT_Node root) {
	BT_Node temp = root;
	while (temp != NULL || s.top != 0) {
		//先遍历左孩子，并输出。
		while (temp != NULL) {
			printf("%c", temp->value);
			push(temp);
			temp = temp->lChild;
		}
		//当左孩子遍历完后，取栈顶，找右孩子。此时循环还没有结束，再遍历它的左孩子，直至孩子全部遍历结束。
		if (s.top != 0) {
			temp = pop();
			temp = temp->rChild;
		}
	}
	printf("\n");
}
//中序遍历的非递归算法
void Inorder_traverse(BT_Node root) {
	BT_Node temp = root;
	while (temp != NULL || s.top != 0) {
		//先把左孩子入栈，所有左孩子入栈结束
		while (temp != NULL) {
			push(temp);
			temp = temp->lChild;
		}
		//左孩子入栈结束，取栈顶，输出栈顶元素，遍历右孩子
		if (s.top != 0) {
			temp = pop();
			printf("%c", temp->value);
			temp = temp->rChild;
		}
	}
	printf("\n");
}

int main() {
	BT_Node root;
	root = Create_BinaryTree();
	Preorder_traverse(root);
	Inorder_traverse(root);
	//Postorder_traverse(root);
}
