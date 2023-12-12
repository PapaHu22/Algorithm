#pragma once

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000 /* 무한대 (연결이 없는 경우) */


typedef struct GraphType {
	int n; // 정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int choose(int distance[], int n, int found[]);
void print_status(GraphType* g);
int shortest_path(GraphType* g, int start, int index);

void En2_Room1();
void En3_Room1();
void En4_Room1();
void En4_Room2();
void En5_Room1();
void En5_Room2();