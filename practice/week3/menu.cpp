#include <iostream>
using namespace std;

int main()
{
	int choice;

	cout << "1. ���� ����" << endl;
	cout << "2. ���� ���� �ݱ�" << endl;
	cout << "3. ����" << endl;
	cin >> choice;

	switch (choice) {
		case 1:
			cout << "���� ������ �����߽��ϴ�." << endl;
			break;
		case 2:
			cout << "���� �ݱ⸦ �����߽��ϴ�." << endl;
			break;
		case 3:
			cout << "���α׷��� �����մϴ�." << endl;
			break;
		default:
			cout << "�߸��� �����Դϴ�." << endl;
			break;
	}
	return 0;
}
// choice��� int�ڷ��� ������ �̸� ������ ��, choice�� ���� cin���� �Է¹޴´�.
// switch������ choice�������� ���ǹ��� �ø� ��, case���� �Ҵ�� ���� ���������� ���� �ٸ� ����� ���´�.
// break���� ���ؼ� �״�� switch���� �������´�. break�� ���ٸ� choice�� 1�� ��, 1���� �� �������� default������ ��µ� ���̴�.
// default���� ��� case�� �ش���� ���� �� ������ ���̴�.