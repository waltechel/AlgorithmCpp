#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <unordered_set>
#include <set>

using namespace std;

/*
	이 소스는 TLE가 나는데 왜 그런가요?
*/

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	/*cout << fixed;
	cout.precision(0);*/

	multiset<int> multiset;
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int command;
		cin >> command;
		if (command == 1) {
			int X;
			cin >> X;
			multiset.insert(X);
		} else if (command == 2) {
			int x, c;
			cin >> x >> c;
			int count = multiset.count(x);
			int m = min(count, c);
			for (int i = 0; i < m; i++) {
				multiset.erase(multiset.find(x));
			}
		} else if (command == 3) {
			int max_val = *multiset.rbegin();
			int min_val = *multiset.begin();
			int diff = max_val - min_val;
			cout << diff << "\n";
		}
	}

	return 0;
}