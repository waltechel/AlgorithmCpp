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

	long long N, Q;
	cin >> N >> Q;
	
	vector<long long> A;
	for (int i = 0; i < N; i++) {
		long long temp;
		cin >> temp;
		A.push_back(temp);
	}
	sort(A.begin(), A.end());

	vector<long long> B;
	B.push_back(A[0]);
	for (int i = 1; i < N; i++) {
		long long temp = B[i - 1] + A[i];
		B.push_back(temp);
	}

	for (int q = 0; q < Q; q++) {
		long long query;
		cin >> query;
		int index = -1;
		for (int i = 1 << 20; i > 0; i /= 2) {
			index += i;
			if (N <= index) {
				index -= i;
				continue;
			}
			if (query < A[index]) {
				index -= i;
				continue;
			}
		}

		// 0부터 index 까지는 query보다 작음
		long long left = 0;
		if (index != -1) {
			left = query * (index + 1) - B[index];
		}
		
		// index + 1부터 N - 1까지는 query보다 큼
		long long right = 0;
		if (index != -1) {
			right = B[N - 1] - B[index] - query * (N - 1 - index);
		} else {
			right = B[N - 1] - query * N;
		}
		
		long long answer = left + right;
		cout << answer << "\n";
		
	}

	return 0;
}