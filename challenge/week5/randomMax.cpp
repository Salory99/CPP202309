#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	const int numCell = 10;
	int numList[numCell][numCell];

	for (int i = 0; i < numCell; i++)
	{
		for (int j = 0; j < numCell; j++)
		{
			numList[i][j] = rand() % 1000;
			cout << i << ", " << j << " : " << numList[i][j] << endl;
		}
	}
	// �� �κ��� ���� for���� rand�� �̿��Ͽ� 0~999������ ����
	// 2���� �迭�� numList�� ����ִ� �κ��̴�.
	// ������� �� ��µ� ���ش�.

	cout << endl;

	int max = 0; // ū �� ������ ���� ����
	int maxI; // ū ���� �ִ� i�� �����ϱ� ���� ����
	int maxJ; // ū ���� �ִ� j�� �����ϱ� ���� ����

	/*
	for (int i = 0; i < numCell; i++)
	{
		for (int j = 0; j < numCell; j++)
		{
			int value = numList[i][j];
			if (max < value)
			{
				max = value;
				maxI = i;
				maxJ = j;
			}
		}
	}
	*/
	
	
	for (int i = 0; i < numCell; i++)
	{
		int j = 0;
		for (int value : numList[i])
		{
			if (max < value)
			{
				max = value;
				maxI = i;
				maxJ = j;
			}
			j++;
		}
	}
	

	// �� �κ��� max���� ã�Ƴ��� �κ��̴�.
	// ���� numList[i][j]�� max���� ũ�ٸ� max, maxI, maxJ�� ���� ���� �ٲ�� �ȴ�.

	cout << "���� ū ���� " << max << "�̰�,";
	cout << "i�� j�� ���� " << maxI << ", " << maxJ << "�Դϴ�." << endl;
	cout << "���� ��� : " << numList[maxI][maxJ] << endl;

	return 0;
}