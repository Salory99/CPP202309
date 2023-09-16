#include <iostream>
using namespace std;

int main() {

	// 변수 선언
	float fahrenheit;
	float celcius;

	// 사용자 입력
	cout << "화씨 to 섭씨 변환기입니다.";
	cout << "화씨온도값을 소수점 단위를 포함하여 입력하십시오.";
	cin >> fahrenheit;

	// 연산 부분
	celcius = (fahrenheit - 32.0) * (5.0 / 9.0);
	
	// 출력 부분
	cout << "섭씨온도값은 " << celcius << "입니다.";

}