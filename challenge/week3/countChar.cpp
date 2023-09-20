#include <iostream>
using namespace std;

int main()
{
	int vowel = 0;
	int consonant = 0;
	cout << "영문자를 입력하고 ctrl+z을 치시오." << endl;

	char ch; // char ch변수 정의
	// 모음 : a, e, i, o, u

	while (cin >> ch){ //while 조건에 ch를 cin으로 받아올 경우 계속되도록 함.
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		{
			vowel++; // 모음에 해당될 경우 vowel++
		}
		else
		{
			consonant++; // 이외의 경우 consonant++
		}
	}

	cout << "모음 : " << vowel << endl;
	cout << "자음 : " << consonant << endl;
	return 0;
}