#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>

using namespace std;

int** A;
int** B;

/*
	그냥 한번씩 해보면 어떨까?
	이거는 안되고, 비트마스크를 써서 줄여보도록 한다.
	디버깅을 못함
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int R1, C1;
	cin >> R1 >> C1;
	A = new int* [R1];
	for (int i = 0; i < R1; i++) {
		A[i] = new int[C1];
		for (int j = 0; j < C1; j++) {
			cin >> A[i][j];
		}
	}

	int R2, C2;
	cin >> R2 >> C2;
	B = new int* [R2];
	for (int i = 0; i < R2; i++) {
		B[i] = new int[C2];
		for (int j = 0; j < C2; j++) {
			cin >> B[i][j];
		}
	}

	bool isFind = false;
	for (int rowState = 1; rowState < (1 << R1); rowState++) {
		for (int colState = 1; colState < (1 << C1); colState++) {

			vector<int> rowCheckList;
			int temp = rowState;
			for (int i = 9; i >= 0; i--) {
				if (temp >= (1 << i)) {
					temp -= (1 << i);
					rowCheckList.push_back(1);
				} else {
					rowCheckList.push_back(0);
				}
			}
			vector<int> colCheckList;
			temp = colState;
			for (int i = 9; i >= 0; i--) {
				if (temp >= (1 << i)) {
					temp -= (1 << i);
					colCheckList.push_back(1);
				} else {
					colCheckList.push_back(0);
				}
			}

			int rowCount = 0;
			for (int i = 0; i < rowCheckList.size(); i++) {
				if (rowCheckList[i] == 1) {
					rowCount++;
				}
			}
			int colCount = 0;
			for (int i = 0; i < colCheckList.size(); i++) {
				if (colCheckList[i] == 1) {
					colCount++;
				}
			}
			if (rowCount != R2 || colCount != C2) {
				continue;
			}

			int start_A_row = 10 - R1;
			int start_A_col = 10 - C1;

			isFind = true;
			for (int i = start_A_row, rowIndexOfA = 0, rowIndexOfB = 0; i < 10; i++, rowIndexOfA++) {
				if (rowCheckList[i] == 0) {
					continue;
				}
				for (int j = start_A_col, colIndexOfA = 0, colIndexOfB = 0; j < 10; j++, colIndexOfA++) {
					if (colCheckList[j] == 0) {
						continue;
					}
					if (A[rowIndexOfA][colIndexOfA] != B[rowIndexOfB][colIndexOfB]) {
						isFind = false;
					}
					colIndexOfB++;
				}
				rowIndexOfB++;
			}

			if (isFind) {
				cout << "Yes";
				return 0;
			}
		}
	}

	cout << "No";

	return 0;
}