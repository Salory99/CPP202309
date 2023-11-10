#pragma once
#include <iostream>
#include <string>
using namespace std;

class User {
 public:  // 단 하나라도 public으로 지정하지 않으면 제대로 작동 안됨.
  int hp;
  void DecreaseHP(int dec_hp);
  int GetHP();
};