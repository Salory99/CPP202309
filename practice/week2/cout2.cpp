#include <iostream>
#include <string>
using namespace std;

int main()
{
	char character = 'C';
	int inteager = 100;
	double precision = 3.14159;
	bool is_true = true;
	string word = "Hello World";

	cout << "char : " << character << endl;
	cout << "int : " << inteager << endl;
	cout << "double : " << precision << endl;
	cout << "bool : " << is_true << endl;
	cout << "string : " << word << endl;

	return 0;
}

// char자료형 변수인 character에 'C'로 초기화하고
// int자료형 변수인 inteager에 100으로 초기화하고
// double자료형 변수인 precision을 3.14159로 초기화하며
// boolean 자료형 변쉰 is_true에 true를 대입한다.
// string자료형인 word에는 Hello World라는 문자열을 넣는다.
// 문자열이 가능한 이유는 include <string>를 삽입했기 때문이다.
// 이를 전부 출력한다.