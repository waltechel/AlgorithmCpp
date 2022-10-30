#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>

using namespace std;

/*
* 대입을 잘하자.
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 전부 블랙으로 깔아
	bool** isBlack = new bool* [16];
	for (int i = 0; i < 16; i++) {
		isBlack[i] = new bool[16];
		for (int j = 0; j < 16; j++) {
			isBlack[i][j] = true;
		}
	}

	// 1번줄은 OK
	// 2번줄은 화이트
	for (int i = 2; i <= 14; i++) {
		isBlack[2][i] = false;
	}
	// 3번 줄은 2개 화이트
	isBlack[3][2] = false;
	isBlack[3][14] = false;
	// 4번 줄도 2개 화이트 그리고 깔기
	isBlack[4][2] = false;
	isBlack[4][14] = false;
	for (int i = 4; i <= 12; i++) {
		isBlack[4][i] = false;
	}
	// 5번 줄도 2, 4, 12, 24 
	isBlack[5][2] = false;
	isBlack[5][4] = false;
	isBlack[5][12] = false;
	isBlack[5][14] = false;
	// 6번 줄도 깔기
	isBlack[6][2] = false;
	isBlack[6][4] = false;
	isBlack[6][12] = false;
	isBlack[6][14] = false;
	for (int i = 6; i <= 10; i++) {
		isBlack[6][i] = false;
	}
	// 7번 줄
	isBlack[7][2] = false;
	isBlack[7][4] = false;
	isBlack[7][6] = false;
	isBlack[7][10] = false;
	isBlack[7][12] = false;
	isBlack[7][14] = false;
	// 8번 줄
	isBlack[8][2] = false;
	isBlack[8][4] = false;
	isBlack[8][6] = false;
	isBlack[8][8] = false;
	isBlack[8][10] = false;
	isBlack[8][12] = false;
	isBlack[8][14] = false;
	// 9번 줄
	isBlack[9][2] = false;
	isBlack[9][4] = false;
	isBlack[9][6] = false;
	isBlack[9][10] = false;
	isBlack[9][12] = false;
	isBlack[9][14] = false;
	//10 번 줄
	isBlack[10][2] = false;
	isBlack[10][4] = false;
	isBlack[10][12] = false;
	isBlack[10][14] = false;
	for (int i = 6; i <= 10; i++) {
		isBlack[10][i] = false;
	}
	// 11 번 줄(5)
	isBlack[11][2] = false;
	isBlack[11][4] = false;
	isBlack[11][12] = false;
	isBlack[11][14] = false;
	// 12번 줄(4)
	isBlack[12][2] = false;
	isBlack[12][14] = false;
	for (int i = 4; i <= 12; i++) {
		isBlack[12][i] = false;
	}
	// 13번 줄(3)
	isBlack[13][2] = false;
	isBlack[13][14] = false;
	// 14번 줄(2)
	for (int i = 2; i <= 14; i++) {
		isBlack[14][i] = false;
	}
	// 15번 줄도 ok
	int R, C;
	cin >> R >> C;
	if (isBlack[R][C]) {
		cout << "black";
	} else {
		cout << "white";
	}

	return 0;
}

