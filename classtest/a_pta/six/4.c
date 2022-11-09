// 7-4 层次遍历
// 分数 10
// 作者 王燕
// 单位 西安邮电大学
// 从键盘接收扩展先序序列，以二叉链表作为存储结构，建立二叉树。输出这棵二叉树的层次遍历序列。

// 输入格式:
// 输入扩展先序序列。二叉树结点的data是字符类型数据, 其中#表示空格字符。

// 输出格式:
// 输出层次遍历序列。

// 输入样例:
// ABC##DE#G##F### 
// 输出样例:
// ABCDEFG
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