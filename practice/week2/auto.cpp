#include <iostream>
using namespace std;

auto add(int x, int y)
{
	return x + y;
}

int main()
{
	auto sum = add(5, 6);
	cout << sum;
	return 0;
}

// auto add에서 x와 y를 더한 값을 반환하도록 함수를 만든 뒤
// add(5, 6)에서 x와 y에 해당하는 값을 지정해 준다.
// 이때 sum의 타입은 auto의 추론에 따라 int로 정해진다.
// sum값을 출력시켜준다.