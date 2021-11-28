#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		auto a = new int*[n];
		auto visited = new bool*[n];
		for(int i = 0; i < n; i++) {
			a[i] = new int[n];
			visited[i] = new bool[n]();
			for(int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		queue<pair<int, int>> q;
		q.push({ 0, 0 });
		while(!q.empty()) {
			auto const now = q.front(); q.pop();
			if(visited[now.first][now.second]) continue;
			visited[now.first][now.second] = true;
			if(now.first == n - 1 && now.second == n - 1) {
				printf("YES\n");
				goto END;
			}
			auto const val = a[now.first][now.second];
			if(now.first + val < n && !visited[now.first + val][now.second])
				q.push({ now.first + val, now.second });
			if(now.second + val < n && !visited[now.first][now.second + val])
				q.push({ now.first, now.second + val });
		}
		printf("NO\n");
	END:for(int i = 0; i < n; i++) delete[] a[i];
		delete[] a;
	}
}