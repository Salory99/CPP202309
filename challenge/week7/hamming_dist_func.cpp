#include <iostream>
#include <string>
using namespace std;

string toLowerStr(string str);
string toUpperStr(string str);
int calcHammingDist(string s1, string s2);
// �Լ� �̸� �����ص�.

int main()
{
	string s1, s2;
	int count = 0;
	// ���ڿ�, ���� ���� �κ�
	while (true)
	{
		cout << "DNA1: ";
		cin >> s1;
		cout << "DNA2: ";
		cin >> s2;
		if (s1.length() != s2.length())
		{
			cout << "����: ���̰� �ٸ�" << endl;
			cout << "���̰� ���� ���ڿ��� �Է��ϼ���." << endl;
		}
		else
		{
			break;
		}
	}
	// ���ڿ� �Է¹޴� �κ�
	// ���ڿ� ���̰� ������ �ٸ��� length�� ���ڿ��� ���� ����.
	// while������ ���ڿ� ������ �ٸ� �� ���������� �Է� ��û�� �ϰ�
	// �ƴ� �� break������ ���� ��������.

	s1 = toLowerStr(s1);
	s2 = toLowerStr(s2);
	count = calcHammingDist(s1, s2);
	cout << "�ع� �Ÿ��� " << count << endl;
	// ���� toLowerStr�� ���ؼ� �ҹ���ȭ�ؼ� ���ϱ⿡ ��ҹ��� ���谡 ����.
	// count������ calcHammingDist�� ���ؼ� �ع� �Ÿ��� ������ �� �����.

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
// ���̸� ��� sl�� �����Ͽ� for������ ������.

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
	// ���ڿ� ���̰� ���ٸ�, �عְŸ��� �����.
	// ���ڿ��� ������ �ٸ��� ���Ͽ�, �ٸ��� count���� ������Ŵ.
	// count���� ������.
}