#include <stdio.h>
#include <stdlib.h>

#define MAX_SERVICES 50
typedef struct GraphNode
{
	int vertex;
	struct GraphNode* link;

}GraphNode;

typedef struct GraphType {
	int n;
	GraphNode* adj_list[MAX_SERVICES];
}GraphType;

void init(GraphType* g)
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_SERVICES; v++)
		g->adj_list[v] = NULL;
}

void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_SERVICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u, int v)
{
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;

}

void print_adj_list(GraphType* g)
{
	for (int i = 0; i < g->n; i++) {
		GraphNode* p = g->adj_list[i];
		printf("정점 %d의 인접 리스트 ", i);
		while (p!=NULL) {
			printf("-> %d ", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}

int main()
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 4; i++)
		insert_vertex(g, i);
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 1);
	print_adj_list(g);
	free(g);
	return 0;
}