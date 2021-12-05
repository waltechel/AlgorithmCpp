#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
unsigned long long lis(vector<int> const &a) {
	vector<int> v;
	for(auto now : a) {
		if(v.empty() || v.back() < now) {
			v.push_back(now);
			continue;
		}
		*lower_bound(v.begin(), v.end(), now) = now;
	}
	return v.size();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		int n, m, x; cin >> n >> m;
		vector<int> a, b;
		for(int i = 0; i < n; i++) {
			cin >> x; a.push_back(x);
		}
		for(int i = 0; i < m; i++) {
			cin >> x;
			bool flag = false;
			for(auto now : a) {
				if(x == now) {
					flag = true;
					break;
				}
			}
			if(!flag) b.push_back(x);
		}
		cout << lis(a) + lis(b) << '\n';
	}
}