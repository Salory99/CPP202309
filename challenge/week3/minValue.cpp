#include <iostream>
using namespace std;

int main()
{
	int a, b, c, least;

	cout << "3���� ������ �Է��Ͻÿ� : ";
	cin >> a >> b >> c;

	if (a < b && a < c)
		least = a;
	else if (b < a && b < c)
		least = b;
	else
		least = c;

	cout << "���� ���� ������ " << least << endl;
	return 0;
}

// int�ڷ����� a, b, c, least�� ������ �� ��
// cin���� 3���� ������ �޾ƿ´�.

// if������ ��ȣ �ȿ� ���ǹ��� �����ϴµ�, a�� b���� �۰�, a�� c���� �۴ٴ� �� ������ ���ÿ� ����(AND������)�ȴٸ� least = a�� ���Եȴ�.
// �������� �ʴ´ٸ�Ʒ� else if������ �Ѿ��, else if���� ���� �����ϰ� �۵��Ѵ�. else if���� �������� ���� ��� else������ ������.
// cout�� ���ؼ� least���� ����Ѵ�.