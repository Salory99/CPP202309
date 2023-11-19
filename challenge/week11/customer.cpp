#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int max_people;
  cout << "�� ���� ���� �Է��϶�: ";
  cin >> max_people;

  // ���� ����
  vector<string> names(max_people);
  vector<int> ages(max_people);

  // �Է¹޴� ��
  cout << "�� ���� ���� �Է�" << endl;
  for (int i = 0; i < max_people; i++) {
    cout << i + 1 << "�� �� ���� �Է�" << endl;
    cin >> names[i];
    cout << i + 1 << "�� �� ���� �Է�" << endl;
    cin >> ages[i];
  }

  int age_threshold;
  cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ���.";
  cin >> age_threshold;
  cout << age_threshold << "�� �̻��� ����\n";

  // ã�� ����
  bool found = false;
  for (int j = 0; j < max_people; j++) {
    if (ages[j] >= age_threshold) {
      cout << names[j] << "(" << ages[j] << ")" << endl;
      found = true;
    }
  }

  // ã�� ������ �� ���
  if (!found) {
    cout << age_threshold << "�� �̻��� ���� �����ϴ�." << endl;
  }

  return 0;
}
