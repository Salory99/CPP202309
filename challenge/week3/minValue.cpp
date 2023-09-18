#include <iostream>
using namespace std;

int main()
{
	int a, b, c, least;

	cout << "3개의 정수를 입력하시오 : ";
	cin >> a >> b >> c;

	if (a < b && a < c)
		least = a;
	else if (b < a && b < c)
		least = b;
	else
		least = c;

	cout << "가장 작은 정수는 " << least << endl;
	return 0;
}

// int자료형의 a, b, c, least를 정의해 준 뒤
// cin으로 3개의 정수를 받아온다.

// if문으로 괄호 안에 조건문을 설정하는데, a가 b보다 작고, a가 c보다 작다는 두 조건이 동시에 충족(AND연산자)된다면 least = a로 대입된다.
// 충족되지 않는다면아래 else if문으로 넘어가며, else if문도 위와 동일하게 작동한다. else if문도 충족되지 않을 경우 else문에서 끝난다.
// cout를 통해서 least값을 출력한다.