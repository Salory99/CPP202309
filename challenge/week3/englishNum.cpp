#include <iostream>
using namespace std;

int main()
{
	int number;
	cout << "숫자를 입력하시오 : ";
	cin >> number;

	if (number == 0)
		cout << "zero\n";
	else if (number == 1)
		cout << "one\n";
	else
		cout << "many\n";

	return 0;
}

// int자료형 number변수를 생성하고, cin으로 number의 값을 받는다.
// if문에서 number변수값이 0이면 zero를 출력하고, else if에서 number값이 1이면 one을 출력한다.
// 이외의 경우 else에서 many를 출력한다.