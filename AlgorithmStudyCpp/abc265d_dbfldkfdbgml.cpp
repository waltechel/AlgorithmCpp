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

	int N, P, Q, R;

	cin >> N >> P >> Q >> R;
	int* A = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	long long* B = new long long[N];
	for (int i = 0; i < N; i++) {
		B[i] = A[i];
		if (i > 0) {
			B[i] += B[i - 1];
		}
	}
	
	bool canFind = false;
	for (int x = 0; x <= N; x++) {
		for (int y = x + 1; y <= N; y++) {
			long long candiP = B[y - 1] - (x >= 1 ? B[x - 1] : 0);
			if (candiP < P) {
				continue;
			} else if (candiP > P) {
				break;
			} else if (candiP == P) {
				for (int z = y + 1; z <= N; z++) {
					long long candiQ = B[z - 1] - B[y - 1];
					if (candiQ < Q) {
						continue;
					} else if (candiQ > Q) {
						break;
					} else if (candiQ == Q) {
						for (int w = z + 1; w <= N; w++) {
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