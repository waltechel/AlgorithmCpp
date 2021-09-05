#include <bits/stdc++.h>
using namespace std;
int tree[200001], ans[50001], a[50001];
void init(int node, int start, int end) {
	if (start == end) {
		tree[node] = 1;
		return;
	}
	int mid = (start + end) / 2;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int query(int node, int start, int end, int x) {
	if (start == end)return start;
	int mid = (start + end) / 2;
	if (tree[node * 2] < x)return query(node * 2 + 1, mid + 1, end, x - tree[node * 2]);
	else return query(node * 2, start, mid, x);
}
void update(int node, int start, int end, int x) {
	if (start > x || end < x)return;
	tree[node]--;
	if (start == end)return;
	int mid = (start + end) / 2;
	update(node * 2, start, mid, x);
	update(node * 2 + 1, mid + 1, end, x);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)cin >> a[i];
		init(1, 1, n);
		for (int i = n; i > 0; i--) {
			ans[i] = query(1, 1, n, a[i] + 1);
			update(1, 1, n, ans[i]);
			ans[i] = n - ans[i] + 1;
		}
		for (int i = 1; i <= n; i++)cout << ans[i] << ' ';
		cout << '\n';
	}
}