#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	vector<pair<int, int>> list;

	int Q;
	cin >> Q;
	int index = 0;
	for (int i = 0; i < Q; i++) {
		int command;
		cin >> command;
		if (command == 1) {
			int x, c;
			cin >> x >> c;
			list.push_back({ x, c });
		} else if (command == 2) {
			int c;
			cin >> c;
			long long answer = 0;
			while (c) {
				if(list[index].second > c){
					answer += (long long)list[index].first * c;
					list[index].second -= c;
					c = 0;
				} else {
					answer += (long long)list[index].first * list[index].second;
					c -= list[index].second;
					index++;
				}
			}
			cout << answer << "\n";
		}
	}

	return 0;
}