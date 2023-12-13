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
	initialize_weapons();

	int player_HP = 100;
	int randomindex;
	int turn = 0;

	printf("창을 풀스크린으로 하고 플레이하시길 바랍니다.아무키나 눌러 시작하십시오\n");
	char keyPressed = _getch();
	system("cls");
	printf("이곳에 납치된 여동생이 있다. 들어간다.\n");
	keyPressed = _getch();


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
	
	system("cls");

	if (turn >= 100) {
		printf("적을 모두 처단했지만 여동생은 이미 사라지고 없었다.\n");
		printf("더 빠르게 왔다면 구할수 있었을텐데...\n");
		printf("Bed Ending...");
	}
	else {
		printf("보스까지 쓰러트리고 여동생을 구하였다!\n");
		printf("Game Clear~! Happy Ending");
	}

	return 0;
}