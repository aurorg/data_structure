#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTree_Node {
	char value;
	struct BinaryTree_Node* lChild;
	struct BinaryTree_Node* rChild;
} *BT_Node;

int MAX = 0;

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

// 先序遍历 
void Preorder_traverse(BT_Node root, int depth) {
	if (root == NULL) {
		return;
	}
	if (depth > MAX) {
		MAX = depth;
	}
	Preorder_traverse(root->lChild, depth + 1);
	Preorder_traverse(root->rChild, depth + 1);
}

int main() {
	BT_Node root;
	root = Create_BinaryTree();
	Preorder_traverse(root, 1);
	printf("%d", MAX);
}
