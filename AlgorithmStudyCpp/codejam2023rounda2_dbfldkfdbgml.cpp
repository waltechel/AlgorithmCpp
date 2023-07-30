#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <unordered_set>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed;
	cout.precision(0);

	int T;
	cin >> T;
	for (int test = 1; test <= T; test++) {
		int M, R, N;
		cin >> M >> R >> N;

		vector<int> lights(N);
		for (int i = 0; i < N; i++) {
			cin >> lights[i];
		}
		// 만약에 모든 불을 다 켰는데도 중간에 비는 데가 있거나 끝까지 못가면 그거는 문제가 있다.
		int current = 0;
		for (int i = 0; i < N; i++) {
			if (lights[i] <= current + R) {
				current = lights[i] + R;
			}
		}
		if (current < M) {
			cout << "Case #" << test << ": IMPOSSIBLE\n";
			continue;
		}


		// 순서대로 통과하면 된다.
		int answer = 0;
		int now = 0;
		for (int start = 0; start < lights.size() && now < M; ) {
			int index = -1;
			for (int i = start; i < lights.size(); i++) {
				if (lights[i] <= now + R) {
					index = i;
				} else {
					break;
				}
			}
			if (index != -1) { // 선택했다는 뜻이므로 
				now = lights[index] + R;
				start = index + 1;
				answer++;
			} else {
				break;
			}
		}

		cout << "Case #" << test << ": " <<  answer << "\n";

	}
	
	return 0;
}