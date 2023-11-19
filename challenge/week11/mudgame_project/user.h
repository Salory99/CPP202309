#pragma once
#include <iostream>
#include <string>
using namespace std;

class User {
 private:
  int hp;

 public:
  User() {}
  User(int default_hp) { hp = default_hp; } // 생성자 초기화
  void IncreaseHP(int inc_hp);
  void DecreaseHP(int dec_hp);
  int GetHP();
  void SetHP();
};