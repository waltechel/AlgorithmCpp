#include <bits/stdc++.h>
using namespace std;
int a[50001], b[50001];
long long ans;
void Merge(int start, int end) {
	int mid = (start + end) / 2;
	int i = start, j = mid + 1, k = start;
	while (i <= mid && j <= end) {
		if (a[i] <= a[j])b[k++] = a[i++];
		else {
			b[k++] = a[j++];
			ans += mid - i + 1LL;
		}
	}
	while (i <= mid)b[k++] = a[i++];
	while (j <= end)b[k++] = a[j++];
	for (int i = start; i <= end; i++)a[i] = b[i];
}
void Sort(int start, int end) {
	if (start == end)return;
	int mid = (start + end) / 2;
	Sort(start, mid);
	Sort(mid + 1, end);
	Merge(start, end);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		if (n == 1) {
			cout << 0 << '\n';
			continue;
		}
		Sort(0, n - 1);
		cout << ans << '\n';
	}
}