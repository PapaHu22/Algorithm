#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <Windows.h>
#include "range.h"


int distance[MAX_VERTICES];/* 시작정점으로부터의 최단경로 거리 */
int found[MAX_VERTICES];

int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++)
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}

int time = 0;

void print_status(GraphType* g, int* distance, int* found)
{
	time++;
	int i = 0;
	printf("STEP %d: distance:", time);
	for (i = 0; i < g->n; i++) {
		if (distance[i] == INF) {
			printf(" *");
		}
		else {
			printf(" %d", distance[i]);
		}
	}
	printf("\n");
	printf("\tfound: %d %d %d %d %d %d\n\n",
		found[0], found[1], found[2], found[3], found[4], found[5]);
}

int shortest_path(GraphType* g, int start, int index)
{

	int distance[MAX_VERTICES];/* 시작정점으로부터의 최단경로 거리 */
	int found[MAX_VERTICES];

	int i, u, w;
	for (i = 0; i < g->n; i++) /* 초기화 */
	{
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE; /* 시작 정점 방문 표시 */
	distance[start] = 0;
	for (i = 0; i < g->n - 1; i++) {
		//print_status(g, distance, found);
		u = choose(distance, g->n, found);
		found[u] = TRUE;
		for (w = 0; w < g->n; w++)
			if (!found[w])
				if (distance[u] + g->weight[u][w] < distance[w])
					distance[w] = distance[u] + g->weight[u][w];
	}

	return distance[index] / 2;
}



void En5_Room1() {
	GraphType g = { 6,
		{{0, 2, INF, INF, INF, INF},
		{2, 0, 2, 2, INF, INF},
		{INF, 2, 0, INF, INF, INF, INF},
		{INF, 2, INF, 0, 2, INF},
		{INF, INF, INF, 2, 0, 2},
		{INF, INF, INF, INF, 2, 0}}
	};

	int died[5];
	int i;
	for (i = 0; i < 5; i++) {
		died[i] = FALSE;
	}

	int index = 0;
	int enemy_range;

	while (1) {
		do {
			printf("적이 5명 있습니다. 몇 번 적을 공격할까요? >> ");
			scanf("%d", &index);

			if (died[index - 1]) {
				printf("해당 적은 이미 죽였습니다.");
			}
			else {
				break;
			}
		} while (1);

		enemy_range = shortest_path(&g, 0, index);

		printf("선택한 적은 %d만큼 떨어져 있습니다.", enemy_range);


		if (enemy[index].hp <= 0) {
			printf("1번 적을 물리쳤다.\n");
			died[0] = TRUE;
			g.weight[0][1] = 1;
			g.weight[1][0] = 1;
			g.weight[1][2] = 1;
			g.weight[1][3] = 1;
			g.weight[2][1] = 1;
			g.weight[3][1] = 1;
		}

		if (index == 2) {
			printf("2번 적을 물리쳤다.\n");
			died[1] = TRUE;
			g.weight[2][1] = 1;
			g.weight[1][2] = 1;
		}

		if (index == 3) {
			printf("3번 적을 물리쳤다.\n");
			died[2] = TRUE;
			g.weight[3][1] = 1;
			g.weight[3][4] = 1;
			g.weight[1][3] = 1;
			g.weight[4][3] = 1;
		}

		if (index == 4) {
			printf("4번 적을 물리쳤다.\n");
			died[3] = TRUE;
			g.weight[4][3] = 1;
			g.weight[4][5] = 1;
			g.weight[3][4] = 1;
			g.weight[5][4] = 1;
		}

		if (index == 5) {
			printf("5번 적을 물리쳤다.\n");
			died[4] = TRUE;
			g.weight[5][4] = 1;
			g.weight[4][5] = 1;
		}

		if (died[0]) {
			if (died[1]) {
				if (died[2]) {
					if (died[3]) {
						if (died[4]) {
							printf("모든 적을 물리쳤다\n");
							Sleep(5000);
							break;
						}
					}
				}
			}
		}
	}

}

void En5_Room2() {
	GraphType g = { 6,
		{{0, 2, INF, INF, INF, INF},
		{2, 0, 2, 2, INF, INF},
		{INF, 2, 0, INF, 2, INF},
		{INF, 2, INF, 0, INF, INF},
		{INF, INF, 2, INF, 0, 2},
		{INF, INF, INF, INF, 2, 0}}
	};

	int died[5];
	int i;
	for (i = 0; i < 5; i++) {
		died[i] = FALSE;
	}

	int index = 0;
	int enemy_range;

	while (1) {
		do {
			printf("적이 5명 있습니다. 몇 번 적을 공격할까요? >> ");
			scanf("%d", &index);

			if (died[index - 1]) {
				printf("해당 적은 이미 죽였습니다.");
			}
			else {
				break;
			}
		} while (1);

		enemy_range = shortest_path(&g, 0, index);

		printf("선택한 적은 %d만큼 떨어져 있습니다.", enemy_range);


		if (index == 1) {
			printf("1번 적을 물리쳤다.\n");
			died[0] = TRUE;
			g.weight[0][1] = 1;
			g.weight[1][0] = 1;
			g.weight[1][2] = 1;
			g.weight[1][3] = 1;
			g.weight[2][1] = 1;
			g.weight[3][1] = 1;
		}

		if (index == 2) {
			printf("2번 적을 물리쳤다.\n");
			died[1] = TRUE;
			g.weight[2][1] = 1;
			g.weight[1][2] = 1;
			g.weight[2][4] = 1;
			g.weight[4][2] = 1;
		}

		if (index == 3) {
			printf("3번 적을 물리쳤다.\n");
			died[2] = TRUE;
			g.weight[3][1] = 1;
			g.weight[1][3] = 1;
		}

		if (index == 4) {
			printf("4번 적을 물리쳤다.\n");
			died[3] = TRUE;
			g.weight[4][2] = 1;
			g.weight[4][5] = 1;
			g.weight[2][4] = 1;
			g.weight[5][4] = 1;
		}

		if (index == 5) {
			printf("5번 적을 물리쳤다.\n");
			died[4] = TRUE;
			g.weight[5][4] = 1;
			g.weight[4][5] = 1;
		}

		if (died[0]) {
			if (died[1]) {
				if (died[2]) {
					if (died[3]) {
						if (died[4]) {
							printf("모든 적을 물리쳤다\n");
							Sleep(5000);
							break;
						}
					}
				}
			}
		}
	}
}

void En4_Room1() {
	GraphType g = { 5,
		{{0, 2, INF, INF, INF},
		{2, 0, 2, 2, INF},
		{INF, 2, 0, INF, 2},
		{INF, 2, INF, 0, INF},
		{INF, INF, 2, INF, 0}}
	};

	int died[4];
	int i;
	for (i = 0; i < 4; i++) {
		died[i] = FALSE;
	}

	int index = 0;
	int enemy_range;

	while (1) {
		do {
			printf("적이 4명 있습니다. 몇 번 적을 공격할까요? >> ");
			scanf("%d", &index);

			if (died[index - 1]) {
				printf("해당 적은 이미 죽였습니다.");
			}
			else {
				break;
			}
		} while (1);

		enemy_range = shortest_path(&g, 0, index);

		printf("선택한 적은 %d만큼 떨어져 있습니다.", enemy_range);


		if (index == 1) {
			printf("1번 적을 물리쳤다.\n");
			died[0] = TRUE;
			g.weight[1][0] = 1;
			g.weight[1][2] = 1;
			g.weight[1][3] = 1;
			g.weight[0][1] = 1;
			g.weight[2][1] = 1;
			g.weight[3][1] = 1;
		}

		if (index == 2) {
			printf("2번 적을 물리쳤다.\n");
			died[1] = TRUE;
			g.weight[2][1] = 1;
			g.weight[1][2] = 1;
			g.weight[2][4] = 1;
			g.weight[4][2] = 1;
		}

		if (index == 3) {
			printf("3번 적을 물리쳤다.\n");
			died[2] = TRUE;
			g.weight[3][1] = 1;
			g.weight[1][3] = 1;
		}

		if (index == 4) {
			printf("4번 적을 물리쳤다.\n");
			died[3] = TRUE;
			g.weight[4][3] = 1;
			g.weight[4][5] = 1;
			g.weight[3][4] = 1;
			g.weight[5][4] = 1;
		}

		if (died[0]) {
			if (died[1]) {
				if (died[2]) {
					if (died[3]) {
						printf("모든 적을 물리쳤다\n");
						Sleep(5000);
						break;
					}
				}
			}
		}
	}

}

void En4_Room2() {
	GraphType g = { 5,
		{{0, 2, 2, INF, INF},
		{2, 0, INF, 2, 2},
		{2, INF, 0, INF, INF},
		{INF, 2, INF, 0, INF},
		{INF, 2, INF, INF, 0}}
	};

	int died[4];
	int i;
	for (i = 0; i < 4; i++) {
		died[i] = FALSE;
	}

	int index = 0;
	int enemy_range;

	while (1) {
		do {
			printf("적이 4명 있습니다. 몇 번 적을 공격할까요? >> ");
			scanf("%d", &index);

			if (died[index - 1]) {
				printf("해당 적은 이미 죽였습니다.");
			}
			else {
				break;
			}
		} while (1);

		enemy_range = shortest_path(&g, 0, index);

		printf("선택한 적은 %d만큼 떨어져 있습니다.", enemy_range);


		if (index == 1) {
			printf("1번 적을 물리쳤다.\n");
			died[0] = TRUE;
			g.weight[1][0] = 1;
			g.weight[1][3] = 1;
			g.weight[1][4] = 1;
			g.weight[0][1] = 1;
			g.weight[3][1] = 1;
			g.weight[4][1] = 1;
		}

		if (index == 2) {
			printf("2번 적을 물리쳤다.\n");
			died[1] = TRUE;
			g.weight[2][0] = 1;
			g.weight[0][2] = 1;
		}

		if (index == 3) {
			printf("3번 적을 물리쳤다.\n");
			died[2] = TRUE;
			g.weight[3][1] = 1;
			g.weight[1][3] = 1;
		}

		if (index == 4) {
			printf("4번 적을 물리쳤다.\n");
			died[3] = TRUE;
			g.weight[4][1] = 1;
			g.weight[1][4] = 1;
		}

		if (died[0]) {
			if (died[1]) {
				if (died[2]) {
					if (died[3]) {
						printf("모든 적을 물리쳤다\n");
						Sleep(5000);
						break;
					}
				}
			}
		}
	}
}

void En3_Room1() {
	GraphType g = { 4,
   {{ 0, 2, 2, INF },
   { 2, 0, INF, 2 },
   { 2, INF, 0, 2 },
   { INF, 2, 2, 0 }}
	};

	int died[3];
	int i;
	for (i = 0; i < 3; i++) {
		died[i] = FALSE;
	}

	int index = 0;
	int enemy_range;

	while (1) {
		do {
			printf("적이 3명 있습니다. 몇 번 적을 공격할까요? >> ");
			scanf("%d", &index);

			if (died[index - 1]) {
				printf("해당 적은 이미 죽였습니다.");
			}
			else {
				break;
			}
		} while (1);

		enemy_range = shortest_path(&g, 0, index);

		printf("선택한 적은 %d만큼 떨어져 있습니다.", enemy_range);


		if (index == 1) {
			printf("1번 적을 물리쳤다.\n");
			died[0] = TRUE;
			g.weight[0][1] = 1;
			g.weight[1][0] = 1;
			g.weight[1][3] = 1;
			g.weight[3][1] = 1;
		}

		if (index == 2) {
			printf("2번 적을 물리쳤다.\n");
			died[1] = TRUE;
			g.weight[2][3] = 1;
			g.weight[2][0] = 1;
			g.weight[0][2] = 1;
			g.weight[3][2] = 1;
		}

		if (index == 3) {
			printf("3번 적을 물리쳤다.\n");
			died[2] = TRUE;
			g.weight[3][1] = 1;
			g.weight[3][2] = 1;
			g.weight[1][3] = 1;
			g.weight[2][3] = 1;
		}

		if (died[0]) {
			if (died[1]) {
				if (died[2]) {
					printf("모든적 물리침\n");
					Sleep(5000);
					break;
				}
			}
		}
	}
}

void En2_Room1() {
	GraphType g = { 3,
		{{0,2,INF},
		{2,0,2},
		{INF, 2, 0}}
	};

	int died[2];
	int i;
	for (i = 0; i < 2; i++) {
		died[i] = FALSE;
	}

	int index = 0;
	int enemy_range;

	while (1) {
		do {
			printf("적이 2명 있습니다. 몇 번 적을 공격할까요? >> ");
			scanf("%d", &index);

			if (died[index - 1]) {
				printf("해당 적은 이미 죽였습니다.");
			}
			else {
				break;
			}
		} while (1);

		enemy_range = shortest_path(&g, 0, index);

		printf("선택한 적은 %d만큼 떨어져 있습니다.", enemy_range);


		if (index == 1) {
			printf("1번 적을 물리쳤다.\n");
			died[0] = TRUE;
			g.weight[1][0] = 1;
			g.weight[1][2] = 1;
			g.weight[0][1] = 1;
			g.weight[2][1] = 1;
		}

		if (index == 2) {
			printf("2번 적을 물리쳤다.\n");
			died[1] = TRUE;
			g.weight[2][1] = 1;
			g.weight[1][2] = 1;
		}

		if (died[0]) {
			if (died[1]) {
				printf("모든적 물리침\n");
				Sleep(5000);
				break;
			}
		}
	}
}