#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<unordered_set>
#include<regex>
#include<bitset>

using namespace std;

/*
	종이접기를 해본다
*/
char W[10];
char R[10];
char B[10];
char O[10];
char G[10];
char Y[10];

void white_turn_right() {
	int * t = new int[10];
	t[1] = W[1];
	t[2] = W[2];
	t[3] = W[3];
	t[4] = W[4];
	t[5] = W[5];
	t[6] = W[6];
	t[7] = W[7];
	t[8] = W[8];
	t[9] = W[9];

	W[1] = t[7];
	W[2] = t[4];
	W[3] = t[1];
	W[4] = t[8];
	W[5] = t[5];
	W[6] = t[2];
	W[7] = t[9];
	W[8] = t[6];
	W[9] = t[3];

	t = new int[13];
	t[1] = O[7];
	t[2] = O[8];
	t[3] = O[9];
	t[4] = B[1];
	t[5] = B[4];
	t[6] = B[7];
	t[7] = R[3];
	t[8] = R[2];
	t[9] = R[1];
	t[10] = G[9];
	t[11] = G[6];
	t[12] = G[3];

	O[7] = t[10];
	O[8] = t[11];
	O[9] = t[12];
	B[1] = t[1];
	B[4] = t[2]; 
	B[7] = t[3];
	R[3] = t[4];
	R[2] = t[5];
	R[1] = t[6];
	G[9] = t[7];
	G[6] = t[8];
	G[3] = t[9];
}

void white_turn_left() {
	int* t = new int[10];
	t[1] = W[1];
	t[2] = W[2];
	t[3] = W[3];
	t[4] = W[4];
	t[5] = W[5];
	t[6] = W[6];
	t[7] = W[7];
	t[8] = W[8];
	t[9] = W[9];

	W[1] = t[3];
	W[2] = t[6];
	W[3] = t[9];
	W[4] = t[2];
	W[5] = t[5];
	W[6] = t[8];
	W[7] = t[1];
	W[8] = t[4];
	W[9] = t[7];

	t = new int[13];
	t[1] = O[7];
	t[2] = O[8];
	t[3] = O[9];
	t[4] = B[1];
	t[5] = B[4];
	t[6] = B[7];
	t[7] = R[3];
	t[8] = R[2];
	t[9] = R[1];
	t[10] = G[9];
	t[11] = G[6];
	t[12] = G[3];

	O[7] = t[4];
	O[8] = t[5];
	O[9] = t[6];
	B[1] = t[7];
	B[4] = t[8];
	B[7] = t[9];
	R[3] = t[10];
	R[2] = t[11];
	R[1] = t[12];
	G[9] = t[1];
	G[6] = t[2];
	G[3] = t[3];
}

void yellow_turn_right() {
	int* t = new int[10];
	t[1] = Y[1];
	t[2] = Y[2];
	t[3] = Y[3];
	t[4] = Y[4];
	t[5] = Y[5];
	t[6] = Y[6];
	t[7] = Y[7];
	t[8] = Y[8];
	t[9] = Y[9];

	Y[1] = t[7];
	Y[2] = t[4];
	Y[3] = t[1];
	Y[4] = t[8];
	Y[5] = t[5];
	Y[6] = t[2];
	Y[7] = t[9];
	Y[8] = t[6];
	Y[9] = t[3];

	t = new int[13];
	t[1] = R[7];
	t[2] = R[8];
	t[3] = R[9];
	t[4] = B[9];
	t[5] = B[6];
	t[6] = B[3];
	t[7] = O[3];
	t[8] = O[2];
	t[9] = O[1];
	t[10] = G[1];
	t[11] = G[4];
	t[12] = G[7];

	R[7] = t[10];
	R[8] = t[11];
	R[9] = t[12];
	B[9] = t[1];
	B[6] = t[2];
	B[3] = t[3];
	O[3] = t[4];
	O[2] = t[5];
	O[1] = t[6];
	G[1] = t[7];
	G[4] = t[8];
	G[7] = t[9];
}

void yellow_turn_left() {
	int* t = new int[10];
	t[1] = Y[1];
	t[2] = Y[2];
	t[3] = Y[3];
	t[4] = Y[4];
	t[5] = Y[5];
	t[6] = Y[6];
	t[7] = Y[7];
	t[8] = Y[8];
	t[9] = Y[9];

	Y[1] = t[3];
	Y[2] = t[6];
	Y[3] = t[9];
	Y[4] = t[2];
	Y[5] = t[5];
	Y[6] = t[8];
	Y[7] = t[1];
	Y[8] = t[4];
	Y[9] = t[7];

	t = new int[13];
	t[1] = R[7];
	t[2] = R[8];
	t[3] = R[9];
	t[4] = B[9];
	t[5] = B[6];
	t[6] = B[3];
	t[7] = O[3];
	t[8] = O[2];
	t[9] = O[1];
	t[10] = G[1];
	t[11] = G[4];
	t[12] = G[7];

	R[7] = t[4];
	R[8] = t[5];
	R[9] = t[6];
	B[9] = t[7];
	B[6] = t[8];
	B[3] = t[9];
	O[3] = t[10];
	O[2] = t[11];
	O[1] = t[12];
	G[1] = t[1];
	G[4] = t[2];
	G[7] = t[3];
}

void orange_turn_right() {
	int* t = new int[10];
	t[1] = O[1];
	t[2] = O[2];
	t[3] = O[3];
	t[4] = O[4];
	t[5] = O[5];
	t[6] = O[6];
	t[7] = O[7];
	t[8] = O[8];
	t[9] = O[9];

	O[1] = t[7];
	O[2] = t[4];
	O[3] = t[1];
	O[4] = t[8];
	O[5] = t[5];
	O[6] = t[2];
	O[7] = t[9];
	O[8] = t[6];
	O[9] = t[3];

	t = new int[13];
	t[1] = Y[7];
	t[2] = Y[8];
	t[3] = Y[9];
	t[4] = B[3];
	t[5] = B[2];
	t[6] = B[1];
	t[7] = W[3];
	t[8] = W[2];
	t[9] = W[1];
	t[10] = G[3];
	t[11] = G[2];
	t[12] = G[1];

	Y[7] = t[10];
	Y[8] = t[11];
	Y[9] = t[12];
	B[3] = t[1];
	B[2] = t[2];
	B[1] = t[3];
	W[3] = t[4];
	W[2] = t[5];
	W[1] = t[6];
	G[3] = t[7];
	G[2] = t[8];
	G[1] = t[9];
}

void orange_turn_left() {
	int* t = new int[10];
	t[1] = O[1];
	t[2] = O[2];
	t[3] = O[3];
	t[4] = O[4];
	t[5] = O[5];
	t[6] = O[6];
	t[7] = O[7];
	t[8] = O[8];
	t[9] = O[9];

	O[1] = t[3];
	O[2] = t[6];
	O[3] = t[9];
	O[4] = t[2];
	O[5] = t[5];
	O[6] = t[8];
	O[7] = t[1];
	O[8] = t[4];
	O[9] = t[7];

	t = new int[13];
	t[1] = Y[7];
	t[2] = Y[8];
	t[3] = Y[9];
	t[4] = B[3];
	t[5] = B[2];
	t[6] = B[1];
	t[7] = W[3];
	t[8] = W[2];
	t[9] = W[1];
	t[10] = G[3];
	t[11] = G[2];
	t[12] = G[1];

	Y[7] = t[4];
	Y[8] = t[5];
	Y[9] = t[6];
	B[3] = t[7];
	B[2] = t[8];
	B[1] = t[9];
	W[3] = t[10];
	W[2] = t[11];
	W[1] = t[12];
	G[3] = t[1];
	G[2] = t[2];
	G[1] = t[3];
}

void red_turn_right() {
	int* t = new int[10];
	t[1] = R[1];
	t[2] = R[2];
	t[3] = R[3];
	t[4] = R[4];
	t[5] = R[5];
	t[6] = R[6];
	t[7] = R[7];
	t[8] = R[8];
	t[9] = R[9];

	R[1] = t[7];
	R[2] = t[4];
	R[3] = t[1];
	R[4] = t[8];
	R[5] = t[5];
	R[6] = t[2];
	R[7] = t[9];
	R[8] = t[6];
	R[9] = t[3];

	t = new int[13];
	t[1] = W[7];
	t[2] = W[8];
	t[3] = W[9];
	t[4] = B[7];
	t[5] = B[8];
	t[6] = B[9];
	t[7] = Y[3];
	t[8] = Y[2];
	t[9] = Y[1];
	t[10] = G[7];
	t[11] = G[8];
	t[12] = G[9];

	W[7] = t[10];
	W[8] = t[11];
	W[9] = t[12];
	B[7] = t[1];
	B[8] = t[2];
	B[9] = t[3];
	Y[3] = t[4];
	Y[2] = t[5];
	Y[1] = t[6];
	G[7] = t[7];
	G[8] = t[8];
	G[9] = t[9];
}

void red_turn_left() {
	int* t = new int[10];
	t[1] = R[1];
	t[2] = R[2];
	t[3] = R[3];
	t[4] = R[4];
	t[5] = R[5];
	t[6] = R[6];
	t[7] = R[7];
	t[8] = R[8];
	t[9] = R[9];

	R[1] = t[3];
	R[2] = t[6];
	R[3] = t[9];
	R[4] = t[2];
	R[5] = t[5];
	R[6] = t[8];
	R[7] = t[1];
	R[8] = t[4];
	R[9] = t[7];

	t = new int[13];
	t[1] = W[7];
	t[2] = W[8];
	t[3] = W[9];
	t[4] = B[7];
	t[5] = B[8];
	t[6] = B[9];
	t[7] = Y[3];
	t[8] = Y[2];
	t[9] = Y[1];
	t[10] = G[7];
	t[11] = G[8];
	t[12] = G[9];

	W[7] = t[4];
	W[8] = t[5];
	W[9] = t[6];
	B[7] = t[7];
	B[8] = t[8];
	B[9] = t[9];
	Y[3] = t[10];
	Y[2] = t[11];
	Y[1] = t[12];
	G[7] = t[1];
	G[8] = t[2];
	G[9] = t[3];
}

void green_turn_right() {
	int* t = new int[10];
	t[1] = G[1];
	t[2] = G[2];
	t[3] = G[3];
	t[4] = G[4];
	t[5] = G[5];
	t[6] = G[6];
	t[7] = G[7];
	t[8] = G[8];
	t[9] = G[9];

	G[1] = t[7];
	G[2] = t[4];
	G[3] = t[1];
	G[4] = t[8];
	G[5] = t[5];
	G[6] = t[2];
	G[7] = t[9];
	G[8] = t[6];
	G[9] = t[3];

	t = new int[13];
	t[1] = O[1];
	t[2] = O[4];
	t[3] = O[7];
	t[4] = W[1];
	t[5] = W[4];
	t[6] = W[7];
	t[7] = R[1];
	t[8] = R[4];
	t[9] = R[7];
	t[10] = Y[1];
	t[11] = Y[4];
	t[12] = Y[7];

	O[1] = t[10];
	O[4] = t[11];
	O[7] = t[12];
	W[1] = t[1];
	W[4] = t[2];
	W[7] = t[3];
	R[1] = t[4];
	R[4] = t[5];
	R[7] = t[6];
	Y[1] = t[7];
	Y[4] = t[8];
	Y[7] = t[9];
}

void green_turn_left() {
	int* t = new int[10];
	t[1] = G[1];
	t[2] = G[2];
	t[3] = G[3];
	t[4] = G[4];
	t[5] = G[5];
	t[6] = G[6];
	t[7] = G[7];
	t[8] = G[8];
	t[9] = G[9];

	G[1] = t[3];
	G[2] = t[6];
	G[3] = t[9];
	G[4] = t[2];
	G[5] = t[5];
	G[6] = t[8];
	G[7] = t[1];
	G[8] = t[4];
	G[9] = t[7];

	t = new int[13];
	t[1] = O[1];
	t[2] = O[4];
	t[3] = O[7];
	t[4] = W[1];
	t[5] = W[4];
	t[6] = W[7];
	t[7] = R[1];
	t[8] = R[4];
	t[9] = R[7];
	t[10] = Y[1];
	t[11] = Y[4];
	t[12] = Y[7];

	O[1] = t[4];
	O[4] = t[5];
	O[7] = t[6];
	W[1] = t[7];
	W[4] = t[8];
	W[7] = t[9];
	R[1] = t[10];
	R[4] = t[11];
	R[7] = t[12];
	Y[1] = t[1];
	Y[4] = t[2];
	Y[7] = t[3];
}

void blue_turn_right() {
	int* t = new int[10];
	t[1] = B[1];
	t[2] = B[2];
	t[3] = B[3];
	t[4] = B[4];
	t[5] = B[5];
	t[6] = B[6];
	t[7] = B[7];
	t[8] = B[8];
	t[9] = B[9];

	B[1] = t[7];
	B[2] = t[4];
	B[3] = t[1];
	B[4] = t[8];
	B[5] = t[5];
	B[6] = t[2];
	B[7] = t[9];
	B[8] = t[6];
	B[9] = t[3];

	t = new int[13];
	t[1] = O[9];
	t[2] = O[6];
	t[3] = O[3];
	t[4] = Y[9];
	t[5] = Y[6];
	t[6] = Y[3];
	t[7] = R[9];
	t[8] = R[6];
	t[9] = R[3];
	t[10] = W[9];
	t[11] = W[6];
	t[12] = W[3];

	O[9] = t[10];
	O[6] = t[11];
	O[3] = t[12];
	Y[9] = t[1];
	Y[6] = t[2];
	Y[3] = t[3];
	R[9] = t[4];
	R[6] = t[5];
	R[3] = t[6];
	W[9] = t[7];
	W[6] = t[8];
	W[3] = t[9];
}

void blue_turn_left() {
	int* t = new int[10];
	t[1] = B[1];
	t[2] = B[2];
	t[3] = B[3];
	t[4] = B[4];
	t[5] = B[5];
	t[6] = B[6];
	t[7] = B[7];
	t[8] = B[8];
	t[9] = B[9];

	B[1] = t[3];
	B[2] = t[6];
	B[3] = t[9];
	B[4] = t[2];
	B[5] = t[5];
	B[6] = t[8];
	B[7] = t[1];
	B[8] = t[4];
	B[9] = t[7];

	t = new int[13];
	t[1] = O[9];
	t[2] = O[6];
	t[3] = O[3];
	t[4] = Y[9];
	t[5] = Y[6];
	t[6] = Y[3];
	t[7] = R[9];
	t[8] = R[6];
	t[9] = R[3];
	t[10] = W[9];
	t[11] = W[6];
	t[12] = W[3];

	O[9] = t[4];
	O[6] = t[5];
	O[3] = t[6];
	Y[9] = t[7];
	Y[6] = t[8];
	Y[3] = t[9];
	R[9] = t[10];
	R[6] = t[11];
	R[3] = t[12];
	W[9] = t[1];
	W[6] = t[2];
	W[3] = t[3];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		int N;
		cin >> N;
		for (int i = 1; i <= 9; i++) {
			W[i] = 'w';
			R[i] = 'r';
			B[i] = 'b';
			O[i] = 'o';
			G[i] = 'g';
			Y[i] = 'y';
		}

		for (int i = 0; i < N; i++) {
			string command;
			cin >> command;
			if (command == "U+") { // U 시계방향
				white_turn_right();
			} else if (command == "U-") { // U 반시계방향
				white_turn_left();
			} else if (command == "D+") { // D 시계방향
				yellow_turn_right();
			} else if (command == "D-") { // D 반시계방향
				yellow_turn_left();
			} else if (command == "F+") { // F 시계방향
				red_turn_right();
			} else if (command == "F-") { // F 반시계방향
				red_turn_left();
			} else if (command == "B+") { // B 시계방향
				orange_turn_right();
			} else if (command == "B-") { // B 반시계방향
				orange_turn_left();
			} else if (command == "L+") { // L 시계방향
				green_turn_right();
			} else if (command == "L-") { // L 반시계방향
				green_turn_left();
			} else if (command == "R+") { // R 시계방향
				blue_turn_right();
			} else if (command == "R-") { // R 반시계방향
				blue_turn_left();
			}

		}
		
		for (int i = 1; i <= 9; i++) {
			cout << W[i];
			if (i % 3 == 0) {
				cout << "\n";
			}

		}
		
	}
   
    return 0;

}