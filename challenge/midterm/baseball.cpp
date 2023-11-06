#include <iostream>
#include <string>
using namespace std;

string random_string;
bool CheckNumber(int n1, int user_sel, int& strike, int& ball);

int main() {
  int random_num;  // ����� �ϴ� 3�ڸ����� ���� ���� ����
  int user_selection = 0;  // ���� ���� �ܰ� ���� ����
  int strike = 0;          // ��Ʈ����ũ ������ �����ϴ� ����
  int ball = 0;            // �� ������ �����ϴ� ����
  bool full_strike = false; // Ǯ��Ʈ����ũ ���� ���� ����

  while (1) {
    random_num = rand() % 900 + 100;  // ������ 3�ڸ��� ����

    bool same = false;  // ��� ���� �ٸ� ��� true�� ���� ����

    // TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ�
    // �ڵ��� �ۼ�
    random_string = to_string(random_num);
    same = CheckNumber(random_num, user_selection, strike, ball);
    if (same == true) {
      break;
    }
  }

  int turn = 0;
  while (1) {
    user_selection = 1;
    cout << turn + 1 << "��° �õ��Դϴ�. " << endl;

    int user_number;  // ����ڰ� �Է��� ���ڸ��� ���� ����

    // ����ڿ��� ���ڸ� ���� �Է¹޴� �ڵ� ���
    while (1) {
      cout << "���ڸ� ���� �Է����ּ���: ";
      cin >> user_number;

      bool same = false;  // ��� ���� �ٸ� ��� true�� ���� ����
      // TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ�
      // �ڵ��� �ۼ�
      if (to_string(user_number).length() != 3) {
        cout << "�Էµ� ���ڰ� 3�ڸ� ���� �ƴմϴ�. �ٽ� �Է��ϼ���." << endl;
        continue;
      }
      same = CheckNumber(user_number, user_selection, strike, ball);
      if (same == true) {
        break;
      }
    }

    user_selection = 2;

    // TODO 2: ����� ������ ������ �ڸ����� ���ڸ� ���ϸ� ��Ʈ�� �ֱ� ����
    // �ڵ��� �ۼ�
    full_strike = CheckNumber(user_number, user_selection, strike, ball);
    if (full_strike == true) {
      cout << "������ ������ϴ�. �����մϴ�.";
      break;
    }
    turn += 1;   // turnȽ�� ����
    strike = 0;  // strike Ƚ�� �ʱ�ȭ
    ball = 0;    // ball Ƚ�� �ʱ�ȭ
  }
  return 0;
}

bool CheckNumber(int n1, int user_sel, int& strike, int& ball) {
  string str1 = to_string(n1);
  char num1 = str1[0];
  char num2 = str1[1];
  char num3 = str1[2];

  if (user_sel == 0) {
    if (num1 != num2 && num1 != num3 && num2 != num3) {
      return true;
    }
  } else if (user_sel == 1) {
    if (num1 != num2 && num1 != num3 && num2 != num3) {
      return true;
    } else
      cout << "�Էµ� ���ڿ� �ߺ��� ���ڰ� �ֽ��ϴ�. �ٽ� �Է��ϼ���." << endl;
  } else {
    for (int i = 0; i < 3; i++) {
      if (random_string[i] == str1[i]) {
        // ���� ��ġ�� ���� ���ڰ� �ִ� ��� strike++
        strike++;
      }
      for (int j = 0; j < 3; j++) {
        if (random_string[i] ==
            str1[j])  // ��� ��ġ�� ���� ���ڰ� ���� ��� ball++
        {
          ball++;
          if (i == j)  // ���� �װ� ��Ʈ����ũ ��ġ�� ��� ball--
            ball--;
        }
      }
    }
    if (strike == 3)
      return true;
    else
      cout << n1 << "�� ��� : " << strike << " ��Ʈ����ũ, " << ball
           << "�� �Դϴ�." << endl;
  }
}