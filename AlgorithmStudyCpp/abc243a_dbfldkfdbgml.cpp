#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
	a, b, c의 합 모듈러를 하면 쉽게 구할 수 있다.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	int V, A, B, C;
	cin >> V >> A >> B >> C;
	char answer = 'a';
	while (V >= 0) {
		V -= A;
		if (V < 0) {
			answer = 'F';
			break;
		}
		V -= B;
		if (V < 0) {
			answer = 'M';
			break;
		}
		V -= C;
		if (V < 0) {
			answer = 'T';
			break;
		}
	}


	cout << answer;
	return 0;
}