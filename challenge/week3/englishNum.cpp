#include <iostream>
using namespace std;

int main()
{
	int number;
	cout << "���ڸ� �Է��Ͻÿ� : ";
	cin >> number;

	if (number == 0)
		cout << "zero\n";
	else if (number == 1)
		cout << "one\n";
	else
		cout << "many\n";

	return 0;
}

// int�ڷ��� number������ �����ϰ�, cin���� number�� ���� �޴´�.
// if������ number�������� 0�̸� zero�� ����ϰ�, else if���� number���� 1�̸� one�� ����Ѵ�.
// �̿��� ��� else���� many�� ����Ѵ�.