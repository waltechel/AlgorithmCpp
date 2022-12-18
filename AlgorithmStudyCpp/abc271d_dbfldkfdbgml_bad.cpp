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

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, S;

	cin >> N >> S;

	bool** dp = new bool*[N + 1];
	char** hist = new char*[N + 1];
	for (int i = 0; i < N + 1; i++) {
		dp[i] = new bool[10001];
		hist[i] = new char[10001];
		for (int j = 0; j < 10001; j++) {
			dp[i][j] = false;
			hist[i][j] = 'A';
		}
	}

	vector<int*> inputList;
	dp[0][0] = true;
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		int* A = new int[2];
		A[0] = a;
		A[1] = b;
		inputList.push_back(A);
		for (int j = 0; j <= 10000; j++) {
			if (dp[i - 1][j] == true && j + a <= 10000) {
				dp[i][j + a] = true;
				hist[i][j + a] = 'H';
			}
			if (dp[i - 1][j] == true && j + b <= 10000) {
				dp[i][j + b] = true;
				hist[i][j + b] = 'T';
			}
		}
	}

	if (dp[N][S]) {
		cout << "YES\n";
		stack<char> stack;
		for (int i = N; i >= 1; i--) {
			char nowChar = hist[i][S];
			stack.push(nowChar);
			if (nowChar == 'T') {
				int b = inputList[i - 1][1];
				S -= b;
			} else {
				int a = inputList[i - 1][0];
				S -= a;
			}
		}
		while (!stack.empty()) {
			cout << stack.top() << "";
			stack.pop();
		}
	} else {
		cout << "NO";
	}



	return 0;
}