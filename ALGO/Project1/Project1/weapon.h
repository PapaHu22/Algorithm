#pragma once

typedef struct {
    char* name;
    int range;
    int durability;
    int damage; 
} Weapon;
//�ٸ� c���� �����ȵǼ� ã�ƺ��� extern����ϸ� �ȴٴ���
extern Weapon selectedWeapons[];
extern int numSelectedWeapons;
extern Weapon allWeapons[];

void weapon_add(Weapon weapon);
void weapon_delete(int index);
void print_weapons();
void use_weapon(int index);
void sort_by_range(Weapon weapons[], int size);