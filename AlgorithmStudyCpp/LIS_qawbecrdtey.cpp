#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> v;
		while(n--) {
			int x; cin >> x;
			if(v.empty() || v.back() < x) {
				v.push_back(x);
				continue;
			}
			*lower_bound(v.begin(), v.end(), x) = x;
		}
		cout << v.size() << '\n';
	}
}