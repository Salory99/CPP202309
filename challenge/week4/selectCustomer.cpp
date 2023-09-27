#include <iostream>
#include <string>
using namespace std;

int main()
{
	//int maxPeople = 0;
	//cout << "총 고객의 수를 입력하라: ";
	//cin >> maxPeople;
	
	const int maxPeople = 3;
	// maxPeople를 상수 int자료형으로 선언
	
	string names[maxPeople];
	int ages[maxPeople];
	// names와 ages라는 두 개의 배열을 maxPeople값만큼 생성
	
	cout << "고객 성함 연세 입력" << endl;
	int i = 0;
	for (i = 0; i < maxPeople; i++)
	{
		cout << i+1 << "번 고객 성함 입력" << endl;
		cin >> names[i];
		cout << i+1 << "번 고객 연세 입력" << endl;
		cin >> ages[i];
	}
	// for문으로 각각 입력받음.
	
	int ageThreshold;
	cout << "특정 나이 이상인 사람을 찾으려면 나이를 입력하세요.";
	cin >> ageThreshold;
	cout << ageThreshold << "세 이상인 고객들\n";
	int k = 0;
	for (int j = 0; j < maxPeople; j++)
	{
		if (ages[j] >= ageThreshold)
		{
			cout << names[j] << "(" << ages[j] << ")" << endl;
			k++;
		}
	}
	// for문 내부의 if문을 통해서 값을 대조하고 조건에 해당되면 출력함. 조건에 맞다면 k값 상승.

	if (k == 0)
	{
		cout << ageThreshold << "세 이상의 고객이 없습니다." << endl;
	}
	// k값이 늘어나지 않았으면 특정 나이 이상의 고객이 한 명도 없다는 것이므로 if문 작동.

	return 0;
}