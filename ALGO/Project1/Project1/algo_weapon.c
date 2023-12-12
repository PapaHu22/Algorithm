#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "weapon.h"

#define TOTAL_WEAPONS 8
#define MAX_RANGE 4
#define MAX_WEAPONS 5

Weapon allWeapons[TOTAL_WEAPONS];
Weapon selectedWeapons[MAX_WEAPONS];
int numSelectedWeapons = 0;

//----------------------------------------초기 세팅 함수 라인
// 무기 이름 설정
char* get_weapon_name(int index) {
    char* names[TOTAL_WEAPONS] = { "연필", "비상도끼", "부서진나무걸레", "권총", "유리조각", "쇠지렛대", "채찍", "밥솥폭탄" };
    return names[index];
}

//맨 처음 무기 초기화.
void initialize_weapons() {
    srand((unsigned int)time(NULL));

    int ranges[TOTAL_WEAPONS] = { 1, 2, 3, 4, 1, 2, 4, 1 };//사거리
    int durabilities[TOTAL_WEAPONS] = { 4, 3, 2, 1, 3, 2, 4, 1 }; //내구도
    int damages[TOTAL_WEAPONS] = { 10, 40, 30, 40, 20, 30, 10, 40 }; //데미지

    for (int i = 0; i < TOTAL_WEAPONS; i++) {
        allWeapons[i].range = ranges[i]; // Set range manually
        allWeapons[i].durability = durabilities[i]; // Set durability manually
        allWeapons[i].damage = damages[i]; // Set damage manually
        allWeapons[i].name = get_weapon_name(i);
    }
}

// 무작위로 5개 무기 추가하는 함수
void add_random_weapons() {
    while (numSelectedWeapons < MAX_WEAPONS) {
        int randomIndex = rand() % TOTAL_WEAPONS;
        weapon_add(allWeapons[randomIndex]);
    }
}
//----------------------------------------중요 기능 함수 라인
//무기 추가
void weapon_add(Weapon weapon) {
    if (numSelectedWeapons < MAX_WEAPONS) {
        selectedWeapons[numSelectedWeapons] = weapon;
        numSelectedWeapons++;
    }
    else {
        printf("더 이상 무기를 추가할 수 없습니다.\n");
    }
}
//무기 제거
void weapon_delete(int index) {
    if (index >= 0 && index < numSelectedWeapons) {
        for (int i = index; i < numSelectedWeapons - 1; i++) {
            selectedWeapons[i] = selectedWeapons[i + 1];
        }
        numSelectedWeapons--;
    }
    else {
        printf("잘못된 인덱스입니다.\n");
    }
}

//무기 사용시.
void use_weapon(int index) {
    if (index >= 0 && index < numSelectedWeapons) {
        if (selectedWeapons[index].durability > 0) {
            selectedWeapons[index].durability--;
            printf("%s를 사용했습니다. 내구도: %d\n", selectedWeapons[index].name, selectedWeapons[index].durability);
            if (selectedWeapons[index].durability == 0) {
                printf("%s의 내구도가 다 소모되어 제거됩니다.\n", selectedWeapons[index].name);
                weapon_delete(index);
            }
        }
        else {
            printf("%s의 내구도가 이미 소모되어 사용할 수 없습니다.\n", selectedWeapons[index].name);
        }
    }
    else {
        printf("잘못된 인덱스입니다.\n");
    }
}
//----------------------------------------무기 정보 함수 라인


// 무기의 데미지 반환 함수
int get_weapon_damage(Weapon weapon) {//int damage = get_weapon_damage(selectedWeapons[index]); 같은 느낌으로 사용하면됨.
    return weapon.damage;
}

// 무기의 사거리 반환 함수 //int range = get_weapon_range(selectedWeapons[index]);  같은 느낌으로 사용하면됨.
int get_weapon_range(Weapon weapon) {
    return weapon.range;
}


//----------------------------------------무기 인터페이스 함수 라인
// //무기 인터페이스(출력)
void print_weapons() {
    printf("무기 목록:\n");

    for (int i = 0; i < numSelectedWeapons; i += 5) {
        printf("##################################################\n");

        printf("#무기  : %-9s  # #무기  : %-9s  # #무기  : %-9s  # #무기  : %-9s  # #무기  : %-9s  #\n",
            selectedWeapons[i].name,
            (i + 1 < numSelectedWeapons) ? selectedWeapons[i + 1].name : "",
            (i + 2 < numSelectedWeapons) ? selectedWeapons[i + 2].name : "",
            (i + 3 < numSelectedWeapons) ? selectedWeapons[i + 3].name : "",
            (i + 4 < numSelectedWeapons) ? selectedWeapons[i + 4].name : "");

        printf("#사거리:   %-9d# #사거리:   %-9d# #사거리:   %-9d# #사거리:   %-9d# #사거리:   %-9d#\n",
            selectedWeapons[i].range,
            (i + 1 < numSelectedWeapons) ? selectedWeapons[i + 1].range : 0,
            (i + 2 < numSelectedWeapons) ? selectedWeapons[i + 2].range : 0,
            (i + 3 < numSelectedWeapons) ? selectedWeapons[i + 3].range : 0,
            (i + 4 < numSelectedWeapons) ? selectedWeapons[i + 4].range : 0);

        printf("#데미지:   %-9d# #데미지:   %-9d# #데미지:   %-9d# #데미지:   %-9d# #데미지:   %-9d#\n",
            selectedWeapons[i].damage,
            (i + 1 < numSelectedWeapons) ? selectedWeapons[i + 1].damage : 0,
            (i + 2 < numSelectedWeapons) ? selectedWeapons[i + 2].damage : 0,
            (i + 3 < numSelectedWeapons) ? selectedWeapons[i + 3].damage : 0,
            (i + 4 < numSelectedWeapons) ? selectedWeapons[i + 4].damage : 0);

        printf("#내구도:   %-9d# #내구도:   %-9d# #내구도:   %-9d# #내구도:   %-9d# #내구도:   %-9d#\n",
            selectedWeapons[i].durability,
            (i + 1 < numSelectedWeapons) ? selectedWeapons[i + 1].durability : 0,
            (i + 2 < numSelectedWeapons) ? selectedWeapons[i + 2].durability : 0,
            (i + 3 < numSelectedWeapons) ? selectedWeapons[i + 3].durability : 0,
            (i + 4 < numSelectedWeapons) ? selectedWeapons[i + 4].durability : 0);

        printf("##################################################\n\n");
    }
}
//----------------------------------------무기 정렬 알고리즘 함수 라인
//퀵정렬 알고리즘 사용
/*
swap()
partition : 피벗 설정
quickSort : 배열을 분할하고 재귀적으로 정렬
sort_by_range : 퀵정렬 정리. 최종*/
void swap(Weapon* a, Weapon* b) {
    Weapon temp = *a;
    *a = *b;
    *b = temp;
}

// 퀵 정렬에서 사용되는 파티션 함수
int partition(Weapon weapons[], int low, int high) {
    int pivot = weapons[high].range;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (weapons[j].range < pivot) {
            i++;
            swap(&weapons[i], &weapons[j]);
        }
    }
    swap(&weapons[i + 1], &weapons[high]);
    return i + 1;
}

// 퀵 정렬 함수
void quickSort(Weapon weapons[], int low, int high) {
    if (low < high) {
        int pi = partition(weapons, low, high);

        quickSort(weapons, low, pi - 1);
        quickSort(weapons, pi + 1, high);
    }
}

// 사거리를 기준으로 무기를 퀵 정렬로 정렬하는 함수
void sort_by_range(Weapon weapons[], int size) {
    quickSort(weapons, 0, size - 1);
}
//----------------------------------------
