#include <stdio.h>
#include <stdlib.h>

#define Max 100

typedef struct BinaryTree_Node {
	char value;
	int count;
	struct BinaryTree_Node* lChild;
	struct BinaryTree_Node* rChild;
} *BT_Node;

typedef struct queue {
	BT_Node elements[Max];
	int front;
	int rear;
} Queue;

BT_Node root;
Queue q;

//初始化
void init() {
	q.front= 0;
	q.rear = 0;
}
//入栈操作
void push(BT_Node temp) {
	q.elements[++q.rear] = temp;
}
//取栈顶并出栈顶
BT_Node pop() {
	return q.elements[++q.front];
}
//判空
int empty() {
	return q.rear == q.front;
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
//二叉树的层次遍历
void LevelOrder_Traversal(BT_Node root) {
	BT_Node temp;
	push(root);
	while (!empty()) {
		temp = pop();
		printf("%c", temp->value);
		if (temp->lChild) {
			push(temp->lChild);
		}
		if (temp->rChild) {
			push(temp->rChild);
		}
	}
	printf("\n");
}

int main() {
	init();
	root = Create_BinaryTree();
	LevelOrder_Traversal(root);
}
