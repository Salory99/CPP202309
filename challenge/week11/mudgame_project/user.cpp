#include "user.h"

void User::IncreaseHP(int inc_hp) { hp += inc_hp; } // hp ����

void User::DecreaseHP(int dec_hp) { hp -= dec_hp; } // hp ����

int User::GetHP() { return hp; } // hp �ܼ� ��¿�

void User::SetHP() { hp = 20; } // hp �Ѱ�ġ������