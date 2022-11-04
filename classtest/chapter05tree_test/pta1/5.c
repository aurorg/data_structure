#include <stdio.h>
#include <stdlib.h>
typedef struct BinaryTree_Node {
	char data;
	struct BinaryTree_Node* lChild;
	struct BinaryTree_Node* rChild;
} *BT_Node;
int LeafNodes = 0;
int Nodes1 = 0;
int Nodes2 = 0;
char leaves[100] = { 0 };

BT_Node createBiTree() {
	BT_Node root = (BT_Node)malloc(sizeof(struct BinaryTree_Node));
	char temp;
	scanf("%c", &temp);
	if (temp != '#') {
		root->data = temp;
		root->lChild = createBiTree();
		root->rChild = createBiTree();
	}
	else {
		root = NULL;
	}
	return root;
}

//先序遍历
void Preorder(BT_Node root) {
	if (root == NULL) {
		return;
	}
	if (root->lChild && root->rChild) {
		Nodes2++;
	} else if (root->lChild || root->rChild) {
		Nodes1++;
	} else {
		leaves[LeafNodes++] = root->data;
	}
	Preorder(root->lChild);
	Preorder(root->rChild);
}

int main() {
	BT_Node root;
	root = createBiTree();
	Preorder(root);
	printf("%d %d %d\n", LeafNodes, Nodes1, Nodes2);
	printf("%s", leaves);
}
