#include <iostream>
using namespace std;

int main()
{
	cout << "char 크기 : " << sizeof('p') << endl;
	cout << "int 크기 : " << sizeof(10) << endl;
	cout << "double 크기" << sizeof(10.0) << endl;

	return 0;
}

// 첫 번째는 문자 p의 데이터 크기인 1을 반환한다.
// 두 번째는 int자료형의 10의 데이터 크기인 4를 반환한다.
// 세 번째는 double 자료형인 10.0의 데이터 크기인 8을 반환한다.