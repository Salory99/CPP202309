#include <iostream>
using namespace std;

int main() {

	// ���� ����
	float fahrenheit;
	float celcius;

	// ����� �Է�
	cout << "���� to ȭ�� ��ȯ���Դϴ�.";
	cout << "�����µ����� �Ҽ��� ������ �����Ͽ� �Է��Ͻʽÿ�.";
	cin >> celcius;

	// ���� �κ�
	fahrenheit = celcius * 9.0 / 5.0 + 32;
	
	// ��� �κ�
	cout << "ȭ���µ����� " << fahrenheit << "�Դϴ�.";

}

// ���� ���� ���� �ڿ�, cin�� ���ؼ� celcius���� �޾ƿ´�.
// �̸� ��ȯ ���Ĵ�� celcius * 9/5 + 32�� ���ְ� ����ϸ� �ȴ�.