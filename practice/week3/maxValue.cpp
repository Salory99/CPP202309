#include <iostream>
using namespace std;

int main()
{
	int a, b, c, largest;

	cout << "3���� ������ �Է��Ͻÿ� : ";
	cin >> a >> b >> c;

	if (a > b && a > c)
		largest = a;
	else if (b > a && b > c)
		largest = b;
	else
		largest = c;

	cout << "���� ū ������ " << largest << endl;
	return 0;
}

// int�ڷ����� a, b, c, largest�� ������ �� ��
// cin���� 3���� ������ �޾ƿ´�.

// if������ ��ȣ �ȿ� ���ǹ��� �����ϴµ�, a�� b���� ũ��, a�� c���� ũ�ٴ� �� ������ ���ÿ� ����(AND������)�ȴٸ� largest = a�� ���Եȴ�.
// �������� �ʴ´ٸ�Ʒ� else if������ �Ѿ��, else if���� ���� �����ϰ� �۵��Ѵ�. else if���� �������� ���� ��� else������ ������.
// cout�� ���ؼ� largest���� ����Ѵ�.