#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<stack>

// 그런데 이게 x, y가 같을 필요가 없지 않나?
using namespace std;

void dfs(int depth, int value);

int main() {

	long long N, L, R;
	cin >> N >> L >> R;
	long long* A = new long long[N + 1];
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	long long* left = new long long[N + 1];
	left[0] = 0;
	left[1] = min(L, A[1]);
	for (int i = 2; i <= N; i++) {
		left[i] = min(left[i - 1] + A[i], L * i);
	}

	//cout << "left is : \n";
	//for (int i = 1; i <= N; i++) {
	//	cout << left[i] << " ";
	//}
	//cout << "\n";

	long long* right = new long long[N + 2];
	right[N + 1] = 0;
	right[N] = min(R, A[N]);
	for (int i = N - 1; i >= 1; i--) {
		right[i] = min(right[i + 1] + A[i], R * (N + 1 - i));
	}

	//cout << "right is : \n";
	//for (int i = 1; i <= N; i++) {
	//	cout << right[i] << " ";
	//}
	//cout << "\n";

	long long answer = 1e17;
	for (int i = 0; i <= N; i++) {
		answer = min(answer, left[i] + right[i + 1]);
	}

	cout << answer;

	return 0;
}


