#include <iostream>
#include <set>
#include <queue>
#include <utility>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int n; cin >> n;
		auto a = new pair<int, int>[n];
		bool p = false, m = false;
		for(int i = 0; i < n; i++) {
			cin >> a[i].first >> a[i].second;
			a[i].second -= a[i].first;
			p = p || (a[i].second >= 0);
			m = m || (a[i].second <= 0);
		}
		set<int> s;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		if(!p && !m) {
			goto NO;
		}
		for(int i = 0; i < n; i++) pq.push(a[i]);
		while(!pq.empty()) {
			auto const now = pq.top(); pq.pop();
			if(s.find(now.second) != s.end()) continue;
			s.insert(now.second);
			if(!now.second) {
				cout << now.first << '\n';
				goto END;
			}
			for(int i = 0; i < n; i++) {
				int const next = now.second + a[i].second;
				if(next > 200 || next < -200) continue;
				if(s.find(next) != s.end()) continue;
				pq.push({ now.first + a[i].first, next });
			}
		}
	NO:	cout << "IMPOSSIBLE\n";
	END:delete[] a;
	}
}