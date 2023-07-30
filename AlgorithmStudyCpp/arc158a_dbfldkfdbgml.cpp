#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<queue>
#include<stack>
#include<unordered_set>
#include<regex>

using namespace std;

/*
	+ 3, + 5, + 7을 결국 -2, 0, 2로 치환하는 것은 생각
	3으로 나누었을 때 나누어 떨어지면 답이 있을 거라는 것은 직감
	결국 절댓값의 합을 4로 나눈 거리가 답
	그리고 차이가 홀수면 절대로 답이 나오지 않음
*/


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		long long x1, x2, x3;
		cin >> x1 >> x2 >> x3;
		if ((x1 + x2 + x3) % 3 != 0) {
			cout << "-1\n";
			continue;
		}
		if (abs(x1 - x2) % 2 != 0) {
			cout << "-1\n";
			continue;
		}
		if (abs(x2 - x3) % 2 != 0) {
			cout << "-1\n";
			continue;
		}
		if (abs(x3 - x1) % 2 != 0) {
			cout << "-1\n";
			continue;
		}
		long long a = (x1 + x2 + x3) / 3;
		cout << (abs(x1 - a) + abs(x2 - a) + abs(x3 - a)) / 4 << "\n";
	}

	return 0;
}