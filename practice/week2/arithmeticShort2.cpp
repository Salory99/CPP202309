#include <iostream>
using namespace std;

int main()
{
	int two = 2;
	int eight = 8;
	int sum1 = 2;
	int sum2 = 8;

	sum1 *= two;
	sum2 /= eight;

	cout << "sum1 = " << sum1 << endl;
	cout << "sum2 = " << sum2 << endl;

	return 0;
}

// int자료형의 변수 4개를 지정해 둔 뒤
// sum1의 값을 2*=2를 통해 4라는 값으로 재지정한다.
// sum2의 값을 8/=8을 통해 1로 재지정한다.
// 재지정된 값들을 출력한다.
