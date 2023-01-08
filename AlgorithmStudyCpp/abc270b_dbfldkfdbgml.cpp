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

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int X, Y, Z;
	cin >> X >> Y >> Z;

	int now = 0;

	// 열쇠를 갖고 가느냐 아니면 그냥 가느냐 둘 중에 작은 것이 답
	int t1 = 10000;
	int t2 = 10000;

	if (X < 0) {
		if (X < Y && Y < 0) {
			// 열쇠를 먹는 경우
			if (Y < Z) {
				t1 = abs(Z) + abs(Y - Z) + abs(X - Y);
			}
			// 열쇠를 못 먹으면 가지 못한다.
		} else {
			t1 = abs(X);
		}
	} else {
		if (Y < X && 0 < Y) {
			// 열쇠를 먹는 경우
			if (Z < Y) {
				t2 = abs(Z) + abs(Y - Z) + abs(X - Y);
			}
			// 열쇠를 못 먹으면 가지 못한다
		} else {
			t2 = abs(X);
		}
	}

	int answer = min(t1, t2);
	if (answer == 10000) {
		cout << "-1";
	} else {
		cout << answer;
	}



	return 0;
}