#include "user.h"

void User::IncreaseHP(int inc_hp) { hp += inc_hp; } // hp 증가

void User::DecreaseHP(int dec_hp) { hp -= dec_hp; } // hp 감소

int User::GetHP() { return hp; } // hp 단순 출력용

void User::SetHP() { hp = 20; } // hp 한계치설정용