#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <Windows.h>
#include "range.h"


int distance[MAX_VERTICES];/* �����������κ����� �ִܰ�� �Ÿ� */
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

	int distance[MAX_VERTICES];/* �����������κ����� �ִܰ�� �Ÿ� */
	int found[MAX_VERTICES];

	int i, u, w;
	for (i = 0; i < g->n; i++) /* �ʱ�ȭ */
	{
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE; /* ���� ���� �湮 ǥ�� */
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


void St1() {
	//1STAGE
	GraphType g = { 3,
		{{ 0, 2, INF },//���ΰ����� ��1���Դ� 2�� �Ÿ�, ��1���� ��2������ INF(4)
		{ 2, 0, 2 },
		{ INF, 2, 0 },
		} };

	int died[2];
	int i;
	for (i = 0; i < 2; i++) {
		died[i] = FALSE;
	}

	int index = 0;
	int enemy_range;

	while (1) {
		do {
			printf("���� 2�� �ֽ��ϴ�. �� �� ���� �����ұ��? >> ");
			scanf("%d", &index);

			if (died[index - 1]) {
				printf("�ش� ���� �̹� �׿����ϴ�.");
			}
			else {
				break;
			}
		} while (1);

		enemy_range = shortest_path(&g, 0, index);

		printf("������ ���� %d��ŭ ������ �ֽ��ϴ�.", enemy_range);


		if (index == 1) {
			printf("1�� ���� �����ƴ�.\n");
			died[0] = TRUE;
			g.weight[0][1] = 1;
			g.weight[1][0] = 1;
			g.weight[1][2] = 1;
			g.weight[2][1] = 1;
		}

		if (index == 2) {
			printf("2�� ���� �����ƴ�.\n");
			died[1] = TRUE;
			g.weight[1][2] = 1;
			g.weight[2][1] = 1;
		}

		

		if (died[0]) {
			if (died[1]) {
				printf("��� ���� �����ƴ�\n");
				Sleep(5000);
				break;
			}
		}
	}
}


void St2_1() {
	//2STAGE FIRST
	GraphType g = { 6,
		{{ 0, 2, 2, INF, INF, INF },
		{ 2, 0, INF, 2, INF, INF },
		{ 2, INF, 0, INF, 2, INF },
		{ INF, 2, INF, 0, INF, 2 },
		{ INF, INF, 2, INF, 0, INF },
		{ INF, INF, INF, INF, 2, 0 },
		} };

	int died[5];
	int i;
	for (i = 0; i < 5; i++) {
		died[i] = FALSE;
	}

	int index = 0;
	int enemy_range;

	while (1) {
		do {
			printf("���� 5�� �ֽ��ϴ�. �� �� ���� �����ұ��? >> ");
			scanf("%d", &index);

			if (died[index - 1]) {
				printf("�ش� ���� �̹� �׿����ϴ�.");
			}
			else {
				break;
			}
		} while (1);

		enemy_range = shortest_path(&g, 0, index);

		printf("������ ���� %d��ŭ ������ �ֽ��ϴ�.", enemy_range);


		if (index == 1) {
			printf("1�� ���� �����ƴ�.\n");
			died[0] = TRUE;
			g.weight[0][1] = 1;
			g.weight[1][0] = 1;
			g.weight[1][3] = 1;
			g.weight[3][1] = 1;
			
		}

		if (index == 2) {
			printf("2�� ���� �����ƴ�.\n");
			died[1] = TRUE;
			g.weight[0][2] = 1;
			g.weight[2][0] = 1;
			g.weight[2][4] = 1;
			g.weight[4][2] = 1;
		}

		if (index == 3) {
			printf("3�� ���� �����ƴ�.\n");
			died[2] = TRUE;
			g.weight[1][3] = 1;
			g.weight[3][1] = 1;

			g.weight[3][5] = 1;
			g.weight[5][3] = 1;
		}

		if (index == 4) {
			printf("4�� ���� �����ƴ�.\n");
			died[3] = TRUE;
			g.weight[2][4] = 1;
			g.weight[4][2] = 1;

		}

		if (index == 5) {
			printf("5�� ���� �����ƴ�.\n");
			died[4] = TRUE;
			g.weight[3][5] = 1;
			g.weight[5][3] = 1;
			
		}


		if (died[0]) {
			if (died[1]) {
				if (died[2]) {
					if (died[3]) {
						if (died[4]) {							
							printf("��� ���� �����ƴ�\n");
							Sleep(5000);
							break;					
						}
					}
				}
			}
		}
	}

}



void St2_2() {
	//2STAGE SECOND
	GraphType g = { 6,
		{{ 0, 2, 2, INF, INF, INF },
		{ 2, 0, INF, 2, 2, INF },
		{ 2, INF, 0, INF, INF, INF },
		{ INF, 2, INF, 0, INF, 2 },
		{ INF, 2, INF, INF, 0, 2 },
		{ INF, INF, INF, 2, 2, 0 },
		} };

	int died[5];
	int i;
	for (i = 0; i < 5; i++) {
		died[i] = FALSE;
	}

	int index = 0;
	int enemy_range;

	while (1) {
		do {
			printf("���� 5�� �ֽ��ϴ�. �� �� ���� �����ұ��? >> ");
			scanf("%d", &index);

			if (died[index - 1]) {
				printf("�ش� ���� �̹� �׿����ϴ�.");
			}
			else {
				break;
			}
		} while (1);

		enemy_range = shortest_path(&g, 0, index);

		printf("������ ���� %d��ŭ ������ �ֽ��ϴ�.", enemy_range);


		if (index == 1) {
			printf("1�� ���� �����ƴ�.\n");
			died[0] = TRUE;
			g.weight[0][1] = 1;
			g.weight[1][0] = 1;
			g.weight[1][3] = 1;
			g.weight[3][1] = 1;
			g.weight[1][4] = 1;
			g.weight[4][1] = 1;

		}

		if (index == 2) {
			printf("2�� ���� �����ƴ�.\n");
			died[1] = TRUE;
			g.weight[0][2] = 1;
			g.weight[2][0] = 1;
			
		}

		if (index == 3) {
			printf("3�� ���� �����ƴ�.\n");
			died[2] = TRUE;
			g.weight[1][3] = 1;
			g.weight[3][1] = 1;

			g.weight[3][5] = 1;
			g.weight[5][3] = 1;
		}

		if (index == 4) {
			printf("4�� ���� �����ƴ�.\n");
			died[3] = TRUE;
			g.weight[1][4] = 1;
			g.weight[4][1] = 1;
			g.weight[4][5] = 1;
			g.weight[5][4] = 1;

		}

		if (index == 5) {
			printf("5�� ���� �����ƴ�.\n");
			died[4] = TRUE;
			g.weight[3][5] = 1;
			g.weight[5][3] = 1;
			g.weight[4][5] = 1;
			g.weight[5][4] = 1;
		}


		if (died[0]) {
			if (died[1]) {
				if (died[2]) {
					if (died[3]) {
						if (died[4]) {
							printf("��� ���� �����ƴ�\n");
							Sleep(5000);
							break;
						}
					}
				}
			}
		}
	}

}







void St3_1() {
	//3STAGE FIRST
	GraphType g = { 7,
		{{ 0, 2, 2, INF, INF, INF, INF },
		{ 2, 0, INF, 2, 2, INF, INF },
		{ 2, INF, 0, INF, INF, INF, INF },
		{ INF, 2, INF, 0, 2, 2, INF },
		{ INF, 2, INF, INF, 0, INF, INF },
		{ INF, INF, INF, 2, INF, 0, 2 },
		{ INF, INF, INF, INF, INF, 2, 0 },
		} };

	int died[6];
	int i;
	for (i = 0; i < 6; i++) {
		died[i] = FALSE;
	}

	int index = 0;
	int enemy_range;

	while (1) {
		do {
			printf("���� 6�� �ֽ��ϴ�. �� �� ���� �����ұ��? >> ");
			scanf("%d", &index);

			if (died[index - 1]) {
				printf("�ش� ���� �̹� �׿����ϴ�.");
			}
			else {
				break;
			}
		} while (1);

		enemy_range = shortest_path(&g, 0, index);

		printf("������ ���� %d��ŭ ������ �ֽ��ϴ�.", enemy_range);


		if (index == 1) {
			printf("1�� ���� �����ƴ�.\n");
			died[0] = TRUE;
			g.weight[0][1] = 1;
			g.weight[1][0] = 1;
			g.weight[1][3] = 1;
			g.weight[3][1] = 1;
			g.weight[1][4] = 1;
			g.weight[4][1] = 1;	
		}

		if (index == 2) {
			printf("2�� ���� �����ƴ�.\n");
			died[1] = TRUE;
			g.weight[0][2] = 1;
			g.weight[2][0] = 1;
		}

		if (index == 3) {
			printf("3�� ���� �����ƴ�.\n");
			died[2] = TRUE;
			g.weight[1][3] = 1;
			g.weight[3][1] = 1;
			
			g.weight[3][5] = 1;
			g.weight[5][3] = 1;
		}

		if (index == 4) {
			printf("4�� ���� �����ƴ�.\n");
			died[3] = TRUE;
			g.weight[1][4] = 1;
			g.weight[4][1] = 1;
			
		}

		if (index == 5) {
			printf("5�� ���� �����ƴ�.\n");
			died[4] = TRUE;
			g.weight[3][5] = 1;
			g.weight[5][3] = 1;
			g.weight[5][6] = 1;
			g.weight[6][5] = 1;
		}

		if (index == 6){
			printf("6�� ���� �����ƴ�.\n");
			died[5] = TRUE;
			g.weight[6][5] = 1;
			g.weight[5][6] = 1;
		}

		if (died[0]) {
			if (died[1]) {
				if (died[2]) {
					if (died[3]) {
						if (died[4]) {
							if (died[5]) {
								printf("��� ���� �����ƴ�\n");
								Sleep(5000);
								break;
							}
						}
					}
				}
			}
		}
	}

}


void St3_2() {
	//3STAGE SECOND
	GraphType g = { 7,
		{{ 0, 2, INF, INF, INF, INF, INF },
		{ 2, 0, 2, INF, INF, INF, INF },
		{ INF, 2, 0, 2, 2, INF, INF },
		{ INF, INF, 2, 0, INF, 2, 2 },
		{ INF, INF, 2, INF, 0, INF, INF },
		{ INF, INF, INF, 2, INF, 0, INF },
		{ INF, INF, INF, 2, INF, INF, 0 },
		} };

	int died[6];
	int i;
	for (i = 0; i < 6; i++) {
		died[i] = FALSE;
	}

	int index = 0;
	int enemy_range;

	while (1) {
		do {
			printf("���� 6�� �ֽ��ϴ�. �� �� ���� �����ұ��? >> ");
			scanf("%d", &index);

			if (died[index - 1]) {
				printf("�ش� ���� �̹� �׿����ϴ�.");
			}
			else {
				break;
			}
		} while (1);

		enemy_range = shortest_path(&g, 0, index);

		printf("������ ���� %d��ŭ ������ �ֽ��ϴ�.", enemy_range);


		if (index == 1) {
			printf("1�� ���� �����ƴ�.\n");
			died[0] = TRUE;
			g.weight[0][1] = 1;
			g.weight[1][0] = 1;
			
		}

		if (index == 2) {
			printf("2�� ���� �����ƴ�.\n");
			died[1] = TRUE;
			g.weight[1][2] = 1;
			g.weight[2][1] = 1;
			g.weight[2][3] = 1;
			g.weight[3][2] = 1;
			g.weight[2][4] = 1;
			g.weight[4][2] = 1;
		}

		if (index == 3) {
			printf("3�� ���� �����ƴ�.\n");
			died[2] = TRUE;
			g.weight[2][3] = 1;
			g.weight[3][2] = 1;
			g.weight[3][5] = 1;
			g.weight[5][3] = 1;
			g.weight[3][6] = 1;
			g.weight[6][3] = 1;
		}

		if (index == 4) {
			printf("4�� ���� �����ƴ�.\n");
			died[3] = TRUE;
			g.weight[2][4] = 1;
			g.weight[4][2] = 1;

		}

		if (index == 5) {
			printf("5�� ���� �����ƴ�.\n");
			died[4] = TRUE;
			g.weight[3][5] = 1;
			g.weight[5][3] = 1;
			
		}

		if (index == 6) {
			printf("6�� ���� �����ƴ�.\n");
			died[5] = TRUE;
			g.weight[6][3] = 1;
			g.weight[3][6] = 1;
		}

		if (died[0]) {
			if (died[1]) {
				if (died[2]) {
					if (died[3]) {
						if (died[4]) {
							if (died[5]) {
								printf("��� ���� �����ƴ�\n");
								Sleep(5000);
								break;
							}
						}
					}
				}
			}
		}
	}

}



void St3_3() {
	//3STAGE THIRD
	GraphType g = { 7,
		{{ 0, 2, INF, INF, INF, INF, INF },
		{ 2, 0, 2, 2, INF, INF, INF },
		{ INF, 2, 0, INF, 2, 2, INF },
		{ INF, 2, INF, 0, INF, INF, INF },
		{ INF, INF, 2, INF, 0, INF, 2 },
		{ INF, INF, 2, INF, INF, 0, 2 },
		{ INF, INF, INF, INF, 2, 2, 0 },
		} };

	int died[6];
	int i;
	for (i = 0; i < 6; i++) {
		died[i] = FALSE;
	}

	int index = 0;
	int enemy_range;

	while (1) {
		do {
			printf("���� 6�� �ֽ��ϴ�. �� �� ���� �����ұ��? >> ");
			scanf("%d", &index);

			if (died[index - 1]) {
				printf("�ش� ���� �̹� �׿����ϴ�.");
			}
			else {
				break;
			}
		} while (1);

		enemy_range = shortest_path(&g, 0, index);

		printf("������ ���� %d��ŭ ������ �ֽ��ϴ�.", enemy_range);


		if (index == 1) {
			printf("1�� ���� �����ƴ�.\n");
			died[0] = TRUE;
			g.weight[0][1] = 1;
			g.weight[1][0] = 1;
			g.weight[1][2] = 1;
			g.weight[2][1] = 1;
			g.weight[1][3] = 1;
			g.weight[3][1] = 1;

		}

		if (index == 2) {
			printf("2�� ���� �����ƴ�.\n");
			died[1] = TRUE;
			g.weight[1][2] = 1;
			g.weight[2][1] = 1;			
			g.weight[2][4] = 1;
			g.weight[4][2] = 1;
			g.weight[2][5] = 1;
			g.weight[5][2] = 1;
		}

		if (index == 3) {
			printf("3�� ���� �����ƴ�.\n");
			died[2] = TRUE;
			g.weight[1][3] = 1;
			g.weight[3][1] = 1;
			
		}

		if (index == 4) {
			printf("4�� ���� �����ƴ�.\n");
			died[3] = TRUE;
			g.weight[2][4] = 1;
			g.weight[4][2] = 1;
			g.weight[4][6] = 1;
			g.weight[6][4] = 1;

		}

		if (index == 5) {
			printf("5�� ���� �����ƴ�.\n");
			died[4] = TRUE;
			g.weight[2][5] = 1;
			g.weight[5][2] = 1;
			g.weight[5][6] = 1;
			g.weight[6][5] = 1;

		}

		if (index == 6) {
			printf("6�� ���� �����ƴ�.\n");
			died[5] = TRUE;
			g.weight[6][4] = 1;
			g.weight[4][6] = 1;
			g.weight[6][5] = 1;
			g.weight[5][6] = 1;
		}

		if (died[0]) {
			if (died[1]) {
				if (died[2]) {
					if (died[3]) {
						if (died[4]) {
							if (died[5]) {
								printf("��� ���� �����ƴ�\n");
								Sleep(5000);
								break;
							}
						}
					}
				}
			}
		}
	}

}

void St4_1() {
	//4STAGE FIRST
	GraphType g = { 8,
		{{ 0, 2, INF, INF, INF, INF, INF, INF },
		{ 2, 0, 2, 2, 2, INF, INF, INF },
		{ INF, 2, 0, INF, INF, 2, INF, INF },
		{ INF, 2, INF, 0, INF, INF, INF, INF },
		{ INF, 2, INF, INF, 0, 2, INF, INF },
		{ INF, INF, 2, INF, 2, 0, 2, 2 },
		{ INF, INF, INF, INF, INF, 2, 0, INF },
		{ INF, INF, INF, INF, INF, 2, INF, 0 },
		} };

	int died[7];
	int i;
	for (i = 0; i < 7; i++) {
		died[i] = FALSE;
	}

	int index = 0;
	int enemy_range;

	while (1) {
		do {
			printf("���� 7�� �ֽ��ϴ�. �� �� ���� �����ұ��? >> ");
			scanf("%d", &index);

			if (died[index - 1]) {
				printf("�ش� ���� �̹� �׿����ϴ�.");
			}
			else {
				break;
			}
		} while (1);

		enemy_range = shortest_path(&g, 0, index);

		printf("������ ���� %d��ŭ ������ �ֽ��ϴ�.", enemy_range);


		if (index == 1) {
			printf("1�� ���� �����ƴ�.\n");
			died[0] = TRUE;
			g.weight[0][1] = 1;
			g.weight[1][0] = 1;
			g.weight[1][2] = 1;
			g.weight[2][1] = 1;
			g.weight[1][3] = 1;
			g.weight[3][1] = 1;
			g.weight[1][4] = 1;
			g.weight[4][1] = 1;

		}

		if (index == 2) {
			printf("2�� ���� �����ƴ�.\n");
			died[1] = TRUE;
			g.weight[1][2] = 1;
			g.weight[2][1] = 1;
			g.weight[2][5] = 1;
			g.weight[5][2] = 1;
			
		}

		if (index == 3) {
			printf("3�� ���� �����ƴ�.\n");
			died[2] = TRUE;
			g.weight[1][3] = 1;
			g.weight[3][1] = 1;

		}

		if (index == 4) {
			printf("4�� ���� �����ƴ�.\n");
			died[3] = TRUE;
			g.weight[1][4] = 1;
			g.weight[4][1] = 1;
			g.weight[4][5] = 1;
			g.weight[5][4] = 1;

		}

		if (index == 5) {
			printf("5�� ���� �����ƴ�.\n");
			died[4] = TRUE;
			g.weight[2][5] = 1;
			g.weight[5][2] = 1;
			g.weight[5][6] = 1;
			g.weight[6][5] = 1;
			g.weight[5][4] = 1;
			g.weight[4][5] = 1;
			g.weight[5][7] = 1;
			g.weight[7][5] = 1;

		}

		if (index == 6) {
			printf("6�� ���� �����ƴ�.\n");
			died[5] = TRUE;
			
			g.weight[6][5] = 1;
			g.weight[5][6] = 1;
		}

		if (index == 7) {
			printf("7�� ���� �����ƴ�.\n");
			died[6] = TRUE;
			g.weight[7][5] = 1;
			g.weight[5][7] = 1;
		}

		if (died[0]) {
			if (died[1]) {
				if (died[2]) {
					if (died[3]) {
						if (died[4]) {
							if (died[5]) {
								if (died[6]) {
									printf("��� ���� �����ƴ�\n");
									Sleep(5000);
									break;
								}
							}
						}
					}
				}
			}
		}
	}

}

























void St4_3() {
	//4STAGE THIRD
	GraphType g = { 8,
		{{ 0, 2, INF, INF, INF, INF, INF, INF },
		{ 2, 0, 2, 2, 2, 2, INF, INF },
		{ INF, 2, 0, INF, INF, INF, 2, INF },
		{ INF, 2, INF, 0, INF, INF, INF, INF },
		{ INF, 2, INF, INF, 0, INF, INF, INF },
		{ INF, 2, INF, INF, INF, 0, 2, INF },
		{ INF, INF, 2, INF, INF, 2, 0, 2 },
		{ INF, INF, INF, INF, INF, INF, 2, 0 },
		} };

	int died[7];
	int i;
	for (i = 0; i < 7; i++) {
		died[i] = FALSE;
	}

	int index = 0;
	int enemy_range;

	while (1) {
		do {
			printf("���� 7�� �ֽ��ϴ�. �� �� ���� �����ұ��? >> ");
			scanf("%d", &index);

			if (died[index - 1]) {
				printf("�ش� ���� �̹� �׿����ϴ�.");
			}
			else {
				break;
			}
		} while (1);

		enemy_range = shortest_path(&g, 0, index);

		printf("������ ���� %d��ŭ ������ �ֽ��ϴ�.", enemy_range);


		if (index == 1) {
			printf("1�� ���� �����ƴ�.\n");
			died[0] = TRUE;
			g.weight[0][1] = 1;
			g.weight[1][0] = 1;
			g.weight[1][2] = 1;
			g.weight[2][1] = 1;
			g.weight[1][3] = 1;
			g.weight[3][1] = 1;
			g.weight[1][4] = 1;
			g.weight[4][1] = 1;
			g.weight[1][5] = 1;
			g.weight[5][1] = 1;

		}

		if (index == 2) {
			printf("2�� ���� �����ƴ�.\n");
			died[1] = TRUE;
			g.weight[1][2] = 1;
			g.weight[2][1] = 1;
			g.weight[2][6] = 1;
			g.weight[6][2] = 1;

		}

		if (index == 3) {
			printf("3�� ���� �����ƴ�.\n");
			died[2] = TRUE;
			g.weight[1][3] = 1;
			g.weight[3][1] = 1;

		}

		if (index == 4) {
			printf("4�� ���� �����ƴ�.\n");
			died[3] = TRUE;
			g.weight[1][4] = 1;
			g.weight[4][1] = 1;
			

		}

		if (index == 5) {
			printf("5�� ���� �����ƴ�.\n");
			died[4] = TRUE;
			g.weight[1][5] = 1;
			g.weight[5][1] = 1;
			g.weight[5][6] = 1;
			g.weight[6][5] = 1;
			

		}

		if (index == 6) {
			printf("6�� ���� �����ƴ�.\n");
			died[5] = TRUE;
			g.weight[2][6] = 1;
			g.weight[6][2] = 1;
			g.weight[6][5] = 1;
			g.weight[5][6] = 1;
			g.weight[6][7] = 1;
			g.weight[7][6] = 1;
		}

		if (index == 7) {
			printf("7�� ���� �����ƴ�.\n");
			died[6] = TRUE;
			g.weight[7][6] = 1;
			g.weight[6][7] = 1;
		}

		if (died[0]) {
			if (died[1]) {
				if (died[2]) {
					if (died[3]) {
						if (died[4]) {
							if (died[5]) {
								if (died[6]) {
									printf("��� ���� �����ƴ�\n");
									Sleep(5000);
									break;
								}
							}
						}
					}
				}
			}
		}
	}

}


void Boss() {
	//Boss_STAGE
	GraphType g = { 7,
		{{ 0, 2, INF, INF, INF, INF, INF },
		{ 2, 0, 2, INF, INF, INF, INF },
		{ INF, 2, 0, 2, INF, INF, INF },
		{ INF, INF, 2, 0, 2, 2, INF },
		{ INF, INF, INF, 2, 0, INF, 2 },
		{ INF, INF, INF, 2, INF, 0, 2 },
		{ INF, INF, INF, INF, 2, 2, 0 },
		} };

	int died[6];
	int i;
	for (i = 0; i < 6; i++) {
		died[i] = FALSE;
	}

	int index = 0;
	int enemy_range;

	while (1) {
		do {
			printf("���� 6�� �ֽ��ϴ�. �� �� ���� �����ұ��? >> ");
			scanf("%d", &index);

			if (died[index - 1]) {
				printf("�ش� ���� �̹� �׿����ϴ�.");
			}
			else {
				break;
			}
		} while (1);

		enemy_range = shortest_path(&g, 0, index);

		printf("������ ���� %d��ŭ ������ �ֽ��ϴ�.", enemy_range);


		if (index == 1) {
			printf("1�� ���� �����ƴ�.\n");
			died[0] = TRUE;
			g.weight[0][1] = 1;
			g.weight[1][0] = 1;
			g.weight[1][2] = 1;
			g.weight[2][1] = 1;
			

		}

		if (index == 2) {
			printf("2�� ���� �����ƴ�.\n");
			died[1] = TRUE;
			g.weight[1][2] = 1;
			g.weight[2][1] = 1;
			g.weight[2][3] = 1;
			g.weight[3][2] = 1;
			
		}

		if (index == 3) {
			printf("3�� ���� �����ƴ�.\n");
			died[2] = TRUE;
			g.weight[2][3] = 1;
			g.weight[3][2] = 1;
			g.weight[3][4] = 1;
			g.weight[4][3] = 1;
			g.weight[3][5] = 1;
			g.weight[5][3] = 1;
		}

		if (index == 4) {
			printf("4�� ���� �����ƴ�.\n");
			died[3] = TRUE;
			g.weight[3][4] = 1;
			g.weight[4][3] = 1;
			g.weight[4][6] = 1;
			g.weight[6][4] = 1;

		}

		if (index == 5) {
			printf("5�� ���� �����ƴ�.\n");
			died[4] = TRUE;
			g.weight[3][5] = 1;
			g.weight[5][3] = 1;
			g.weight[5][6] = 1;
			g.weight[6][5] = 1;

		}

		if (index == 6) {
			printf("6�� ���� �����ƴ�.\n");
			died[5] = TRUE;
			g.weight[6][4] = 1;
			g.weight[4][6] = 1;
			g.weight[6][5] = 1;
			g.weight[5][6] = 1;
		}

		if (died[0]) {
			if (died[1]) {
				if (died[2]) {
					if (died[3]) {
						if (died[4]) {
							if (died[5]) {
								printf("��� ���� �����ƴ�\n");
								Sleep(5000);
								break;
							}
						}
					}
				}
			}
		}
	}

}

