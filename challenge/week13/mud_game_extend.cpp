#include <iostream>
#include <string>

#include "user.h"
using namespace std;

// ��� ����
const int MAP_X = 5;
const int MAP_Y = 5;
const int DEFAULT_HP = 20;

// ���� ����
bool ongoing = true;  // �� bool�� ������ ���������� ���θ� Ȯ��. �⺻�� true.
bool debug_mod = false;  // �� bool�� ����� ��� ���¸� Ȯ��. �⺻�� false.
int k = 0;               // ���� �� ǥ���
bool not_change_turn = false;  // ���� �ٲ��� �ʴ� ��Ȳ�� ���� ��
bool magician_dead = false;    // ���� ǥ��
bool warrior_dead = false;

// ����� ���� �Լ�
bool CheckXY(int user_x, int mapX, int user_y, int mapY);
void DisplayMap(int map[][MAP_X], Magician my_user, Warrior my_user2);
bool CheckGoal(int map[][MAP_X], int user_x, int user_y);
void CheckState(int map[][MAP_X], int user_x, int user_y, User* current_user);
void DebugMod(int map[][MAP_X], int user_x, int user_y);
void HealthCare(User* current_user);
bool CheckUser(Magician my_user, Warrior my_user2);

// ����  �Լ�
int main() {
  Magician my_user(20);
  Warrior my_user2(20);
  User* users[2];  // UserŬ������ ��ü�� �迭�� ����

  users[0] = &my_user;   // Magician ��ü�� �迭�� ����
  users[1] = &my_user2;  // Warrior ��ü�� �迭�� ����

  // 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
  int map[MAP_Y][MAP_X] = {{0, 1, 2, 0, 4},
                           {1, 0, 0, 2, 0},
                           {0, 0, 0, 0, 0},
                           {0, 2, 3, 0, 0},
                           {3, 0, 0, 0, 0}};

  // ������ ��ġ�� ������ ����
  users[0]->SetUserLocation(0, 0);
  users[1]->SetUserLocation(4, 4);

  // ���� ����
  while (ongoing == true) {  // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����

    // ���� �ٲٱ� �κ�
    if (not_change_turn == false && magician_dead == false &&
        warrior_dead == false) {
      k = (k + 1) % 2;  // ���� ���� ��
    } else if (not_change_turn == true) {
      not_change_turn = false;
    } else if (magician_dead == true) {
      k = 1;
    } else if (warrior_dead == true) {
      k = 0;
    }

    // ������� �Է��� ������ ����
    string user_input = "";

    if (debug_mod == true) {
      DebugMod(map, users[k]->GetUserX(), users[k]->GetUserY());
    }
    cout << "���� �÷��̾�� " << users[k]->CallUserClass() << "�Դϴ�."
         << endl;
    cout << "HP = " << users[k]->GetHP() << endl;
    cout << "��ɾ �Է��ϼ��� (��,��,��,��,����,����,�����): ";
    cin >> user_input;

    if (user_input == "��") {
      // ���� �� ĭ �ö󰡱�
      users[k]->FluUserLocation(0, -1);
      bool inMap =
          CheckXY(users[k]->GetUserX(), MAP_X, users[k]->GetUserY(), MAP_Y);
      if (inMap == false) {
        cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
        users[k]->FluUserLocation(0, 1);
        not_change_turn = true;
      } else {
        cout << "���� �� ĭ �ö󰩴ϴ�." << endl;
        DisplayMap(map, my_user, my_user2);
        CheckState(map, users[k]->GetUserX(), users[k]->GetUserY(), users[k]);
        users[k]->DecreaseHP(1);
      }
    } else if (user_input == "��") {
      // TODO: �Ʒ��� �� ĭ ��������
      users[k]->FluUserLocation(0, 1);
      bool inMap =
          CheckXY(users[k]->GetUserX(), MAP_X, users[k]->GetUserY(), MAP_Y);
      if (inMap == false) {
        cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
        users[k]->FluUserLocation(0, -1);
        not_change_turn = true;
      } else {
        cout << "���� �� ĭ �������ϴ�." << endl;
        DisplayMap(map, my_user, my_user2);
        CheckState(map, users[k]->GetUserX(), users[k]->GetUserY(), users[k]);
        users[k]->DecreaseHP(1);
      }
    } else if (user_input == "��") {
      // TODO: �������� �̵��ϱ�
      users[k]->FluUserLocation(-1, 0);
      bool inMap =
          CheckXY(users[k]->GetUserX(), MAP_X, users[k]->GetUserY(), MAP_Y);

      if (inMap == false) {
        cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
        users[k]->FluUserLocation(1, 0);
        not_change_turn = true;
      } else {
        cout << "�������� �̵��մϴ�." << endl;
        DisplayMap(map, my_user, my_user2);
        CheckState(map, users[k]->GetUserX(), users[k]->GetUserY(), users[k]);
        users[k]->DecreaseHP(1);
      }
    } else if (user_input == "��") {
      // TODO: ���������� �̵��ϱ�
      users[k]->FluUserLocation(1, 0);
      bool inMap =
          CheckXY(users[k]->GetUserX(), MAP_X, users[k]->GetUserY(), MAP_Y);
      if (inMap == false) {
        cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
        users[k]->FluUserLocation(-1, 0);
        not_change_turn = true;
      } else {
        cout << "���������� �̵��մϴ�." << endl;
        DisplayMap(map, my_user, my_user2);
        CheckState(map, users[k]->GetUserX(), users[k]->GetUserY(), users[k]);
        users[k]->DecreaseHP(1);
      }
    } else if (user_input == "����") {
      // TODO: ���� �����ֱ� �Լ� ȣ��
      DisplayMap(map, my_user, my_user2);
      not_change_turn = true;
    } else if (user_input == "����") {
      cout << "�����մϴ�.";
      break;
    } else if (user_input == "�����" && debug_mod == false) {
      cout << "����� ��� on" << endl;
      debug_mod = true;
      not_change_turn = true;
    } else if (user_input == "�����" && debug_mod == true) {
      cout << "����� ��� off" << endl;
      debug_mod = false;
      not_change_turn = true;
    } else {
      cout << "�߸��� �Է��Դϴ�." << endl;
      not_change_turn = true;
      continue;
    }

    // �������� �����ߴ��� üũ
    bool finish = CheckGoal(map, users[k]->GetUserX(), users[k]->GetUserY());
    if (finish == true) {
      cout << users[k]->CallUserClass()
           << "�� �������� �����߽��ϴ�! �����մϴ�!" << endl;
      cout << "������ �����մϴ�." << endl;
      break;
    }
    HealthCare(users[k]);  // ���� �� �κ��� �ִ� ü�� ���� �κи� ���� ����.
    ongoing =
        CheckUser(my_user, my_user2);  // ���� �� �κ��� ���� ���θ� �Ǵ���.
  }
  return 0;
}

// ������ ����� ��ġ ����ϴ� �Լ�
void DisplayMap(int map[][MAP_X], Magician my_user, Warrior my_user2) {
  for (int i = 0; i < MAP_Y; i++) {
    for (int j = 0; j < MAP_X; j++) {
      if (i == my_user.GetUserY() && j == my_user.GetUserX() &&
          magician_dead == false) {
        cout << " MAGI |";  // �� �� 1ĭ ����
      } else if (i == my_user2.GetUserY() && j == my_user2.GetUserX() &&
                 warrior_dead == false) {
        cout << " WARR |";
      } else {
        int pos_state = map[i][j];
        switch (pos_state) {
          case 0:
            cout << "      |";  // 6ĭ ����
            break;
          case 1:
            cout << "������|";
            break;
          case 2:
            cout << "  ��  |";  // �� �� 2ĭ ����
            break;
          case 3:
            cout << " ���� |";  // �� �� 1ĭ ����
            break;
          case 4:
            cout << "������|";
            break;
        }
      }
    }
    cout << endl;
    cout << " -------------------------------- " << endl;
  }
}

// �̵��Ϸ��� ���� ��ȿ�� ��ǥ���� üũ�ϴ� �Լ�
bool CheckXY(int user_x, const int MAP_X, int user_y, const int MAP_Y) {
  bool checkFlag = false;
  if (user_x >= 0 && user_x < MAP_X && user_y >= 0 && user_y < MAP_Y) {
    checkFlag = true;
  }
  return checkFlag;
}

// ������ ��ġ�� ���������� üũ�ϴ� �Լ�
bool CheckGoal(int map[][MAP_X], int user_x, int user_y) {
  // ������ �����ϸ�
  if (map[user_y][user_x] == 4) {
    return true;
  }
  return false;
}

// ������Ʈ�� �������� ���θ� checkStateȣ��� ����.
// �䱸 ��ɿ� ���� ������Ʈ ���� ��� ����. ���� int���� void�� �Լ���
// �ٲپ���.
void CheckState(int map[][MAP_X], int user_x, int user_y, User* current_user) {
  // ������ ������ ����
  if (map[user_y][user_x] == 1) {
    cout << current_user->CallUserClass() << "�� �������� �Ծ����ϴ�." << endl;
  }
  // ���� ����ġ�� HP -2
  else if (map[user_y][user_x] == 2) {
    cout << current_user->CallUserClass() << "�� ���� �����ƽ��ϴ�." << endl;
    cout << "ü���� 2��ŭ �ҽ��ϴ�." << endl;
    current_user->DoAttack();
    current_user->DecreaseHP(2);
  }
  // ������ ������ HP +2
  else if (map[user_y][user_x] == 3) {
    cout << current_user->CallUserClass()
         << "�� ������ �԰� ü���� 2��ŭ ȸ���մϴ�." << endl;
    current_user->IncreaseHP(2);
    ;
  } else {
  }
}

// ü�� ���� �κ�
void HealthCare(User* current_user) {
  // �ִ� ü�� 20 ����
  if (current_user->GetHP() > 20) {
    current_user->SetHP();
  }
}

bool CheckUser(Magician my_user, Warrior my_user2) {
  // �� ���� ��ΰ� hp�� 0�� �� �� ���� ����
  if (my_user.GetHP() <= 0 && my_user2.GetHP() <= 0) {
    cout << "��� ������ ����߽��ϴ�." << endl;
    cout << "������ �����մϴ�," << endl;
    return false;
  } else if (my_user.GetHP() <= 0 &&
             magician_dead == false) {  // �� ������ ����ϸ� �������� ���� ����
    cout << "�����簡 ����߽��ϴ�." << endl;
    magician_dead = true;
    return true;
  } else if (my_user2.GetHP() <= 0 && warrior_dead == false) {
    cout << "���簡 ����߽��ϴ�." << endl;
    warrior_dead = true;
    return true;
  } else
    return true;
}

// ����׸� ���� �κ�
void DebugMod(int map[][MAP_X], int user_x, int user_y) {
  cout << "user_x : " << user_x << endl;
  cout << "user_y : " << user_y << endl;
  cout << "���� ��ǥ : " << map[user_y][user_x] << endl;
  cout << "��ü �� ��Ȳ : " << endl;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cout << map[i][j];
    }
    cout << " " << endl;
    cout << " -------------------- " << endl;
  }
}