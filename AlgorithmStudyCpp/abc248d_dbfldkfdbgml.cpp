#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>

using namespace std;

/*
	값의 인덱스를 넣어두고 계산하면 되는 거 같음
*/
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	int N;
	cin >> N;
	vector<int>* A = new vector<int>[N + 1];
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		A[num].push_back(i);
	}

	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int L, R, X;
		cin >> L >> R >> X;
		// A[X]에서 L보다 크거나 같고 R보다 작거나 같은 값이 몇 개 있는지 찾아내는 방법
		// upper_bound : R보다 큰 값이 처음으로 나오는 위치
		// lower_boudn : L보다 크거나 같은 값이 처음으로 나오는 위치
		// c++은 이게 좋은듯
		int cnt = upper_bound(A[X].begin(), A[X].end(), R) - lower_bound(A[X].begin(), A[X].end(), L);
		cout << cnt << "\n";
	}
	
	return 0;
}