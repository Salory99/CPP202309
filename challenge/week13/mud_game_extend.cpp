#include <iostream>
#include <string>

#include "user.h"
using namespace std;

// 상수 선언
const int MAP_X = 5;
const int MAP_Y = 5;
const int DEFAULT_HP = 20;

// 변수 선언
bool ongoing = true;  // 이 bool은 게임이 진행중인지 여부를 확인. 기본값 true.
bool debug_mod = false;  // 이 bool은 디버그 모드 상태를 확인. 기본값 false.
int k = 0;               // 현재 턴 표사기
bool not_change_turn = false;  // 턴이 바뀌지 않는 상황을 위한 것
bool magician_dead = false;    // 죽음 표시
bool warrior_dead = false;

// 사용자 정의 함수
bool CheckXY(int user_x, int mapX, int user_y, int mapY);
void DisplayMap(int map[][MAP_X], Magician my_user, Warrior my_user2);
bool CheckGoal(int map[][MAP_X], int user_x, int user_y);
void CheckState(int map[][MAP_X], int user_x, int user_y, User* current_user);
void DebugMod(int map[][MAP_X], int user_x, int user_y);
void HealthCare(User* current_user);
bool CheckUser(Magician my_user, Warrior my_user2);

// 메인  함수
int main() {
  Magician my_user(20);
  Warrior my_user2(20);
  User* users[2];  // User클래스의 객체를 배열에 넣음

  users[0] = &my_user;   // Magician 객체를 배열에 저장
  users[1] = &my_user2;  // Warrior 객체를 배열에 저장

  // 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
  int map[MAP_Y][MAP_X] = {{0, 1, 2, 0, 4},
                           {1, 0, 0, 2, 0},
                           {0, 0, 0, 0, 0},
                           {0, 2, 3, 0, 0},
                           {3, 0, 0, 0, 0}};

  // 유저의 위치를 저장할 변수
  users[0]->SetUserLocation(0, 0);
  users[1]->SetUserLocation(4, 4);

  // 게임 시작
  while (ongoing == true) {  // 사용자에게 계속 입력받기 위해 무한 루프

    // 차례 바꾸기 부분
    if (not_change_turn == false && magician_dead == false &&
        warrior_dead == false) {
      k = (k + 1) % 2;  // 전사 선제 턴
    } else if (not_change_turn == true) {
      not_change_turn = false;
    } else if (magician_dead == true) {
      k = 1;
    } else if (warrior_dead == true) {
      k = 0;
    }

    // 사용자의 입력을 저장할 변수
    string user_input = "";

    if (debug_mod == true) {
      DebugMod(map, users[k]->GetUserX(), users[k]->GetUserY());
    }
    cout << "현재 플레이어는 " << users[k]->CallUserClass() << "입니다."
         << endl;
    cout << "HP = " << users[k]->GetHP() << endl;
    cout << "명령어를 입력하세요 (상,하,좌,우,지도,종료,디버그): ";
    cin >> user_input;

    if (user_input == "상") {
      // 위로 한 칸 올라가기
      users[k]->FluUserLocation(0, -1);
      bool inMap =
          CheckXY(users[k]->GetUserX(), MAP_X, users[k]->GetUserY(), MAP_Y);
      if (inMap == false) {
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
        users[k]->FluUserLocation(0, 1);
        not_change_turn = true;
      } else {
        cout << "위로 한 칸 올라갑니다." << endl;
        DisplayMap(map, my_user, my_user2);
        CheckState(map, users[k]->GetUserX(), users[k]->GetUserY(), users[k]);
        users[k]->DecreaseHP(1);
      }
    } else if (user_input == "하") {
      // TODO: 아래로 한 칸 내려가기
      users[k]->FluUserLocation(0, 1);
      bool inMap =
          CheckXY(users[k]->GetUserX(), MAP_X, users[k]->GetUserY(), MAP_Y);
      if (inMap == false) {
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
        users[k]->FluUserLocation(0, -1);
        not_change_turn = true;
      } else {
        cout << "위로 한 칸 내려갑니다." << endl;
        DisplayMap(map, my_user, my_user2);
        CheckState(map, users[k]->GetUserX(), users[k]->GetUserY(), users[k]);
        users[k]->DecreaseHP(1);
      }
    } else if (user_input == "좌") {
      // TODO: 왼쪽으로 이동하기
      users[k]->FluUserLocation(-1, 0);
      bool inMap =
          CheckXY(users[k]->GetUserX(), MAP_X, users[k]->GetUserY(), MAP_Y);

      if (inMap == false) {
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
        users[k]->FluUserLocation(1, 0);
        not_change_turn = true;
      } else {
        cout << "왼쪽으로 이동합니다." << endl;
        DisplayMap(map, my_user, my_user2);
        CheckState(map, users[k]->GetUserX(), users[k]->GetUserY(), users[k]);
        users[k]->DecreaseHP(1);
      }
    } else if (user_input == "우") {
      // TODO: 오른쪽으로 이동하기
      users[k]->FluUserLocation(1, 0);
      bool inMap =
          CheckXY(users[k]->GetUserX(), MAP_X, users[k]->GetUserY(), MAP_Y);
      if (inMap == false) {
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
        users[k]->FluUserLocation(-1, 0);
        not_change_turn = true;
      } else {
        cout << "오른쪽으로 이동합니다." << endl;
        DisplayMap(map, my_user, my_user2);
        CheckState(map, users[k]->GetUserX(), users[k]->GetUserY(), users[k]);
        users[k]->DecreaseHP(1);
      }
    } else if (user_input == "지도") {
      // TODO: 지도 보여주기 함수 호출
      DisplayMap(map, my_user, my_user2);
      not_change_turn = true;
    } else if (user_input == "종료") {
      cout << "종료합니다.";
      break;
    } else if (user_input == "디버그" && debug_mod == false) {
      cout << "디버그 모드 on" << endl;
      debug_mod = true;
      not_change_turn = true;
    } else if (user_input == "디버그" && debug_mod == true) {
      cout << "디버그 모드 off" << endl;
      debug_mod = false;
      not_change_turn = true;
    } else {
      cout << "잘못된 입력입니다." << endl;
      not_change_turn = true;
      continue;
    }

    // 목적지에 도달했는지 체크
    bool finish = CheckGoal(map, users[k]->GetUserX(), users[k]->GetUserY());
    if (finish == true) {
      cout << users[k]->CallUserClass()
           << "가 목적지에 도착했습니다! 축하합니다!" << endl;
      cout << "게임을 종료합니다." << endl;
      break;
    }
    HealthCare(users[k]);  // 현재 이 부분은 최대 체력 제한 부분만 남아 있음.
    ongoing =
        CheckUser(my_user, my_user2);  // 이제 이 부분이 실패 여부를 판단함.
  }
  return 0;
}

// 지도와 사용자 위치 출력하는 함수
void DisplayMap(int map[][MAP_X], Magician my_user, Warrior my_user2) {
  for (int i = 0; i < MAP_Y; i++) {
    for (int j = 0; j < MAP_X; j++) {
      if (i == my_user.GetUserY() && j == my_user.GetUserX() &&
          magician_dead == false) {
        cout << " MAGI |";  // 양 옆 1칸 공백
      } else if (i == my_user2.GetUserY() && j == my_user2.GetUserX() &&
                 warrior_dead == false) {
        cout << " WARR |";
      } else {
        int pos_state = map[i][j];
        switch (pos_state) {
          case 0:
            cout << "      |";  // 6칸 공백
            break;
          case 1:
            cout << "아이템|";
            break;
          case 2:
            cout << "  적  |";  // 양 옆 2칸 공백
            break;
          case 3:
            cout << " 포션 |";  // 양 옆 1칸 공백
            break;
          case 4:
            cout << "목적지|";
            break;
        }
      }
    }
    cout << endl;
    cout << " -------------------------------- " << endl;
  }
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool CheckXY(int user_x, const int MAP_X, int user_y, const int MAP_Y) {
  bool checkFlag = false;
  if (user_x >= 0 && user_x < MAP_X && user_y >= 0 && user_y < MAP_Y) {
    checkFlag = true;
  }
  return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool CheckGoal(int map[][MAP_X], int user_x, int user_y) {
  // 목적지 도착하면
  if (map[user_y][user_x] == 4) {
    return true;
  }
  return false;
}

// 오브젝트를 만났는지 여부를 checkState호출로 구현.
// 요구 기능에 따라 오브젝트 제거 기능 삭제. 따라서 int에서 void로 함수를
// 바꾸었음.
void CheckState(int map[][MAP_X], int user_x, int user_y, User* current_user) {
  // 아이템 먹으면 반응
  if (map[user_y][user_x] == 1) {
    cout << current_user->CallUserClass() << "가 아이템을 먹었습니다." << endl;
  }
  // 적과 마주치면 HP -2
  else if (map[user_y][user_x] == 2) {
    cout << current_user->CallUserClass() << "가 적과 마주쳤습니다." << endl;
    cout << "체력을 2만큼 잃습니다." << endl;
    current_user->DoAttack();
    current_user->DecreaseHP(2);
  }
  // 포션을 먹으면 HP +2
  else if (map[user_y][user_x] == 3) {
    cout << current_user->CallUserClass()
         << "가 포션을 먹고 체력을 2만큼 회복합니다." << endl;
    current_user->IncreaseHP(2);
    ;
  } else {
  }
}

// 체력 관련 부분
void HealthCare(User* current_user) {
  // 최대 체력 20 제한
  if (current_user->GetHP() > 20) {
    current_user->SetHP();
  }
}

bool CheckUser(Magician my_user, Warrior my_user2) {
  // 두 유저 모두가 hp가 0이 될 시 게임 오버
  if (my_user.GetHP() <= 0 && my_user2.GetHP() <= 0) {
    cout << "모든 유저가 사망했습니다." << endl;
    cout << "게임을 종료합니다," << endl;
    return false;
  } else if (my_user.GetHP() <= 0 &&
             magician_dead == false) {  // 한 유저만 사망하면 나머지로 지속 가능
    cout << "마법사가 사망했습니다." << endl;
    magician_dead = true;
    return true;
  } else if (my_user2.GetHP() <= 0 && warrior_dead == false) {
    cout << "전사가 사망했습니다." << endl;
    warrior_dead = true;
    return true;
  } else
    return true;
}

// 디버그를 위한 부분
void DebugMod(int map[][MAP_X], int user_x, int user_y) {
  cout << "user_x : " << user_x << endl;
  cout << "user_y : " << user_y << endl;
  cout << "현재 좌표 : " << map[user_y][user_x] << endl;
  cout << "전체 맵 상황 : " << endl;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cout << map[i][j];
    }
    cout << " " << endl;
    cout << " -------------------- " << endl;
  }
}