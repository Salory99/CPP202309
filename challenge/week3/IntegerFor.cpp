#include <iostream>
using namespace std;

int main()
{
	int userInput;

	cout << "������ 10�� �Է��ϼ��� (0�� �Է��ϸ� ����)";
	int i = 0;

	for (i = 0; i < 10; i++)// if (i==0)��for�� ���ǽ����� ��ȯ��
	{
		cin >> userInput;
		if (userInput == 0)
		{
			break; // for�� ����������
		}
		cout << "�Է°� : " << userInput << " Ƚ�� : " << i << endl;
	}

	cout << "���� �Ǿ����ϴ�." << endl;
	return 0;

}