#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int main() {

	int TEST;
	cin >> TEST;
	for (int test = 0; test < TEST; test++) {

		int n, r, b;
		cin >> n >> r >> b;

		int d;
		if (r % (b + 1) == 0) {
			d = r / (b + 1);
			for (int i = 0; i < b + 1; i++) {
				for (int j = 0; j < d; j++) {
					cout << "R";
				}
				if (i != b) {
					cout << "B";
				}
			}
		} else {
			d = r / (b + 1);
			int q = r % (b + 1);
			for (int i = 0; i < q; i++) {
				for (int j = 0; j < d + 1; j++) {
					cout << "R";
				}
				cout << "B";
			}
			for (int i = q; i < b + 1; i++) {
				for (int j = 0; j < d; j++) {
					cout << "R";
				}
				if (i != b) {
					cout << "B";
				}
			}
		}

		cout << "\n";

	}
	return 0;
}
