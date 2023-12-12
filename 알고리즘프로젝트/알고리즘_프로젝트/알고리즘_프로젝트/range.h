#pragma once

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000 /* ���Ѵ� (������ ���� ���) */

typedef struct Enemy {
	int index;
	int HP;
	int damage;
}Em;

typedef struct GraphType {
	int n; // ������ ����
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int choose(int distance[], int n, int found[]);
void print_status(GraphType* g, int* distance, int* found);
int shortest_path(GraphType* g, int start, int index);


void St1(int* p_hp);
void St2_1(int* p_hp);
void St2_2(int* p_hp);
void St3_1(int* p_hp);
void St3_2(int* p_hp);
void St3_3(int* p_hp);
void St4_1(int* p_hp);
void St4_2(int* p_hp);
void St4_3(int* p_hp);
void Boss(int* p_hp);
