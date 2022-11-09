// 7-2 非递归先序和中序遍历
// 分数 20
// 作者 王燕
// 单位 西安邮电大学
// 从键盘接收扩展先序序列，以二叉链表作为存储结构，建立二叉树。采取非递归方法输出这棵二叉树的先序、中序遍历序列。

// 输入格式:
// 输入扩展先序序列。二叉树结点的data是字符类型数据, 其中#表示空格字符。

// 输出格式:
// 第一行输出先序遍历序列，第二行输出中序遍历序列。

// 输入样例:
// ABC##DE#G##F### 

#include <stdio.h>
#include <stdlib.h>
typedef struct BinaryTree_Node {
	char data;
	struct BinaryTree_Node* lChild;
	struct BinaryTree_Node* rChild;
} *BT_Node;

typedef struct stack {
	BT_Node elements[100];
	int top;
} seqstack;
//定义一个储存树类型地址的栈，方便遍历的时候追踪到树的地址。

BT_Node root;//定义一个树根
seqstack s;//定义栈

//初始化栈
void setnull() {
	s.top = 0;
}
//空
int empty() {
	return s.top == 0;
}
//入栈
void push(BT_Node temp) {
	s.elements[s.top++] = temp;
}
//取出栈顶
BT_Node pop() {
	return s.elements[--s.top];
}
 
//创建树
BT_Node Create() {
	BT_Node root = (BT_Node)malloc(sizeof(struct BinaryTree_Node));
	char c;
	scanf("%c", &c);
	if (c != '#') {
		root->data = c;
		root->lChild = Create();
		root->rChild = Create();
	} else {
		root = NULL;
	}
	return root;
}
//前序遍历的非递归算法
void Preorder (BT_Node root) {
	BT_Node temp = root;
	while (temp != NULL || s.top != 0) {
		//先遍历左孩子，并输出。
		while (temp != NULL) {
			printf("%c", temp->data);
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
void Inorder (BT_Node root) {
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
			printf("%c", temp->data);
			temp = temp->rChild;
		}
	}
	printf("\n");
}

int main() {
	BT_Node root;
	root = Create();
	Preorder(root);
	Inorder(root);
}