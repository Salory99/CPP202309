#include <iostream>
#include <string>
using namespace std;

// 현재는 아이템과 적이 사라지지 않도록 조정 완료.


// 상수 선언
const int mapX = 5;
const int mapY = 5;
const int default_health = 20;

// 변수 선언
bool ongoing = true; // 이 bool은 게임이 진행중인지 여부를 확인. 기본값 true.
bool debug_mod = false; // 이 bool은 디버그 모드 상태를 확인. 기본값 false.
int health = default_health; // 현재 체력 설정.

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void checkState(int map[][mapX], int user_x, int user_y, int& health);
void debugMod(int map[][mapX], int user_x, int user_y);
void healthCare(int& health);



// 메인  함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
							{1, 0, 0, 2, 0},
							{0, 0, 0, 0, 0},
							{0, 2, 3, 0, 0},
							{3, 0, 0, 0, 2} };


	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호

	// 게임 시작 
	while (ongoing == true) { // 사용자에게 계속 입력받기 위해 무한 루프

		// 사용자의 입력을 저장할 변수
		string user_input = "";

		if (debug_mod == true)
		{
			debugMod(map, user_x, user_y);
		}
		cout << "HP = " << health << endl;
		cout << "명령어를 입력하세요 (상,하,좌,우,지도,종료,디버그): ";
		cin >> user_input;

		if (user_input == "상") {
			// 위로 한 칸 올라가기
			user_y -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_y += 1;
			}
			else {
				cout << "위로 한 칸 올라갑니다." << endl;
				displayMap(map, user_x, user_y);
				checkState(map, user_x, user_y, health);
				health -= 1;
			}
		}
		else if (user_input == "하") {
			// TODO: 아래로 한 칸 내려가기
			user_y += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_y -= 1;
			}
			else {
				cout << "위로 한 칸 내려갑니다." << endl;
				displayMap(map, user_x, user_y);
				checkState(map, user_x, user_y, health);
				health -= 1;
			}
		}
		else if (user_input == "좌") {
			// TODO: 왼쪽으로 이동하기
			user_x -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);

			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_x += 1;
			}
			else {
				cout << "왼쪽으로 이동합니다." << endl;
				displayMap(map, user_x, user_y);
				checkState(map, user_x, user_y, health);
				health -= 1;
			}
		}
		else if (user_input == "우") {
			// TODO: 오른쪽으로 이동하기
			user_x += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_x -= 1;
			}
			else {
				cout << "오른쪽으로 이동합니다." << endl;
				displayMap(map, user_x, user_y);
				checkState(map, user_x, user_y, health);
				health -= 1;
			}
		}
		else if (user_input == "지도") {
			// TODO: 지도 보여주기 함수 호출
			displayMap(map, user_x, user_y);
		}
		else if (user_input == "종료") {
			cout << "종료합니다.";
			break;
		}
		else if (user_input == "디버그" && debug_mod == false)
		{
			cout << "디버그 모드 on" << endl;
			debug_mod = true;
		}
		else if (user_input == "디버그" && debug_mod == true)
		{
			cout << "디버그 모드 off" << endl;
			debug_mod = false;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}

		// 목적지에 도달했는지 체크
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}
		healthCare(health); // 헬스케어 부분은 체력이 0으로 떨어졌는지 확인하기 위한 목적.
	}
	return 0;

}


// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // 양 옆 1칸 공백
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6칸 공백
					break;
				case 1:
					cout << "아이템|";
					break;
				case 2:
					cout << "  적  |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << " 포션 |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << "목적지|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

// 오브젝트를 만났는지 여부를 checkState호출로 구현.
// 요구 기능에 따라 오브젝트 제거 기능 삭제. 따라서 int에서 void로 함수를 바꾸었음.
void checkState(int map[][mapX], int user_x, int user_y, int& health)
{
	// 아이템 먹으면 반응
	if (map[user_y][user_x] == 1)
	{
		cout << "아이템을 먹었습니다." << endl;
	}
	// 적과 마주치면 HP -2
	else if (map[user_y][user_x] == 2)
	{
		cout << "적과 마주쳤습니다." << endl;
		cout << "체력을 2만큼 잃습니다." << endl;
		health -= 2;
	}
	// 포션을 먹으면 HP +2
	else if (map[user_y][user_x] == 3)
	{
		cout << "포션을 먹고 체력을 2만큼 회복합니다." << endl;
		health += 2;
	}
	else
	{
	}
}

// 체력 관련 부분
void healthCare(int& health)
{
	// 최대 체력 20 제한
	if (health > 20)
	{
		health = default_health;
	}
	// 체력이 0이 될 시 게임 오버
	else if (health <= 0)
	{
		cout << "HP가 바닥났기에 실패했습니다." << endl;
		cout << "게임을 종료합니다," << endl;
		ongoing = false;
	}
}

// 디버그를 위한 부분
void debugMod(int map[][mapX], int user_x, int user_y)
{
	cout << "user_x : " << user_x << endl;
	cout << "user_y : " << user_y << endl;
	cout << "현재 좌표 : " << map[user_y][user_x] << endl;
	cout << "전체 맵 상황 : " << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << map[i][j];
		}
		cout << " " << endl;
		cout << " -------------------- " << endl;
	}
}