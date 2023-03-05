#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>

using namespace std;

int* parent;
int* parentSize;

int find(int a) {
	if (parent[a] == a) {
		return a;
	} else {
		return parent[a] = find(parent[a]);
	}
}

void merge(int a, int b) {
	int rootA = find(a);
	int rootB = find(b);
	if (rootA < rootB) {
		parent[rootB] = rootA;
		parentSize[rootA] += parentSize[rootB];
		parentSize[rootB] = 0;
	} else {
		parent[rootA] = rootB;
		parentSize[rootB] += parentSize[rootA];
		parentSize[rootA] = 0;
	}
}

/*
	이 문제가 E번보다 사실 구현은 더 쉬운 거 같음 답에서 말하는 대로 
	F(1) = 1, F(2) = 2, F(3) = 3, F(N) = F(N - 1) + F(N - 2)
	G(1) = 1, G(2) = 2, G(3) = 4, G(N) = F(N - 1) + F(N - 3)
	이거를 각 사이클마다 얻어낸 다음에 서로 곱해서 해결하면 된다
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	const int MOD = 998244353;

	vector<long long> F;
	vector<long long> G;
	F.push_back(1); // 0은 깔아넣음
	F.push_back(2);
	F.push_back(3);
	F.push_back(5);
	for (int i = 4; i <= 200000; i++) {
		F.push_back((F[i - 1] + F[i - 2]) % MOD);
	}
	G.push_back(1); // 0은 깔아넣음
	G.push_back(1);
	G.push_back(3);
	G.push_back(4);
	for (int i = 4; i <= 200000; i++) {
		G.push_back((F[i - 1] + F[i - 3]) % MOD);
	}

	int N;
	vector<int> P;
	vector<int> Q;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		P.push_back(p);
	}
	for (int i = 0; i < N; i++) {
		int q;
		cin >> q;
		Q.push_back(q);
	}

	parent = new int[N + 1];
	parentSize = new int[N + 1];
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
		parentSize[i] = 1;
	}

	for (int i = 0; i < N; i++) {
		int from = P[i];
		int to = Q[i];
		if(find(from) != find(to))
			merge(from, to);
	}

	long long answer = 1;
	for (int i = 1; i <= N; i++) {
		answer *= G[parentSize[i]];
		answer %= MOD;
	}

	cout << answer;

	return 0;
}