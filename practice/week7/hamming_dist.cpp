#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1, s2;
	int count = 0;
	// ���ڿ�, ���� ���� �κ�

	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;
	// ���ڿ� �Է¹޴� �κ�

	if (s1.length() != s2.length())
	{
		cout << "����: ���̰� �ٸ�" << endl;
	}
	// ���ڿ� ���̰� ������ �ٸ��� length�� ���ڿ��� ���� ����.
	else
	{
		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] != s2[i])
			{
				count += 1;
			}
		}
		cout << "�ع� �Ÿ��� " << count << endl;
	}
	// ���ڿ� ���̰� ���ٸ�, �عְŸ��� �����.
	// ���ڿ��� ������ �ٸ��� ���Ͽ�, �ٸ��� count���� ������Ŵ.
	// count���� �����.

	return 0;
}