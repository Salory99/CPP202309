#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int max_people;
  cout << "총 고객의 수를 입력하라: ";
  cin >> max_people;

  // 벡터 선언
  vector<string> names(max_people);
  vector<int> ages(max_people);

  // 입력받는 곳
  cout << "고객 성함 연세 입력" << endl;
  for (int i = 0; i < max_people; i++) {
    cout << i + 1 << "번 고객 성함 입력" << endl;
    cin >> names[i];
    cout << i + 1 << "번 고객 연세 입력" << endl;
    cin >> ages[i];
  }

  int age_threshold;
  cout << "특정 나이 이상인 사람을 찾으려면 나이를 입력하세요.";
  cin >> age_threshold;
  cout << age_threshold << "세 이상인 고객들\n";

  // 찾는 과정
  bool found = false;
  for (int j = 0; j < max_people; j++) {
    if (ages[j] >= age_threshold) {
      cout << names[j] << "(" << ages[j] << ")" << endl;
      found = true;
    }
  }

  // 찾지 못했을 시 출력
  if (!found) {
    cout << age_threshold << "세 이상의 고객이 없습니다." << endl;
  }

  return 0;
}
