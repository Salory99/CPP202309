#include <iostream>
using namespace std;

int main() {

	// ���� ����
	float fahrenheit;
	float celcius;

	// ����� �Է�
	cout << "ȭ�� to ���� ��ȯ���Դϴ�.";
	cout << "ȭ���µ����� �Ҽ��� ������ �����Ͽ� �Է��Ͻʽÿ�.";
	cin >> fahrenheit;

	// ���� �κ�
	celcius = (fahrenheit - 32.0) * (5.0 / 9.0);
	
	// ��� �κ�
	cout << "�����µ����� " << celcius << "�Դϴ�.";

}