#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1 = "Good";
	string s2 = "Morning";
	string s3 = s1 + " " + s2 + "!";
	cout << s3 << endl;
	return 0;
}

// string s1과 s2에 각각 Good와 Morning이라는 문자열을 저장한 뒤,
// string s3에서 s1과 s2를 각각 +로 이어준 것이다.
// cout라는 출력 연산자로 출력한다.
