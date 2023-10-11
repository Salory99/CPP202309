#include <iostream>
using namespace std;

int main()
{
	const int numCell = 3;
	char board[numCell][numCell]{};
	int x, y;
	// ���⼭�� �� ���� ũ�⸦ ��Ÿ���� ��� �� x, y��ǥ ������ ������ �迭�� �����Ѵ�.
	// x, y��ǥ�� ����ڷκ��� �Է¹޴´�.

	// ������ �ʱ�ȭ
	for (x = 0; x < numCell; x++)
	{
		for (y = 0; y < numCell; y++)
		{
			board[x][y] = ' ';
		}
	}
	// ���⼭�� board[x][y]�� ���� �������� �ʱ�ȭ���ֱ� ���� ���� for���̴�.


	// �ʱⰪ ����
	int k = 0;
	char currentUser = 'X';
	// k���� ȸ���� �ǹ��Ѵ�. �ʱⰪ�� 0�̴�.
	// currentUser�� �⺻���� X�̱⿡ X�� ���� �����Ѵ�.

	// While�� ���ѹݺ�
	while (true) // �� while���� break�� ���������� �ʴ� �̻� ���� �ݺ��̴�.
	{
		// ���� �������� ���
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


		// ��ǥ �Է� �ޱ�
		cout << "(x, y) ��ǥ�� �Է��ϼ��� : ";
		cin >> x >> y;
		// ���⼭�� x�� y���� �޴´�.


		// ��ǥ ��ȿ�� üũ
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


		// �Է¹��� ��ǥ�� ���� ������ �� ����
		board[x][y] = currentUser;


		// ���� �� ��±�
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
		// ���⼭�� ���� ����Ѵ�. ���� ���� ���¸� �״�� ��½��� �ش�.
		// ���� for�������� ���� ���м��� ����ϰ� �ִ�.
		// board[i][j]�� ���� ���� �� ������(�������� ���� �־�����) ��µǸ�
		// ������ ������� ��쿡�� ������ �״�� ��µȴ�.


		// �¸� ����
		bool isOwin = false;
		bool isXwin = false;

		// ���� �¸� �ǵ���
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
						cout << "���ο� ��� ���� �������ϴ�!: ";
						isOwin = true;
					}
				}
				if (board[i][j] == 'X')
				{
					colXscore++;
					if (colXscore == numCell)
					{
						cout << "���ο� ��� ���� �������ϴ�!: ";
						isXwin = true;
					}
				}
			}
		}

		// ���� �¸� �ǵ���
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
						cout << "���ο� ��� ���� �������ϴ�!: ";
						isOwin = true;
					}
				}
				if (board[i][j] == 'X')
				{
					rowXscore++;
					if (rowXscore == numCell)
					{
						cout << "���ο� ��� ���� �������ϴ�!: ";
						isXwin = true;
					}
				}
			}
		}
		// �� �κ��� ���� �ǵ��� ����� ���� for���̴�.
		// row ����(��) col����(��)


		// ���� �밢�� ���� �ǵ���
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
					cout << "���� �밢���� ��� ���� �������ϴ�!: ";
					isOwin = true;
				}
			}
			if (board[i][i] == 'X')
			{
				diaLXscore++;
				if (diaLXscore == numCell)
				{
					cout << "���� �밢���� ��� ���� �������ϴ�!: ";
					isXwin = true;
				}
			}
		}

		// ���� �밢�� ���� �ǵ���
		for (int i = 0; i < numCell; i++)
		{
			if (board[i][numCell - 1 - i] == 'O')
			{
				diaROscore++;
				if (diaROscore == numCell)
				{
					cout << "������ �밢���� ��� ���� �������ϴ�!: ";
					isOwin = true;
				}
			}
			if (board[i][numCell - 1 - i] == 'X')
			{
				diaRXscore++;
				if (diaRXscore == numCell)
				{
					cout << "������ �밢���� ��� ���� �������ϴ�!: ";
					isXwin = true;
				}
			}
		}
		// �밢�� �κп� �ش��ϴ� ����
		// (0,0), (1,1), (2,2), (2,0), (0,2)�� �ټ� ���̴�.
		// �̰��� ���и� �ǵ��ϱ� ���ؼ��ε�, �Ϲ������� ���� �밢���� ��ǥ��
		// x�� y�� ���� �Ǿ� �ִ�.
		// ������ ���� �밢���� ���� ���� �ٸ��⿡, �ٸ� ������� �ؾ� �Ѵ�.

		// �¸� ���� �� �ݺ��� Ż���
		if (isOwin == true)
		{
			cout << k % 2 + 1 << "�� ����(" << currentUser << ")�� �¸��Դϴ�!" << endl;
			cout << "�����մϴ�." << endl;
			break;
		}
		if (isXwin == true)
		{
			cout << k % 2 + 1 << "�� ����(" << currentUser << ")�� �¸��Դϴ�!" << endl;
			cout << "�����մϴ�." << endl;
			break;
		}
		// �� �κ��� ���� �ÿ� �ݺ��� Ż���� ���� �κ��̴�.
		// O�� X�� ������ �̱�� break������ �ݺ����� Ż���Ѵ�.

		// �� á���� ���� Ȯ�α�
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
			cout << "��� ĭ�� �� á���ϴ�. �����մϴ�." << endl;
			break;
		}
		k++;
		// �� �κ��� ��� ĭ�� á���� ������ ���� ���� for���̴�.
		// ���� ��� 9ĭ ��ΰ� ���� break�� ���� while���� �������´�.
		// �̰� �۵��ϸ� ��������� ���� ���� ������ ����ȴ�.
		// �� �κ��� �������� �δ� ������ ���������� ���ڰ� ������ �� �ֱ� �����̴�.
		// �������� k++�� ȸ�� ���� ī��Ʈ�̴�.
	}
	return 0;
}
