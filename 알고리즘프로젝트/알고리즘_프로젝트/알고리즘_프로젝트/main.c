#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include "range.h"
#include "weapon.h"
#include <conio.h>


int main()
{
	srand(time(NULL));

	int player_HP = 100;
	int randomindex;
	int turn = 0;

	printf("�̰��� ��ġ�� �������� �ִ�. ����.");
	char keyPressed = _getch();

	initialize_weapons();

	turn += St1(&player_HP);

	building_turn();

	randomindex = rand() % 2;

	if (randomindex == 0) {
		turn += St2_1(&player_HP);
	}
	else {
		turn += St2_2(&player_HP);
	}

	building_turn();

	randomindex = rand() % 2;

	if (randomindex == 0) {
		turn += St3_1(&player_HP);
	}
	else if (randomindex == 1) {
		turn += St3_2(&player_HP);
	}
	else {
		turn += St3_3(&player_HP);
	}

	building_turn();

	randomindex = rand() % 2;

	if (randomindex == 0) {
		turn += St4_1(&player_HP);
	}
	else if (randomindex == 1) {
		turn += St4_2(&player_HP);
	}
	else {
		turn += St4_3(&player_HP);
	}

	building_turn();

    turn += Boss(&player_HP);

	if (turn >= 100) {
		printf("���� ��� ó�������� �������� �̹� ������� ������.\n");
		printf("�� ������ �Դٸ� ���Ҽ� �־����ٵ�...\n");
		printf("Bed Ending...");
	}
	else {
		printf("�������� ����Ʈ���� �������� ���Ͽ���!\n");
		printf("Game Clear~! Happy Ending");
	}

	return 0;
}