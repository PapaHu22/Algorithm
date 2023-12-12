#include <stdio.h>
#include "weapon.h"


int main() {
    //-----
    // �ʱ� ���� ����
    initialize_weapons();

    // �������� 5���� ���� �߰�
    add_random_weapons();
    //-----�ʱ� �����̶� �� ���� �ʼ�
    
    // ���� ��� ���
    print_weapons();
    
    // ���� ��� ����: ù ��° ���� ���
    use_weapon(0);

    // ���� ��� ���
    print_weapons();

    // ���� ���� ����: �� ��° ���� ����
    weapon_delete(2);

    // ���� ��� ���
    print_weapons();

    // ���⸦ ��Ÿ��� �������� ����
    sort_by_range(selectedWeapons, numSelectedWeapons);

    // ���ĵ� ���� ��� ���
    print_weapons();

    return 0;
}
