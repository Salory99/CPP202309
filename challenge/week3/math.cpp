#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	int i=0;
	int ans;
	cout << "��� ������ �ڵ����� �����մϴ�. " << endl;

	while (i <= 4) { // 5�� ������ ���� �� �ֵ��� while�� ���� ����
		int firstNum = rand() % 100; // int�ڷ��� firstNum�� rand�Լ��� ���ؼ� �������� ������.
		int secondNum = rand() % 100; // int�ڷ��� secondNum�� rand�Լ��� ���ؼ� �������� ������.
		
		cout << firstNum << " + " << secondNum << " = ";
		cin >> ans; // ���� ans�� cin���� ������.
		if (firstNum + secondNum == ans) // ���� ����
		{
			cout << "�¾ҽ��ϴ�." << endl;
			i++; // ������ i�� �߰�
		}
		else
		{
			cout << "Ʋ�Ƚ��ϴ�." << endl; // Ʋ���� i�� �߰� ����.
		}
	}
	return 0;
}