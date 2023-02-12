#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

/*
*	정렬만 하면 알 수 있는데 그 안에 두 사람이 부딪치면 안 부딪칠 수가 없다.
*   반드시 이웃한 두 사람에 대해 부딪치는 경우가 있어야 한다. 
*   Y좌표가 같고 i-1과 i가 부딪칠 만한 애인지 보면 된다.
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