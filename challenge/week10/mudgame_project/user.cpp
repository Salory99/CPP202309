#include "user.h"

void User::DecreaseHP(int dec_hp) {
  hp -= dec_hp;  // 닳을 hp는 양수로, 얻을 hp는 음수로 dec_hp의 값을 넣어줌.
}

int User::GetHP() {
  return hp;  // hp 단순 출력용.
}