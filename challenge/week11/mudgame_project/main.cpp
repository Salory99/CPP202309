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

// ����� ���� �Լ�
bool CheckXY(int user_x, int mapX, int user_y, int mapY);
void DisplayMap(int map[][MAP_X], int user_x, int user_y);
bool CheckGoal(int map[][MAP_X], int user_x, int user_y);
void CheckState(int map[][MAP_X], int user_x, int user_y, User& my_user);
void DebugMod(int map[][MAP_X], int user_x, int user_y);
void HealthCare(User& my_user);
bool CheckUser(User user);

// ����  �Լ�
int main() {
  User my_user(20);

  // 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
  int map[MAP_Y][MAP_X] = {{0, 1, 2, 0, 4},
                           {1, 0, 0, 2, 0},
                           {0, 0, 0, 0, 0},
                           {0, 2, 3, 0, 0},
                           {3, 0, 0, 0, 2}};

  // ������ ��ġ�� ������ ����
  int user_x = 0;  // ���� ��ȣ
  int user_y = 0;  // ���� ��ȣ

  // ���� ����
  while (ongoing == true) {  // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����

    // ������� �Է��� ������ ����
    string user_input = "";

    if (debug_mod == true) {
      DebugMod(map, user_x, user_y);
    }
    cout << "HP = " << my_user.GetHP() << endl;
    cout << "��ɾ �Է��ϼ��� (��,��,��,��,����,����,�����): ";
    cin >> user_input;

    if (user_input == "��") {
      // ���� �� ĭ �ö󰡱�
      user_y -= 1;
      bool inMap = CheckXY(user_x, MAP_X, user_y, MAP_Y);
      if (inMap == false) {
        cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
        user_y += 1;
      } else {
        cout << "���� �� ĭ �ö󰩴ϴ�." << endl;
        DisplayMap(map, user_x, user_y);
        CheckState(map, user_x, user_y, my_user);
        my_user.DecreaseHP(1);
      }
    } else if (user_input == "��") {
      // TODO: �Ʒ��� �� ĭ ��������
      user_y += 1;
      bool inMap = CheckXY(user_x, MAP_X, user_y, MAP_Y);
      if (inMap == false) {
        cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
        user_y -= 1;
      } else {
        cout << "���� �� ĭ �������ϴ�." << endl;
        DisplayMap(map, user_x, user_y);
        CheckState(map, user_x, user_y, my_user);
        my_user.DecreaseHP(1);
      }
    } else if (user_input == "��") {
      // TODO: �������� �̵��ϱ�
      user_x -= 1;
      bool inMap = CheckXY(user_x, MAP_X, user_y, MAP_Y);

      if (inMap == false) {
        cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
        user_x += 1;
      } else {
        cout << "�������� �̵��մϴ�." << endl;
        DisplayMap(map, user_x, user_y);
        CheckState(map, user_x, user_y, my_user);
        my_user.DecreaseHP(1);
      }
    } else if (user_input == "��") {
      // TODO: ���������� �̵��ϱ�
      user_x += 1;
      bool inMap = CheckXY(user_x, MAP_X, user_y, MAP_Y);
      if (inMap == false) {
        cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
        user_x -= 1;
      } else {
        cout << "���������� �̵��մϴ�." << endl;
        DisplayMap(map, user_x, user_y);
        CheckState(map, user_x, user_y, my_user);
        my_user.DecreaseHP(1);
      }
    } else if (user_input == "����") {
      // TODO: ���� �����ֱ� �Լ� ȣ��
      DisplayMap(map, user_x, user_y);
    } else if (user_input == "����") {
      cout << "�����մϴ�.";
      break;
    } else if (user_input == "�����" && debug_mod == false) {
      cout << "����� ��� on" << endl;
      debug_mod = true;
    } else if (user_input == "�����" && debug_mod == true) {
      cout << "����� ��� off" << endl;
      debug_mod = false;
    } else {
      cout << "�߸��� �Է��Դϴ�." << endl;
      continue;
    }

    // �������� �����ߴ��� üũ
    bool finish = CheckGoal(map, user_x, user_y);
    if (finish == true) {
      cout << "�������� �����߽��ϴ�! �����մϴ�!" << endl;
      cout << "������ �����մϴ�." << endl;
      break;
    }
    HealthCare(my_user);  // ���� �� �κ��� �ִ� ü�� ���� �κи� ���� ����.
    ongoing = CheckUser(my_user);  // ���� �� �κ��� ���� ���θ� �Ǵ���.
  }
  return 0;
}

// ������ ����� ��ġ ����ϴ� �Լ�
void DisplayMap(int map[][MAP_X], int user_x, int user_y) {
  for (int i = 0; i < MAP_Y; i++) {
    for (int j = 0; j < MAP_X; j++) {
      if (i == user_y && j == user_x) {
        cout << " USER |";  // �� �� 1ĭ ����
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
void CheckState(int map[][MAP_X], int user_x, int user_y, User& my_user) {
  // ������ ������ ����
  if (map[user_y][user_x] == 1) {
    cout << "�������� �Ծ����ϴ�." << endl;
  }
  // ���� ����ġ�� HP -2
  else if (map[user_y][user_x] == 2) {
    cout << "���� �����ƽ��ϴ�." << endl;
    cout << "ü���� 2��ŭ �ҽ��ϴ�." << endl;
    my_user.DecreaseHP(2);
  }
  // ������ ������ HP +2
  else if (map[user_y][user_x] == 3) {
    cout << "������ �԰� ü���� 2��ŭ ȸ���մϴ�." << endl;
    my_user.IncreaseHP(2);
    ;
  } else {
  }
}

// ü�� ���� �κ�
void HealthCare(User& my_user) {
  // �ִ� ü�� 20 ����
  if (my_user.GetHP() > 20) {
    my_user.SetHP();
  }
}

bool CheckUser(User my_user) {
  // hp�� 0�� �� �� ���� ����
  if (my_user.GetHP() <= 0) {
    cout << "HP�� �ٴڳ��⿡ �����߽��ϴ�." << endl;
    cout << "������ �����մϴ�," << endl;
    return false;
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