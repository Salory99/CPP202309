#include <iostream>
using namespace std;

int main()
{
	int choice;

	cout << "1. 파일 저장" << endl;
	cout << "2. 저장 없이 닫기" << endl;
	cout << "3. 종료" << endl;
	cin >> choice;

	if (choice == 1)
		cout << "파일 저장을 선택했습니다." << endl;
	else if (choice == 2)
		cout << "파일 닫기를 선택했습니다." << endl;
	else if (choice == 3)
		cout << "프로그램을 종료합니다." << endl;
	else
		cout << "잘못된 선택입니다." << endl;

	return 0;
}

// int자료형 변수 choice를 정의해주고, cin으로 해당되는 정수값을 받는다.
// if문에서 choice가 1이면 파일 저장이 뜨고, 만일 충족시키지 못할 경우 else if문들을 통해서 2 혹은 3일 경우 각각에 맞는 파일 닫기와 종료가 출력된다.
// 앞의 모든 조건들을 충족시키지 못했을 경우, else문에 있는 잘못된 선택입니다가 출력된다.