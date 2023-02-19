#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	int N, M;
	cin >> N >> M;
	vector<int> A(N + 1, 0);
	vector<int> C(N + M + 1, 0);
	vector<int> B(M + 1, 0);
	for (int i = 0; i <= N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i <= N + M; i++) {
		cin >> C[i];
	}

	// 이거를 거꾸로 해야 한다.
	for (int i = M; i >= 0; i--) {
		B[i] = C[i + N] / A[N];
		for (int j = 0; j <= N; j++) {
			C[i + j] -= B[i] * A[j];
		}
	}

	for (int i = 0; i <= M; i++) {
		cout << B[i] << " ";
	}

	return 0;
}