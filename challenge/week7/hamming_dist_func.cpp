#include <iostream>
#include <string>
using namespace std;

string toLowerStr(string str);
string toUpperStr(string str);
int calcHammingDist(string s1, string s2);
// 함수 미리 선언해둠.

int main()
{
	string s1, s2;
	int count = 0;
	// 문자열, 변수 선언 부분
	while (true)
	{
		cout << "DNA1: ";
		cin >> s1;
		cout << "DNA2: ";
		cin >> s2;
		if (s1.length() != s2.length())
		{
			cout << "오류: 길이가 다름" << endl;
			cout << "길이가 같은 문자열을 입력하세요." << endl;
		}
		else
		{
			break;
		}
	}
	// 문자열 입력받는 부분
	// 문자열 길이가 같은지 다른지 length로 문자열을 세서 비교함.
	// while문으로 문자열 개수가 다를 때 지속적으로 입력 요청을 하고
	// 아닐 시 break문으로 루프 빠져나감.

	s1 = toLowerStr(s1);
	s2 = toLowerStr(s2);
	count = calcHammingDist(s1, s2);
	cout << "해밍 거리는 " << count << endl;
	// 전부 toLowerStr을 통해서 소문자화해서 비교하기에 대소문자 관계가 없음.
	// count변수의 calcHammingDist를 통해서 해밍 거리를 측정한 뒤 출력함.

	return 0;
}

string toLowerStr(string str)
{
	int sl = 0;
	sl = str.length();
	for (int i = 0; i < sl; i++)
	{
		char a = str[i];
		a = tolower(a);
		str[i] = a;
	}
	return str;
}
string toUpperStr(string str)
{
	int sl = 0;
	sl = str.length();
	for (int i = 0; i < sl; i++)
	{
		char a = str[i];
		a = toupper(a);
		str[i] = a;
	}
	return str;
}
// 길이를 담는 sl를 생성하여 for문으로 구성함.

int calcHammingDist(string s1, string s2)
{
	int count = 0;
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] != s2[i])
		{
			count += 1;
		}
	}

	return count;
	// 문자열 길이가 같다면, 해밍거리를 계산함.
	// 문자열이 같은지 다른지 비교하여, 다르면 count값을 증가시킴.
	// count값을 리턴함.
}