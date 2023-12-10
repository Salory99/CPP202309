#include "user.h"

void User::IncreaseHP(int inc_hp) { hp += inc_hp; }  // hp ����

void User::DecreaseHP(int dec_hp) { hp -= dec_hp; }  // hp ����

int User::GetHP() { return hp; }  // hp �ܼ� ��¿�

void User::SetHP() { hp = 20; }  // hp �Ѱ�ġ������

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

void User::DoAttack() { cout << "�����մϴ�" << endl; }

string User::CallUserClass() {
  string k = "���� : ";
  return k;
}

string Magician::CallUserClass() {
  User::CallUserClass();
  string k = "������";
  return k;
}

void Magician::DoAttack() {
  User::DoAttack();
  cout << "���� ���" << endl;
}

string Warrior::CallUserClass() {
  User::CallUserClass();
  string k = "����";
  return k;
}

void Warrior::DoAttack() {
  User::DoAttack();
  cout << "���� ���" << endl;
}