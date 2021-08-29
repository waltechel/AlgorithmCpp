#include <bits/stdc++.h>
using namespace std;
int preorder[101], inorder[101], idx[1001];
void go(int ps, int pe, int is, int ie) {
	int mid = idx[preorder[ps]];
	int l = mid - is, r = ie - mid;
	if (l)go(ps + 1, ps + l, is, is + l - 1);
	if (r)go(pe - r + 1, pe, mid + 1, mid + r);
	cout << preorder[ps] << ' ';
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)cin >> preorder[i];
		for (int i = 0; i < n; i++) {
			cin >> inorder[i];
			idx[inorder[i]] = i;
		}
		go(0, n - 1, 0, n - 1);
		cout << '\n';
	}
}