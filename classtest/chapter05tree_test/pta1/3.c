 #include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTree_Node {
	char data;
	int count;
	struct BinaryTree_Node* lChild;
	struct BinaryTree_Node* rChild;
} *BT_Node;

typedef struct stack {
	BT_Node elements[100];
	int top;
} seqstack;

BT_Node root;
seqstack s;

//初始化
void init() {
	s.top = 0;
}

//判空
int empty() {
	return s.top == 0;
}

//入栈操作
void push(BT_Node temp) {
	s.elements[s.top++] = temp;
}

//取栈顶并出栈顶
BT_Node pop() {
	return s.elements[--s.top];
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

//后序遍历非递归算法
void Postorder (BT_Node root) {
	BT_Node temp = root;
	while (temp != NULL || s.top != 0) {
		while (temp != NULL) {
			temp->count = 1;// 当前节点首次被访问
			push(temp);
			temp = temp->lChild;
		}
		if (s.top != 0) {
			temp = pop();
			// 第一次出现在栈顶，继续向右找
			if (temp->count == 1) {
				temp->count++;
				push(temp);
				temp = temp->rChild;
			} else if (temp->count == 2) {
                //第二次输出并制空，防止陷入死循环
				printf("%c", temp->data);
				temp = NULL;
			}
		}
	}
	printf("\n");
}

int main() {
	BT_Node root;
	init();
	root = Create();
	Postorder(root);
}
