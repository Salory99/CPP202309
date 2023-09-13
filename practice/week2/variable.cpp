#include <iostream>

using namespace std;

int main()
{
	int one = 0;
	int two = 0;
	int sum = one + two;
	cout << "1 + 2 = " << sum << endl;

	return 0;
}

// 변수 one과 two를 0으로 초기화한 뒤
// 역시 같은 int변수인 sum을 one과 two를 더한 값으로 초기화한다.
// 따라서 역시 0인 값이 sum에 들어가며, 1+2=0이 출력된다.