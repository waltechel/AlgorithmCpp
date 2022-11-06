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

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long N, P, Q, R;

	cin >> N >> P >> Q >> R;
	long long* A = new long long[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	long long* B = new long long[N + 3];
	for (int i = 0; i < N + 3; i++) {
		if (i < N) {
			B[i] = A[i];
		}
		if (i >= 1) {
			B[i] += B[i - 1];
		}
	}

	bool canFind = false;
	int x = 0, y = 1, z = 2, w = 3;
	for (; x <= N; x++) {
		for (; y <= N; y++) {
			if (!(x < y)) {
				y = x + 1;
			}
			long long candiP = B[y - 1] - (x >= 1 ? B[x - 1] : 0);
			if (candiP < P) {
				continue;
			} else if (candiP > P) {
				break;
			} else if (candiP == P) {
				for (; z <= N; z++) {
					if (!(y < z)) {
						z = y + 1;
					}
					long long candiQ = B[z - 1] - B[y - 1];
					if (candiQ < Q) {
						continue;
					} else if (candiQ > Q) {
						break;
					} else if (candiQ == Q) {
						for (; w <= N; w++) {
							if (!(z < w)) {
								w = z + 1;
							}
							long long candiR = B[w - 1] - B[z - 1];
							if (candiR < R) {
								continue;
							} else if (candiR > R) {
								break;
							} else if (candiR == R) {
								canFind = true;
							}
						}
					}
				}
			}
		}
	}

	if (canFind) {
		cout << "Yes";
	} else {
		cout << "No";
	}

	return 0;
}