#include <iostream>
using namespace std;

const int NUM_CELL = 3;  // 보드판의 가로 세로 길이
bool IsValid(char board[][NUM_CELL], int x, int y);
bool CheckWin(char board[][NUM_CELL], char current_user);

int main() {
  // 게임을 진행하는 데 필요한 변수 선언
  int k = 0;                // 누구 차례인지 체크하기 위한 변수
  char current_user = 'X';  // 현재 유저의 돌을 저장하기 위한 변수
  char board[NUM_CELL][NUM_CELL]{};  // 보드판을 나타내는 2차원 배열
  int x, y = 0;  // 사용자에게 xy좌표값을 입력받기 위한 변수

  // 보드판 초기화
  for (int i = 0; i < NUM_CELL; i++) {
    for (int j = 0; j < NUM_CELL; j++) {
      board[i][j] = ' ';
    }
  }

  // 게임을 무한 반복
  while (true) {
    // 1. 누구 차례인지 출력
    // TODO 1.1: 3인용 게임으로 변경
    switch (k % 3) {
      case 0:
        current_user = 'X';
        break;
      case 1:
        current_user = 'O';
        break;
      case 2:
        current_user = 'H';
        break;
    }
    cout << k % 3 + 1 << "번 유저(" << current_user << ")의 차례입니다. -> ";

    // 2. 좌표 입력 받기
    cout << "(x, y) 좌표를 입력하세요: ";
    int x, y;
    cin >> x >> y;

    // 3. 입력받은 좌표의 유효성 체크
    // TODO FUNC 1: isValid 함수 생성 후 호출
    if (IsValid(board, x, y) == false) {
      continue;
    }

    // 4. 입력받은 좌표에 현재 유저의 돌 놓기
    board[x][y] = current_user;

    // 5. 현재 보드 판 출력
    // TODO 1.2: numCell 숫자에 맞춘 보드판 출력
    for (int i = 0; i < NUM_CELL; i++) {
      for (int a = 0; a < NUM_CELL - 1; a++) cout << "---|";
      cout << "---" << endl;
      for (int j = 0; j < NUM_CELL; j++) {
        cout << board[i][j];
        if (j == NUM_CELL - 1) {
          break;
        }
        cout << "  |";
      }
      cout << endl;
    }
    for (int a = 0; a < NUM_CELL - 1; a++) cout << "---|";
    cout << "---" << endl;

    bool isWin = CheckWin(board, current_user);
    ;  // 승리 여부 결정
    // TODO FUNC2: 6.1부터 6.2까지 checkWin 함수 생성 후 호출
    // 6.1. 가로/세로 돌 체크하기
    // 6.2. 대각선을 체크하기
    // TODO 1.3: numCell에 맞춘 대각선 빙고 체크 코드로 확장
    // HINT: for 문
    // 6.1, 6.2 이 부분은 checkWin으로 대체됨.

    // 승리자가 결정되었으면 해당 플레이어를 출력하고 게임을 종료한다.
    if (isWin == true) {
      cout << k % 3 + 1 << "번 유저(" << current_user << ")의 승리입니다!"
           << endl;
      // 유저 번호 수정 완료
      break;
    }

    // 7. 모든 칸 다 찼는지 체크하기
    int checked = 0;
    for (int i = 0; i < NUM_CELL; i++) {
      for (int j = 0; j < NUM_CELL; j++) {
        if (board[i][j] == ' ') {
          checked++;
        }
      }
    }
    if (checked == 0) {
      cout << "모든 칸이 다 찼습니다.  종료합니다. " << endl;
      break;
    }

    k++;
  }

  return 0;
}

bool IsValid(char board[][NUM_CELL], int x, int y) {
  if (x >= NUM_CELL || y >= NUM_CELL || x < 0 || y < 0) {
    cout << x << "," << y << ": 좌표가 범위를 벗어났습니다." << endl;
    return false;
  }
  if (board[x][y] != ' ') {
    cout << x << "," << y << ": 이미 돌이 놓여있습니다." << endl;
    return false;
  }
  return true;
}

bool CheckWin(char board[][NUM_CELL], char current_user) {
  // 가로, 세로 체크
  bool rowWin = true;
  bool colWin = true;
  for (int i = 0; i < NUM_CELL; i++) {
    for (int j = 0; j < NUM_CELL; j++) {
      if (board[i][j] != current_user) {
        rowWin = false;
      }
      if (board[j][i] != current_user) {
        colWin = false;
      }
    }
  }
  if (rowWin == true) {
    cout << "가로에 모두 돌이 놓였습니다!!" << endl;
  }
  if (colWin == true) {
    cout << "세로에 모두 돌이 놓였습니다!!" << endl;
  }
  if (rowWin || colWin) return true;

  // 대각선 체크
  bool diag1Win = true;
  bool diag2Win = true;
  for (int i = 0; i < NUM_CELL; i++) {
    if (board[i][i] != current_user) {
      diag1Win = false;
    }
    if (board[i][NUM_CELL - i - 1] != current_user) {
      diag2Win = false;
    }
  }
  if (diag1Win == true) {
    cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
  }
  if (diag2Win == true) {
    cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
  }
  return diag1Win || diag2Win;
}