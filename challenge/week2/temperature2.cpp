#include <iostream>
using namespace std;

int main() {

	// 변수 선언
	float fahrenheit;
	float celcius;

	// 사용자 입력
	cout << "섭씨 to 화씨 변환기입니다.";
	cout << "섭씨온도값을 소수점 단위를 포함하여 입력하십시오.";
	cin >> celcius;

	// 연산 부분
	fahrenheit = celcius * 9.0 / 5.0 + 32;
	
	// 출력 부분
	cout << "화씨온도값은 " << fahrenheit << "입니다.";

}

// 변수 선언 해준 뒤에, cin을 통해서 celcius값을 받아온다.
// 이를 변환 공식대로 celcius * 9/5 + 32를 해주고 출력하면 된다.