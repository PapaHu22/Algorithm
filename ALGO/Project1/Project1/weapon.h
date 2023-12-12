#pragma once

typedef struct {
    char* name;
    int range;
    int durability;
    int damage; 
} Weapon;
//다른 c파일 공유안되서 찾아보니 extern사용하면 된다더라
extern Weapon selectedWeapons[];
extern int numSelectedWeapons;
extern Weapon allWeapons[];

void weapon_add(Weapon weapon);
void weapon_delete(int index);
void print_weapons();
void use_weapon(int index);
void sort_by_range(Weapon weapons[], int size);