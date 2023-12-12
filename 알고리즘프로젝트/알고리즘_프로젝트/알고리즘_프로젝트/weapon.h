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

void add_random_deck_weapons();
void deck_weapon_add(Weapon weapon);
void deck_weapon_delete(int index);
void reload_deck(int index);
void select_weapon_in_deck(int index);
void weapon_add(Weapon weapon);
void weapon_delete(int index);
int get_weapon_range(Weapon weapon);
int get_weapon_damage(Weapon weapon);
void print_weapons();
void use_weapon(int index);
void sort_by_range(Weapon weapons[], int size);
int partition(Weapon weapons[], int low, int high);
void quickSort(Weapon weapons[], int low, int high);
void sort_by_range(Weapon weapons[], int size);
void swap(Weapon* a, Weapon* b);