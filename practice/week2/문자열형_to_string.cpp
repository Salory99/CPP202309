#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1 = "���";
	string s2;
	//s2 = s1 + " " + 10 + "��";
	s2 = s1 + " " + to_string(10) + "��";
	cout << s2 << endl;
}

// string s1�� ����� �ְ�, s2���� �ƹ��͵� ���� �ʴ´�.
// �ּ� �κ��� ������ ���� ������ 10�� ���ڿ��� �ƴϱ� �����̴�.
// ���ڿ��� ������� tostring�� �̿��ϸ� �ȴ�.
