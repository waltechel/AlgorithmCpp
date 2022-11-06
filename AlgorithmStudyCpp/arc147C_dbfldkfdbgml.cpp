#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<queue>

using namespace std;

int main() {

	int N;
	cin >> N;
	vector<long long> L(N), R(N);
	for (int i = 0; i < N; i++) {
		cin >> L[i] >> R[i];
	}

	sort(L.begin(), L.end(), greater<>());
	sort(R.begin(), R.end());

	long long answer = 0;
	for (int i = 0; i < N; i++) {
		answer += max(0ll, L[i] - R[i]) * (N - 2 * i - 1);
	}
	cout << answer;
	
	return 0;
}

