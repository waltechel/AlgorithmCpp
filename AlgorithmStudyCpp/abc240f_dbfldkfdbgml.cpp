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

double f2(long long A, long long B, double x) {
	return A - (B + x / 2) * (B + x / 2) / (2 * x);
}

long long f(long long A, long long B, long long x, int n) {
	return A + n * B + x * n * (n + 1) / 2;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		long long answer = LLONG_MIN;
		int N, M;
		cin >> N >> M;
		long long A = 0, B = 0;
		for (int i = 0; i < N; i++) {
			long long x, y;
			cin >> x >> y;
			if (x > 0) {
				long long left = f(A, B, x, 1);
				answer = max(answer, left);
				long long right = f(A, B, x, y);
				answer = max(answer, right);
			} else {
				double candi = f2(A, B, (double)x);
				if (candi < 0) {
					candi -= 1;
					answer = max(answer, (long long)candi);
				} else {
					answer = max(answer, (long long) candi);
				}
			}
			A = f(A, B, x, y);
			B += x * y;
		}
		cout << answer << "\n";
	}
	
	return 0;
}