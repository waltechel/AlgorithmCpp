#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

/*
	rights.insert({ y, { x } });
	이 문장의 의미를 모르겠어요 어쩌다보니 아다리가 맞았어요
*/

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	vector<pair<int, int>> list;
	string S;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		list.push_back({ x, y });
	}
	cin >> S;

	// 오른쪽으로 이동하는 애들 
	map<int, vector<int>> rights;
	// 왼쪽으로 이동하는 공등
	map<int, vector<int>> lefts;

	for (int i = 0; i < S.length(); i++) {
		char command = S[i];
		int x = list[i].first;
		int y = list[i].second;
		if (command == 'R') {
			if (rights.find(y) == rights.end()) {
				rights.insert({ y, { x } });
			} else {
				rights[y].push_back(x);
			}
		} else {
			if (lefts.find(y) == lefts.end()) {
				lefts.insert({ y, { x } });
			} else {
				lefts[y].push_back(x);
			}
		}
	}
	bool find = false;
	for (auto element : rights) {
		int rightY = element.first;
		sort(element.second.begin(), element.second.end());
		int rightMinX = element.second[0];
		if (lefts.find(rightY) == lefts.end()) {
			continue;
		} else {
			for (auto e2 : lefts[rightY]) {
				if (rightMinX < e2) {
					find = true;
				}
			}
		}
	}

	if (find) {
		cout << "Yes";
	} else {
		cout << "No";
	}

	return 0;
}