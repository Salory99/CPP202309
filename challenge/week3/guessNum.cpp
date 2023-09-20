#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL)); // random 함수 관련 설정

	int answer = rand() % 100; // 정답(rand로 랜덤 생성)
	int tries = 0; // 시도 횟수 저장하는 변수

	int guess; // 사용자 입력 저장하기 위한 변수

	do { // while문 작동 전에 먼저 실행됨. guess!=answer가 true일 경우 계속 실행.
		cout << "정답을 추측하여 보시오 : ";
		cin >> guess; // int자료형 변수 guess의 값을 cin으로 받음.
		tries++; // tries를 1씩 올려줌. 이는 시도 횟수를 의미함.

		if (guess > answer) // guess가 answer보다 높을 경우
			cout << "제시한 정수가 높습니다." << endl;
		if (guess < answer) // guess가 answer보다 낮을 경우
			cout << "제시한 정수가 낮습니다." << endl;
	} while (guess != answer); // guess == answer일 경우 빠져나감.


	cout << "축하합니다. 시도 횟수 = " << tries << endl; // 시도 횟수 적힘.
	return 0;
}