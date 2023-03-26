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

int H, W, R, C;
bool isSafe(int r, int c) {
	if (1 <= r && r <= H && 1 <= c && c <= W) {
		return true;
	} else {
		return false;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> H >> W >> R >> C;
	int answer = 0;
	if (isSafe(R - 1, C)) {
		answer++;
	}
	if (isSafe(R + 1, C)) {
		answer++;
	}
	if (isSafe(R, C + 1)) {
		answer++;
	}
	if (isSafe(R, C - 1)) {
		answer++;
	}

	cout << answer;



	return 0;
}