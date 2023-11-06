#include <iostream>
#include <string>
using namespace std;

string random_string;
bool CheckNumber(int n1, int user_sel, int& strike, int& ball);

int main() {
  int random_num;  // 맞춰야 하는 3자리수의 숫자 저장 변수
  int user_selection = 0;  // 현재 진행 단계 저장 변수
  int strike = 0;          // 스트라이크 갯수를 저장하는 변수
  int ball = 0;            // 볼 갯수를 저장하는 변수
  bool full_strike = false; // 풀스트라이크 여부 저장 변수

  while (1) {
    random_num = rand() % 900 + 100;  // 랜덤한 3자리수 생성

    bool same = false;  // 모든 수가 다를 경우 true를 갖는 변수

    // TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는
    // 코드블록 작성
    random_string = to_string(random_num);
    same = CheckNumber(random_num, user_selection, strike, ball);
    if (same == true) {
      break;
    }
  }

  int turn = 0;
  while (1) {
    user_selection = 1;
    cout << turn + 1 << "번째 시도입니다. " << endl;

    int user_number;  // 사용자가 입력한 세자리수 저장 변수

    // 사용자에게 세자리 수를 입력받는 코드 블록
    while (1) {
      cout << "세자리 수를 입력해주세요: ";
      cin >> user_number;

      bool same = false;  // 모든 수가 다를 경우 true를 갖는 변수
      // TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는
      // 코드블록 작성
      if (to_string(user_number).length() != 3) {
        cout << "입력된 숫자가 3자리 수가 아닙니다. 다시 입력하세요." << endl;
        continue;
      }
      same = CheckNumber(user_number, user_selection, strike, ball);
      if (same == true) {
        break;
      }
    }

    user_selection = 2;

    // TODO 2: 정답과 추측한 숫자의 자릿수와 숫자를 비교하며 힌트를 주기 위한
    // 코드블록 작성
    full_strike = CheckNumber(user_number, user_selection, strike, ball);
    if (full_strike == true) {
      cout << "정답을 맞췄습니다. 축하합니다.";
      break;
    }
    turn += 1;   // turn횟수 증가
    strike = 0;  // strike 횟수 초기화
    ball = 0;    // ball 횟수 초기화
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
      cout << "입력된 숫자에 중복된 숫자가 있습니다. 다시 입력하세요." << endl;
  } else {
    for (int i = 0; i < 3; i++) {
      if (random_string[i] == str1[i]) {
        // 같은 위치에 같은 숫자가 있는 경우 strike++
        strike++;
      }
      for (int j = 0; j < 3; j++) {
        if (random_string[i] ==
            str1[j])  // 모든 위치에 같은 숫자가 있을 경우 ball++
        {
          ball++;
          if (i == j)  // 만일 그게 스트라이크 위치일 경우 ball--
            ball--;
        }
      }
    }
    if (strike == 3)
      return true;
    else
      cout << n1 << "의 결과 : " << strike << " 스트라이크, " << ball
           << "볼 입니다." << endl;
  }
}