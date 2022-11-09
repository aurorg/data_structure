// 7-5 结点个数
// 分数 20
// 作者 王燕
// 单位 西安邮电大学
// 从键盘接收扩展先序序列，以二叉链表作为存储结构，建立二叉树。分别统计二叉树中叶子结点、度为1的结点、度为2的结点的个数，并输出。

// 输入格式:
// 输入扩展先序序列。二叉树结点的data是字符类型数据, 其中#表示空格字符。

// 输出格式:
// 第一行依次输出叶子结点个数、度为1的结点个数、度为2的结点个数，以空格隔开。
// 第二行连续输出叶子结点，中间不间隔。

// 输入样例:
// ABC##DE#G##F###
// 输出样例:
// 3 2 2
// CGF
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

