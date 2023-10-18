#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1, s2;
	int count = 0;
	// 문자열, 변수 선언 부분

	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;
	// 문자열 입력받는 부분

	if (s1.length() != s2.length())
	{
		cout << "오류: 길이가 다름" << endl;
	}
	// 문자열 길이가 같은지 다른지 length로 문자열을 세서 비교함.
	else
	{
		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] != s2[i])
			{
				count += 1;
			}
		}
		cout << "해밍 거리는 " << count << endl;
	}
	// 문자열 길이가 같다면, 해밍거리를 계산함.
	// 문자열이 같은지 다른지 비교하여, 다르면 count값을 증가시킴.
	// count값을 출력함.

	return 0;
}