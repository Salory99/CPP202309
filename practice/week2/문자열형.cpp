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

// string s1�� s2�� ���� Good�� Morning�̶�� ���ڿ��� ������ ��,
// string s3���� s1�� s2�� ���� +�� �̾��� ���̴�.
// cout��� ��� �����ڷ� ����Ѵ�.
