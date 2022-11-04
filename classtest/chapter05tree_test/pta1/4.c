 #include <stdio.h>
#include <stdlib.h>


typedef struct BinaryTree_Node {
	char data;
	int count;
	struct BinaryTree_Node* lChild;
	struct BinaryTree_Node* rChild;
} *BT_Node;

typedef struct queue {
	BT_Node elements[100];
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
//判空
int empty() {
	return q.rear == q.front;
}
//入栈操作
void push(BT_Node temp) {
	q.elements[++q.rear] = temp;
}
//取出栈顶
BT_Node pop() {
	return q.elements[++q.front];
}
 
//创建
BT_Node Create () {
	BT_Node root = (BT_Node)malloc(sizeof(struct BinaryTree_Node));
	char c;
	scanf("%c", &c);
	if (c != '#') {
		root->data = c;
		root->lChild = Create ();
		root->rChild = Create ();
	} else {
		root = NULL;
	}
	return root;
}
//二叉树的层次遍历
void LevelOrder (BT_Node root) {
	BT_Node temp;
	push(root);
	while (!empty()) {
		temp = pop();
		printf("%c", temp->data);
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
	root = Create ();
	LevelOrder(root);
}