#include <iostream>
using namespace std;

int main()
{
	const int numCell = 3;
	char board[numCell][numCell]{};
	int x, y;
	// 여기서는 셀 수의 크기를 나타내는 상수 및 x, y좌표 변수와 이차원 배열을 정의한다.
	// x, y좌표는 사용자로부터 입력받는다.

	// 보드판 초기화
	for (x = 0; x < numCell; x++)
	{
		for (y = 0; y < numCell; y++)
		{
			board[x][y] = ' ';
		}
	}
	// 여기서는 board[x][y]의 값을 공란으로 초기화해주기 위한 이중 for문이다.


	// 초기값 설정
	int k = 0;
	char currentUser = 'X';
	// k값은 회차를 의미한다. 초기값은 0이다.
	// currentUser의 기본값은 X이기에 X가 먼저 시작한다.

	// While문 무한반복
	while (true) // 이 while문은 break로 빠져나오지 않는 이상 무한 반복이다.
	{
		// 누구 차례인지 출력
		switch (k % 2)
		{
		case 0:
			cout << k % 2 + 1 << "번 유저(X)의 차례입니다 -> ";
			currentUser = 'X';
			break;
		case 1:
			cout << k % 2 + 1 << "번 유저(O)의 차례입니다 -> ";
			currentUser = 'O';
			break;
		}
		// 여기서는 유저의 차례를 서술하고 있다.
		// 유저의 번호는 k값을 2로 나눈 나머지에 1을 더한 값으로 출력되도록 한다.


		// 좌표 입력 받기
		cout << "(x, y) 좌표를 입력하세요 : ";
		cin >> x >> y;
		// 여기서는 x와 y값을 받는다.


		// 좌표 유효성 체크
		if (x >= numCell || y >= numCell)
		{
			cout << x << ", " << y << ": ";
			cout << " x와 y 둘 중 하나가 칸을 벗어납니다." << endl;
			continue;
		}
		// numCell은 3으로 지정되어 있고, 좌표값은 0, 1, 2만 존재하기에
		// 3을 넘는 값은 해당 문구를 출력하고 게임이 계속된다.
		if (board[x][y] != ' ')
		{
			cout << x << ", " << y << "이미 돌이 차 있습니다." << endl;
			continue;
		}
		// 이 부분은 해당 지점에 이미 돌이 차 있을 때 다시 놓을 수 없을 때이다.
		// 이는 board[x][y]가 공란이 아님을 확인한 뒤 해당 문구를 출력하고 계속한다.


		// 입력받은 좌표에 현재 유저의 돌 놓기
		board[x][y] = currentUser;


		// 보드 판 출력기
		for (int i = 0; i < numCell; i++)
		{
			cout << "---|---|---" << endl;
			for (int j = 0; j < numCell; j++)
			{
				cout << board[i][j];
				if (j == numCell - 1)
				{
					break;
				}
				cout << "  |";
			}
			cout << endl;
		}
		cout << "---|---|---" << endl;
		// 여기서는 맵을 출력한다. 맵은 현재 상태를 그대로 출력시켜 준다.
		// 이중 for문에서는 벽과 구분선을 출력하고 있다.
		// board[i][j]은 현재 값이 차 있으면(누군가가 값을 넣었으면) 출력되며
		// 공란만 들어있을 경우에는 공란이 그대로 출력된다.


		// 승리 변수
		bool isOwin = false;
		bool isXwin = false;

		// 세로 승리 판독기
		for (int j = 0; j < numCell; j++)
		{
			int colOscore = 0;
			int colXscore = 0;
			for (int i = 0; i < numCell; i++)
			{
				if (board[i][j] == 'O')
				{
					colOscore++;
					if (colOscore == numCell)
					{
						cout << "세로에 모두 돌이 놓였습니다!: ";
						isOwin = true;
					}
				}
				if (board[i][j] == 'X')
				{
					colXscore++;
					if (colXscore == numCell)
					{
						cout << "세로에 모두 돌이 놓였습니다!: ";
						isXwin = true;
					}
				}
			}
		}

		// 가로 승리 판독기
		for (int i = 0; i < numCell; i++)
		{
			int rowOscore = 0;
			int rowXscore = 0;
			for (int j = 0; j < numCell; j++)
			{
				if (board[i][j] == 'O')
				{
					rowOscore++;
					if (rowOscore == numCell)
					{
						cout << "가로에 모두 돌이 놓였습니다!: ";
						isOwin = true;
					}
				}
				if (board[i][j] == 'X')
				{
					rowXscore++;
					if (rowXscore == numCell)
					{
						cout << "가로에 모두 돌이 놓였습니다!: ";
						isXwin = true;
					}
				}
			}
		}
		// 이 부분은 승패 판독기 기능의 이중 for문이다.
		// row 가로(행) col세로(열)


		// 좌측 대각선 승패 판독기
		int diaLOscore = 0;
		int diaLXscore = 0;
		int diaROscore = 0;
		int diaRXscore = 0;
		for (int i = 0; i < numCell; i++)
		{
			if (board[i][i] == 'O')
			{
				diaLOscore++;
				if (diaLOscore == numCell)
				{
					cout << "왼쪽 대각선에 모두 돌이 놓였습니다!: ";
					isOwin = true;
				}
			}
			if (board[i][i] == 'X')
			{
				diaLXscore++;
				if (diaLXscore == numCell)
				{
					cout << "왼쪽 대각선에 모두 돌이 놓였습니다!: ";
					isXwin = true;
				}
			}
		}

		// 우측 대각선 승패 판독기
		for (int i = 0; i < numCell; i++)
		{
			if (board[i][numCell - 1 - i] == 'O')
			{
				diaROscore++;
				if (diaROscore == numCell)
				{
					cout << "오른쪽 대각선에 모두 돌이 놓였습니다!: ";
					isOwin = true;
				}
			}
			if (board[i][numCell - 1 - i] == 'X')
			{
				diaRXscore++;
				if (diaRXscore == numCell)
				{
					cout << "오른쪽 대각선에 모두 돌이 놓였습니다!: ";
					isXwin = true;
				}
			}
		}
		// 대각선 부분에 해당하는 항은
		// (0,0), (1,1), (2,2), (2,0), (0,2)의 다섯 곳이다.
		// 이곳의 승패를 판독하기 위해서인데, 일반적으로 좌측 대각선의 좌표는
		// x와 y가 같게 되어 있다.
		// 하지만 우측 대각선의 경우는 전혀 다르기에, 다른 방식으로 해야 한다.

		// 승리 문구 및 반복문 탈출기
		if (isOwin == true)
		{
			cout << k % 2 + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
			cout << "종료합니다." << endl;
			break;
		}
		if (isXwin == true)
		{
			cout << k % 2 + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
			cout << "종료합니다." << endl;
			break;
		}
		// 이 부분은 승패 시에 반복문 탈출을 위한 부분이다.
		// O건 X건 한쪽이 이기면 break문으로 반복문을 탈출한다.

		// 꽉 찼는지 여부 확인기
		int full = 0;
		for (int i = 0; i < numCell; i++)
		{
			for (int j = 0; j < numCell; j++)
			{
				if (board[i][j] != ' ')
				{
					full++;
				}
			}
		}
		if (full == numCell * numCell)
		{
			cout << "모든 칸이 다 찼습니다. 종료합니다." << endl;
			break;
		}
		k++;
		// 이 부분은 모든 칸이 찼는지 검증을 위한 이중 for문이다.
		// 검증 결과 9칸 모두가 차면 break를 통해 while문을 빠져나온다.
		// 이게 작동하면 결과적으로 승자 없이 게임이 종료된다.
		// 이 부분을 마지막에 두는 이유는 마지막에도 승자가 결정될 수 있기 때문이다.
		// 마지막의 k++는 회차 종료 카운트이다.
	}
	return 0;
}
