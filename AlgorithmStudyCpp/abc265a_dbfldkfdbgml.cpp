#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int xPrice, yPrice, N;

	cin >> xPrice >> yPrice >> N;

	if (3 * xPrice <= yPrice) {
		// 1개씩 사는 게 나은 경우도 있다.
		cout << N * xPrice;
	} else {
		// 3개씩 사고 자투리를 1개씩 산다.
		cout << N / 3 * yPrice + N % 3 * xPrice;
	}

	// 그냥 min 값 주고 찾으면 된다.
	// cout << min(N * xPrice, N / 3 * yPrice + N % 3 * xPrice);

	return 0;
}