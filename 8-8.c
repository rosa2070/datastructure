#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define max(a,b)  (((a)>(b))?(a):(b))

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int is_thread;
}TreeNode;

TreeNode n1 = { 'A', NULL, NULL, 1 };
TreeNode n2 = { 'B', NULL, NULL, 1 };
TreeNode n3 = { 'C', &n1, &n2, 0 };
TreeNode n4 = { 'D', NULL, NULL, 1 };
TreeNode n5 = { 'E', NULL, NULL, 0 };
TreeNode n6 = { 'F', &n4, &n5, 0 };
TreeNode n7 = { 'G', &n3, &n6, 0 };
TreeNode* exp = &n7;

TreeNode* find_successor(TreeNode* p)
{
	TreeNode* q = p->right;
	if (q == NULL || p->is_thread == TRUE)
		return q;


	while (q->left != NULL)
		q = q->left;


	return q;
}

void thread_inorder(TreeNode* t)
{
	TreeNode* q;

	q = t;
	while (q->left) q = q->left;
	do {
		printf("%c -> ", q->data);
		q = find_successor(q);
	} while (q);
}

int get_node_count(TreeNode* node)
{
	int count = 0;

	if (node != NULL)
		count = 1 + get_node_count(node->left) + get_node_count(node->right);

	return count;
}

int get_leaf_count(TreeNode* node)
{
	int count = 0;

	if (node != NULL) {
		if (node->left == NULL && node->right == NULL)
			return 1;
		else
			count = get_leaf_count(node->left) + get_leaf_count(node->right);
	}
	return count;
}

int get_nonleaf_count(TreeNode* node)
{
	int count = 0;
	if (node != NULL && (node->left != NULL || node->right != NULL))
		count = 1 + get_nonleaf_count(node->left) + get_nonleaf_count(node->right);
	return count;
}

int get_height(TreeNode* node)
{
	int height = 0;

	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));

	return height;
}



int main(void)
{
	printf("총 노드 수는 %d개입니다.\n", get_node_count(exp));
	printf("단말 노드 수는 %d개입니다.\n", get_leaf_count(exp));
	printf("비단말 노드 수는 %d개입니다.\n", get_nonleaf_count(exp));
	printf("트리의 높이는 %d입니다.\n", get_height(exp));

	n1.right = &n3;
	n2.right = &n7;
	n4.right = &n6;

	thread_inorder(exp);
	printf("\n");



	return 0;
}




