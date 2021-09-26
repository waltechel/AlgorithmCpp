#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
int ind[26];
void makeGraph(const vector<string>& words) {
	adj = vector<vector<int>>(26, vector<int>(26, 0));
	for (int j = 1; j < words.size(); ++j) {
		int i = j - 1, len = min(words[i].size(), words[j].size());
		for (int k = 0; k < len; k++) {
			if (words[i][k] != words[j][k]) {
				int a = words[i][k] - 'a';
				int b = words[j][k] - 'a';
				if (adj[a][b])break;
				adj[a][b] = 1;
				ind[b]++;
				break;
			}
		}
	}
}
vector<int> order;

vector<int> topologicalSort() {
	order.clear();
	queue<int> q;
	bool check[26];
	for (int i = 0; i < 26; i++) {
		check[i] = false;
		if (ind[i] == 0) {
			q.push(i);
			check[i] = true;
		}

	}
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		order.push_back(x);
		for (int i = 0; i < 26; i++) {
			if (check[i] == false && adj[x][i]) {
				ind[i]--;
				if (ind[i] == 0) {
					q.push(i);
					check[i] = true;
				}
			}
		}
	}
	if (order.size() != 26)return vector<int>();
	for (int i = 0; i < 26; i++) {
		for (int j = i + 1; j < 26; j++) {
			if (adj[order[j]][order[i]])return vector<int>();
		}
	}
	return order;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < 26; i++)ind[i] = 0;
		vector<string> v(n);
		for (int i = 0; i < n; i++)cin >> v[i];
		makeGraph(v);
		vector<int> ans = topologicalSort();
		if (ans.size() == 0)cout << "INVALID HYPOTHESIS\n";
		else {
			for (auto k : ans) {
				cout << (char)(k + 'a');
			}
			cout << '\n';
		}
	}
}