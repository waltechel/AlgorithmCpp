#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>

/*
	swap의 횟수가 홀수냐 짝수냐를 결정한다.
	세 개의 수 중 한 개만 다르면 안된다. 0개면 되고, 3개면 순열 사이클 분할, 2개면 안된다. 1개 다른 경우는 없다. 
*/

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