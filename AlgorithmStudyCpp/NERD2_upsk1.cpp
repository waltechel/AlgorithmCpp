#include <bits/stdc++.h>
using namespace std;
map<int, int> coords, resetM;
int csize = 0;
bool isDominated(int x, int y) {
	map<int, int>::iterator it = coords.lower_bound(x);
	if (it == coords.end())return false;
	return y < it->second;
}
void removeDominated(int x, int y) {
	map<int, int>::iterator it = coords.lower_bound(x);
	if (it == coords.begin())return;
	--it;
	while (true) {
		if (it->second > y)break;
		if (it == coords.begin()) {
			coords.erase(it);
			csize--;
			break;
		}
		else {
			map<int, int>::iterator jt = it;
			--jt;
			coords.erase(it);
			it = jt;
			csize--;
		}
	}
}
int registered(int x, int y) {
	if (isDominated(x, y))return coords.size();
	removeDominated(x, y);
	coords[x] = y;
	csize++;
	return csize;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, ans = 0;
		csize = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			ans += registered(x, y);
		}
		coords = resetM;
		cout << ans << '\n';
	}

}