#include <iostream>
using namespace std;

int main()
{
	int vowel = 0;
	int consonant = 0;
	cout << "�����ڸ� �Է��ϰ� ctrl+z�� ġ�ÿ�." << endl;

	char ch; // char ch���� ����
	// ���� : a, e, i, o, u

	while (cin >> ch){ //while ���ǿ� ch�� cin���� �޾ƿ� ��� ��ӵǵ��� ��.
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		{
			vowel++; // ������ �ش�� ��� vowel++
		}
		else
		{
			consonant++; // �̿��� ��� consonant++
		}
	}

	cout << "���� : " << vowel << endl;
	cout << "���� : " << consonant << endl;
	return 0;
}