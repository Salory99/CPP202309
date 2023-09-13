#include <iostream>
#define PI 3.14159265359

using namespace std;

int main() {
	int	income = 1000;
	const double TAX_RATE = 0.25;
	income = income - TAX_RATE * income;

	double x = 100;
	x = x * PI;

	cout << x << endl;
	return 0;
}

// PI의 값을 #define을 통해서 미리 저장해 주고
// income의 값을 int로 저장한 뒤
// const로 상수로 만들어준 TAX_RATE라는 double값을 0.25로 저장하고
// income의 값을 income에서 TAX_RATE를 곱한 값을 빼 준 것으로 다시 정의한다.
// double x는 100으로 정의한 뒤, 100에 미리 define된 PI의 값을 곱한다.
