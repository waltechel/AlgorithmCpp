#include <bits/stdc++.h>
using namespace std;
map<vector<int>, int> Map;
bool check[10];
void go(int n) {
	vector<int> start(n);
	for (int i = 0; i < n; i++)start[i] = i;
	Map[start] = 1;
	queue<vector<int>> q;
	q.push(start);
	while (!q.empty()) {
		vector<int> now = q.front();
		q.pop();
		int cost = Map[now] + 1;
		for (int i = 0; i < n; i++) {
			for (int j = i + 2; j <= n; j++) {
				reverse(now.begin() + i, now.begin() + j);
				if (Map[now] == 0) {
					Map[now] = cost;
					q.push(now);
				}
				reverse(now.begin() + i, now.begin() + j);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> v(n), v2(n);
		for (int i = 0; i < n; i++)cin >> v[i];
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (v[i] > v[j])cnt++;
			}
			v2[i] = cnt;
		}
		if (check[n] == false) {
			check[n] = true;
			go(n);
		}
		cout << Map[v2] - 1 << '\n';
	}

}