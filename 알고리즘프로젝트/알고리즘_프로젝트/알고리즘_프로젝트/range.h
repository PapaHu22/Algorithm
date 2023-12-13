#pragma once

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000 /* 무한대 (연결이 없는 경우) */

typedef struct Enemy {
	int index;
	int HP;
	int damage;
}Em;

typedef struct GraphType {
	int n; // 정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int choose(int distance[], int n, int found[]);
void print_status(GraphType* g, int* distance, int* found);
int shortest_path(GraphType* g, int start, int index);


int St1(int* p_hp);
int St2_1(int* p_hp);
int St2_2(int* p_hp);
int St3_1(int* p_hp);
int St3_2(int* p_hp);
int St3_3(int* p_hp);
int St4_1(int* p_hp);
int St4_2(int* p_hp);
int St4_3(int* p_hp);
int Boss(int* p_hp);
