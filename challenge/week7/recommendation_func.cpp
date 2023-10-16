#include <iostream>
using namespace std;

const int NUM_USERS = 3;
const int NUM_ITEMS = 3;
int userPreferences[NUM_USERS][NUM_ITEMS];

void initializePreference(int preferences[NUM_USERS][NUM_ITEMS], int NUM_USERS, int NUM_ITEMS)
{
	for (int i = 0; i < NUM_USERS; ++i) {
		cout << "사용자 " << (i + 1) << "의 선호도를 입력하세요 (";
		cout << NUM_ITEMS << "개의 항목에 대해 ):";
		for (int j = 0; j < NUM_ITEMS; ++j)
		{
			cin >> preferences[i][j];
		}
	}
}
// 함수를 정의해 둔다. 매개변수는 main에서 미리 지정된 대로 들어간다.
// 이 부분은 선호도를 입력받는 부분이다.

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
		cout << "사용자 " << (i + 1) << "에게 추천하는 항목: ";
		cout << (maxPreferenceIndex + 1) << endl;
	}
}
// 함수를 정의해 둔다. 매개변수는 main에서 미리 지정된 대로 들어간다.
// 이 경우 maxPreferenceIndex는 선호도가 이전보다 클 경우에만 저장된다.

int main()
{
	initializePreference(userPreferences, NUM_USERS, NUM_ITEMS);
	findRecommendedItems(userPreferences, NUM_USERS, NUM_ITEMS);
	// main에서 함수를 호출하며 값을 넣어준다.

	return 0;
}