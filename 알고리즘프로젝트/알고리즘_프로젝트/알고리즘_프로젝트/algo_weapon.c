#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "weapon.h"

#define TOTAL_WEAPONS 8
#define MAX_RANGE 4
#define MAX_DECK_WEAPONS 10
#define MAX_WEAPONS 5

Weapon allWeapons[TOTAL_WEAPONS];
Weapon selectedWeapons[MAX_WEAPONS];
Weapon deckWeapons[MAX_DECK_WEAPONS];
int numSelectedWeapons = 0;
int numdeckWeapons = 0;

// ������ �����Լ�
void add_random_deck_weapons() {
    while (numdeckWeapons < MAX_DECK_WEAPONS) {
        int randomIndex = rand() % TOTAL_WEAPONS;
        deck_weapon_add(allWeapons[randomIndex]);
    }
}

void deck_weapon_add(Weapon weapon) {
    if (numdeckWeapons < MAX_DECK_WEAPONS) {
        deckWeapons[numdeckWeapons] = weapon;
        numdeckWeapons++;
    }
    else {
        printf("�� �̻� ���⸦ �߰��� �� �����ϴ�.\n");
    }
}
//���� ����
void deck_weapon_delete(int index) {
    if (index >= 0 && index < numdeckWeapons) {
        for (int i = index; i < numdeckWeapons - 1; i++) {
            deckWeapons[i] = deckWeapons[i + 1];
        }
        numdeckWeapons--;
    }
    else {
        printf("�߸��� �ε����Դϴ�.\n");
    }
}

void reload_deck(int index) {
    if (index >= 0 && index < numdeckWeapons) {
        deck_weapon_delete(index);
        int randomIndex = rand() % TOTAL_WEAPONS;;
        deck_weapon_add(allWeapons[randomIndex]);
    }
    else {
        printf("�߸��� �ε����Դϴ�.\n");
    }
}

void building_turn() {
    int reload_count = 3;
    int input;
    int index;
    numSelectedWeapons = 0;
    add_random_deck_weapons();

    while (1) {
        system("cls");

        print_deck();
        printf("������ ���⸦ �ٲٽðڽ��ϱ�?(���� ���� Ƚ��:%d)[yes(1)/no(2)]", reload_count);
        scanf("%d", &input);
        if (input == 1) {
            printf("�� �� ���⸦ �ٲٽðڽ��ϱ�?");
            scanf("%d", &index);
            reload_deck(index - 1);
            reload_count--;
        }
        else if (input == 2) {
            printf("�ش� ���� ���� ����ϴ�.\n");
            Sleep(1000);
            break;
        }
        else {
            printf("�߸��� �Է��Դϴ�");
            Sleep(1000);
        }

        if (reload_count == 0) {
            printf("���� Ƚ���� ���� �����߽��ϴ�.\n");
            Sleep(1000);
            break;
        }
    }


}

void select_weapon_in_deck(int index) {
    if (index >= 0 && index < numdeckWeapons) {
        if (numSelectedWeapons < MAX_WEAPONS) {
            weapon_add(deckWeapons[index-1]);
            deck_weapon_delete(index-1);
        }
        else {
            printf("�� �̻� ���⸦ ì��� �����ϴ�.\n");
        }
    }
    else {
    printf("�߸��� �Է��Դϴ�.\n");
    }
}

void print_deck() {
    for (int i = 0; i < numdeckWeapons; i++) {
        printf("|[%d]%s ��Ÿ�: %d|", i + 1, deckWeapons[i].name, deckWeapons[i].range);
        if (i == 5) {
            printf("\n");
        }
    }
    printf("\n");
}


//----------------------------------------�ʱ� ���� �Լ� ����
// ���� �̸� ����
char* get_weapon_name(int index) {
    char* names[TOTAL_WEAPONS] = { "����", "��󵵳�", "�����ɷ�", "����", "��������", "��������", "ä��", "�����ź" };
    return names[index];
}

//�� ó�� ���� �ʱ�ȭ.
void initialize_weapons() {
    srand((unsigned int)time(NULL));

    int ranges[TOTAL_WEAPONS] = { 1, 2, 3, 4, 1, 2, 4, 1 };//��Ÿ�
    int durabilities[TOTAL_WEAPONS] = { 4, 3, 2, 1, 3, 2, 4, 1 }; //������
    int damages[TOTAL_WEAPONS] = { 10, 40, 30, 40, 20, 30, 10, 40 }; //������

    for (int i = 0; i < TOTAL_WEAPONS; i++) {
        allWeapons[i].range = ranges[i]; // Set range manually
        allWeapons[i].durability = durabilities[i]; // Set durability manually
        allWeapons[i].damage = damages[i]; // Set damage manually
        allWeapons[i].name = get_weapon_name(i);
    }
}

// �������� 5�� ���� �߰��ϴ� �Լ�
void add_random_weapons() {
    while (numSelectedWeapons < MAX_WEAPONS) {
        int randomIndex = rand() % TOTAL_WEAPONS;
        weapon_add(allWeapons[randomIndex]);
    }
}
//----------------------------------------�߿� ��� �Լ� ����
//���� �߰�
void weapon_add(Weapon weapon) {
    if (numSelectedWeapons < MAX_WEAPONS) {
        selectedWeapons[numSelectedWeapons] = weapon;
        numSelectedWeapons++;
    }
    else {
        printf("�� �̻� ���⸦ �߰��� �� �����ϴ�.\n");
    }
}
//���� ����
void weapon_delete(int index) {
    if (index >= 0 && index < numSelectedWeapons) {
        for (int i = index; i < numSelectedWeapons - 1; i++) {
            selectedWeapons[i] = selectedWeapons[i + 1];
        }
        numSelectedWeapons--;
    }
    else {
        printf("�߸��� �ε����Դϴ�.\n");
    }
}

//���� ����.
void use_weapon(int index) {
    if (index >= 0 && index < numSelectedWeapons) {
        if (selectedWeapons[index].durability > 0) {
            selectedWeapons[index].durability--;
            printf("%s�� ����߽��ϴ�. ������: %d\n", selectedWeapons[index].name, selectedWeapons[index].durability);
            if (selectedWeapons[index].durability == 0) {
                printf("%s�� �������� �� �Ҹ�Ǿ� ���ŵ˴ϴ�.\n", selectedWeapons[index].name);
                weapon_delete(index);
            }
        }
        else {
            printf("%s�� �������� �̹� �Ҹ�Ǿ� ����� �� �����ϴ�.\n", selectedWeapons[index].name);
        }
    }
    else {
        printf("�߸��� �ε����Դϴ�.\n");
    }
}
//----------------------------------------���� ���� �Լ� ����


// ������ ������ ��ȯ �Լ�
int get_weapon_damage(Weapon weapon) {//int damage = get_weapon_damage(selectedWeapons[index]); ���� �������� ����ϸ��.
    return weapon.damage;
}

// ������ ��Ÿ� ��ȯ �Լ� //int range = get_weapon_range(selectedWeapons[index]);  ���� �������� ����ϸ��.
int get_weapon_range(Weapon weapon) {
    return weapon.range;
}


//----------------------------------------���� �������̽� �Լ� ����
// //���� �������̽�(���)
void print_weapons() {
    printf("���� ���:\n");

    for (int i = 0; i < numSelectedWeapons; i += 5) {
        printf("##################################################\n");

        printf("#[1]����: %-9s  # #[2]����: %-9s  # #[3]����: %-9s  # #[4]����: %-9s  # #[5]����: %-9s  #\n",
            selectedWeapons[i].name,
            (i + 1 < numSelectedWeapons) ? selectedWeapons[i + 1].name : "",
            (i + 2 < numSelectedWeapons) ? selectedWeapons[i + 2].name : "",
            (i + 3 < numSelectedWeapons) ? selectedWeapons[i + 3].name : "",
            (i + 4 < numSelectedWeapons) ? selectedWeapons[i + 4].name : "");

        printf("#��Ÿ� :   %-9d# #��Ÿ� :   %-9d# #��Ÿ� :   %-9d# #��Ÿ� :   %-9d# #��Ÿ� :   %-9d#\n",
            selectedWeapons[i].range,
            (i + 1 < numSelectedWeapons) ? selectedWeapons[i + 1].range : 0,
            (i + 2 < numSelectedWeapons) ? selectedWeapons[i + 2].range : 0,
            (i + 3 < numSelectedWeapons) ? selectedWeapons[i + 3].range : 0,
            (i + 4 < numSelectedWeapons) ? selectedWeapons[i + 4].range : 0);

        printf("#������ :   %-9d# #������ :   %-9d# #������ :   %-9d# #������ :   %-9d# #������ :   %-9d#\n",
            selectedWeapons[i].damage,
            (i + 1 < numSelectedWeapons) ? selectedWeapons[i + 1].damage : 0,
            (i + 2 < numSelectedWeapons) ? selectedWeapons[i + 2].damage : 0,
            (i + 3 < numSelectedWeapons) ? selectedWeapons[i + 3].damage : 0,
            (i + 4 < numSelectedWeapons) ? selectedWeapons[i + 4].damage : 0);

        printf("#������ :   %-9d# #������ :   %-9d# #������ :   %-9d# #������ :   %-9d# #������ :   %-9d#\n",
            selectedWeapons[i].durability,
            (i + 1 < numSelectedWeapons) ? selectedWeapons[i + 1].durability : 0,
            (i + 2 < numSelectedWeapons) ? selectedWeapons[i + 2].durability : 0,
            (i + 3 < numSelectedWeapons) ? selectedWeapons[i + 3].durability : 0,
            (i + 4 < numSelectedWeapons) ? selectedWeapons[i + 4].durability : 0);

        printf("##################################################\n\n");
    }
}
//----------------------------------------���� ���� �˰��� �Լ� ����
//������ �˰��� ���
/*
swap()
partition : �ǹ� ����
quickSort : �迭�� �����ϰ� ��������� ����
sort_by_range : ������ ����. ����*/
void swap(Weapon* a, Weapon* b) {
    Weapon temp = *a;
    *a = *b;
    *b = temp;
}

// �� ���Ŀ��� ���Ǵ� ��Ƽ�� �Լ�
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

// �� ���� �Լ�
void quickSort(Weapon weapons[], int low, int high) {
    if (low < high) {
        int pi = partition(weapons, low, high);

        quickSort(weapons, low, pi - 1);
        quickSort(weapons, pi + 1, high);
    }
}

// ��Ÿ��� �������� ���⸦ �� ���ķ� �����ϴ� �Լ�
void sort_by_range(Weapon weapons[], int size) {
    quickSort(weapons, 0, size - 1);
}
//----------------------------------------
