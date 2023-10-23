#include <iostream>
#include <string>
using namespace std;

// ����� ������, ��, ������ ������� ����.
// �ڿ� ������� �ʵ��� ������ ����.


// ��� ����
const int mapX = 5;
const int mapY = 5;
const int default_health = 20;

// ���� ����
bool ongoing = true;
bool debug_mod = false;
int health = default_health;

// ����� ���� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
int checkObject(int map[][mapX], int user_x, int user_y, int& health);
void debugMod(int map[][mapX], int user_x, int user_y);
void healthCare(int& health);



// ����  �Լ�
int main() {
	// 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
							{1, 0, 0, 2, 0},
							{0, 0, 0, 0, 0},
							{0, 2, 3, 0, 0},
							{3, 0, 0, 0, 2} };


	// ������ ��ġ�� ������ ����
	int user_x = 0; // ���� ��ȣ
	int user_y = 0; // ���� ��ȣ

	// ���� ���� 
	while (ongoing == true) { // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����

		// ������� �Է��� ������ ����
		string user_input = "";

		if (debug_mod == true)
		{
			debugMod(map, user_x, user_y);
		}
		cout << "HP = " << health << endl;
		cout << "��ɾ �Է��ϼ��� (��,��,��,��,����,����,�����): ";
		cin >> user_input;

		if (user_input == "��") {
			// ���� �� ĭ �ö󰡱�
			user_y -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_y += 1;
			}
			else {
				cout << "���� �� ĭ �ö󰩴ϴ�." << endl;
				displayMap(map, user_x, user_y);
				map[user_y][user_x] = checkObject(map, user_x, user_y, health);
				health -= 1;
			}
		}
		else if (user_input == "��") {
			// TODO: �Ʒ��� �� ĭ ��������
			user_y += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_y -= 1;
			}
			else {
				cout << "���� �� ĭ �������ϴ�." << endl;
				displayMap(map, user_x, user_y);
				map[user_y][user_x] = checkObject(map, user_x, user_y, health);
				health -= 1;
			}
		}
		else if (user_input == "��") {
			// TODO: �������� �̵��ϱ�
			user_x -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);

			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_x += 1;
			}
			else {
				cout << "�������� �̵��մϴ�." << endl;
				displayMap(map, user_x, user_y);
				map[user_y][user_x] = checkObject(map, user_x, user_y, health);
				health -= 1;
			}
		}
		else if (user_input == "��") {
			// TODO: ���������� �̵��ϱ�
			user_x += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_x -= 1;
			}
			else {
				cout << "���������� �̵��մϴ�." << endl;
				displayMap(map, user_x, user_y);
				map[user_y][user_x] = checkObject(map, user_x, user_y, health);
				health -= 1;
			}
		}
		else if (user_input == "����") {
			// TODO: ���� �����ֱ� �Լ� ȣ��
			displayMap(map, user_x, user_y);
		}
		else if (user_input == "����") {
			cout << "�����մϴ�.";
			break;
		}
		else if (user_input == "�����" && debug_mod == false)
		{
			cout << "����� ��� on" << endl;
			debug_mod = true;
		}
		else if (user_input == "�����" && debug_mod == true)
		{
			cout << "����� ��� off" << endl;
			debug_mod = false;
		}
		else {
			cout << "�߸��� �Է��Դϴ�." << endl;
			continue;
		}

		// �������� �����ߴ��� üũ
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "�������� �����߽��ϴ�! �����մϴ�!" << endl;
			cout << "������ �����մϴ�." << endl;
			break;
		}
		healthCare(health);
	}
	return 0;

}


// ������ ����� ��ġ ����ϴ� �Լ�
void displayMap(int map[][mapX], int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // �� �� 1ĭ ����
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6ĭ ����
					break;
				case 1:
					cout << "������|";
					break;
				case 2:
					cout << "  ��  |"; // �� �� 2ĭ ����
					break;
				case 3:
					cout << " ���� |"; // �� �� 1ĭ ����
					break;
				case 4:
					cout << "������|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// �̵��Ϸ��� ���� ��ȿ�� ��ǥ���� üũ�ϴ� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// ������ ��ġ�� ���������� üũ�ϴ� �Լ�
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// ������ �����ϸ�
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

// ������Ʈ�� ���� ��
int checkObject(int map[][mapX], int user_x, int user_y, int& health)
{
	// ������ ������
	if (map[user_y][user_x] == 1)
	{
		int del = 0;
		cout << "�������� �Ծ����ϴ�." << endl;
		return del;
	}
	// ���� ����ġ�� HP -2
	else if (map[user_y][user_x] == 2)
	{
		int del = 0;
		cout << "���� �����ƽ��ϴ�." << endl;
		cout << "ü���� 2��ŭ �ҽ��ϴ�." << endl;
		health -= 2;
		return del;
	}
	// ������ ������ HP +5
	else if (map[user_y][user_x] == 3)
	{
		int del = 0;
		cout << "������ �԰� ü���� 5��ŭ ȸ���մϴ�." << endl;
		health += 5;
		return del;
	}
	// �̿� ��� 0 ��ȯ. �ش� �κ��� ������ �����Ⱚ ��ȯ���� ���� �߻�.
	else
	{
		int del = 0;
		return del;
	}
}

// ü�� ���� �κ�
void healthCare(int& health)
{
	// �ִ� ü�� 20 ����
	if (health > 20)
	{
		health = default_health;
	}
	// ü���� 0�� �� �� ���� ����
	else if (health <= 0)
	{
		cout << "HP�� �ٴڳ��⿡ �����߽��ϴ�." << endl;
		cout << "������ �����մϴ�," << endl;
		ongoing = false;
	}
}

// ����׸� ���� �κ�
void debugMod(int map[][mapX], int user_x, int user_y)
{
	cout << "user_x : " << user_x << endl;
	cout << "user_y : " << user_y << endl;
	cout << "���� ��ǥ : " << map[user_y][user_x] << endl;
	cout << "��ü �� ��Ȳ : " << endl;
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