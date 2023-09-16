#include <iostream>
using namespace std;

int main() {

	// 변수 선언
	int candyprice;
	int ownmoney;
	int howmany;
	int left;

	// 사용자 입력
	cout << "사탕 가격 입력 : ";
	cin >> candyprice;
	cout << "가진 돈 입력 : ";
	cin >> ownmoney;

	// 연산
	howmany = ownmoney / candyprice;
	left = ownmoney % candyprice;

	// 결과 출력
	cout << "사탕 개수는 " << howmany << "개이다.";
	cout << "남은 돈은 " << left << "원이다.";

}