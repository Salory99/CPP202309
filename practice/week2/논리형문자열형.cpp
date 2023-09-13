#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1 = "Good";
	string s2 = "Bad";
	bool b = (s1 == s2);
	cout << b << endl;

	s2 = "Good";
	b = (s1 == s2);
	cout << b << endl;
}

// s1이라는 문자열에 Good을 저장하고
// s2라는 문자열에 Bad를 저장한 뒤에
// bool b에서 s1과 s2가 완전히 동일한 연산자인지 '=='로 확인 후
// true값을 반환하는지 아닌지 그 여부를 출력한다.
// 그 뒤에 s2의 값을 Good로 바꾼 뒤
// 다시 반환 여부를 확인한다.