#include <stdio.h>
#include "weapon.h"


int main() {
    //-----
    // 초기 무기 설정
    initialize_weapons();

    // 무작위로 5개의 무기 추가
    add_random_weapons();
    //-----초기 세팅이라 이 위는 필수
    
    // 무기 목록 출력
    print_weapons();
    
    // 무기 사용 예시: 첫 번째 무기 사용
    use_weapon(0);

    // 무기 목록 출력
    print_weapons();

    // 무기 삭제 예시: 세 번째 무기 삭제
    weapon_delete(2);

    // 무기 목록 출력
    print_weapons();

    // 무기를 사거리를 기준으로 정렬
    sort_by_range(selectedWeapons, numSelectedWeapons);

    // 정렬된 무기 목록 출력
    print_weapons();

    return 0;
}
