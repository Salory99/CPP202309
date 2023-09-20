#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL)); // random �Լ� ���� ����

	int answer = rand() % 100; // ����(rand�� ���� ����)
	int tries = 0; // �õ� Ƚ�� �����ϴ� ����

	int guess; // ����� �Է� �����ϱ� ���� ����

	do { // while�� �۵� ���� ���� �����. guess!=answer�� true�� ��� ��� ����.
		cout << "������ �����Ͽ� ���ÿ� : ";
		cin >> guess; // int�ڷ��� ���� guess�� ���� cin���� ����.
		tries++; // tries�� 1�� �÷���. �̴� �õ� Ƚ���� �ǹ���.

		if (guess > answer) // guess�� answer���� ���� ���
			cout << "������ ������ �����ϴ�." << endl;
		if (guess < answer) // guess�� answer���� ���� ���
			cout << "������ ������ �����ϴ�." << endl;
	} while (guess != answer); // guess == answer�� ��� ��������.


	cout << "�����մϴ�. �õ� Ƚ�� = " << tries << endl; // �õ� Ƚ�� ����.
	return 0;
}