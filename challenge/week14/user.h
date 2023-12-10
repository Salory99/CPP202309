#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class User {
 protected:
  int hp = 20;
  int user_x = 0;
  int user_y = 0;

 public:
  User() {}
  User(int default_hp) { hp = default_hp; }  // 생성자 초기화
  void IncreaseHP(int inc_hp);
  void DecreaseHP(int dec_hp);
  int GetHP();
  void SetHP();
  void FluUserLocation(int x, int y);
  void SetUserLocation(int x, int y);
  int GetUserX();
  int GetUserY();
  virtual void DoAttack();
  virtual string CallUserClass();
};

class Magician : public User {
 public:
  Magician(int default_hp) { hp = default_hp; }
  void DoAttack() override;
  string CallUserClass() override;
};

class Warrior : public User {
 public:
  Warrior(int default_hp) { hp = default_hp; }
  void DoAttack() override;
  string CallUserClass() override;
};