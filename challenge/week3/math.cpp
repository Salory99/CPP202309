#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	int i=0;
	int ans;
	cout << "산수 문제를 자동으로 출제합니다. " << endl;

	while (i <= 4) { // 5번 맞으면 맞출 수 있도록 while문 조건 설정
		int firstNum = rand() % 100; // int자료형 firstNum을 rand함수를 통해서 랜덤으로 생성함.
		int secondNum = rand() % 100; // int자료형 secondNum을 rand함수를 통해서 랜덤으로 생성함.
		
		cout << firstNum << " + " << secondNum << " = ";
		cin >> ans; // 답을 ans에 cin으로 저장함.
		if (firstNum + secondNum == ans) // 정답 조건
		{
			cout << "맞았습니다." << endl;
			i++; // 맞으면 i값 추가
		}
		else
		{
			cout << "틀렸습니다." << endl; // 틀리면 i값 추가 안함.
		}
	}
	return 0;
}