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

// 몇 번 뺑뺑이를 돌았는지만 알면 나머지는 대충 알 수 있다.
// priorityQueue를 쓰면 nlogn으로 할 수 있다.

int main() {
	 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long N, K;
	cin >> N >> K;
	long long* A = new long long[N];

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	long long cntOfLoop = 0;
	for (long long i =  (((long long)1) << 40); i > 0; i /= 2) {
		// i 번 돌았을 때 K를 못 채웠다고 생각하면 돌아도 된다.
		long long candi = 0;
		cntOfLoop += i;
		for (int j = 0; j < N; j++) {
			candi += min(cntOfLoop, A[j]);
		}
		if (candi > K) {
			cntOfLoop -= i;
		}
	}

	// 정리를 한번 한다.
	for (int i = 0; i < N; i++) {
		K -= min(cntOfLoop, A[i]);
		A[i] -= min(cntOfLoop, A[i]);
	}

	// 자투리를 정리한다.
	for (int i = 0; i < N; i++) {
		if (K > 0 && A[i] > 0) {
			K--;
			A[i]--;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << A[i] << " ";
	}

			
	return 0;
}