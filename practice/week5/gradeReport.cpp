#include <iostream>
#include <string>
using namespace std;

int main()
{
	const int STUDENT = 5;
	const int SUBJECT = 3; // STUDENT�� SUBJECT ����� ����� ��
	int scores[STUDENT][SUBJECT];
	string studentNames[STUDENT]
		= { "����", "����", "ö��", "�̹�", "����" };
	string subjectNames[SUBJECT]
		= { "����", "����", "CPP" };
	// string 1���� �迭�� ��������� ������

	for (int i = 0; i < STUDENT; i++)
	{
		cout << studentNames[i]
			<< "�� ������ �ϳ��� �Է��ϼ���." << endl;
		for (int j = 0; j < SUBJECT; j++)
		{
			cout << subjectNames[j] << ":";
			cin >> scores[i][j];
		}
	}
	// ���� for���� �̿��Ͽ� 2���� �迭 scores�� i�� �л�, j�� ��������� ����Ͽ� ���� �Է¹���

	for (int i = 0; i < STUDENT; i++)
	{
		cout << studentNames[i] << "�� ��� ������ ";
		double sum = 0;
		double average = 0; // sum�� �Ǽ� �ڷ����� double�� ����� ���� average�� ���� �Ǽ��� �� �� �ֱ� ����.
		for (int j = 0; j < SUBJECT; j++)
		{
			sum += scores[i][j];
		}
		average = sum / SUBJECT;
		cout << average << "�Դϴ�" << endl;
	}
	// ���� for���� �̿��Ͽ� ��հ��� ���Ѵ�.

}