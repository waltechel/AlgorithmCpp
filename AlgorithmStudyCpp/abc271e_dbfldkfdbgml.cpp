#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<queue>
#include<stack>
#include<unordered_set>
#include<regex>
#include <climits>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	int* A = new int[M];
	int* B = new int[M];
	int* C = new int[M];
	for (int i = 0; i < M; i++) {
		cin >> A[i] >> B[i] >> C[i];
	}
	long long maximum = LLONG_MAX / 10000;
	long long* dist = new long long[N + 1];
	for (int i = 0; i <= N; i++) {
		dist[i] = maximum;
	}
	dist[1] = 0;

	int e;
	for (int i = 0; i < K; i++) {
		cin >> e;
		e--;
		int a = A[e];
		int b = B[e];
		int c = C[e];
		if (dist[B[e]] > dist[A[e]] + C[e]) {
			dist[B[e]] = dist[A[e]] + C[e];
		}
	}

	if (dist[N] == maximum) {
		cout << "-1";
	} else {
		cout << dist[N];
	}

	return 0;
}