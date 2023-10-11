#include <iostream>
using namespace std;

int main()
{
	const int numCell = 3;
	char board[numCell][numCell]{};
	int x, y;
	// ���⼭�� �� ���� ũ�⸦ ��Ÿ���� ��� �� x, y��ǥ ������ ������ �迭�� �����Ѵ�.

	for (x = 0; x < numCell; x++)
	{
		for (y = 0; y < numCell; y++)
		{
			board[x][y] = ' ';
		}
	}
	// ���⼭�� board[x][y]�� ���� �������� �ʱ�ȭ���ֱ� ���� ���� for���̴�.

	int k = 0;
	char currentUser = 'X';
	// k���� ȸ���� �ǹ��Ѵ�. �ʱⰪ�� 0�̴�.
	// currentUser�� �⺻���� X�̱⿡ X�� ���� �����Ѵ�.

	while (true) // �� while���� break�� ���������� �ʴ� �̻� ���� �ݺ��̴�.
	{
		switch (k % 2)
		{
		case 0:
			cout << k % 2 + 1 << "�� ����(X)�� �����Դϴ� -> ";
			currentUser = 'X';
			break;
		case 1:
			cout << k % 2 + 1 << "�� ����(O)�� �����Դϴ� -> ";
			currentUser = 'O';
			break;
		}
		// ���⼭�� ������ ���ʸ� �����ϰ� �ִ�.
		// ������ ��ȣ�� k���� 2�� ���� �������� 1�� ���� ������ ��µǵ��� �Ѵ�.


		cout << "(x, y) ��ǥ�� �Է��ϼ��� : ";
		cin >> x >> y;
		// ���⼭�� x�� y���� �޴´�.

		if (x >= numCell || y >= numCell)
		{
			cout << x << ", " << y << ": ";
			cout << " x�� y �� �� �ϳ��� ĭ�� ����ϴ�." << endl;
			continue;
		}
		// numCell�� 3���� �����Ǿ� �ְ�, ��ǥ���� 0, 1, 2�� �����ϱ⿡
		// 3�� �Ѵ� ���� �ش� ������ ����ϰ� ������ ��ӵȴ�.

		if (board[x][y] != ' ')
		{
			cout << x << ", " << y << "�̹� ���� �� �ֽ��ϴ�." << endl;
			continue;
		}
		// �� �κ��� �ش� ������ �̹� ���� �� ���� �� �ٽ� ���� �� ���� ���̴�.
		// �̴� board[x][y]�� ������ �ƴ��� Ȯ���� �� �ش� ������ ����ϰ� ����Ѵ�.

		board[x][y] = currentUser;

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
		k++;
		// ���⼭�� ���� ����Ѵ�. ���� ���� ���¸� �״�� ��½��� �ش�.
		// ���� for�������� ���� ���м��� ����ϰ� �ִ�.
		// board[i][j]�� ���� ���� �� ������(�������� ���� �־�����) ��µǸ�
		// ������ ������� ��쿡�� ������ �״�� ��µȴ�.
		// �������� k++�� ȸ�� ���� ī��Ʈ�̴�.

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
		if (full == 9)
		{
			cout << "��� ĭ�� �� á���ϴ�. �����մϴ�." << endl;
			break;
		}
		// �� �κ��� ��� ĭ�� á���� ������ ���� ���� for���̴�.
		// ���� ��� 9ĭ ��ΰ� ���� break�� ���� while���� �������´�.
		// �̰� �۵��ϸ� ��������� ���� ���� ������ ����ȴ�.

		bool isWin = false;

		for (int i = 0; i < numCell; i++)
		{
			if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser)
			{
				cout << "���ο� ��� ���� �������ϴ�!: ";
				isWin = true;
			}
			if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser)
			{
				cout << "���ο� ��� ���� �������ϴ�!: ";
				isWin = true;
			}
		}
		// �� �κ��� �� �����ڷ� ������ ��� �����Ǹ� �¸��� �����ϴ� �κ��̴�.

		if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser)
		{
			cout << "���� ������ ������ �Ʒ� �밢������ ��� ���� �������ϴ�!: ";
			isWin = true;
		}
		if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser)
		{
			cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� �������ϴ�!: ";
			isWin = true;
		}
		// �� �κ��� �� �����ڷ� ������ ��� �����Ǹ� �¸��� �����ϴ� �κ��̴�.

		if (isWin == true)
		{
			cout << k % 2 + 1 << "�� ����(" << currentUser << ")�� �¸��Դϴ�!" << endl;
			cout << "�����մϴ�." << endl;
			break;
		}
		// �� �κ��� ���ڰ� �����Ǹ� break���� ���ؼ� while���� ���������� �κ��̴�.
		


		// ���� �κ��� ����� �������� �κ� �����Դϴ�.

		/*
		for (int i = 0; i < numCell; i++)
		{
			if (i == 0 || i == 2)
			{
				for (int j = 0; j < numCell; j++)
				{
					int colOscore = 0;
					int colXscore = 0;
					if (board[i][j] == 'O')
					{
						colOscore++;
						if (colOscore == 3)
						{
							cout << "���ο� ��� ���� �������ϴ�! ";
							cout << k % 2 + 1 << "�� ����(O)�� �¸��Դϴ�!";
						}
					}
					if (board[i][j] == 'X')
					{
						colOscore++;
						if (colXscore == 3)
						{
							cout << "���ο� ��� ���� �������ϴ�! ";
							cout << k % 2 + 1 << "�� ����(X)�� �¸��Դϴ�!";
						}
					}
				}
			}
		}
		for (int i = 0; i < numCell; i++)
		{
			if (i == 0 || i == 2)
			{
				for (int j = 0; j < numCell; j++)
				{
					int rowOscore = 0;
					int rowXscore = 0;
					if (board[j][i] == 'O')
					{
						rowOscore++;
						if (rowOscore == 3)
						{
							cout << "���ο� ��� ���� �������ϴ�! ";
							cout << k % 2 + 1 << "�� ����(O)�� �¸��Դϴ�!";
						}
					}
					if (board[j][i] == 'X')
					{
						rowOscore++;
						if (rowXscore == 3)
						{
							cout << "���ο� ��� ���� �������ϴ�! ";
							cout << k % 2 + 1 << "�� ����(X)�� �¸��Դϴ�!";
						}
					}
				}
			}
		}
		// �� �κ��� ���� �ǵ��� ����� ���� for���̴�.
		// row ����(��) col����(��)
		int diaLOscore = 0;
		int diaROscore = 0;
		int diaLXscore = 0;
		int diaRXscore = 0;
		for (int i = 0; i < numCell; i++)
		{
			for (int j = 0; j < numCell; j++)
			{
				if (i == j)
				{
					if (board[i][j] == 'O')
					{
						diaLOscore++;
						if (diaLOscore == 3)
						{
							cout << "�밢���� ��� ���� �������ϴ�!";
							cout << k % 2 + 1 << "�� ����(O)�� �¸��Դϴ�!";
						}
					}
					if (board[i][j] == 'X')
					{
						diaLXscore++;
						if (diaLXscore == 3)
						{
							cout << "�밢���� ��� ���� �������ϴ�!";
							cout << k % 2 + 1 << "�� ����(X)�� �¸��Դϴ�!";
						}
					}
				}
			}
		}
		// �밢�� �κп� �ش��ϴ� ����
		// (0,0), (1,1), (2,2), (2,0), (0,2)�� �ټ� ���̴�.
		*/
	}
	return 0;
}