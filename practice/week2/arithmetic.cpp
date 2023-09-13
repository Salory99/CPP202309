#include <iostream>
using namespace std;

int main()
{
	int one = 1;
	int two = 2;
	int three = 3;
	int four = 4;

	cout << "1 + 3 = " << one + three << endl;
	cout << "4 - 2 = " << four - two << endl;
	cout << "2 * 3 = " << two * three << endl;
	cout << "4 / 2 = " << four / two << endl;

	cout << "2 + 3 * 4 = " << two + three * four << endl;
	cout << "2 + 3 * 4 = " << two + three * four << endl;
	cout << "1 + 4 / 2 = " << one + four / two << endl;
}

// int자료형인 one, two, three, four를 각자 해당되는 값으로 초기화해두고
// 미리 적어둔 변수와 연산자에 계산된 int값이 출력된다..
// 이 경우에는 변수의 이름과 값, 그리고 출력 내용이 일치하기 때문에 일반적인 사칙연산처럼 동작한다.