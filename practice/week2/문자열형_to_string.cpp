#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1 = "사과";
	string s2;
	//s2 = s1 + " " + 10 + "개";
	s2 = s1 + " " + to_string(10) + "개";
	cout << s2 << endl;
}

// string s1에 사과를 넣고, s2에는 아무것도 넣지 않는다.
// 주석 부분이 에러가 나는 이유는 10이 문자열이 아니기 때문이다.
// 문자열로 만들려면 tostring을 이용하면 된다.
