#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <Windows.h>
#include "range.h"
#include "weapon.h"


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


void St1(int* p_hp) {
	//1STAGE
	int w_range;
	int w_damage;
	int w_index;
	GraphType g = { 3,
		{{ 0, 2, INF },//���ΰ����� ��1���Դ� 2�� �Ÿ�, ��1���� ��2������ INF(4)
		{ 2, 0, 2 },
		{ INF, 2, 0 },
		} };

	Em em[2];
	for (int i = 0; i < 2; i++) {
		em[i].index = i+1;
		em[i].HP = 20;
		em[i].damage = 1;
	};

	add_random_weapons();


	int died[2];
	int i;
	for (i = 0; i < 2; i++) {
		died[i] = FALSE;
	}

	int index = 0;
	int enemy_range;

	while (1) {
		do {
			system("cls");

			printf("1��° ��\n");
			printf("�÷��̾� ü�� : %d\n\n", *p_hp);

			//��ǥ��
			for (int i = 0; i < 2; i++) {
				if (!died[i]) {
					printf("[%d] ü��: %d,�Ÿ�: %d\n", em[i].index, em[i].HP, shortest_path(&g, 0, em[i].index));
				}
			}

			print_weapons();
			printf("���� ����(1 ~ 5) >> ");
			scanf("%d", &w_index);

			w_range = get_weapon_range(selectedWeapons[w_index - 1]);
			w_damage = get_weapon_damage(selectedWeapons[w_index - 1]);

			printf("������ �� ���� >> ");
			scanf("%d", &index);

			enemy_range = shortest_path(&g, 0, index);

			if (died[index - 1]) {
				printf("�ش� ���� �̹� �׿����ϴ�.\n");
				Sleep(2000);
			}
			else {
				if (enemy_range > w_range) {
					printf("���� �����Ÿ� �ۿ� �ִ�\n");
					Sleep(2000);
				}
				else {
					use_weapon(w_index-1);
					break;
				}
			}
		} while (1);

		em[index - 1].HP -= w_damage;


		if (em[0].HP <= 0 && !died[0]) {
			printf("1�� ���� �����ƴ�.\n");
			died[0] = TRUE;
			g.weight[0][1] = 1;
			g.weight[1][0] = 1;
			g.weight[1][2] = 1;
			g.weight[2][1] = 1;
		}

		if (em[1].HP <= 0 && !died[1]) {
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

		printf("���� �����Ѵ�!\n");
		//���� �� ������ �ֱ�
		for (int i = 0; i < 2; i++) {
			if (!died[i]) {
				*p_hp -= em[i].damage;
			}
		}
		Sleep(2000);
	}
}

void St2_1(int* p_hp) {
	//2STAGE FIRST
	int w_range;
	int w_damage;
	int w_index;
	GraphType g = { 6,
		{{ 0, 2, 2, INF, INF, INF },
		{ 2, 0, INF, 2, INF, INF },
		{ 2, INF, 0, INF, 2, INF },
		{ INF, 2, INF, 0, INF, 2 },
		{ INF, INF, 2, INF, 0, INF },
		{ INF, INF, INF, INF, 2, 0 },
		} };

	Em em[5];
	for (int i = 0; i < 5; i++) {
		em[i].index = i + 1;
		em[i].HP = 20;
		em[i].damage = 1;
	};

	int died[5];
	int i;
	for (i = 0; i < 5; i++) {
		died[i] = FALSE;
	}

	int index = 0;
	int enemy_range;

	for (int i = 0; i < 5; i++) {
		system("cls");
		printf("������ ����� ���� ����� ���� 5���� ����\n");
		for (int i = 0; i < 5; i++) {
			if (!died[i]) {
				printf("[%d] ü��: %d,�Ÿ�: %d\n", em[i].index, em[i].HP, shortest_path(&g, 0, em[i].index));
			}
		}
		print_deck();
		printf("����� ���� ��ȣ >> ");
		scanf("%d", &w_index);
		select_weapon_in_deck(w_index);
	}


	while (1) {
		do {
			system("cls");

			printf("2��° ��\n");
			printf("�÷��̾� ü�� : %d\n\n", *p_hp);

			//��ǥ��
			for (int i = 0; i < 5; i++) {
				if (!died[i]) {
					printf("[%d] ü��: %d,�Ÿ�: %d\n", em[i].index, em[i].HP, shortest_path(&g, 0, em[i].index));
				}
			}

			print_weapons();
			printf("���� ����(1 ~ 5) >> ");
			scanf("%d", &w_index);

			w_range = get_weapon_range(selectedWeapons[w_index - 1]);
			w_damage = get_weapon_damage(selectedWeapons[w_index - 1]);

			printf("������ �� ���� >> ");
			scanf("%d", &index);

			enemy_range = shortest_path(&g, 0, index);

			if (died[index - 1]) {
				printf("�ش� ���� �̹� �׿����ϴ�.\n");
				Sleep(2000);
			}
			else {
				if (enemy_range > w_range) {
					printf("���� �����Ÿ� �ۿ� �ִ�\n");
					Sleep(2000);
				}
				else {
					use_weapon(w_index-1);
					break;
				}
			}
		} while (1);

		em[index - 1].HP -= w_damage;

		if (em[0].HP <= 0 && !died[0]) {
			printf("1�� ���� �����ƴ�.\n");
			died[0] = TRUE;
			g.weight[0][1] = 1;
			g.weight[1][0] = 1;
			g.weight[1][3] = 1;
			g.weight[3][1] = 1;
			
		}

		if (em[1].HP <= 0 && !died[1]) {
			printf("2�� ���� �����ƴ�.\n");
			died[1] = TRUE;
			g.weight[0][2] = 1;
			g.weight[2][0] = 1;
			g.weight[2][4] = 1;
			g.weight[4][2] = 1;
		}

		if (em[2].HP <= 0 && !died[2]) {
			printf("3�� ���� �����ƴ�.\n");
			died[2] = TRUE;
			g.weight[1][3] = 1;
			g.weight[3][1] = 1;

			g.weight[3][5] = 1;
			g.weight[5][3] = 1;
		}

		if (em[3].HP <= 0 && !died[3]) {
			printf("4�� ���� �����ƴ�.\n");
			died[3] = TRUE;
			g.weight[2][4] = 1;
			g.weight[4][2] = 1;

		}

		if (em[4].HP <= 0 && !died[4]) {
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

		printf("���� �����Ѵ�!\n");
		//���� �� ������ �ֱ�
		for (int i = 0; i < 2; i++) {
			if (!died[i]) {
				*p_hp -= em[i].damage;
			}
		}
		Sleep(2000);
	}

}

void St2_2(int* p_hp) {
	//2STAGE SECOND
	int w_range;
	int w_damage;
	int w_index;

	GraphType g = { 6,
		{{ 0, 2, 2, INF, INF, INF },
		{ 2, 0, INF, 2, 2, INF },
		{ 2, INF, 0, INF, INF, INF },
		{ INF, 2, INF, 0, INF, 2 },
		{ INF, 2, INF, INF, 0, 2 },
		{ INF, INF, INF, 2, 2, 0 },
		} };

	Em em[5];
	for (int i = 0; i < 5; i++) {
		em[i].index = i + 1;
		em[i].HP = 20;
		em[i].damage = 1;
	};

	int died[5];
	int i;
	for (i = 0; i < 5; i++) {
		died[i] = FALSE;
	}

	int index = 0;
	int enemy_range;

	for (int i = 0; i < 5; i++) {
		system("cls");
		printf("������ ����� ���� ����� ���� 5���� ����\n");
		for (int i = 0; i < 5; i++) {
			if (!died[i]) {
				printf("[%d] ü��: %d,�Ÿ�: %d\n", em[i].index, em[i].HP, shortest_path(&g, 0, em[i].index));
			}
		}
		print_deck();
		printf("����� ���� ��ȣ >> ");
		scanf("%d", &w_index);
		select_weapon_in_deck(w_index);
	}


	while (1) {
		do {
			system("cls");

			printf("2��° ��\n");
			printf("�÷��̾� ü�� : %d\n\n", *p_hp);

			//��ǥ��
			for (int i = 0; i < 5; i++) {
				if (!died[i]) {
					printf("[%d] ü��: %d,�Ÿ�: %d\n", em[i].index, em[i].HP, shortest_path(&g, 0, em[i].index));
				}
			}

			print_weapons();
			printf("���� ����(1 ~ 5) >> ");
			scanf("%d", &w_index);

			w_range = get_weapon_range(selectedWeapons[w_index - 1]);
			w_damage = get_weapon_damage(selectedWeapons[w_index - 1]);

			printf("������ �� ���� >> ");
			scanf("%d", &index);

			enemy_range = shortest_path(&g, 0, index);

			if (died[index - 1]) {
				printf("�ش� ���� �̹� �׿����ϴ�.\n");
				Sleep(2000);
			}
			else {
				if (enemy_range > w_range) {
					printf("���� �����Ÿ� �ۿ� �ִ�\n");
					Sleep(2000);
				}
				else {
					use_weapon(w_index-1);
					break;
				}
			}
		} while (1);

		em[index - 1].HP -= w_damage;

		if (em[0].HP <= 0 && !died[0]) {
			printf("1�� ���� �����ƴ�.\n");
			died[0] = TRUE;
			g.weight[0][1] = 1;
			g.weight[1][0] = 1;
			g.weight[1][3] = 1;
			g.weight[3][1] = 1;
			g.weight[1][4] = 1;
			g.weight[4][1] = 1;

		}

		if (em[1].HP <= 0 && !died[1]) {
			printf("2�� ���� �����ƴ�.\n");
			died[1] = TRUE;
			g.weight[0][2] = 1;
			g.weight[2][0] = 1;
			
		}

		if (em[2].HP <= 0 && !died[2]) {
			printf("3�� ���� �����ƴ�.\n");
			died[2] = TRUE;
			g.weight[1][3] = 1;
			g.weight[3][1] = 1;

			g.weight[3][5] = 1;
			g.weight[5][3] = 1;
		}

		if (em[3].HP <= 0 && !died[3]) {
			printf("4�� ���� �����ƴ�.\n");
			died[3] = TRUE;
			g.weight[1][4] = 1;
			g.weight[4][1] = 1;
			g.weight[4][5] = 1;
			g.weight[5][4] = 1;

		}

		if (em[4].HP <= 0 && !died[4]) {
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

		printf("���� �����Ѵ�!\n");
		//���� �� ������ �ֱ�
		for (int i = 0; i < 2; i++) {
			if (!died[i]) {
				*p_hp -= em[i].damage;
			}
		}
		Sleep(2000);
	}

}

void St3_1(int* p_hp) {
	//3STAGE FIRST
	int w_range;
	int w_damage;
	int w_index;

	GraphType g = { 7,
		{{ 0, 2, 2, INF, INF, INF, INF },
		{ 2, 0, INF, 2, 2, INF, INF },
		{ 2, INF, 0, INF, INF, INF, INF },
		{ INF, 2, INF, 0, 2, 2, INF },
		{ INF, 2, INF, INF, 0, INF, INF },
		{ INF, INF, INF, 2, INF, 0, 2 },
		{ INF, INF, INF, INF, INF, 2, 0 },
		} };

	Em em[6];
	for (int i = 0; i < 6; i++) {
		em[i].index = i + 1;
		em[i].HP = 20;
		em[i].damage = 1;
	};

	int died[6];
	int i;
	for (i = 0; i < 6; i++) {
		died[i] = FALSE;
	}

	int index = 0;
	int enemy_range;

	for (int i = 0; i < 5; i++) {
		system("cls");
		printf("������ ����� ���� ����� ���� 5���� ����\n");
		for (int i = 0; i < 5; i++) {
			if (!died[i]) {
				printf("[%d] ü��: %d,�Ÿ�: %d\n", em[i].index, em[i].HP, shortest_path(&g, 0, em[i].index));
			}
		}
		print_deck();
		printf("����� ���� ��ȣ >> ");
		scanf("%d", &w_index);
		select_weapon_in_deck(w_index);
	}


	while (1) {
		do {
			system("cls");

			printf("3��° ��\n");
			printf("�÷��̾� ü�� : %d\n\n", *p_hp);

			//��ǥ��
			for (int i = 0; i < 6; i++) {
				if (!died[i]) {
					printf("[%d] ü��: %d,�Ÿ�: %d\n", em[i].index, em[i].HP, shortest_path(&g, 0, em[i].index));
				}
			}

			print_weapons();
			printf("���� ����(1 ~ 5) >> ");
			scanf("%d", &w_index);

			w_range = get_weapon_range(selectedWeapons[w_index - 1]);
			w_damage = get_weapon_damage(selectedWeapons[w_index - 1]);

			printf("������ �� ���� >> ");
			scanf("%d", &index);

			enemy_range = shortest_path(&g, 0, index);

			if (died[index - 1]) {
				printf("�ش� ���� �̹� �׿����ϴ�.\n");
				Sleep(2000);
			}
			else {
				if (enemy_range > w_range) {
					printf("���� �����Ÿ� �ۿ� �ִ�\n");
					Sleep(2000);
				}
				else {
					use_weapon(w_index - 1);
					break;
				}
			}
		} while (1);

		em[index - 1].HP -= w_damage;


		if (em[0].HP <= 0 && !died[0]) {
			printf("1�� ���� �����ƴ�.\n");
			died[0] = TRUE;
			g.weight[0][1] = 1;
			g.weight[1][0] = 1;
			g.weight[1][3] = 1;
			g.weight[3][1] = 1;
			g.weight[1][4] = 1;
			g.weight[4][1] = 1;	
		}

		if (em[1].HP <= 0 && !died[1]) {
			printf("2�� ���� �����ƴ�.\n");
			died[1] = TRUE;
			g.weight[0][2] = 1;
			g.weight[2][0] = 1;
		}

		if (em[2].HP <= 0 && !died[2]) {
			printf("3�� ���� �����ƴ�.\n");
			died[2] = TRUE;
			g.weight[1][3] = 1;
			g.weight[3][1] = 1;
			
			g.weight[3][5] = 1;
			g.weight[5][3] = 1;
		}

		if (em[3].HP <= 0 && !died[3]) {
			printf("4�� ���� �����ƴ�.\n");
			died[3] = TRUE;
			g.weight[1][4] = 1;
			g.weight[4][1] = 1;
			
		}

		if (em[4].HP <= 0 && !died[4]) {
			printf("5�� ���� �����ƴ�.\n");
			died[4] = TRUE;
			g.weight[3][5] = 1;
			g.weight[5][3] = 1;
			g.weight[5][6] = 1;
			g.weight[6][5] = 1;
		}

		if (em[5].HP <= 0 && !died[5]){
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
		printf("���� �����Ѵ�!\n");
		//���� �� ������ �ֱ�
		for (int i = 0; i < 2; i++) {
			if (!died[i]) {
				*p_hp -= em[i].damage;
			}
		}
		Sleep(2000);
	}

}

void St3_2(int* p_hp) {
	//3STAGE SECOND
	int w_range;
	int w_damage;
	int w_index;
	GraphType g = { 7,
		{{ 0, 2, INF, INF, INF, INF, INF },
		{ 2, 0, 2, INF, INF, INF, INF },
		{ INF, 2, 0, 2, 2, INF, INF },
		{ INF, INF, 2, 0, INF, 2, 2 },
		{ INF, INF, 2, INF, 0, INF, INF },
		{ INF, INF, INF, 2, INF, 0, INF },
		{ INF, INF, INF, 2, INF, INF, 0 },
		} };
	Em em[6];
	for (int i = 0; i < 6; i++) {
		em[i].index = i + 1;
		em[i].HP = 20;
		em[i].damage = 1;
	};

	int died[6];
	int i;
	for (i = 0; i < 6; i++) {
		died[i] = FALSE;
	}

	int index = 0;
	int enemy_range;

	for (int i = 0; i < 5; i++) {
		system("cls");
		printf("������ ����� ���� ����� ���� 5���� ����\n");
		for (int i = 0; i < 5; i++) {
			if (!died[i]) {
				printf("[%d] ü��: %d,�Ÿ�: %d\n", em[i].index, em[i].HP, shortest_path(&g, 0, em[i].index));
			}
		}
		print_deck();
		printf("����� ���� ��ȣ >> ");
		scanf("%d", &w_index);
		select_weapon_in_deck(w_index);
	}

	while (1) {
		do {
			system("cls");

			printf("3��° ��\n");
			printf("�÷��̾� ü�� : %d\n\n", *p_hp);

			//��ǥ��
			for (int i = 0; i < 6; i++) {
				if (!died[i]) {
					printf("[%d] ü��: %d,�Ÿ�: %d\n", em[i].index, em[i].HP, shortest_path(&g, 0, em[i].index));
				}
			}

			print_weapons();
			printf("���� ����(1 ~ 5) >> ");
			scanf("%d", &w_index);

			w_range = get_weapon_range(selectedWeapons[w_index - 1]);
			w_damage = get_weapon_damage(selectedWeapons[w_index - 1]);

			printf("������ �� ���� >> ");
			scanf("%d", &index);

			enemy_range = shortest_path(&g, 0, index);

			if (died[index - 1]) {
				printf("�ش� ���� �̹� �׿����ϴ�.\n");
				Sleep(2000);
			}
			else {
				if (enemy_range > w_range) {
					printf("���� �����Ÿ� �ۿ� �ִ�\n");
					Sleep(2000);
				}
				else {
					use_weapon(w_index - 1);
					break;
				}
			}
		} while (1);

		em[index - 1].HP -= w_damage;


		if (em[0].HP <= 0 && !died[0]) {
			printf("1�� ���� �����ƴ�.\n");
			died[0] = TRUE;
			g.weight[0][1] = 1;
			g.weight[1][0] = 1;
			
		}

		if (em[1].HP <= 0 && !died[1]) {
			printf("2�� ���� �����ƴ�.\n");
			died[1] = TRUE;
			g.weight[1][2] = 1;
			g.weight[2][1] = 1;
			g.weight[2][3] = 1;
			g.weight[3][2] = 1;
			g.weight[2][4] = 1;
			g.weight[4][2] = 1;
		}

		if (em[2].HP <= 0 && !died[2]) {
			printf("3�� ���� �����ƴ�.\n");
			died[2] = TRUE;
			g.weight[2][3] = 1;
			g.weight[3][2] = 1;
			g.weight[3][5] = 1;
			g.weight[5][3] = 1;
			g.weight[3][6] = 1;
			g.weight[6][3] = 1;
		}

		if (em[3].HP <= 0 && !died[3]) {
			printf("4�� ���� �����ƴ�.\n");
			died[3] = TRUE;
			g.weight[2][4] = 1;
			g.weight[4][2] = 1;

		}

		if (em[4].HP <= 0 && !died[4]) {
			printf("5�� ���� �����ƴ�.\n");
			died[4] = TRUE;
			g.weight[3][5] = 1;
			g.weight[5][3] = 1;
			
		}

		if (em[5].HP <= 0 && !died[5]) {
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
		printf("���� �����Ѵ�!\n");
		//���� �� ������ �ֱ�
		for (int i = 0; i < 2; i++) {
			if (!died[i]) {
				*p_hp -= em[i].damage;
			}
		}
		Sleep(2000);
	}

}

void St3_3(int* p_hp) {
	//3STAGE THIRD
	int w_range;
	int w_damage;
	int w_index;
	GraphType g = { 7,
		{{ 0, 2, INF, INF, INF, INF, INF },
		{ 2, 0, 2, 2, INF, INF, INF },
		{ INF, 2, 0, INF, 2, 2, INF },
		{ INF, 2, INF, 0, INF, INF, INF },
		{ INF, INF, 2, INF, 0, INF, 2 },
		{ INF, INF, 2, INF, INF, 0, 2 },
		{ INF, INF, INF, INF, 2, 2, 0 },
		} };
	Em em[6];
	for (int i = 0; i < 6; i++) {
		em[i].index = i + 1;
		em[i].HP = 20;
		em[i].damage = 1;
	};

	int died[6];
	int i;
	for (i = 0; i < 6; i++) {
		died[i] = FALSE;
	}

	int index = 0;
	int enemy_range;

	for (int i = 0; i < 5; i++) {
		system("cls");
		printf("������ ����� ���� ����� ���� 5���� ����\n");
		for (int i = 0; i < 5; i++) {
			if (!died[i]) {
				printf("[%d] ü��: %d,�Ÿ�: %d\n", em[i].index, em[i].HP, shortest_path(&g, 0, em[i].index));
			}
		}
		print_deck();
		printf("����� ���� ��ȣ >> ");
		scanf("%d", &w_index);
		select_weapon_in_deck(w_index);
	}

	while (1) {
		do {
			system("cls");

			printf("3��° ��\n");
			printf("�÷��̾� ü�� : %d\n\n", *p_hp);

			//��ǥ��
			for (int i = 0; i < 6; i++) {
				if (!died[i]) {
					printf("[%d] ü��: %d,�Ÿ�: %d\n", em[i].index, em[i].HP, shortest_path(&g, 0, em[i].index));
				}
			}

			print_weapons();
			printf("���� ����(1 ~ 5) >> ");
			scanf("%d", &w_index);

			w_range = get_weapon_range(selectedWeapons[w_index - 1]);
			w_damage = get_weapon_damage(selectedWeapons[w_index - 1]);

			printf("������ �� ���� >> ");
			scanf("%d", &index);

			enemy_range = shortest_path(&g, 0, index);

			if (died[index - 1]) {
				printf("�ش� ���� �̹� �׿����ϴ�.\n");
				Sleep(2000);
			}
			else {
				if (enemy_range > w_range) {
					printf("���� �����Ÿ� �ۿ� �ִ�\n");
					Sleep(2000);
				}
				else {
					use_weapon(w_index - 1);
					break;
				}
			}
		} while (1);

		em[index - 1].HP -= w_damage;



		if (em[0].HP <= 0 && !died[0]) {
			printf("1�� ���� �����ƴ�.\n");
			died[0] = TRUE;
			g.weight[0][1] = 1;
			g.weight[1][0] = 1;
			g.weight[1][2] = 1;
			g.weight[2][1] = 1;
			g.weight[1][3] = 1;
			g.weight[3][1] = 1;

		}

		if (em[1].HP <= 0 && !died[1]) {
			printf("2�� ���� �����ƴ�.\n");
			died[1] = TRUE;
			g.weight[1][2] = 1;
			g.weight[2][1] = 1;			
			g.weight[2][4] = 1;
			g.weight[4][2] = 1;
			g.weight[2][5] = 1;
			g.weight[5][2] = 1;
		}

		if (em[2].HP <= 0 && !died[2]) {
			printf("3�� ���� �����ƴ�.\n");
			died[2] = TRUE;
			g.weight[1][3] = 1;
			g.weight[3][1] = 1;
			
		}

		if (em[3].HP <= 0 && !died[3]) {
			printf("4�� ���� �����ƴ�.\n");
			died[3] = TRUE;
			g.weight[2][4] = 1;
			g.weight[4][2] = 1;
			g.weight[4][6] = 1;
			g.weight[6][4] = 1;

		}

		if (em[4].HP <= 0 && !died[4]) {
			printf("5�� ���� �����ƴ�.\n");
			died[4] = TRUE;
			g.weight[2][5] = 1;
			g.weight[5][2] = 1;
			g.weight[5][6] = 1;
			g.weight[6][5] = 1;

		}

		if (em[5].HP <= 0 && !died[5]) {
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
		printf("���� �����Ѵ�!\n");
		//���� �� ������ �ֱ�
		for (int i = 0; i < 2; i++) {
			if (!died[i]) {
				*p_hp -= em[i].damage;
			}
		}
		Sleep(2000);
	}

}

void St4_1(int* p_hp) {
	//4STAGE FIRST
	int w_range;
	int w_damage;
	int w_index;
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
	Em em[7];
	for (int i = 0; i < 7; i++) {
		em[i].index = i + 1;
		em[i].HP = 20;
		em[i].damage = 1;
	};

	int died[7];
	int i;
	for (i = 0; i < 7; i++) {
		died[i] = FALSE;
	}

	int index = 0;
	int enemy_range;

	for (int i = 0; i < 5; i++) {
		system("cls");
		printf("������ ����� ���� ����� ���� 5���� ����\n");
		for (int i = 0; i < 5; i++) {
			if (!died[i]) {
				printf("[%d] ü��: %d,�Ÿ�: %d\n", em[i].index, em[i].HP, shortest_path(&g, 0, em[i].index));
			}
		}
		print_deck();
		printf("����� ���� ��ȣ >> ");
		scanf("%d", &w_index);
		select_weapon_in_deck(w_index);
	}

	while (1) {
		do {
			system("cls");

			printf("4��° ��\n");
			printf("�÷��̾� ü�� : %d\n\n", *p_hp);

			//��ǥ��
			for (int i = 0; i < 7; i++) {
				if (!died[i]) {
					printf("[%d] ü��: %d,�Ÿ�: %d\n", em[i].index, em[i].HP, shortest_path(&g, 0, em[i].index));
				}
			}

			print_weapons();
			printf("���� ����(1 ~ 5) >> ");
			scanf("%d", &w_index);

			w_range = get_weapon_range(selectedWeapons[w_index - 1]);
			w_damage = get_weapon_damage(selectedWeapons[w_index - 1]);

			printf("������ �� ���� >> ");
			scanf("%d", &index);

			enemy_range = shortest_path(&g, 0, index);

			if (died[index - 1]) {
				printf("�ش� ���� �̹� �׿����ϴ�.\n");
				Sleep(2000);
			}
			else {
				if (enemy_range > w_range) {
					printf("���� �����Ÿ� �ۿ� �ִ�\n");
					Sleep(2000);
				}
				else {
					use_weapon(w_index - 1);
					break;
				}
			}
		} while (1);

		em[index - 1].HP -= w_damage;


		if (em[0].HP <= 0 && !died[0]) {
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

		if (em[1].HP <= 0 && !died[1]) {
			printf("2�� ���� �����ƴ�.\n");
			died[1] = TRUE;
			g.weight[1][2] = 1;
			g.weight[2][1] = 1;
			g.weight[2][5] = 1;
			g.weight[5][2] = 1;
			
		}

		if (em[2].HP <= 0 && !died[2]) {
			printf("3�� ���� �����ƴ�.\n");
			died[2] = TRUE;
			g.weight[1][3] = 1;
			g.weight[3][1] = 1;

		}

		if (em[3].HP <= 0 && !died[3]) {
			printf("4�� ���� �����ƴ�.\n");
			died[3] = TRUE;
			g.weight[1][4] = 1;
			g.weight[4][1] = 1;
			g.weight[4][5] = 1;
			g.weight[5][4] = 1;

		}

		if (em[4].HP <= 0 && !died[4]) {
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

		if (em[5].HP <= 0 && !died[5]) {
			printf("6�� ���� �����ƴ�.\n");
			died[5] = TRUE;
			
			g.weight[6][5] = 1;
			g.weight[5][6] = 1;
		}

		if (em[6].HP <= 0 && !died[6]) {
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
		printf("���� �����Ѵ�!\n");
		//���� �� ������ �ֱ�
		for (int i = 0; i < 2; i++) {
			if (!died[i]) {
				*p_hp -= em[i].damage;
			}
		}
		Sleep(2000);
	}
}

void St4_2(int* p_hp) {
	//4STAGE THIRD
	int w_range;
	int w_damage;
	int w_index;
	GraphType g = { 8,
		{{ 0, 2, 2, INF, INF, INF, INF, INF },
		{ 2, 0, INF, 2, INF, INF, INF, INF },
		{ 2, INF, 0, INF, 2, INF, INF, INF },
		{ INF, 2, INF, 0, INF, 2, INF, INF },
		{ INF, INF, 2, INF, 0, INF, 2, INF },
		{ INF, INF, INF, 2, INF, 0, INF, 2 },
		{ INF, INF, INF, INF, 2, INF, 0, 2 },
		{ INF, INF, INF, INF, INF, 2, 2, 0 },
		} };

	Em em[7];
	for (int i = 0; i < 7; i++) {
		em[i].index = i + 1;
		em[i].HP = 20;
		em[i].damage = 1;
	};

	int died[7];
	int i;
	for (i = 0; i < 7; i++) {
		died[i] = FALSE;
	}

	int index = 0;
	int enemy_range;

	for (int i = 0; i < 5; i++) {
		system("cls");
		printf("������ ����� ���� ����� ���� 5���� ����\n");
		for (int i = 0; i < 5; i++) {
			if (!died[i]) {
				printf("[%d] ü��: %d,�Ÿ�: %d\n", em[i].index, em[i].HP, shortest_path(&g, 0, em[i].index));
			}
		}
		print_deck();
		printf("����� ���� ��ȣ >> ");
		scanf("%d", &w_index);
		select_weapon_in_deck(w_index);
	}


	while (1) {
			do {
				system("cls");

				printf("4��° ��\n");
				printf("�÷��̾� ü�� : %d\n\n", *p_hp);

				//��ǥ��
				for (int i = 0; i < 7; i++) {
					if (!died[i]) {
						printf("[%d] ü��: %d,�Ÿ�: %d\n", em[i].index, em[i].HP, shortest_path(&g, 0, em[i].index));
					}
				}

				print_weapons();
				printf("���� ����(1 ~ 5) >> ");
				scanf("%d", &w_index);

				w_range = get_weapon_range(selectedWeapons[w_index - 1]);
				w_damage = get_weapon_damage(selectedWeapons[w_index - 1]);

				printf("������ �� ���� >> ");
				scanf("%d", &index);

				enemy_range = shortest_path(&g, 0, index);

				if (died[index - 1]) {
					printf("�ش� ���� �̹� �׿����ϴ�.\n");
					Sleep(2000);
				}
				else {
					if (enemy_range > w_range) {
						printf("���� �����Ÿ� �ۿ� �ִ�\n");
						Sleep(2000);
					}
					else {
						use_weapon(w_index - 1);
						break;
					}
				}
			} while (1);

			em[index - 1].HP -= w_damage;


		if (em[0].HP <= 0 && !died[0]) {
			printf("1�� ���� �����ƴ�.\n");
			died[0] = TRUE;
			g.weight[0][1] = 1;
			g.weight[1][0] = 1;
			
			g.weight[1][3] = 1;
			g.weight[3][1] = 1;
			

		}

		if (em[1].HP <= 0 && !died[1]) {
			printf("2�� ���� �����ƴ�.\n");
			died[1] = TRUE;
			g.weight[0][2] = 1;
			g.weight[2][0] = 1;
			g.weight[2][4] = 1;
			g.weight[4][2] = 1;

		}

		if (em[2].HP <= 0 && !died[2]) {
			printf("3�� ���� �����ƴ�.\n");
			died[2] = TRUE;
			g.weight[1][3] = 1;
			g.weight[3][1] = 1;
			g.weight[5][3] = 1;
			g.weight[3][5] = 1;

		}

		if (em[3].HP <= 0 && !died[3]) {
			printf("4�� ���� �����ƴ�.\n");
			died[3] = TRUE;
			g.weight[2][4] = 1;
			g.weight[4][2] = 1;
			g.weight[6][4] = 1;
			g.weight[4][6] = 1;

		}

		if (em[4].HP <= 0 && !died[4]) {
			printf("5�� ���� �����ƴ�.\n");
			died[4] = TRUE;
			g.weight[3][5] = 1;
			g.weight[5][3] = 1;
			g.weight[5][7] = 1;
			g.weight[7][5] = 1;


		}

		if (em[5].HP <= 0 && !died[5]) {
			printf("6�� ���� �����ƴ�.\n");
			died[5] = TRUE;
			g.weight[4][6] = 1;
			g.weight[6][4] = 1;
			
			g.weight[6][7] = 1;
			g.weight[7][6] = 1;
		}

		if (em[6].HP <= 0 && !died[6]) {
			printf("7�� ���� �����ƴ�.\n");
			died[6] = TRUE;
			g.weight[7][5] = 1;
			g.weight[5][7] = 1;
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
		printf("���� �����Ѵ�!\n");
		//���� �� ������ �ֱ�
		for (int i = 0; i < 2; i++) {
			if (!died[i]) {
				*p_hp -= em[i].damage;
			}
		}
		Sleep(2000);
	}

}

void St4_3(int* p_hp) {
	//4STAGE THIRD
	int w_range;
	int w_damage;
	int w_index;
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
	Em em[7];
	for (int i = 0; i < 7; i++) {
		em[i].index = i + 1;
		em[i].HP = 20;
		em[i].damage = 1;
	};

	int died[7];
	int i;
	for (i = 0; i < 7; i++) {
		died[i] = FALSE;
	}

	int index = 0;
	int enemy_range;

	for (int i = 0; i < 5; i++) {
		system("cls");
		printf("������ ����� ���� ����� ���� 5���� ����\n");
		for (int i = 0; i < 5; i++) {
			if (!died[i]) {
				printf("[%d] ü��: %d,�Ÿ�: %d\n", em[i].index, em[i].HP, shortest_path(&g, 0, em[i].index));
			}
		}
		print_deck();
		printf("����� ���� ��ȣ >> ");
		scanf("%d", &w_index);
		select_weapon_in_deck(w_index);
	}

	while (1) {
		do {
			system("cls");

			printf("4��° ��\n");
			printf("�÷��̾� ü�� : %d\n\n", *p_hp);

			//��ǥ��
			for (int i = 0; i < 7; i++) {
				if (!died[i]) {
					printf("[%d] ü��: %d,�Ÿ�: %d\n", em[i].index, em[i].HP, shortest_path(&g, 0, em[i].index));
				}
			}

			print_weapons();
			printf("���� ����(1 ~ 5) >> ");
			scanf("%d", &w_index);

			w_range = get_weapon_range(selectedWeapons[w_index - 1]);
			w_damage = get_weapon_damage(selectedWeapons[w_index - 1]);

			printf("������ �� ���� >> ");
			scanf("%d", &index);

			enemy_range = shortest_path(&g, 0, index);

			if (died[index - 1]) {
				printf("�ش� ���� �̹� �׿����ϴ�.\n");
				Sleep(2000);
			}
			else {
				if (enemy_range > w_range) {
					printf("���� �����Ÿ� �ۿ� �ִ�\n");
					Sleep(2000);
				}
				else {
					use_weapon(w_index - 1);
					break;
				}
			}
		} while (1);

		em[index - 1].HP -= w_damage;


		if (em[0].HP <= 0 && !died[0]) {
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

		if (em[1].HP <= 0 && !died[1]) {
			printf("2�� ���� �����ƴ�.\n");
			died[1] = TRUE;
			g.weight[1][2] = 1;
			g.weight[2][1] = 1;
			g.weight[2][6] = 1;
			g.weight[6][2] = 1;

		}

		if (em[2].HP <= 0 && !died[2]) {
			printf("3�� ���� �����ƴ�.\n");
			died[2] = TRUE;
			g.weight[1][3] = 1;
			g.weight[3][1] = 1;

		}

		if (em[3].HP <= 0 && !died[3]) {
			printf("4�� ���� �����ƴ�.\n");
			died[3] = TRUE;
			g.weight[1][4] = 1;
			g.weight[4][1] = 1;
			

		}

		if (em[4].HP <= 0 && !died[4]) {
			printf("5�� ���� �����ƴ�.\n");
			died[4] = TRUE;
			g.weight[1][5] = 1;
			g.weight[5][1] = 1;
			g.weight[5][6] = 1;
			g.weight[6][5] = 1;
			

		}

		if (em[5].HP <= 0 && !died[5]) {
			printf("6�� ���� �����ƴ�.\n");
			died[5] = TRUE;
			g.weight[2][6] = 1;
			g.weight[6][2] = 1;
			g.weight[6][5] = 1;
			g.weight[5][6] = 1;
			g.weight[6][7] = 1;
			g.weight[7][6] = 1;
		}

		if (em[6].HP <= 0 && !died[6]) {
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
		printf("���� �����Ѵ�!\n");
		//���� �� ������ �ֱ�
		for (int i = 0; i < 2; i++) {
			if (!died[i]) {
				*p_hp -= em[i].damage;
			}
		}
		Sleep(2000);

	}

}

void Boss(int* p_hp) {
	//Boss_STAGE
	int w_range;
	int w_damage;
	int w_index;
	GraphType g = { 7,
		{{ 0, 2, INF, INF, INF, INF, INF },
		{ 2, 0, 2, INF, INF, INF, INF },
		{ INF, 2, 0, 2, INF, INF, INF },
		{ INF, INF, 2, 0, 2, 2, INF },
		{ INF, INF, INF, 2, 0, INF, 2 },
		{ INF, INF, INF, 2, INF, 0, 2 },
		{ INF, INF, INF, INF, 2, 2, 0 },
		} };
	Em em[6];
	for (int i = 0; i < 6; i++) {
		em[i].index = i + 1;
		em[i].HP = 20;
		em[i].damage = 1;
	};

	em[3].HP = 40;
	em[3].damage = 3;
	em[4].HP = 40;
	em[4].damage = 3;

	em[5].HP = 60;
	em[5].damage = 5;


	int died[6];
	int i;
	for (i = 0; i < 6; i++) {
		died[i] = FALSE;
	}

	int index = 0;
	int enemy_range;

	for (int i = 0; i < 5; i++) {
		system("cls");
		printf("������ ����� ���� ����� ���� 5���� ����\n");
		for (int i = 0; i < 5; i++) {
			if (!died[i]) {
				printf("[%d] ü��: %d,�Ÿ�: %d\n", em[i].index, em[i].HP, shortest_path(&g, 0, em[i].index));
			}
		}
		print_deck();
		printf("����� ���� ��ȣ >> ");
		scanf("%d", &w_index);
		select_weapon_in_deck(w_index);
	}

	while (1) {
		do {
			system("cls");

			printf("���� ��\n");
			printf("�÷��̾� ü�� : %d\n\n", *p_hp);

			//��ǥ��
			for (int i = 0; i < 6; i++) {
				if (!died[i]) {
					printf("[%d] ü��: %d,�Ÿ�: %d\n", em[i].index, em[i].HP, shortest_path(&g, 0, em[i].index));
				}
			}

			print_weapons();
			printf("���� ����(1 ~ 5) >> ");
			scanf("%d", &w_index);

			w_range = get_weapon_range(selectedWeapons[w_index - 1]);
			w_damage = get_weapon_damage(selectedWeapons[w_index - 1]);

			printf("������ �� ���� >> ");
			scanf("%d", &index);

			enemy_range = shortest_path(&g, 0, index);

			if (died[index - 1]) {
				printf("�ش� ���� �̹� �׿����ϴ�.\n");
				Sleep(2000);
			}
			else {
				if (enemy_range > w_range) {
					printf("���� �����Ÿ� �ۿ� �ִ�\n");
					Sleep(2000);
				}
				else {
					use_weapon(w_index - 1);
					break;
				}
			}
		} while (1);

		em[index - 1].HP -= w_damage;


		if (em[0].HP <= 0 && !died[0]) {
			printf("1�� ���� �����ƴ�.\n");
			died[0] = TRUE;
			g.weight[0][1] = 1;
			g.weight[1][0] = 1;
			g.weight[1][2] = 1;
			g.weight[2][1] = 1;
			

		}

		if (em[1].HP <= 0 && !died[1]) {
			printf("2�� ���� �����ƴ�.\n");
			died[1] = TRUE;
			g.weight[1][2] = 1;
			g.weight[2][1] = 1;
			g.weight[2][3] = 1;
			g.weight[3][2] = 1;
			
		}

		if (em[2].HP <= 0 && !died[2]) {
			printf("3�� ���� �����ƴ�.\n");
			died[2] = TRUE;
			g.weight[2][3] = 1;
			g.weight[3][2] = 1;
			g.weight[3][4] = 1;
			g.weight[4][3] = 1;
			g.weight[3][5] = 1;
			g.weight[5][3] = 1;
		}

		if (em[3].HP <= 0 && !died[3]) {
			printf("4�� ���� �����ƴ�.\n");
			died[3] = TRUE;
			g.weight[3][4] = 1;
			g.weight[4][3] = 1;
			g.weight[4][6] = 1;
			g.weight[6][4] = 1;

		}

		if (em[4].HP <= 0 && !died[4]) {
			printf("5�� ���� �����ƴ�.\n");
			died[4] = TRUE;
			g.weight[3][5] = 1;
			g.weight[5][3] = 1;
			g.weight[5][6] = 1;
			g.weight[6][5] = 1;

		}

		if (em[5].HP <= 0 && !died[5]) {
			printf("������ �����ƴ�.\n");
			died[5] = TRUE;
			g.weight[6][4] = 1;
			g.weight[4][6] = 1;
			g.weight[6][5] = 1;
			g.weight[5][6] = 1;
		}

		if (died[5]) {
			printf("������ ����ߴ�.");
			Sleep(3000);
			break;
		}

		if (died[0]) {
			if (died[1]) {
				if (died[2]) {
					if (died[3]) {
						if (died[4]) {
							if (died[5]) {
								printf("������ ��� ���� �����ƴ�\n");
								Sleep(5000);
								break;
							}
						}
					}
				}
			}
		}
		printf("���� �����Ѵ�!\n");
		//���� �� ������ �ֱ�
		for (int i = 0; i < 2; i++) {
			if (!died[i]) {
				*p_hp -= em[i].damage;
			}
		}
		Sleep(2000);
	}

}

