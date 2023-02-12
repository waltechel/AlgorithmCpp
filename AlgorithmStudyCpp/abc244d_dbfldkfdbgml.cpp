#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	string S1, S2, S3;
	cin >> S1 >> S2 >> S3;

	string T1, T2, T3;
	cin >> T1 >> T2 >> T3;

	bool flag = false;
	if (S1 == T1 && S2 == T2 && S3 == T3) {
		flag = true;
	}

	if (S2 == T1 && S3 == T2 && S1 == T3) {
		flag = true;
	}

	if (S3 == T1 && S1 == T2 && S2 == T3) {
		flag = true;
	}

	if (flag) {
		cout << "Yes";
	} else {
		cout << "No";
	}


	return 0;
}