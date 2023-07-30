#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <unordered_set>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long X, A, D, N;

	cin >> X >> A >> D >> N;
	long long A0 = A;
	long long An_1 = A + (N - 1) * D;

	long long answer = -1;
	if (D > 0) {
		if (X >= An_1) {
			answer = abs(X - An_1);
		} else if (X <= A0) {
			answer = abs(A0 - X);
		} else {
			// 작은 것들 중에 가장 큰 것
			long long a = 0;
			for (long long i = (long long)1l << 40; i > 1; i /= 2) {
				a += i;
				if (a >= N) {
					a -= i;
					continue;
				}
				long long candi = A + a * D;
				if (candi > X) {
					a -= i;
					continue;
				}
			}
			long long minMax = A + a * D;
			// 큰 것들 중에 가장 작은 것
			long long minMax2 = minMax + D;
			answer = min(abs(X - minMax), abs(X - minMax2));
		}
	} else {
		if (X >= A0) {
			answer = abs(X - A0);
		} else if (X <= An_1) {
			answer = abs(A0 - X);
		} else {
			// 작은 것들 중에 가장 큰 것
			long long a = 0;
			for (long long i = (long long)1l << 40; i > 1; i /= 2) {
				a += i;
				if (a >= N) {
					a -= i;
					continue;
				}
				long long candi = A + a * D;
				if (candi > X) {
					a -= i;
					continue;
				}
			}
			long long minMax = A + a * D;
			// 큰 것들 중에 가장 작은 것
			long long minMax2 = minMax + D;
			answer = min(abs(X - minMax), abs(X - minMax2));
		}

	}
	

	cout << answer;

	return 0;
}