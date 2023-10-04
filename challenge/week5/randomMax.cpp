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
	// 이 부분은 이중 for문과 rand를 이용하여 0~999사이의 값을
	// 2차원 배열인 numList에 집어넣는 부분이다.
	// 집어넣은 뒤 출력도 해준다.

	cout << endl;

	int max = 0; // 큰 값 저장을 위한 변수
	int maxI; // 큰 값이 있는 i를 저장하기 위한 변수
	int maxJ; // 큰 값이 있는 j를 저장하기 위한 변수

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
	

	// 이 부분은 max값을 찾아내는 부분이다.
	// 만일 numList[i][j]가 max보다 크다면 max, maxI, maxJ의 값은 전부 바뀌게 된다.

	cout << "가장 큰 값은 " << max << "이고,";
	cout << "i와 j는 각각 " << maxI << ", " << maxJ << "입니다." << endl;
	cout << "검증 결과 : " << numList[maxI][maxJ] << endl;

	return 0;
}