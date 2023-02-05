#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


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