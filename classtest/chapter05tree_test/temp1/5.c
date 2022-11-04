#include <stdio.h>
#include <stdlib.h>

#define M 100

typedef struct BinaryTree_Node {
	char value;
	struct BinaryTree_Node* lChild;
	struct BinaryTree_Node* rChild;
} *BT_Node;

int numberOfLeafNodes = 0;
int numberOf1Nodes = 0;
int numberOf2Nodes = 0;
char leaves[M] = { 0 };

//创建
BT_Node Create_BinaryTree() {
	BT_Node root = (BT_Node)malloc(sizeof(struct BinaryTree_Node));
	char temp;
	scanf("%c", &temp);
	if (temp != '#') {
		root->value = temp;
		root->lChild = Create_BinaryTree();
		root->rChild = Create_BinaryTree();
	}
	else {
		root = NULL;
	}
	return root;
}

//先序遍历
void Preorder_traverse(BT_Node root) {
	if (root == NULL) {
		return;
	}
	if (root->lChild && root->rChild) {
		numberOf2Nodes++;
	} else if (root->lChild || root->rChild) {
		numberOf1Nodes++;
	} else {
		leaves[numberOfLeafNodes++] = root->value;
	}
	Preorder_traverse(root->lChild);
	Preorder_traverse(root->rChild);
}

int main() {
	BT_Node root;
	root = Create_BinaryTree();
	Preorder_traverse(root);
	printf("%d %d %d\n", numberOfLeafNodes, numberOf1Nodes, numberOf2Nodes);
	printf("%s", leaves);
}
