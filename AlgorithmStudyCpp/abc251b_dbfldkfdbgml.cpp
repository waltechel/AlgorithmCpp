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

	int N, W;
	cin >> N >> W;
	int* A = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	unordered_set<int> answers;
	if (N >= 1) {
		for (int i = 0; i < N; i++) {
			if (A[i] <= W) {
				answers.insert(A[i]);
			}
		}
	}

	if (N >= 2) {
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (A[i] + A[j] <= W) {
					answers.insert(A[i] + A[j]);
				}
			}
		}
	}

	if (N >= 3) {
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				for (int k = j + 1; k < N; k++) {
					if (A[i] + A[j] + A[k] <= W) {
						answers.insert(A[i] + A[j] + A[k]);
					}
				}
			}
		}
	}

	cout << answers.size();

	return 0;
}