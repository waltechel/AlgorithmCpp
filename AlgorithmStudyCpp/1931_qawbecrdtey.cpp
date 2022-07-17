#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	auto a = new pair<int, int>[n];
	for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	sort(a, a + n, [](pair<int, int> const &a, pair<int, int> const &b) {
		return a.second < b.second || (a.second == b.second && a.first < b.first);
	});
	int current_time = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(current_time > a[i].first) continue;
		current_time = a[i].second;
		cnt++;
	} cout << cnt;
}