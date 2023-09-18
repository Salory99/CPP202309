#include <iostream>
using namespace std;

int main()
{
	int a, b, c, largest;

	cout << "3개의 정수를 입력하시오 : ";
	cin >> a >> b >> c;

	if (a > b && a > c)
		largest = a;
	else if (b > a && b > c)
		largest = b;
	else
		largest = c;

	cout << "가장 큰 정수는 " << largest << endl;
	return 0;
}

// int자료형의 a, b, c, largest를 정의해 준 뒤
// cin으로 3개의 정수를 받아온다.

// if문으로 괄호 안에 조건문을 설정하는데, a가 b보다 크고, a가 c보다 크다는 두 조건이 동시에 충족(AND연산자)된다면 largest = a로 대입된다.
// 충족되지 않는다면아래 else if문으로 넘어가며, else if문도 위와 동일하게 작동한다. else if문도 충족되지 않을 경우 else문에서 끝난다.
// cout를 통해서 largest값을 출력한다.