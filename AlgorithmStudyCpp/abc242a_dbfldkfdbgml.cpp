#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	int A, B, C, X;
	cin >> A >> B >> C >> X;

	if (X <= A) {
		cout << 1;
	} else if (A + 1 <= X && X <= B) {
		cout << (double)C / (B - A);
	} else {
		cout << 0;
	}

	return 0;
}