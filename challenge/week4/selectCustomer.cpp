#include <iostream>
#include <string>
using namespace std;

int main()
{
	//int maxPeople = 0;
	//cout << "�� ���� ���� �Է��϶�: ";
	//cin >> maxPeople;
	
	const int maxPeople = 3;
	// maxPeople�� ��� int�ڷ������� ����
	
	string names[maxPeople];
	int ages[maxPeople];
	// names�� ages��� �� ���� �迭�� maxPeople����ŭ ����
	
	cout << "�� ���� ���� �Է�" << endl;
	int i = 0;
	for (i = 0; i < maxPeople; i++)
	{
		cout << i+1 << "�� �� ���� �Է�" << endl;
		cin >> names[i];
		cout << i+1 << "�� �� ���� �Է�" << endl;
		cin >> ages[i];
	}
	// for������ ���� �Է¹���.
	
	int ageThreshold;
	cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ���.";
	cin >> ageThreshold;
	cout << ageThreshold << "�� �̻��� ����\n";
	int k = 0;
	for (int j = 0; j < maxPeople; j++)
	{
		if (ages[j] >= ageThreshold)
		{
			cout << names[j] << "(" << ages[j] << ")" << endl;
			k++;
		}
	}
	// for�� ������ if���� ���ؼ� ���� �����ϰ� ���ǿ� �ش�Ǹ� �����. ���ǿ� �´ٸ� k�� ���.

	if (k == 0)
	{
		cout << ageThreshold << "�� �̻��� ���� �����ϴ�." << endl;
	}
	// k���� �þ�� �ʾ����� Ư�� ���� �̻��� ���� �� �� ���ٴ� ���̹Ƿ� if�� �۵�.

	return 0;
}