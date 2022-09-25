#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int A[101];
	vector<int> B;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	for (int i = 0; i < N; i++) {
		int hit = A[i];
		for (int j = 0; j < B.size(); j++) {
			B[j] += hit;
		}
		B.push_back(hit);
	}

	int answer = 0;
	for (int i = 0; i < B.size(); i++) {
		if (B[i] >= 4) {
			answer++;
		}
	}

	cout << answer;


	return 0;
}