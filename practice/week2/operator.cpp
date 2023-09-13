#include <iostream>
using namespace std;

int main()
{
	int x = 1;
	int y = -1;
	int z = -2;

	cout << "1 + (-1) = " << x + y << endl;
	cout << "-1 + -2 = " << y + z << endl;

	return 0;
}

// int자료형인 변수들 x에는 1을, y에는 -1을, z에는 -2를 대입한다.
// 해당 변수들을 그대로 연산자를 이용하여 연산하여 출력한다.
// 1 + (-1)은 당연히 0이며, (-1) + (-2)는 당연히 -3이다.