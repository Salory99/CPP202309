#include "user.h"

void User::IncreaseHP(int inc_hp) { hp += inc_hp; }  // hp 증가

void User::DecreaseHP(int dec_hp) { hp -= dec_hp; }  // hp 감소

int User::GetHP() { return hp; }  // hp 단순 출력용

void User::SetHP() { hp = 20; }  // hp 한계치설정용

void User::FluUserLocation(int x, int y) {
  user_x += x;
  user_y += y;
}

void User::SetUserLocation(int x, int y) {
  user_x = x;
  user_y = y;
}

int User::GetUserX() { return user_x; }
int User::GetUserY() { return user_y; }

void User::DoAttack() { cout << "공격합니다" << endl; }

string User::CallUserClass() {
  string k = "유저 : ";
  return k;
}

string Magician::CallUserClass() {
  User::CallUserClass();
  string k = "마법사";
  return k;
}

void Magician::DoAttack() {
  User::DoAttack();
  cout << "마법 사용" << endl;
}

string Warrior::CallUserClass() {
  User::CallUserClass();
  string k = "전사";
  return k;
}

void Warrior::DoAttack() {
  User::DoAttack();
  cout << "베기 사용" << endl;
}