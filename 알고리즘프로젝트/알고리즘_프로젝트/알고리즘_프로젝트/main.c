#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include "range.h"
#include "weapon.h"


int main()
{
	int player_HP = 100;
	int randomindex;

	initialize_weapons();

	St1(&player_HP);

	building_turn();

	randomindex = rand() % 2;

	if (randomindex == 0) {
		St2_1(&player_HP);
	}
	else {
		St2_2(&player_HP);
	}

	return 0;
}