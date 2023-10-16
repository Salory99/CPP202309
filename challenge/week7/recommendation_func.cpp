#include <iostream>
using namespace std;

const int NUM_USERS = 3;
const int NUM_ITEMS = 3;
int userPreferences[NUM_USERS][NUM_ITEMS];

void initializePreference(int preferences[NUM_USERS][NUM_ITEMS], int NUM_USERS, int NUM_ITEMS)
{
	for (int i = 0; i < NUM_USERS; ++i) {
		cout << "����� " << (i + 1) << "�� ��ȣ���� �Է��ϼ��� (";
		cout << NUM_ITEMS << "���� �׸� ���� ):";
		for (int j = 0; j < NUM_ITEMS; ++j)
		{
			cin >> preferences[i][j];
		}
	}
}
// �Լ��� ������ �д�. �Ű������� main���� �̸� ������ ��� ����.
// �� �κ��� ��ȣ���� �Է¹޴� �κ��̴�.

void findRecommendedItems(const int preferences[NUM_USERS][NUM_ITEMS], int NUM_USERS, int NUM_ITEMS)
{
	for (int i = 0; i < NUM_USERS; ++i) {
		int maxPreferenceIndex = 0;
		for (int j = 1; j < NUM_ITEMS; ++j)
		{
			if (preferences[i][j] > preferences[i][maxPreferenceIndex])
			{
				maxPreferenceIndex = j;
			}
		}
		cout << "����� " << (i + 1) << "���� ��õ�ϴ� �׸�: ";
		cout << (maxPreferenceIndex + 1) << endl;
	}
}
// �Լ��� ������ �д�. �Ű������� main���� �̸� ������ ��� ����.
// �� ��� maxPreferenceIndex�� ��ȣ���� �������� Ŭ ��쿡�� ����ȴ�.

int main()
{
	initializePreference(userPreferences, NUM_USERS, NUM_ITEMS);
	findRecommendedItems(userPreferences, NUM_USERS, NUM_ITEMS);
	// main���� �Լ��� ȣ���ϸ� ���� �־��ش�.

	return 0;
}