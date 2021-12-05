#include <bits/stdc++.h>
using namespace std;
int d[100001];
string s;
const int INF = 100001;
int Range(int start, int end) {
	bool flag = true;
	//모두 같다
	for (int i = start; i <= end; i++) {
		if (s[start] != s[i]) {
			flag = false;
			break;
		}
	}
	if (flag)return 1;
	//등차 수열
	int dif = s[start + 1] - s[start];
	for (int i = start + 1; i <= end; i++) {
		if (s[i] - s[i - 1] != dif) {
			flag = true;
			break;
		}
	}
	if (flag == false) {
		if (dif == 1 || dif == -1)return 2;
		else return 5;
	}
	//두개 숫자 번갈아 출현
	for (int i = start + 2; i <= end; i += 2) {
		if (s[i - 2] != s[i]) {
			flag = false;
			break;
		}
	}
	for (int i = start + 3; i <= end; i += 2) {
		if (s[i - 2] != s[i]) {
			flag = false;
			break;
		}
	}
	if (flag)return 4;
	//그 외
	return 10;
}
int solve(int idx) {
	if (idx >= s.size())return 0;
	if (s.size() - idx < 3)return INF;
	if (d[idx] != -1)return d[idx];
	d[idx] = INF;
	for (int i = 2; i <= 4; i++) {
		if (idx + i < s.size()) {
			d[idx] = min(d[idx], solve(idx + i + 1) + Range(idx, idx + i));
		}
	}
	return d[idx];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		cin >> s;
		for (int i = 0; i < s.size(); i++)d[i] = -1;
		cout << solve(0) << '\n';
	}
}