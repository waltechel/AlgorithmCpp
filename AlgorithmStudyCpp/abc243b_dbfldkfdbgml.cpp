#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
	set<int> Set은 순회가 가능하다.
	set은 이진 트리로 구성되어 있어 순회가 가능하다.
*/

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	int N;
	cin >> N;
	int* A = new int[N + 1];
	int* B = new int[N + 1];

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> B[i];
	}
	int a = 0;
	int b = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (A[i] == B[j]) {
				if (i == j) {
					a++;
				} else {
					b++;
				}
			}
		}
	}

	cout << a << "\n" << b;

	return 0;
}