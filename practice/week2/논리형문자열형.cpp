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

// s1�̶�� ���ڿ��� Good�� �����ϰ�
// s2��� ���ڿ��� Bad�� ������ �ڿ�
// bool b���� s1�� s2�� ������ ������ ���������� '=='�� Ȯ�� ��
// true���� ��ȯ�ϴ��� �ƴ��� �� ���θ� ����Ѵ�.
// �� �ڿ� s2�� ���� Good�� �ٲ� ��
// �ٽ� ��ȯ ���θ� Ȯ���Ѵ�.