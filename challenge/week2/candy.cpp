#include <iostream>
using namespace std;

int main() {

	// ���� ����
	int candyprice;
	int ownmoney;
	int howmany;
	int left;

	// ����� �Է�
	cout << "���� ���� �Է� : ";
	cin >> candyprice;
	cout << "���� �� �Է� : ";
	cin >> ownmoney;

	// ����
	howmany = ownmoney / candyprice;
	left = ownmoney % candyprice;

	// ��� ���
	cout << "���� ������ " << howmany << "���̴�.";
	cout << "���� ���� " << left << "���̴�.";

}