#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<queue>

using namespace std;

int main() {

	int N;

	cin >> N;
	int* A = new int[N + 1];

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	priority_queue<int> pqDesc;
	priority_queue<int, vector<int>, greater<int>> pqAsc;
	for (int i = 1; i <= N; i++) {
		pqDesc.push(A[i]);
		pqAsc.push(A[i]);
	}

	long answer = 0;
	while (true) {
		int cnt = pqDesc.size();
		if (cnt == 1) {
			break;
		}
		int maxValue = pqDesc.top();
		pqDesc.pop();
		int minValue = pqAsc.top();
		int newMaxValue = maxValue % minValue;
		if (newMaxValue != 0) {
			pqDesc.push(newMaxValue);
			if (newMaxValue < minValue) {
				pqAsc.push(newMaxValue);
			}
		}
		answer++;
	}

	cout << answer;

	return 0;
}

