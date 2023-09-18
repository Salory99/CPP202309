#include <iostream>
using namespace std;

int main()
{
	int choice;

	cout << "1. 파일 저장" << endl;
	cout << "2. 저장 없이 닫기" << endl;
	cout << "3. 종료" << endl;
	cin >> choice;

	switch (choice) {
		case 1:
			cout << "파일 저장을 선택했습니다." << endl;
			break;
		case 2:
			cout << "파일 닫기를 선택했습니다." << endl;
			break;
		case 3:
			cout << "프로그램을 종료합니다." << endl;
			break;
		default:
			cout << "잘못된 선택입니다." << endl;
			break;
	}
	return 0;
}
// choice라는 int자료형 변수를 미리 정의한 뒤, choice의 값을 cin으로 입력받는다.
// switch문에서 choice변수값을 조건문에 올린 뒤, case별로 할당된 값이 무엇인지에 따라 다른 결과가 나온다.
// break문을 통해서 그대로 switch문을 빠져나온다. break가 없다면 choice가 1일 때, 1부터 쭉 내려가서 default값까지 출력될 것이다.
// default값은 모든 case에 해당되지 않을 시 나오는 값이다.