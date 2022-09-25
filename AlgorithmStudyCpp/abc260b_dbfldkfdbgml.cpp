#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, X, Y, Z;
	cin >> N >> X >> Y >> Z;

	int* A = new int[N];
	int* B = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}

	bool* checked = new bool[N];
	for (int i = 0; i < N; i++) {
		checked[i] = false;
	}

	vector<int> answer;
	// 수학 점수가 높은 순서대로 X 쳐내기
	for (int i = 0; i < X; i++) {
		int index = 0; 
		int criteria = -1;
		for (int j = 0; j < N; j++) {
			if (checked[j] == false && criteria < A[j]) {
				criteria = A[j];
				index = j;
			}
		}
		checked[index] = true;
		answer.push_back(index + 1);
	}

	// 영어 점수가 높은 순서대로 X 쳐내기
	for (int i = 0; i < Y; i++) {
		int index = 0;
		int criteria = -1;
		for (int j = 0; j < N; j++) {
			if (checked[j] == false && criteria < B[j]) {
				criteria = B[j];
				index = j;
			}
		}
		checked[index] = true;
		answer.push_back(index + 1);
	}

	// 수학 + 영어 점수가 높은 순서대로 X 쳐내기
	for (int i = 0; i < Z; i++) {
		int index = 0;
		int criteria = -1;
		for (int j = 0; j < N; j++) {
			if (checked[j] == false && criteria < A[j] + B[j]) {
				criteria = A[j] + B[j];
				index = j;
			}
		}
		checked[index] = true;
		answer.push_back(index + 1);
	}

	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}


	return 0;
}