#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>

using namespace std;

/*
* 시간, long long 주의
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long N, M, T;
	cin >> N >> M >> T;
	int* A = new int[N];
	for (int i = 1; i <= N - 1; i++) {
		cin >> A[i];
	}

	unordered_map<int, int> B;
	int X, Y;
	for (int i = 1; i <= M; i++) {
		cin >> X >> Y;
		B[X] = Y;
	}


	bool canGo = true;
	for (int now = 1; now < N;) {
		int time = A[now];
		T -= time;
		if (T <= 0) {
			canGo = false;
			break;
		}
		now++;
		T += B[now];
	}

	if (canGo) {
		cout << "Yes";
	} else {
		cout << "No";
	}


	return 0;
}