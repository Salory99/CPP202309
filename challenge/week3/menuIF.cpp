#include <iostream>
using namespace std;

int main()
{
	int choice;

	cout << "1. ���� ����" << endl;
	cout << "2. ���� ���� �ݱ�" << endl;
	cout << "3. ����" << endl;
	cin >> choice;

	if (choice == 1)
		cout << "���� ������ �����߽��ϴ�." << endl;
	else if (choice == 2)
		cout << "���� �ݱ⸦ �����߽��ϴ�." << endl;
	else if (choice == 3)
		cout << "���α׷��� �����մϴ�." << endl;
	else
		cout << "�߸��� �����Դϴ�." << endl;

	return 0;
}

// int�ڷ��� ���� choice�� �������ְ�, cin���� �ش�Ǵ� �������� �޴´�.
// if������ choice�� 1�̸� ���� ������ �߰�, ���� ������Ű�� ���� ��� else if������ ���ؼ� 2 Ȥ�� 3�� ��� ������ �´� ���� �ݱ�� ���ᰡ ��µȴ�.
// ���� ��� ���ǵ��� ������Ű�� ������ ���, else���� �ִ� �߸��� �����Դϴٰ� ��µȴ�.