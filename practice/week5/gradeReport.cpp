#include <iostream>
#include <string>
using namespace std;

int main()
{
	const int STUDENT = 5;
	const int SUBJECT = 3; // STUDENT와 SUBJECT 상수를 만들어 둠
	int scores[STUDENT][SUBJECT];
	string studentNames[STUDENT]
		= { "영수", "영희", "철수", "미미", "쥬쥬" };
	string subjectNames[SUBJECT]
		= { "수학", "영어", "CPP" };
	// string 1차원 배열을 상수값으로 만들어둠

	for (int i = 0; i < STUDENT; i++)
	{
		cout << studentNames[i]
			<< "의 성적을 하나씩 입력하세요." << endl;
		for (int j = 0; j < SUBJECT; j++)
		{
			cout << subjectNames[j] << ":";
			cin >> scores[i][j];
		}
	}
	// 이중 for문을 이용하여 2차원 배열 scores에 i는 학생, j는 과목명으로 사용하여 값을 입력받음

	for (int i = 0; i < STUDENT; i++)
	{
		cout << studentNames[i] << "의 평균 점수는 ";
		double sum = 0;
		double average = 0; // sum을 실수 자료형인 double로 만드는 것은 average의 값이 실수가 될 수 있기 때문.
		for (int j = 0; j < SUBJECT; j++)
		{
			sum += scores[i][j];
		}
		average = sum / SUBJECT;
		cout << average << "입니다" << endl;
	}
	// 이중 for문을 이용하여 평균값을 구한다.

}