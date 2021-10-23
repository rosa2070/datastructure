#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* search(TreeNode* node, int key)
{
	if (node == NULL)return NULL;
	if (key == node->key)return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}

TreeNode* new_node(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, int key)
{
	if (node == NULL) return new_node(key);

	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if(key > node->key)
		node->right = insert_node(node->right, key);

	return node;
}

TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;

	while (current->left != NULL)
		current = current->left;

	return current;
}

TreeNode* delete_node(TreeNode* root, int key)
{
	if (root == NULL)return root;

	if (key < root->key)
		root->left = delete_node(root->left, key);
	else if (key > root->key)
		root->right = delete_node(root->right, key);
	else {
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}

		TreeNode* temp = min_value_node(root->right);

		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}


void help()
{
	printf("\n**** i: 입력, d: 삭제, s: 탐색, p: 출력, q: 종료 ****: ");
}
int main(void)
{
	int number=0;
	char command;
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;



	do {
		help();
		command = getchar();
		getchar();
		switch (command) {
		case 'i':
			printf("삽입할 정수: ");
			scanf("%d",&number);
			root = insert_node(root, number);
			break;
		case 'd':
			printf("삭제할 정수: ");
			scanf("%d", &number);
			root = delete_node(root, number);
			break;
		case 's':
			printf("검색할 정수: ");
			scanf("%d", &number);
			tmp = search(root, number);
			if (tmp != NULL)
				printf("이진 탐색트리에서 %d를 발견함", number);
			break;
		case 'p':
			inorder(root);
			break;
		}
		getchar();    //while(getchar() != '\n');

	} while (command != 'q');

	return 0;
}