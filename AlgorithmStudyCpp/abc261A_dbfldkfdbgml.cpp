#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>

/*
	l과 r을 비교해서 풀 수 있다.
	max(l) 왼쪽은 겹치지 않고, min(r) 오른쪽도 겹치지 않으며
	r < l 이라면 두 막대는 서로 떨어져 있다.
*/
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int L1, R1, L2, R2;

	int* A = new int[200];
	cin >> L1 >> R1 >> L2 >> R2;

	for (int i = 0; i <= 200; i++) {
		A[i] = 0;
	}

	for (int i = L1; i <= R1; i++) {
		A[i]++;
	}
	for (int i = L2; i <= R2; i++) {
		A[i]++;
	}

	int cnt = 0;
	for (int i = 0; i <= 200; i++) {
		if (A[i] == 2) {
			cnt++;
		}
	}

	if (cnt >= 2) {
	cout << cnt - 1;

	} else {
		cout << 0;
	}

	return 0;
}

