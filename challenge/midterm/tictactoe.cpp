#include <iostream>
using namespace std;

const int NUM_CELL = 3;  // �������� ���� ���� ����
bool IsValid(char board[][NUM_CELL], int x, int y);
bool CheckWin(char board[][NUM_CELL], char current_user);

int main() {
  // ������ �����ϴ� �� �ʿ��� ���� ����
  int k = 0;                // ���� �������� üũ�ϱ� ���� ����
  char current_user = 'X';  // ���� ������ ���� �����ϱ� ���� ����
  char board[NUM_CELL][NUM_CELL]{};  // �������� ��Ÿ���� 2���� �迭
  int x, y = 0;  // ����ڿ��� xy��ǥ���� �Է¹ޱ� ���� ����

  // ������ �ʱ�ȭ
  for (int i = 0; i < NUM_CELL; i++) {
    for (int j = 0; j < NUM_CELL; j++) {
      board[i][j] = ' ';
    }
  }

  // ������ ���� �ݺ�
  while (true) {
    // 1. ���� �������� ���
    // TODO 1.1: 3�ο� �������� ����
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
    cout << k % 3 + 1 << "�� ����(" << current_user << ")�� �����Դϴ�. -> ";

    // 2. ��ǥ �Է� �ޱ�
    cout << "(x, y) ��ǥ�� �Է��ϼ���: ";
    int x, y;
    cin >> x >> y;

    // 3. �Է¹��� ��ǥ�� ��ȿ�� üũ
    // TODO FUNC 1: isValid �Լ� ���� �� ȣ��
    if (IsValid(board, x, y) == false) {
      continue;
    }

    // 4. �Է¹��� ��ǥ�� ���� ������ �� ����
    board[x][y] = current_user;

    // 5. ���� ���� �� ���
    // TODO 1.2: numCell ���ڿ� ���� ������ ���
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
    ;  // �¸� ���� ����
    // TODO FUNC2: 6.1���� 6.2���� checkWin �Լ� ���� �� ȣ��
    // 6.1. ����/���� �� üũ�ϱ�
    // 6.2. �밢���� üũ�ϱ�
    // TODO 1.3: numCell�� ���� �밢�� ���� üũ �ڵ�� Ȯ��
    // HINT: for ��
    // 6.1, 6.2 �� �κ��� checkWin���� ��ü��.

    // �¸��ڰ� �����Ǿ����� �ش� �÷��̾ ����ϰ� ������ �����Ѵ�.
    if (isWin == true) {
      cout << k % 3 + 1 << "�� ����(" << current_user << ")�� �¸��Դϴ�!"
           << endl;
      // ���� ��ȣ ���� �Ϸ�
      break;
    }

    // 7. ��� ĭ �� á���� üũ�ϱ�
    int checked = 0;
    for (int i = 0; i < NUM_CELL; i++) {
      for (int j = 0; j < NUM_CELL; j++) {
        if (board[i][j] == ' ') {
          checked++;
        }
      }
    }
    if (checked == 0) {
      cout << "��� ĭ�� �� á���ϴ�.  �����մϴ�. " << endl;
      break;
    }

    k++;
  }

  return 0;
}

bool IsValid(char board[][NUM_CELL], int x, int y) {
  if (x >= NUM_CELL || y >= NUM_CELL || x < 0 || y < 0) {
    cout << x << "," << y << ": ��ǥ�� ������ ������ϴ�." << endl;
    return false;
  }
  if (board[x][y] != ' ') {
    cout << x << "," << y << ": �̹� ���� �����ֽ��ϴ�." << endl;
    return false;
  }
  return true;
}

bool CheckWin(char board[][NUM_CELL], char current_user) {
  // ����, ���� üũ
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
    cout << "���ο� ��� ���� �������ϴ�!!" << endl;
  }
  if (colWin == true) {
    cout << "���ο� ��� ���� �������ϴ�!!" << endl;
  }
  if (rowWin || colWin) return true;

  // �밢�� üũ
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
    cout << "���� ������ ������ �Ʒ� �밢������ ��� ���� �������ϴ�!" << endl;
  }
  if (diag2Win == true) {
    cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� �������ϴ�!" << endl;
  }
  return diag1Win || diag2Win;
}