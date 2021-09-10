#include <bits/stdc++.h>
using namespace std;
int a[100001], maxTree[400001], minTree[400001];
void init(int node, int start, int end) {
	if (start == end) {
		minTree[node] = maxTree[node] = a[start];
		return;
	}
	int mid = (start + end) / 2;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);
	minTree[node] = min(minTree[node * 2], minTree[node * 2 + 1]);
	maxTree[node] = max(maxTree[node * 2], maxTree[node * 2 + 1]);
}
pair<int, int> query(int node, int start, int end, int x, int y) {
	if (start > y || end < x)return{ 0,100001 };
	if (start >= x && end <= y)return { maxTree[node],minTree[node] };
	int mid = (start + end) / 2;
	pair<int, int> m1 = query(node * 2, start, mid, x, y);
	pair<int, int> m2 = query(node * 2 + 1, mid + 1, end, x, y);
	return { max(m1.first,m2.first),min(m1.second,m2.second) };
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)cin >> a[i];
		init(1, 1, n);
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			x++; y++;
			pair<int, int> ans = query(1, 1, n, x, y);
			cout << ans.first - ans.second << '\n';
		}
	}
}