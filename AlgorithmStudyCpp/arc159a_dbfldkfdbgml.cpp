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

using namespace std;

/*
	플로이드 행렬이 대칭이 되는 거 같다...!
	그런데 이게 왜 되는 걸까...?
*/

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;
	vector<vector<long long>> graph(N, vector<long long>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			if (temp != 0) {
				graph[i][j] = temp;
			} else {
				graph[i][j] = 100000000000l;
			}
		}
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		long long from, to;
		cin >> from >> to;
		from--;
		to--;
		from %= N;
		to %= N;
		if (graph[(int)from][(int)to] != 100000000000l) {
			cout << graph[(int) from][(int) to] << "\n";
		} else {
			cout << "-1\n";
		}
	}

	return 0;
}