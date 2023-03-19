#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>

using namespace std;

// 300개의 점 중에 K개의 점을 통과하는 직선이 몇 개 있는지 계산하는 문제
// 모든 두 점의 기울기와 절편을 계산해서 그것들의 직선의 방정식을 구하면 되는 문제
// (0, -1), (1, 0) 은 y = x + 1 -> x - y + 1이 되므로 1, -1, 1이 된다. 
// x증가분, y증가분 해서 기울기를 구하고, 절편을 구한다.
// 이거 구현은 했는데 틀림

pair<int, int> getNotZeroPoint(int x1, int y1, int x2, int y2) {
	if (x1 != 0 || y1 != 0) {
		return make_pair(x1, y1);
	} else {
		return make_pair(x2, y2);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	int N, K;
	cin >> N >> K;
	vector<pair<int, int>> A;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		A.push_back({ x, y });
	}

	map<tuple<int, int, long long>, int> list;
	for (int i = 0; i < A.size(); i++) {
		for (int j = i + 1; j < A.size(); j++) {
			int x1 = A[i].first;
			int y1 = A[i].second;
			int x2 = A[j].first;
			int y2 = A[j].second;
			// ax + by + c = 0;을 만들어야 하므로
			int a = y2 - y1;
			int b = x2 - x1;
			pair<int, int> notZero = getNotZeroPoint(x1, y1, x2, y2);
			long long c = ((long long)a * notZero.first - (long long)b * notZero.second) * -1;
			// 처음에는 2를 넣어야 함 그 다음에는 1을 더해야 함
			tuple<int, int, int> t = make_tuple(a, b * -1, c);
			if (x1 == x2) {
				// y 수직선이라는 얘기이므로
				t = make_tuple(1, 0, -x1);
			}

			if (y1 == y2) {
				t = make_tuple(0, 1, -y1);
			}

			if (list.count(t) != 0) {
				list[t]++;
			} else {
				list[t] = 2;
			}
		}
	}

	int answer = 0;
	for (auto line: list) {
		int cnt = line.second;
		if (cnt >= K) {
			answer++;
		}
	}

	if (K == 1) {
		cout << "Infinity";
	} else {
		cout << answer;
	}

	
	return 0;
}