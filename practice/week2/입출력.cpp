#include <iostream>
#include <string>

using namespace std;

int main() {
	string name;
	cout << "이름을 입력하시오 : ";
	cin >> name;
	cout << name << "을 환영합니다." << endl;
	return 0;
}
// string name을 미리 정의해둔 뒤에
// cout로 "이름을 입력하시오 : "를 출력시키고
// cin으로 이름 값을 받은 것을 name값에 대입한 뒤
// name값을 출력한다.