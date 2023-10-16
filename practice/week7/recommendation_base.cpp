#include <iostream>
using namespace std;

int main() {
	const int NUM_USERS = 3;
	const int NUM_ITEMS = 3;
	int userPreferences[NUM_USERS][NUM_ITEMS];
	// 상수와 2차원 배열을 선언한다.

	for (int i = 0; i < NUM_USERS; ++i) {
		cout << "사용자 " << (i + 1) << "의 선호도를 입력하세요 (";
		cout << NUM_ITEMS << "개의 항목에 대해 ):";
		for (int j = 0; j < NUM_ITEMS; ++j)
		{
			cin >> userPreferences[i][j];
		}
	}
	// 선호도를 입력받아 2차원 배열 안에 넣는다.

	for (int i = 0; i < NUM_USERS; ++i) {
		int maxPreferenceIndex = 0;
		for (int j = 1; j < NUM_ITEMS; ++j)
		{
			if (userPreferences[i][j] > userPreferences[i][maxPreferenceIndex])
			{
				maxPreferenceIndex = j;
			}
		}
		cout << "사용자 " << (i + 1) << "에게 추천하는 항목: ";
		cout << (maxPreferenceIndex + 1) << endl;
	}
	// 만일 선호도가 가장 높은 값이 나오면,
	// maxPreferenceIndex를 현재 상품 인덱스와 같게 한다.
	// 사용자에게 추천하는 항목을 맨 아래에서 출력한다.

	return 0;
}